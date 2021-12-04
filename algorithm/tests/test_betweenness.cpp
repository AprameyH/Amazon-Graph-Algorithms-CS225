#include "catch2/catch.hpp"
#include "../../../parsing/include/graph.h"
#include "include/centrality.h"
#include <iostream>
#include <unordered_map>
using namespace std;
using namespace Parser;

TEST_CASE("Betweenness test") {
    SECTION("Sanity check", "[adder]") {
        int four = 4;
        std::cout<<"betweenness tests running"<<std::endl;
        REQUIRE(four == 4);
    }
    SECTION("Call betweenness on graph") {
        Graph G = Graph("./tests/small_betweenness.txt");
        Centrality c = Centrality(G);
        unordered_map<int, double> betweenness = c.betweenness;
        for (auto n : betweenness) {
            cout<<n.first<<", "<<n.second<<endl;
        }
        
    }
}