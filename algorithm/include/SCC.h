#pragma once
#include <unordered_map>
#include "../../parsing/include/graph.h"
#include <stack>
#include <queue>
#include <vector>

using Parser::Graph;
using std::vector;

class SCC {
    public:
        /**
         * @brief Construct a new SCC object.
         * 
         * @param g The graph to perform SCC on.
         */
        SCC(Graph& g);

        /**
         * @brief Checks if two nodes are connected.
         * 
         * @param node1_id The first node.
         * @param node2_id The second node.
         * @return true Returned if the nodes are connected.
         * @return false Returned if the nodes are not connected.
         */
        bool areConnected(int node1_id, int node2_id);

        /**
         * @brief Get a vector of connected components where the index is the node and the value the node's corresponding connected component.
         * 
         * @return vector<int> The vector of connected components.
         */
        vector<int> getConnectedComponents();

        /**
         * @brief The number of connected components in the graph.
         * 
         * @return int 
         */
        int countComponents();

        /**
         * @brief Print the strongly connected component into a .txt file. 
         * 
         * @param node_id The node to find the connected component of.
         * @param filePath The path to make the new file.
         */
        void printStronglyConnectedComponent(int node_id, std::string filePath);

    private:

        /**
         * @brief Vector of connected components.
         * 
         */
        vector<int> lows;

        /**
         * @brief Performs Tarjan's Algorithm. Fills up lows vector.
         * 
         * @param g The graph to perform the algorithm on.
         */
        void tarjanAlgo(Graph& g);

        /**
         * @brief Helper function for performing Tarjan's algorithm  
         * 
         * @param u The node to perform DFS on.
         * @param g The graph to perform the algortihm on.
         * @param disc The order in which the nodes were discovered.
         * @param stackMember True if nodes are members of the stack.
         * @param st The stack invariant.
         */
        void tarjanUtil(int u, Graph& g, vector<int>& disc, vector<bool>& stackMember, std::stack<int>& st);
    
};