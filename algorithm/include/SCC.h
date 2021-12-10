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
        SCC(Graph& g);

        void TarjanAlgo(Graph& g);

        void TarjanUtil(int u, Graph& g, vector<int>& disc, vector<bool>& stackMember, std::stack<int>& st);

        vector<int> lows;

        bool areConnected(int node1_id, int node2_id);

        vector<int> getConnectedComponents();

        int CountComponents();
    
};