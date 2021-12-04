#include "../include/graph.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include "../tests/test_graph1.txt"
#include <iostream>

namespace Parser {

  Graph::Graph(string filename) {
    this->readData(filename);
  }

  void Graph::readData(string filename) {
    std::cout << filename << std::endl;
    string line;
    
        
        inputFile.open(filename);
        if (!inputFile) {
          std::cout<<"File is open"<<std::endl;
          while (getline(inputFile, line)) {
              //if line doesn't begin with #
              std::cout << line << std::endl;
              if (line.rfind("#", 0) != 0) {
                std::vector<string> result;
                //split string by tab using boost
                std::cout << "test" << std::endl;
                split(result, line, boost::algorithm::is_any_of("\t"));
                std::cout << "test" << std::endl;
                if (result.size() > 1) {
                  int sourceIndex = stoi(result[0]);
                  std::cout << sourceIndex << std::endl;
                  int destIndex = stoi(result[1]);
                  std::cout << destIndex << std::endl;
                  if (nodes.find(sourceIndex) == nodes.end()) {
                    Node source(sourceIndex);
                    std::pair<int, Node> sourcePair = std::make_pair(sourceIndex, source);
                    nodes.insert(sourcePair);
                  }
                  if (nodes.find(destIndex) == nodes.end()) {
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

  std::unordered_map<int, std::unordered_map<int, int>> Graph::BFS() {
      std::unordered_map<int, std::unordered_map<int, int>> map;
      return map;
    //   for (auto& node: nodes) {
    //         BFS(node.getId());
            
    //     }
  }

  std::unordered_map<int, int> Graph::BFS(int start_id) {
      std::unordered_map<int, int> dist_from_root;
      return dist_from_root;
  }

  std::unordered_map<int, Node>& Graph::getNodes() {
      return nodes;
  }
  
  std::vector<Node*> Graph::getNeighbors(int id) {
    return nodes[id].getNeighbors();
  }
}