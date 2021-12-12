#include "../include/graph.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>

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
      for (auto& node: nodes) {
          int node_id = node.second.getID();
          //map.insert(std::make_pair<int, std::unordered_map<int, int>>(node_id, BFS(node_id)));
          map.insert({node_id, BFS(node_id)});
        }
      return map;
  }

  // returns a hashmap with the key being a node id and the value being the distance from the start node to that particular node.
  std::unordered_map<int, int> Graph::BFS(int start_id) {
      std::unordered_map<int, int> dist_from_root;
    
      std::unordered_map<int, bool> visited_nodes;

      std::queue<Node*> q;

      // add start node and initial distance of start(0) to queue
      dist_from_root[start_id] = 0;
      q.push(&nodes[start_id]);

      while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        // mark node as visited
        visited_nodes[curr->getID()] = true;

        for (Node* neighbor : curr->getNeighbors()) {
          // if neighbor is not visited
          if (!visited_nodes[neighbor->getID()]) {
             // visit neighbor, get distance for neighbor, and add to queue.
             visited_nodes[neighbor->getID()] = true;
             q.push(neighbor);
             dist_from_root[neighbor->getID()] = dist_from_root[curr->getID()] + 1;
          }

        }

      }
      return dist_from_root;
  }

 std::unordered_map<int, bool> Graph::DFS(int start_id) {
    std::unordered_map<int, bool> visited_nodes;

    std::stack<Node*> stack;
    stack.push(&nodes[start_id]);

        while (!stack.empty())
    {
        // Pop a vertex from stack and print it
        Node* curr = stack.top();
        stack.pop();
 
        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited.
        if (!visited_nodes[curr->getID()]) {
            std::cout << curr->getID() << " ";
            visited_nodes[curr->getID()] = true;
        }
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (Node* neighbor : curr->getNeighbors()) {
            if (!visited_nodes[neighbor->getID()]) {
              stack.push(neighbor);
            }
        }
    }
    return visited_nodes;
 }

std::unordered_map<int, bool> Graph::DFSRecur(int start_id) {
  std::unordered_map<int, bool> visited;
  return DFSRecurHelper(start_id, visited);
}

 std::unordered_map<int, bool> Graph::DFSRecurHelper(int start_id, std::unordered_map<int, bool>& visited) {

   visited[start_id] = true;
   
   for (Node* neighbor : nodes[start_id].getNeighbors()) {
     int id = neighbor->getID();
     if (visited.count(id) == 0) {
       DFSRecurHelper(id, visited);
     }
   }

   return visited;
 }


  std::unordered_map<int, Node>& Graph::getNodes() {
      return nodes;
  }
  
  std::vector<Node*> Graph::getNeighbors(int id) {
    return nodes[id].getNeighbors();
  }

  int Graph::size() {
    return nodes.size();
  }
}