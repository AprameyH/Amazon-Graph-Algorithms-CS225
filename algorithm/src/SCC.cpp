#include "../include/SCC.h"
#include <tuple>
#include <fstream>

using Parser::Node;
using std::pair;
using std::string;

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
        // Pop a vertex from stack
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

        // continue dfs until current node is on top of stack(all neighbors have been visited)
        if (dfs_st.top().first != node) {
            continue;
        }

        // if we are at a root node, then everything on top of the second stack has already been correctly labeled so we can 
        // successfully remove them from the stack and set the stackmember to false so we never deal with them for the rest of the algorithm.
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

void SCC::getStronglyConnectedComponent(int node_id, string filePath) {
    int component_num = lows[node_id];

    vector<int> component;
    for (int i = 0; i < lows.size(); i++) {
        if (lows[i] == component_num) {
            component.push_back(i);
        }
    }

    // write component to file
    std::ofstream myfile;
    myfile.open(filePath);
    if (myfile.is_open()){
        myfile << "There are " << component.size() << " nodes that are apart of the same Strongly Connected Component as node " << node_id << " \n";
        myfile << "All nodes that are part of the same Strongly Connected Component as node " << node_id << "\n";
        for (auto& node : component) {
            myfile << node << ", ";
        }
        myfile.close();
    } else {
        std::cout<< "Could not open file"<< std::endl;
    }
}
    

