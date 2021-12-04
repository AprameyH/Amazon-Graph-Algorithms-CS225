#pragma once
#include <unordered_map>
#include "../../parsing/include/graph.h"
#include <stack>
#include <queue>
#include <vector>



class Centrality {
  private:
    std::unordered_map<int, double> betweenness;

  public:
    /**
     * @brief Construct a new Centrality object.
     * 
     */
    Centrality(Parser::Graph G, int nodeIdx);

    /**
     * @brief Calculate betweenness centrality of the nodes in graph G based on the index nodeIdx.
     * 
     * @param G 
     * @param nodeIdx 
     * @return std::unordered_map<int, double> 
     */
    std::unordered_map<int, double> nodeCentrality(Parser::Graph G, int nodeIdx);

    std::unordered_map<int, double> getBetweenness();
};
