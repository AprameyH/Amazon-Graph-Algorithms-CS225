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
    stack<Node> S;
    map<Node,vector<Node>> P; 
    map<Node,double> sig;
    map<Node,double> d;
    map<Node, double> del;
    for (pair<double, Node> w : g.getNodes()) {
      P[w.second] = {};
      sig[w.second] = 0;
      d[w.second] = -1;
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
            P.at(*w).push_back(v);
        }
      }
    }
    for (pair<int, Node> w : g.getNodes()) {
      del[w.second] = 0;
    }
    // S returns vertices in order of non-increasing distance from s
    while (!S.empty()) {
      Node w = S.top();
      S.pop();
      for (Node v : P.at(w)) {
        del[v] = del[v] + (sig[v] / sig[w]) * (1 + del[w]);
      }
      if (w.getID() != s.first) {
        Cb[w.getID()] = Cb[w.getID()] + del[w];
      }
    }
  }
  return Cb;
}

double Centrality::getBetweenness(int nodeIndex) {
    return this->betweenness[nodeIndex];
}