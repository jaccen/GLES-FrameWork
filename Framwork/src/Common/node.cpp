//
//  node.cpp
//  Engine
//
//  Created by jaccen on 2019/5/7.
//

#include "node.hpp"
Node::Node() :
name(),
nodes({}),
meshes({}),
parent(),
id(0)
{
}

Node::~Node()
{
}
