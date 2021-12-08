#include "../include/centrality.h"


using namespace std;
using namespace Parser;

Centrality::Centrality(Graph G, int nodeIdx) {
  this->betweenness = nodeCentrality(G, nodeIdx);
}

std::unordered_map<int, double> Centrality::nodeCentrality(Graph g, int nodeIdx) {
  unordered_map<int, double> Cb;
  for (pair<int, Node> s : g.getNodes()) {
    stack<Node> S;
    map<Node,vector<Node>> P; 
    map<Node,int> sig;
    map<Node,int> d;
    map<Node, int> del;
    for (pair<int, Node> w : g.getNodes()) {
      P[w.second] = {};
      sig[w.second] = 0;
      d[w.second] = -1;
      del[w.second] = 0;
      Cb[w.first] = 0;
    }
    sig[s.second] = 1;
    d[s.second] = 0;
    queue<Node> Q;
    

    //BFS begins
    Q.push(s.second);
    while (!Q.empty()) {
      Node v = Q.front();
      Q.pop();
      S.push(v);
      
      for (Node* w : v.getNeighbors()) {
          //w found for the first time?
        if (d[*w] < 0) {
            Q.push(*w);
            d[*w] = d[v] + 1;
        }
        //shortest path to w via v
        if (d[*w] == d[v] + 1) {
            sig[*w] += sig[v];
            P[*w].push_back(v);
        }
      }
    }
    // S returns vertices in order of non-increasing distance from s
    while (!S.empty()) {
      Node w = S.top();
      S.pop();
      for (Node v : P[w]) {
        del[v] = del[v] + (sig[v] / sig[w]) * (1 + del[w]);
      }
      if (w.getID() != s.first) {
        Cb[w.getID()] = Cb[w.getID()] + del[w];
      }
    }
  }
  return Cb;
}

unordered_map<int, double> Centrality::getBetweenness() {
    return betweenness;
}