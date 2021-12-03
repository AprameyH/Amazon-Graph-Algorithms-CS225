#include "../include/node.h"

using std::string;

namespace Parser {
    unsigned Node::num_nodes_;
    
    Node::Node(int id) {
        id_ = id;
    }
    Node::Node() {
        
    }

    Node::~Node() {
        num_nodes_--;
    }

    unsigned Node::getID() {
        return id_;
    }

    void Node::addNeighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }
}