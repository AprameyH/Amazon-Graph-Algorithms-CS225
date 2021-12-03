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


    private:

    std::unordered_map<int, Node> nodes;
  };

}