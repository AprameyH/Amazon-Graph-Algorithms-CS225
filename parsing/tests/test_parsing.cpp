#include "catch2/catch.hpp"

#include "../include/graph.h"
#include "../include/node.h"

using Parser::Graph;
using Parser::Node;
using namespace std;

TEST_CASE("Test Parsing to Find Neighbor Nodes") {
    SECTION("Test Graph 1: Nodes 1 and 4") {
        std::string filename = "../tests/test_graph1.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        std::cout << nodes[1].getID() << std::endl;
        std::vector<Node*> nodeOneNeighbors = nodes[1].getNeighbors();
        std::cout << "hel" << std::endl;
        std::cout <<"is it null___"<< nodeOneNeighbors[0] << std::endl;
        REQUIRE(nodeOneNeighbors[0]->getID() == 4);
        std::cout << "hello" << std::endl;
        REQUIRE(nodeOneNeighbors[1]->getID() == 3);
        REQUIRE(nodeOneNeighbors[2]->getID() == 0);
        REQUIRE(nodeOneNeighbors[3]->getID() == 2);
        std::vector<Node*> nodeFourNeighbors = nodes[4].getNeighbors();
        REQUIRE(nodeFourNeighbors[0]->getID() == 0);
        REQUIRE(nodeFourNeighbors[1]->getID() == 1);
        REQUIRE(nodeFourNeighbors[2]->getID() == 3);
    }

    SECTION("Test Graph 2: Directed Graph") {
        std::string filename = "../include/tests/test_graph2.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        std::vector<Node*> nodeZeroNeighbors = nodes[0].getNeighbors();
        REQUIRE(nodeZeroNeighbors[0]->getID() == 3);
        std::vector<Node*> nodeTwoNeighbors = nodes[2].getNeighbors();
        REQUIRE(nodeTwoNeighbors[0]->getID() == 6);
        std::vector<Node*> nodeSevenNeighbors = nodes[7].getNeighbors();
        REQUIRE(nodeTwoNeighbors[0]->getID() == 8);
    }

    SECTION("Test Graph 3: 2 Connected Components") {
        std::string filename = "../include/tests/test_graph3.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        std::vector<Node*> nodeZeroNeighbors = nodes[0].getNeighbors();
        REQUIRE(nodeZeroNeighbors[0]->getID() == 1);
        REQUIRE(nodeZeroNeighbors[1]->getID() == 2);
        std::vector<Node*> nodeThreeNeighbors = nodes[3].getNeighbors();
        REQUIRE(nodeThreeNeighbors[0]->getID() == 4);
    }
}