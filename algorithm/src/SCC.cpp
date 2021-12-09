#include "../include/SCC.h"

using Parser::Node;

SCC::SCC(Graph& g) {
    TarjanAlgo(g);

}

void SCC::TarjanAlgo(Graph& g) {
    int N = g.size();
    int UNVISITED = -1;

    vector<int> disc(N, UNVISITED);
    lows = disc;
    vector<bool> stackMember(N, false);
    std::stack<int> st;

    for (int i = 0; i < N; i++) {
        if (disc[i] == UNVISITED) {
            TarjanUtil(i, g, disc, stackMember, st);
        }
    }
}

void SCC::TarjanUtil(int u, Graph& g, vector<int>& disc, vector<bool>& stackMember, std::stack<int>& st) {
    int UNVISITED = -1; 
    // A static variable is used for simplicity, we can avoid use
    // of static variable by passing a pointer.
    static int time = 0;
 
    // Initialize discovery time and low value
    disc[u] = time;
    lows[u] = time;
    time++;

    st.push(u);
    stackMember[u] = true;
 
    // Go through all vertices adjacent to this
    for (Node* neighbor : g.getNeighbors(u))    {
        int v = neighbor->getID(); // v is current adjacent of 'u'
 
        // If v is not visited yet, then recur for it
        if (disc[v] == UNVISITED)
        {
            TarjanUtil(v, g, disc, stackMember, st);
 
            // Check if the subtree rooted with 'v' has a
            // connection to one of the ancestors of 'u'
            // Case 1 (per above discussion on Disc and Low value)
            lows[u] = std::min(lows[u], lows[v]);
        }
 
        // Update low value of 'u' only of 'v' is still in stack
        // (i.e. it's a back edge, not cross edge).
        // Case 2 (per above discussion on Disc and Low value)
        else if (stackMember[v] == true)
            lows[u] = std::min(lows[u], disc[v]);
    }
 
    // head node found, pop the stack and print an SCC
    int w = -2; // To store stack extracted vertices
    if (lows[u] == disc[u]) // check if this is the node we started the dfs on.
    {
        while (st.top() != u) // everything ontop on this variable on stack is apart of its strongly connected component.
        {
            w = (int) st.top();
            //cout << w << " ";
            // remove w from stack and have it be inaccesible for the rest of the algorithm.
            stackMember[w] = false;
            st.pop();
        }
        // need to remove u as well from the stack
        w = (int) st.top();
        //cout << w << "\n";
        stackMember[w] = false;
        st.pop();
    }
}

bool SCC::areConnected(int node1_id, int node2_id) {
    return lows[node1_id] == lows[node2_id];
}

