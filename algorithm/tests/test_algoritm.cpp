#include "catch2/catch.hpp"
// #include "include/adder.h"
#include "../parsing/include/graph.h"
#include "include/SCC.h"

using Parser::Graph;

TEST_CASE("simple test") {
    SECTION("test") {
        std::string filename = "../parsing/tests/test_graph2.txt";
        Graph graph(filename);

        SCC scc(graph);
        


    }
}