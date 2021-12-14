# Project Goals

## Leading Question
We will use the Amazon network dataset to create a graph and run BFS, Betweenness Centrality, and Strongly Connected Components. We will be creating a search tool that will allow us to find Amazon products that would significantly reduce the efficiency of search tools if removed. We will accomplish this by using Betweenness Centrality to find central nodes and BFS to find the lengths of their shortest paths. Our search tool will also identify strongly connected components and prioritize their recommendation.

## Dataset Acquisition and Processing
We will be using the Amazon Networks dataset provided by Stanford Large Network Dataset Collection. We will download the dataset from the Stanford Large Network Dataset Collection website and we will store the data in our repository. We will have a Node class and a hashmap with a Node as the key and maps to a list of Nodes that are its neighbors. We will parse the dataset line by line, each line representing a new value to be added to a key, assuming it has the same value as the previous line. If there is a line that doesn’t give us 2 nodes, we will ignore the line itself.

## Graph Algorithms

### Breadth-First Search
Breadth-First Search gives us an efficient way(O(V +E) for G = (V,E)) to find the length of the shortest path between one node to other nodes in our graph since it is unweighted. This is useful because we can find out how connected two products are by calculating the lengths of the shortest paths between those nodes.  Our inputs into our BFS function will be a node id that we want to find all the lengths of the shortest paths between. Our output will be a hashmap where the keys are the nodes that are visitable from the input nodes, and the values are the lengths of the shortest paths between the input node and the key node.
### Betweenness Centrality
Betweenness centrality measures the amount of influence a vertex has on the flow of data in a graph. Vertices with high betweenness lie on several shortest paths between other vertices. They are also the nodes whose removal would result in the most disruption in the flow of information, because they are part of a large number of shortest paths. Measuring the betweenness centrality of nodes in the Amazon dataset would help identify products that are uniquely important to their user experience. New products can be positioned to be more visible by improving their betweenness centrality. Betweenness centrality requires a shortest path algorithm, and we will implement BFS on our unweighted, directed dataset. Our input would be a single node and we would output its corresponding betweenness as a float. Our implementation aims to achieve an efficiency of O(ve + v^2logv) using Brandes algorithm. However, we will explore other less efficient options if this proves too complicated.
### Strongly Connected Components
If there is a two way path between each pair of nodes in a directed graph it is strongly connected. A two way path between a pair of nodes would indicate a higher connection between the two nodes when compared to a single path for our dataset; two strongly connected products are more likely to be purchased together. We will use Tarjan’s strongly connected components algorithm, which will run in linear time O(V + E).  Our input would be a node and we would output all the nodes that are a part of the same strongly connected component as that node.

## Timeline

| Tasks | Deadline |
|-------|----------|
|Final Project Proposal and Team Contract|November 8th|
|Goals in Report|November 14th|
|Goals in Presentation|November 14th|
|Complete BFS Implementation|November 26th|
|Progress summary|November 29th|
|Complete Strongly Connected Components Implementation|December 2nd|
|Complete Betweenness Centrality Implementation|December 5th|
|Development in Report|December 7th|
|Development in Presentation|December 7th|
|Conclusion in Presentation|December 13th|
|Results in report|December 13th|
