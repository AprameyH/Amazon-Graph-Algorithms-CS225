#include "../include/SCC.h"
#include <tuple>

using Parser::Node;
using std::pair;

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
 

    std::stack<pair<int,int>> dfs_st;
    dfs_st.push({u, u});

    while (!dfs_st.empty())  {
        // Pop a vertex from stack and print it
        int node = dfs_st.top().first;
        int predecessor = dfs_st.top().second;
        // add to stack
        if (!stackMember[node]) {
            stackMember[node] = true;
            st.push(node);
        }

        if (disc[node] == UNVISITED) {
            disc[node] = time;
            lows[node] = time;
            time++;
        }
        // Get all adjacent vertices of the popped vertex s
        // If a adjacent has not been visited, then push it
        // to the stack.
        for (Node* neighbor : g.getNeighbors(node)) {
            int neigh_id = neighbor->getID();
            if (disc[neigh_id] == UNVISITED) {
                dfs_st.push({neigh_id, node});
                break;
            }

            if (stackMember[neigh_id]) {
                lows[node] = std::min(lows[node], lows[neigh_id]);
            }
        }

        if (dfs_st.top().first != node) {
            continue;
        }

        if (lows[node] == disc[node]) {
            while (stackMember[node]) {
                int w = (int) st.top();
                lows[w] = lows[node];
                st.pop();
                stackMember[w] = false;
            }
        }

        dfs_st.pop();
    }
    
}

bool SCC::areConnected(int node1_id, int node2_id) {
    return lows[node1_id] == lows[node2_id];
}

vector<int> SCC::getConnectedComponents() {
    return lows;
}

int SCC::CountComponents() {   
    
    std::unordered_map<int, bool> tracker;
    int count = 0;
    for (int elem : lows) {
        // if not in our tracker map then its a new component
        if (tracker.find(elem) == tracker.end()) {
            // add this SCC to tracker so we don't double count it.
            tracker[elem] = true;
            count++;
        }
        
    }
    return count;
}
    
// int UNVISITED = -1; 
//     // A static variable is used for simplicity, we can avoid use
//     // of static variable by passing a pointer.
//     static int time = 0;
 
//     // Initialize discovery time and low value
//     disc[u] = time;
//     lows[u] = time;
//     time++;

//     st.push(u);
//     stackMember[u] = true;

// Go through all vertices adjacent to this
    // for (Node* neighbor : g.getNeighbors(u))    {
    //     int v = neighbor->getID(); // v is current adjacent of 'u'
 
    //     // If v is not visited yet, then recur for it
    //     if (disc[v] == UNVISITED)
    //     {
    //         TarjanUtil(v, g, disc, stackMember, st);
 
    //         // Check if the subtree rooted with 'v' has a
    //         // connection to one of the ancestors of 'u'
    //         // Case 1 (per above discussion on Disc and Low value)
    //         lows[u] = std::min(lows[u], lows[v]);
    //     }
 
    //     // Update low value of 'u' only of 'v' is still in stack
    //     // (i.e. it's a back edge, not cross edge).
    //     // Case 2 (per above discussion on Disc and Low value)
    //     else if (stackMember[v] == true)
    //         lows[u] = std::min(lows[u], disc[v]);
    // }

// // head node found, pop the stack and print an SCC
//     int w = -2; // To store stack extracted vertices
//     if (lows[u] == disc[u]) // check if this is the node we started the dfs on.
//     {
//         while (st.top() != u) // everything ontop on this variable on stack is apart of its strongly connected component.
//         {
//             w = (int) st.top();
//             //cout << w << " ";
//             // remove w from stack and have it be inaccesible for the rest of the algorithm.
//             stackMember[w] = false;
//             st.pop();
//         }
//         // need to remove u as well from the stack
//         w = (int) st.top();
//         //cout << w << "\n";
//         stackMember[w] = false;
//         st.pop();
//     }
