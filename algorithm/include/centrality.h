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
     * @param G The graph to find betweenness centrality on.
     * @return std::unordered_map<int, double> The unordered map of node indices to betweenness values for graph G.
     */
    std::unordered_map<int, double> nodeCentrality(Parser::Graph G);

    /**
     * @brief Unordered map that maps node indices to betweenness values.
     * 
     */
    std::unordered_map<int, double> betweenness;

  public:
    /**
     * @brief Construct a new Centrality object.
     * 
     */
    Centrality(Parser::Graph G);

    /**
     * @brief Get the betweenness value for a specific node.
     * 
     * @param nodeIdx The node to find the betweenness value of.
     * @return double The betweenness value of the node.
     */
    double getBetweenness(int nodeIdx);

    /**
     * @brief Get a vector of pairs of node indices and betweenness centrality values that is ordered by betweenness centrality value.
     * 
     * @return std::vector<std::pair<int, double>> The vector with the pair of node indices and betweenness centrality values.
     */
    std::vector<std::pair<int, double>> getSortedList() const;

    /**
     * @brief Write the betweenness centrality values for all the nodes in the graph to a file.
     * 
     * @param filePath The path to where the file should be created.
     */
    void writeToFile(std::string filePath) const;
};
