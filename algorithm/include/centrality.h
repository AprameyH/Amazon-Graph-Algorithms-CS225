#pragma once
#include <unordered_map>
#include "../../parsing/include/graph.h"
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <fstream>


class Centrality {
  private:
    

    /**
     * @brief Calculate betweenness centrality of the nodes in graph G based on the index nodeIdx.
     * @param G 
     * @param nodeIdx 
     * @return std::unordered_map<int, double> 
     */
    std::unordered_map<int, double> nodeCentrality(Parser::Graph G);

    std::unordered_map<int, double> betweenness;

  public:
    /**
     * @brief Construct a new Centrality object.
     * 
     */
    Centrality(Parser::Graph G);

    double getBetweenness(int nodeIdx);

    std::vector<std::pair<int, double>> getSortedList() const;

    void writeToFile(std::string filePath) const;
};
