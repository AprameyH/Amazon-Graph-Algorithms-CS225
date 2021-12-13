#include "catch2/catch.hpp"
// #include "include/adder.h"
#include "../parsing/include/graph.h"
#include "include/SCC.h"

using Parser::Graph;

TEST_CASE("Test Strongly Connected Components")
{
    SECTION("Test on small graph")
    {
        std::string filename = "../algorithm/tests/test_SCC_graph1.txt";
        Graph graph(filename);

        SCC scc(graph);
        // vector<int> conn_comp = scc.getConnectedComponents();

        REQUIRE(scc.areConnected(0, 1));
        REQUIRE(scc.areConnected(1, 2));
        REQUIRE(scc.areConnected(1, 3) == false);
        REQUIRE(scc.areConnected(3, 4) == false);
    }

    SECTION("Test on larger graph")
    {
        std::string filename = "../algorithm/tests/test_SCC_graph2.txt";
        Graph graph(filename);

        SCC scc(graph);
        // vector<int> conn_comp = scc.getConnectedComponents();

        REQUIRE(scc.areConnected(3, 7));
        REQUIRE(scc.areConnected(4, 5));
        REQUIRE(scc.areConnected(4, 6));
        REQUIRE(scc.areConnected(0, 1));
        REQUIRE(scc.areConnected(1, 2));
        REQUIRE(scc.areConnected(1, 4) == false);
        REQUIRE(scc.areConnected(2, 3) == false);
        REQUIRE(scc.areConnected(4, 7) == false);
    }

    SECTION("Test on directed acyclic graph(one component per node)")
    {
        std::string filename = "../algorithm/tests/test_SCC_graph3.txt";
        Graph graph(filename);

        SCC scc(graph);
        // vector<int> conn_comp = scc.getConnectedComponents();

        REQUIRE(!scc.areConnected(0, 1));
        REQUIRE(!scc.areConnected(1, 2));
        REQUIRE(!scc.areConnected(1, 3));
        REQUIRE(!scc.areConnected(3, 4));
    }

    SECTION("Test Graph 2: 3 Strongly Connected Components")
    {
        std::string filename = "../algorithm/tests/test_SCC_graph3.txt";
        Graph graph(filename);

        SCC scc(graph);
        // vector<int> conn_comp = scc.getConnectedComponents();

        REQUIRE(!scc.areConnected(0, 1));
        REQUIRE(!scc.areConnected(1, 2));
        REQUIRE(!scc.areConnected(1, 3));
        REQUIRE(!scc.areConnected(3, 4));
    }
    SECTION("Test Graph 2: blank graph")
    {
        std::string filename = "../algorithm/tests/test_SCC_emptyGraph";
        Graph graph(filename);

        SCC scc(graph);
        // vector<int> conn_comp = scc.getConnectedComponents();

        REQUIRE(scc.getConnectedComponents().size() == 0);
    }

    // SECTION("Test on real graph") {
    //      std::string filename = "../data/amazon0601.txt";
    //      Graph graph(filename);

    //     SCC scc(graph);
    //     int size = graph.getNodes().size();
    //     std::cout << size << std::endl;
    //     int count = scc.countComponents();
    //     REQUIRE(count == 1588);

    //     scc.printStronglyConnectedComponent(32, "SCCResults.txt");
    // }
}