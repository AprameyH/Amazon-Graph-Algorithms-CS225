#include "../include/node.h"

using std::string;

namespace Parser {
    
    Node::Node(int id) {
        id_ = id;
    }

    unsigned Node::getID() {
        return id_;
    }

    void Node::addNeighbor(Node* neighbor) {
        neighbors.push_back(neighbor);
    }

    std::vector<Node*> Node::getNeighbors() {
        return neighbors;
    }
}