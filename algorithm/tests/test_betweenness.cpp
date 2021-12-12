#include "catch2/catch.hpp"
#include "../../../parsing/include/graph.h"
#include "include/centrality.h"
#include <iostream>
#include <unordered_map>
using namespace std;
using namespace Parser;

TEST_CASE("Betweenness test") {
  SECTION("Smaller_graph") {
    Graph G = Graph("./tests/smaller_test.txt");
    Centrality c = Centrality(G);
    unordered_map<int, double> betweenness = c.betweenness;
    REQUIRE(betweenness[1] == 0.0);
    REQUIRE(betweenness[2] == 3.0);
    REQUIRE(betweenness[3] == 0);
    REQUIRE(betweenness[4] == 1);
  }
  SECTION("Undirected_graph_!") {
    Graph G = Graph("./tests/undirected_graph_1.txt");
    Centrality c = Centrality(G);
    unordered_map<int, double> betweenness = c.betweenness;
    REQUIRE(betweenness[1] / 2 == 3);
    REQUIRE(betweenness[2] / 2 == 0);
    REQUIRE(betweenness[3] / 2 == 3);
    REQUIRE(betweenness[4] / 2 == 15);
    REQUIRE(betweenness[5] / 2 == 6);
    REQUIRE(betweenness[6] / 2 == 6);
    REQUIRE(betweenness[7] / 2 == 7);
    REQUIRE(betweenness[8] / 2 == 0);
    REQUIRE(betweenness[9] / 2 == 0);
  }
  SECTION("Undirected_graph_2") {
    Graph G = Graph("./tests/undirected_graph_2.txt");
    Centrality c = Centrality(G);
    unordered_map<int, double> betweenness = c.betweenness;
    REQUIRE(betweenness[1] == 0);
    REQUIRE(betweenness[2] == 0);
    REQUIRE(betweenness[3] / 2 == 6);
    REQUIRE(betweenness[4] / 2 == 6);
    REQUIRE(betweenness[5] == 0);
    REQUIRE(betweenness[6] == 0);
  }
  SECTION("Multiple_shortest_paths") {
    Graph G = Graph("./tests/multiple_shortest_paths.txt");
    Centrality c = Centrality(G);
    unordered_map<int, double> betweenness = c.betweenness;
    REQUIRE(betweenness[0] == 0.0);
    REQUIRE(betweenness[1] == 1.0/3.0);
    REQUIRE(betweenness[2] == 1.0/3.0);
    REQUIRE(betweenness[3] == 1.0/3.0);
    REQUIRE(betweenness[4] == 0.0);
  }
}