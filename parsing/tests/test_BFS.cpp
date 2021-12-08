#include "catch2/catch.hpp"

#include "../include/graph.h"
#include "../include/node.h"

using Parser::Graph;
using Parser::Node;
using namespace std;

TEST_CASE("BFS") {
    SECTION("BFS on simple undirected graph") {
        std::string filename = "../parsing/tests/test_graph1.txt";
        Graph graph(filename);
        std::unordered_map<int, int> distances = graph.BFS(0);
        
        REQUIRE(distances[4] == 1);
        REQUIRE(distances[1] == 1);
        REQUIRE(distances[2] == 2);
        REQUIRE(distances[3] == 2);
        REQUIRE(distances[0] == 0);

    }

    SECTION("BFS on directed graph") {
        std::string filename = "../parsing/tests/test_graph2.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        std::vector<Node*> nodeZeroNeighbors = nodes[0].getNeighbors();
        REQUIRE(nodeZeroNeighbors[0]->getID() == 3);
        std::vector<Node*> nodeTwoNeighbors = nodes[2].getNeighbors();
        REQUIRE(nodeTwoNeighbors[0]->getID() == 6);
        std::vector<Node*> nodeSevenNeighbors = nodes[7].getNeighbors();
    }

    SECTION("bfs on unconnected graph") {
        std::string filename = "../parsing/tests/test_graph3.txt";
        Graph graph(filename);
        std::unordered_map<int, Node> &nodes = graph.getNodes();
        std::vector<Node*> nodeTwoNeighbors = nodes[2].getNeighbors();
        REQUIRE(nodeTwoNeighbors[0]->getID() == 3);
        std::vector<Node*> nodeFourNeighbors = nodes[4].getNeighbors();
        REQUIRE(nodeFourNeighbors[0]->getID() == 5);
    }


    // SECTION("Test sdfa") {
    //     std::string filename = "../data/amazon0601.txt";
    //     Graph graph(filename);
    //     std::unordered_map<int, Node> &nodes = graph.getNodes();
    //     int size = nodes.size();
    //     REQUIRE(size == 403394);
    // }
}