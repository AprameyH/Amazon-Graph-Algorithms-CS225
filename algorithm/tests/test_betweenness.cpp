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
    REQUIRE(c.getBetweenness(1) == 0.0);
    REQUIRE(c.getBetweenness(2) == 3.0);
    REQUIRE(c.getBetweenness(3) == 0);
    REQUIRE(c.getBetweenness(4) == 1);
  }
  SECTION("Undirected_graph_1") {
    Graph G = Graph("./tests/undirected_graph_1.txt");
    Centrality c = Centrality(G);
    REQUIRE(c.getBetweenness(1) / 2 == 3);
    REQUIRE(c.getBetweenness(2) / 2 == 0);
    REQUIRE(c.getBetweenness(3) / 2 == 3);
    REQUIRE(c.getBetweenness(4) / 2 == 15);
    REQUIRE(c.getBetweenness(5) / 2 == 6);
    REQUIRE(c.getBetweenness(6) / 2 == 6);
    REQUIRE(c.getBetweenness(7) / 2 == 7);
    REQUIRE(c.getBetweenness(8) / 2 == 0);
    REQUIRE(c.getBetweenness(9) / 2 == 0);
  }
  SECTION("Undirected_graph_2") {
    Graph G = Graph("./tests/undirected_graph_2.txt");
    Centrality c = Centrality(G);
    REQUIRE(c.getBetweenness(1) == 0);
    REQUIRE(c.getBetweenness(2) == 0);
    REQUIRE(c.getBetweenness(3) / 2 == 6);
    REQUIRE(c.getBetweenness(4) / 2 == 6);
    REQUIRE(c.getBetweenness(5) == 0);
    REQUIRE(c.getBetweenness(6) == 0);
  }
  SECTION("Multiple_shortest_paths") {
    Graph G = Graph("./tests/multiple_shortest_paths.txt");
    Centrality c = Centrality(G);
    REQUIRE(c.getBetweenness(0) == 0.0);
    REQUIRE(c.getBetweenness(1) == 1.0/3.0);
    REQUIRE(c.getBetweenness(2) == 1.0/3.0);
    REQUIRE(c.getBetweenness(3) == 1.0/3.0);
    REQUIRE(c.getBetweenness(4) == 0.0);
  }
}