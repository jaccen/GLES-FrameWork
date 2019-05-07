//
//  node.hpp
//  Engine
//
//  Created by jaccen on 2019/5/7.
//

#ifndef node_hpp
#define node_hpp
#include "configure.h"
#include <iostream>
#include "mesh.h"
#include "transform.h"
class Node
{
public:
    Node();
    Node(Node* n) {
        name = n->name;
        nodes = n->nodes;
        meshes = n->meshes;
        transform = n->transform;
        parent = n->parent;
        id = n->id;
    }
    ~Node();
    
    std::string name;
    std::vector<Node*> nodes;
    std::vector<Mesh*> meshes;
    Transform transform;
    Node* parent;
    unsigned int id;
};
#endif /* node_hpp */
