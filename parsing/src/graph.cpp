#include "../include/graph.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>

namespace Parser {

  Graph::Graph(string filename) {
    this->readData(filename);
  }

  void Graph::readData(string filename) {
    string line;
    
        std::ifstream inputFile(filename);
        if (inputFile.is_open()) {
          while (getline(inputFile, line)) {
              //if line doesn't begin with #
              if (line.rfind("#", 0) != 0) {
                std::vector<string> result;
                //split string by tab using boost
                split(result, line, boost::algorithm::is_any_of("\t"));
                if (result.size() > 1) {
                  int sourceIndex = stoi(result[0]);
                  int destIndex = stoi(result[1]);
                  if (nodes.find(sourceIndex) == nodes.end()) {
                    Node source(sourceIndex);
                    std::pair<int, Node> sourcePair = std::make_pair(sourceIndex, source);
                    nodes.insert(sourcePair);
                  } else if (nodes.find(destIndex) == nodes.end()) {
                    Node dest(destIndex);
                    std::pair<int, Node> destPair = std::make_pair(destIndex, dest);
                    nodes.insert(destPair);
                  }
                  // add dest node to neighbors of source node
                  Node* sourceNode = &nodes[sourceIndex];
                  sourceNode->addNeighbor(&nodes[destIndex]);
                  }
              }
          }
        }
        inputFile.close();
  }
}