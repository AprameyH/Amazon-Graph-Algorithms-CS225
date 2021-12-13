#pragma once

#include <string>

#include "node.h"
#include <unordered_map>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>

using std::string;

namespace Parser {
  class Graph {
    public:

    /**
     * @brief Construct a new Graph object.
     * 
     * @param filePath The path to the file that has the graph data. Only works on .txt files with a specific format.
     */
    Graph(string filePath);

    /**
     * @brief Reads the data from the file.
     * 
     * @param filePath The path to the file that has the graph data. Only works on .txt files with a specific format.
     */
    void readData(string filePath);

    /**
     * @brief Perform BFS on the graph.
     * 
     * @return std::unordered_map<int, std::unordered_map<int, int>> A hashmap of hashmaps which maps the index of a node to a hashamp of distance to other reachable nodes as the value.
     */
    std::unordered_map<int, std::unordered_map<int, int>> BFS();

    /**
     * @brief Performs BFS on a specific node.
     * 
     * @param start_id The specific node to run BFS on.
     * @return std::unordered_map<int, int> A hashmap with the key being a node id and the value being the distance from the start node to that particular node.
     */
    std::unordered_map<int, int> BFS(int start_id);

    /**
     * @brief Performs DFS on a graph.
     * 
     * @param start_id The node to start DFS.
     * @return std::unordered_map<int, bool> A hashmap of all the visitable nodes from the passed in node.
     */
    std::unordered_map<int, bool> DFS(int start_id);

    /**
     * @brief Recursive version of DFS.
     * 
     * @param start_id The node to start DFS on.
     * @return std::unordered_map<int, bool> A hashmap of all the visitable nodes from the passed in node.
     */
    std::unordered_map<int, bool> DFSRecur(int start_id);

    /**
     * @brief Helper function to the DFSRecur function.
     * 
     * @param start_id The node to start DFS on.
     * @param visited The hashmap of all visited nodes to keep track of which ones have been visited already.
     * @return std::unordered_map<int, bool> A hashmap of all the visitable nodes from the passed in node.
     */
    std::unordered_map<int, bool> DFSRecurHelper(int start_id, std::unordered_map<int, bool>& visited);

    /**
     * @brief Get the private nodes variable.
     * 
     * @return std::unordered_map<int, Node>& 
     */
    std::unordered_map<int, Node>& getNodes();

    /**
     * @brief Get the neighbors of a specific node.
     * 
     * @param id The id of the node.
     * @return std::vector<Node*> A vector of nodes that are the neighbors.
     */
    std::vector<Node*> getNeighbors(int id);
    
    /**
     * @brief Get the total number of nodes in the graph.
     * 
     * @return int 
     */
    int size();

    private:

    /**
     * @brief A hashmap of node ids to nodes in the graph.
     * 
     */
    std::unordered_map<int, Node> nodes;
  };

}