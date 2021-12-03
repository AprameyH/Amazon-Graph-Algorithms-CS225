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

    Graph(string fileName);

    void readData(string filename);

    // preform bfs on the graph and return hashmap of hashmaps which takes in the index of a node as the key with a hashamp of
    // distance to other reachable nodes as the value.
    std::unordered_map<int, std::unordered_map<int, int>> BFS();

    std::unordered_map<int, int> BFS(int start_id);

    std::unordered_map<int, Node>& getNodes();

    std::vector<Node*> getNeighbors(int id);




    private:

    std::unordered_map<int, Node> nodes;
  };

}