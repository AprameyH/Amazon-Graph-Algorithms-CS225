#include "../parsing/include/graph.h"
#include "./include/SCC.h"
#include "./include/centrality.h"
#include <fstream>
#include <iostream>
#include <map>

void writeMapToFile(std::unordered_map<int, int> distances) {
  std::ofstream myfile;
  myfile.open("../results/bfspaths.txt");
  if (myfile.is_open()) {
    myfile << "length of shortest path from Node 0\n";
    for (auto &length : distances) {
      myfile << length.first << ": " << length.second << "\n";
    }
    myfile.close();
  } else {
    std::cout << "Could not open file" << std::endl;
  }
}

int main() {
  std::cout << "Running main" << std::endl;

  // Writing SCC data to a file
  std::string filename = "../data/amazon0601.txt";
  Graph graph(filename);

  SCC scc(graph);
  scc.printStronglyConnectedComponent(0, "../results/SCCResults0.txt");
  scc.printStronglyConnectedComponent(32, "../results/SCCResults1.txt");
  std::cout<<"SCC data written to file"<<std::endl;

  // Writing amazon betweenness data to a file
  Parser::Graph G = Parser::Graph("../data/amazonsubset.txt");
  Centrality c = Centrality(G);
  c.writeToFile("../results/amazonbetweenness.txt");
  std::cout << "Betweenness data written to file" << std::endl;

  std::cout << "The betweenness at node 940: " << c.getBetweenness(940)
            << std::endl;
  std::cout << std::endl;

  // Writing BFS data to a file
  std::unordered_map<int, int> distances = graph.BFS(0);

  writeMapToFile(distances);
  std::cout << "BFS data written to file" << std::endl;
  return 0;
}
