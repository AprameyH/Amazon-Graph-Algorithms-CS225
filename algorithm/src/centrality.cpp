#include "../include/centrality.h"


using namespace std;
using namespace Parser;

Centrality::Centrality(Graph G) {
  this->betweenness = nodeCentrality(G);
}

std::unordered_map<int, double> Centrality::nodeCentrality(Parser::Graph g) {
  unordered_map<int, double> Cb;
  for (pair<int, Node> w : g.getNodes()) {
    Cb[w.first] = 0;
  }
  for (pair<int, Node> s : g.getNodes()) {
    stack<int> S;
    map<int,vector<int>> P;
    map<int,double> sig;
    map<int,double> d;
    map<int, double> del;
    for (pair<double, Node> w : g.getNodes()) {
      P[w.first] = {};
      sig[w.first] = 0;
      d[w.first] = -1;
    }
    sig[s.first] = 1;
    d[s.first] = 0;
    queue<int> Q;
    

    //BFS begins
    Q.push(s.first);
    while (!Q.empty()) {
      int v = Q.front();
      Q.pop();
      S.push(v);
      
      for (Node* w : g.getNodes().at(v).getNeighbors()) {
          //w found for the first time?
        if (d[w->getID()] < 0) {
          Q.push(w->getID());
          d[w->getID()] = d[v] + 1;
        }
        //shortest path to w via v
        if (d[w->getID()] == d[v] + 1) {
          sig[w->getID()] += sig[v];
          P.at(w->getID()).push_back(v);
        }
      }
    }
    for (pair<int, Node> w : g.getNodes()) {
      del[w.first] = 0;
    }
    // S returns vertices in order of non-increasing distance from s
    while (!S.empty()) {
      int w = S.top();
      S.pop();
      for (int v : P.at(w)) {
        del[v] = del[v] + (sig[v] / sig[w]) * (1 + del[w]);
      }
      if (w != s.first) {
        Cb[w] = Cb[w] + del[w];
      }
    }
  }
  return Cb;
}

double Centrality::getBetweenness(int nodeIndex) {
    return this->betweenness[nodeIndex];
}

vector<std::pair<int, double>> Centrality::getSortedList() const {
  vector<pair<int, double>> sorted;


  for (auto &it : betweenness) {
    sorted.push_back(it);
  }
  std::sort(sorted.begin(), sorted.end(), [](pair<int, double> a, pair<int, double> b) { return a.second > b.second; });

  return sorted;
}

void Centrality::writeToFile(string filePath) const {
  ofstream myfile;
  myfile.open(filePath);
  if (myfile.is_open()){
  myfile << "Node: Betweenness\n";
  for (pair<int, double> &val : getSortedList()) {
    myfile << val.first << ": "<<val.second<<"\n";
  }
  myfile.close();
  } else {
    cout<< "Could not open file"<<endl;
  }
}
