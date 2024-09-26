#include "GgsFdebGraph.hpp"

GgsFdebGraph::GgsFdebGraph()
{
    _log.tag("Graph");

    _K = 0.1;
    _I = 90;
    _iter = _I;
    _cycles = 6;
    _compatibilityThreshold = 0.6;
    _smoothWidth = 30.0;

    _S = 2.3;
    _edgeDistance = 1e-4;
    _gravitationIsOn = false;
    _gravitationCenter.set(0.0, 0.0);
    _gravitationExponent = -2.0;

    _edgeWeightThreshold = -1.0;
    _edgePercentageThreshold = -1.0;

    _edgeOpacity = 0.1;
}

void GgsFdebGraph::set_network_params(double edgeWeightThreshold_, double edgePercentageThreshold_)
{
    if( edgeWeightThreshold_ > 0.0 )
        _edgeWeightThreshold = edgeWeightThreshold_;
    else if( edgePercentageThreshold_ > 0.0 )
        _edgePercentageThreshold = edgePercentageThreshold_;
}

void GgsFdebGraph::set_algorithm_params(double K_, int cycles_, int I0_, double compat_, double sigma_)
{
    _K = K_;
    _cycles = cycles_;
    _I = I0_;
    _iter = _I;
    _compatibilityThreshold = compat_;
    _smoothWidth = sigma_;
}

void GgsFdebGraph::set_physics_params(double S0_, double edgeDistance_,
                               meerkat::mk_vector2 gravCenter_,
                               double gravExponent_)
{
    _S = S0_;
    _edgeDistance = edgeDistance_;
    _gravitationCenter = gravCenter_;
    _gravitationExponent = gravExponent_;
}

void GgsFdebGraph::enable_gravitation()
{
    _log.i("enable_gravitation", "gravitation is enabled");
    _gravitationIsOn = true;
}

void GgsFdebGraph::set_graphics_params(double alpha_)
{
    _edgeOpacity = alpha_;
}

void GgsFdebGraph::load(std::map<std::string, GgsFdebNode> nodes, std::vector<GgsFdebEdge> edges)
{
	_nodes = nodes;

	double w, wmax = 0.0;
	std::vector<GgsFdebEdge> allEdges = edges;
	std::sort(allEdges.begin(), allEdges.end(), compare_edges);

	wmax = allEdges[0]._width;

	int rows = edges.size();
	// filter out edges by weight
	if (_edgeWeightThreshold > 0.0)
	{
		for (int i = 0; i < rows ; i++)
		{
			if (allEdges[i]._width > _edgeWeightThreshold)
			{
				_edges.push_back(allEdges[i]);
				_nodes[allEdges[i]._sourceLabel]._degree++;
				_nodes[allEdges[i]._targetLabel]._degree++;
			}
		}
	}
	// filter out edges by percentage
	else if (_edgePercentageThreshold > 0.0)
	{
		int nEdges = int(_edgePercentageThreshold * (rows) / 100);
		for (int i = 0; i < nEdges; i++)
		{
			_edges.push_back(allEdges[i]);
			_nodes[allEdges[i]._sourceLabel]._degree++;
			_nodes[allEdges[i]._targetLabel]._degree++;
		}
	}
	// if no filter option set, take all edges
	else
	{
		for (int i = 0; i < rows; i++)
		{
			_edges.push_back(allEdges[i]);
			_nodes[allEdges[i]._sourceLabel]._degree++;
			_nodes[allEdges[i]._targetLabel]._degree++;
		}
	}
	// normalize edge widths
	int edgesNum = (int)_edges.size();
	for (int i = 0; i < edgesNum; i++)
		_edges[i]._width *= 1.0 / (wmax + 1.0);
	_log.i("read", "number of edges: %i", (int)_edges.size());
	allEdges.clear();

    // build compability lists
    build_compatibility_lists();
}

void GgsFdebGraph::get_bounding_box(meerkat::mk_vector2 &bottomLeft_,
                             meerkat::mk_vector2 &topRight_,
                             double frame_)
{
    std::map<std::string, GgsFdebNode>::iterator it = _nodes.begin();
    bottomLeft_ = it->second._pos;
    topRight_ = it->second._pos;
    it++;
    double x, y;
    for( ;
         it != _nodes.end();
         it++ )
    {
        x = it->second._pos.x();
        y = it->second._pos.y();
        if( x < bottomLeft_.x() )
            bottomLeft_.set_x(x);
        if( y < bottomLeft_.y() )
            bottomLeft_.set_y(y);
        if( x > topRight_.x() )
            topRight_.set_x(x);
        if( y > topRight_.y() )
            topRight_.set_y(y);
    }
    bottomLeft_.set(bottomLeft_.x()-frame_, bottomLeft_.y()-frame_);
    topRight_.set(topRight_.x()+frame_, topRight_.y()+frame_);
    _log.i("get_bounding_box", "bounding box: (%lg, %lg, %lg, %lg)",
           bottomLeft_.x(), bottomLeft_.y(), topRight_.x(), topRight_.y());
}

void GgsFdebGraph::build_compatibility_lists()
{
    _log.i("build_compability_lists", "building lists");

    int edgesNum = (int)_edges.size(), compEdgePairs = 0;
    double comp = 0.0;
    for( int i=0; i<edgesNum; i++ )
    {
        for( int j=i+1; j<edgesNum; j++ )
        {
            comp = GgsFdebEdge::angle_compatilibity(_edges[i], _edges[j])
                    * GgsFdebEdge::scale_compatibility(_edges[i], _edges[j])
                    * GgsFdebEdge::position_compatibility(_edges[i], _edges[j])
                    * GgsFdebEdge::visibility_compability(_edges[i], _edges[j]);
            if( comp >= _compatibilityThreshold )
            {
                _edges[i]._compatibleEdges.push_back(j);
                _edges[j]._compatibleEdges.push_back(i);
                compEdgePairs++;
            }
        }

        if( edgesNum >= 100 && i%(edgesNum/100) == 0 )
            _log.i( "build_compatibility_lists", "%i%% done, compatible edges: %i",
                    i/(edgesNum/100), compEdgePairs );
    }
}

int GgsFdebGraph::iterate()
{
    int edgesNum = (int)_edges.size();
    std::vector<std::vector<meerkat::mk_vector2> > forces(
                edgesNum,
                std::vector<meerkat::mk_vector2>(
                    (int)_edges[0]._subdivs.size(), meerkat::mk_vector2(0.0, 0.0))
            );

    // spring forces
    for( int i=0; i<edgesNum; i++ )
        _edges[i].add_spring_forces(forces[i], _K);

    // electrostatic forces
    for( int i=0; i<edgesNum; i++ )
    {
        int compatibleEdgesNum = (int)_edges[i]._compatibleEdges.size();
        for( int j=0; j<compatibleEdgesNum; j++ )
            _edges[i].add_electrostatic_forces(forces[i],
                                               _edges[_edges[i]._compatibleEdges[j]],
                                               _edgeDistance);
    }

    // gravitation
    if( _gravitationIsOn )
    {
        for( int i=0; i<edgesNum; i++ )
            _edges[i].add_gravitational_forces(forces[i],
                                               _gravitationCenter,
                                               _gravitationExponent);
    }

    // update edges
    for( int i=0; i<edgesNum; i++ )
        _edges[i].update(forces[i], _S);

    _iter--;
    return _iter;
}

int GgsFdebGraph::update_cycle()
{
    _log.i("update_cycle", "updating parameters");
    _S *= 0.5;
    _I = 2*_I/3;
    _iter = _I;
    _cycles--;
    return _cycles;
}

void GgsFdebGraph::add_subvisions()
{
    _log.i("add_subdivisions", "subdividing edges");
    int edgesNum = (int)_edges.size();
    for( int i=0; i<edgesNum; i++ )
        _edges[i].add_subdivisions();
}

void GgsFdebGraph::smooth()
{
    _log.i("smooth", "applying Gaussian smoothing");
    int edgesNum = (int)_edges.size();
    for( int i=0; i<edgesNum; i++ )
        _edges[i].smooth(_smoothWidth);
    _log.i("smooth", "done");
}

void GgsFdebGraph::print_json(std::string output_)
{
    FILE *p = fopen(output_.c_str(), "w");
    if( p == NULL )
    {
        _log.e("print_json", "could not open output file");
        exit(0);
    }

    // nodes
    fprintf( p, "{\n  \"nodes\" : [\n" );
    int numNodes = (int)_nodes.size(), nodeId = 0;
    for( std::map<std::string, GgsFdebNode>::iterator it = _nodes.begin();
         it != _nodes.end();
         it++ )
    {
        fprintf( p, "    {\n" );
        fprintf( p, "      \"label\" : \"%s\",\n", it->first.c_str() );
        fprintf( p, "      \"x\" : %lg,\n", it->second._pos.x() );
        fprintf( p, "      \"y\" : %lg\n", it->second._pos.y() );
        if( nodeId < numNodes-1 )
            fprintf( p, "    },\n");
        else
            fprintf( p, "    }\n" );
        nodeId++;
    }
    fprintf( p, "  ],\n" );

    // edges
    fprintf( p, "  \"edges\" : [\n" );
    int numEdges = (int)_edges.size(), len;
    for( int i=0; i<numEdges; i++ )
    {
        fprintf( p, "    {\n" );
        fprintf( p, "      \"source\" : \"%s\",\n", _edges[i]._sourceLabel.c_str() );
        fprintf( p, "      \"target\" : \"%s\",\n", _edges[i]._targetLabel.c_str() );
        fprintf( p, "      \"coords\" : [\n" );
        fprintf( p, "        { \"x\" : %lg, \"y\" : %lg },\n",
                 _edges[i]._start.x(), _edges[i]._start.y() );
        len = (int)_edges[i]._subdivs.size();
        for( int j=0; j<len; j++ )
        {
            fprintf( p, "        { \"x\" : %lg, \"y\" : %lg },\n",
                     _edges[i]._subdivs[j].x(), _edges[i]._subdivs[j].y() );
        }
        fprintf( p, "        { \"x\" : %lg, \"y\" : %lg }\n",
                 _edges[i]._end.x(), _edges[i]._end.y() );
        fprintf( p, "      ]\n" );
        if( i < numEdges-1 )
            fprintf( p, "    },\n");
        else
            fprintf( p, "    }\n" );
    }
    fprintf( p, "  ]\n" );
    fprintf( p, "}" );
    fclose( p );

    _log.i("print_json", "network is written in '%s'", output_.c_str());
}

void GgsFdebGraph::print_svg(std::string output_)
{
    //TODO
}

