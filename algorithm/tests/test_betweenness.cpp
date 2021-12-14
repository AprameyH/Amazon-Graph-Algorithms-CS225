#include "../../../parsing/include/graph.h"
#include "catch2/catch.hpp"
#include "include/centrality.h"
#include <iostream>
#include <unordered_map>
#define DBL_MAX (9.999999999999999e99)
using namespace std;
using namespace Parser;

TEST_CASE("Betweenness small graph") {
  SECTION("Checking beetweenness value") {
    Graph G = Graph("./tests/smaller_test.txt");
    Centrality c = Centrality(G);
    REQUIRE(c.getBetweenness(1) == 0.0);
    REQUIRE(c.getBetweenness(2) == 3.0);
    REQUIRE(c.getBetweenness(3) == 0);
    REQUIRE(c.getBetweenness(4) == 1);
  }
}

TEST_CASE("Betweenness undirected graph 1") {
  //Betweenness values are doubled for undirected graphs
  SECTION("Checking beetweenness value") {
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
}

TEST_CASE("Betweenness undirected graph 2") {
  SECTION("Checking beetweenness value") {
    Graph G = Graph("./tests/undirected_graph_2.txt");
    Centrality c = Centrality(G);
    REQUIRE(c.getBetweenness(1) == 0);
    REQUIRE(c.getBetweenness(2) == 0);
    REQUIRE(c.getBetweenness(3) / 2 == 6);
    REQUIRE(c.getBetweenness(4) / 2 == 6);
    REQUIRE(c.getBetweenness(5) == 0);
    REQUIRE(c.getBetweenness(6) == 0);
  }
}

TEST_CASE("Betweenness multiple shortest paths") {
  SECTION("Checking beetweenness value") {
    Graph G = Graph("./tests/multiple_shortest_paths.txt");
    Centrality c = Centrality(G);
    REQUIRE(c.getBetweenness(0) == 0.0);
    REQUIRE(c.getBetweenness(1) == 1.0 / 3.0);
    REQUIRE(c.getBetweenness(2) == 1.0 / 3.0);
    REQUIRE(c.getBetweenness(3) == 1.0 / 3.0);
    REQUIRE(c.getBetweenness(4) == 0.0);
  }
}

TEST_CASE("Betweenness sorted by betweenness") {
  SECTION("Checking sort") {
    Graph G = Graph("./tests/undirected_graph_1.txt");
    Centrality c = Centrality(G);
    double previous = DBL_MAX;
    for (auto it : c.getSortedList()) {
      REQUIRE(it.second <= previous);
      previous = it.second;
    }
  }
}

TEST_CASE("Test write to file") {
  SECTION("Checking beetweenness value") {
    Graph G = Graph("./tests/undirected_graph_1.txt");
    Centrality c = Centrality(G);
    c.writeToFile("./tests/testOutput.txt");
  }
}

TEST_CASE("Test on empty graph") {
  SECTION("Check empty map") {
    Graph G = Graph("./tests/empty_text.txt");
    Centrality c = Centrality(G);
    REQUIRE(c.getBetweenness(5000) == -1);
  }
}

TEST_CASE("Test on two node graph") {
  SECTION("Check betweenness") {
    Graph G = Graph("./tests/two_nodes_graph.txt");
    Centrality c = Centrality(G);
    REQUIRE(c.getBetweenness(0) == 0);
    REQUIRE(c.getBetweenness(1) == 0);
  }
}