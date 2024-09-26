#include "GgsFdebNode.hpp"

GgsFdebNode::GgsFdebNode()
{
    _pos.set(0.0, 0.0);
    _degree = 0;
}

GgsFdebNode::GgsFdebNode(double x_, double y_)
{
    _pos.set(x_, y_);
    _degree = 0;
}
