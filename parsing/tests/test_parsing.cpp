#include "catch2/catch.hpp"

#include "../include/graph.h"
#include "../include/node.h"

using Parser::Graph;
using Parser::Node;
using namespace std;

TEST_CASE("Test Parsing to Find Neighbor Nodes") {
    SECTION("Test Graph 1: Nodes 1 and 4") {
        std::string filename = "../parsing/tests/test_graph1.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        std::vector<Node*> nodeOneNeighbors = nodes[1].getNeighbors();
        REQUIRE(nodeOneNeighbors[0]->getID() == 4);
        REQUIRE(nodeOneNeighbors[1]->getID() == 3);
        REQUIRE(nodeOneNeighbors[2]->getID() == 0);
        REQUIRE(nodeOneNeighbors[3]->getID() == 2);
        std::vector<Node*> nodeFourNeighbors = nodes[4].getNeighbors();
        REQUIRE(nodeFourNeighbors[0]->getID() == 0);
        REQUIRE(nodeFourNeighbors[1]->getID() == 1);
        REQUIRE(nodeFourNeighbors[2]->getID() == 3);
    }

    SECTION("Test Graph 2: Directed Graph") {
        std::string filename = "../parsing/tests/test_graph2.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        std::vector<Node*> nodeZeroNeighbors = nodes[0].getNeighbors();
        REQUIRE(nodeZeroNeighbors[0]->getID() == 3);
        std::vector<Node*> nodeTwoNeighbors = nodes[2].getNeighbors();
        REQUIRE(nodeTwoNeighbors[0]->getID() == 6);
        std::vector<Node*> nodeSevenNeighbors = nodes[7].getNeighbors();
    }

    SECTION("Test Graph 3: disconnected graph") {
        std::string filename = "../parsing/tests/test_graph3.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        std::vector<Node*> nodeTwoNeighbors = nodes[2].getNeighbors();
        REQUIRE(nodeTwoNeighbors[0]->getID() == 3);
        std::vector<Node*> nodeFourNeighbors = nodes[4].getNeighbors();
        REQUIRE(nodeFourNeighbors[0]->getID() == 5);
    }


    SECTION("Test Amazon data") {
        std::string filename = "../data/amazon0601.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        int size = nodes.size();
        REQUIRE(size == 403394);
    }
}