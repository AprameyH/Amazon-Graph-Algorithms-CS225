#include <iostream>
#include "../parsing/include/graph.h"
#include "./include/centrality.h"


int main() {
    //std::cout<<"Well this is running now"<<std::endl;
    //Writing amazon betweenness data to a file
    Parser::Graph G = Parser::Graph("../data/amazonsubset.txt");
    Centrality c = Centrality(G);
    c.writeToFile("../results/amazonbetweenness.txt");
    
    std::cout << "The betweenness at node 940: " << c.getBetweenness(940) << std::endl;
    std::cout<<std::endl;

    return 0;
}