#include "catch2/catch.hpp"

#include "../include/graph.h"
#include "../include/node.h"

using Parser::Graph;
using Parser::Node;
using namespace std;

TEST_CASE("BFS")
{

    // SECTION("BFS on simple undirected graph")
    // {
    //     std::string filename = "../parsing/tests/test_graph1.txt";
    //     Graph graph(filename);
    //     std::unordered_map<int, int> distances = graph.BFS(0);
    //     //node 0 = root
    //     REQUIRE(distances[4] == 1);
    //     REQUIRE(distances[1] == 1);
    //     REQUIRE(distances[2] == 2);
    //     REQUIRE(distances[3] == 2);
    //     REQUIRE(distances[0] == 0);
    // }

    // SECTION("BFS on directed graph")
    // {
    //     std::string filename = "../parsing/tests/test_graph2.txt";
    //     Graph graph(filename);
    //     std::unordered_map<int, int> distances = graph.BFS(3);
    //     //node 3 = root
    //     REQUIRE(distances.count(0) == 0);
    //     REQUIRE(distances[3] == 0);
    //     REQUIRE(distances[5] == 1);
    //     REQUIRE(distances[1] == 1);
    //     REQUIRE(distances[7] == 2);
    //     REQUIRE(distances[2] == 2);
    //     REQUIRE(distances[4] == 2);
    //     REQUIRE(distances[6] == 3);
    //     REQUIRE(distances[8] == 3);
    // }

    // SECTION("BFS on unconnected graph")
    // {
    //     std::string filename = "../parsing/tests/test_graph3.txt";
    //     Graph graph(filename);
    //     std::unordered_map<int, int> distances = graph.BFS(0);
    //     //node 0 = root
    //     REQUIRE(distances[0] == 0);
    //     REQUIRE(distances[1] == 1);
    //     REQUIRE(distances[2] == 1);
    //     REQUIRE(distances.count(3) == 0);
    //     REQUIRE(distances.count(4) == 0);
    // }

    SECTION("Test BFS on amazon graph") {
        std::string filename = "../data/amazon0601.txt";
        Graph graph(filename);
        std::unordered_map<int, int> distances = graph.BFS(0);

        int size = distances.size();
        REQUIRE(size == 402793);
        REQUIRE(distances[5] == 1);
    }
    SECTION("Test DFS on Amazon Graph") {
        std::string filename = "../data/amazon0601.txt";
        Graph graph(filename);
        std::unordered_map<int, bool> path_exists = graph.DFS(0);

        int size = path_exists.size();
        REQUIRE(size == 402793);
    }

}