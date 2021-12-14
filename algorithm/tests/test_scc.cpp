#include "catch2/catch.hpp"
#include "../parsing/include/graph.h"
#include "include/SCC.h"

using Parser::Graph;

TEST_CASE("Checking SCC on small graph") {
  SECTION("SCC test graph 1") {
    std::string filename = "./tests/test_SCC_graph1.txt";
    Graph graph(filename);

    SCC scc(graph);

    REQUIRE(scc.areConnected(0, 1));
    REQUIRE(scc.areConnected(1, 2));
    REQUIRE(scc.areConnected(1, 3) == false);
    REQUIRE(scc.areConnected(3, 4) == false);
  }
}

TEST_CASE("SCC test on larger graph") {
  SECTION("Test on larger graph") {
    std::string filename = "./tests/test_SCC_graph2.txt";
    Graph graph(filename);

    SCC scc(graph);

    REQUIRE(scc.areConnected(3, 7));
    REQUIRE(scc.areConnected(4, 5));
    REQUIRE(scc.areConnected(4, 6));
    REQUIRE(scc.areConnected(0, 1));
    REQUIRE(scc.areConnected(1, 2));
    REQUIRE(scc.areConnected(1, 4) == false);
    REQUIRE(scc.areConnected(2, 3) == false);
    REQUIRE(scc.areConnected(4, 7) == false);
  } 
}

TEST_CASE("Test on directed acyclic graph(one component per node)") {
  SECTION("SCC test on graph 3") {
    std::string filename = "./tests/test_SCC_graph3.txt";
    Graph graph(filename);

    SCC scc(graph);

    REQUIRE(!scc.areConnected(0, 1));
    REQUIRE(!scc.areConnected(1, 2));
    REQUIRE(!scc.areConnected(1, 3));
    REQUIRE(!scc.areConnected(3, 4));
    }
}

TEST_CASE("SCC test blank graph") {
  SECTION("Test on blank graph")
    {
        std::string filename = "./tests/test_SCC_emptyGraph";
        Graph graph(filename);

        SCC scc(graph);

        REQUIRE(scc.getConnectedComponents().size() == 0);
    }
}

TEST_CASE("SCC on two node graph") {
  SECTION("Test on two nodes") {
    Graph G = Graph("./tests/two_nodes_graph.txt");
    SCC c = SCC(G);
    REQUIRE(c.countComponents() == 2);
  }
}