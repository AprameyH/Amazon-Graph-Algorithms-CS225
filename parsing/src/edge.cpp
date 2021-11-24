#include "../include/edge.h"

namespace Parser {
    Edge::Edge(Node * source, Node * dest) {
        _source = source;
        _dest = dest;
    }

    Edge::~Edge() {
        delete _source;
        delete _dest;
    }

    unsigned Edge::getID() {
        return id;
    }

    Node * Edge::getSource() {
        return _source;
    }

    Node * Edge::getDestination() {
        return _dest;
    }
}