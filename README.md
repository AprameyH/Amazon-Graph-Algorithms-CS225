# rduquet2-rahuls9-apramey2-anshulb3

# Locations
Our graph is an adjacency list implemented in the parsing folder and constitutes a graph and a node class. A graph can be created by passing the name of a text file to its constructor. Our graph algorithms only required a way to get the entire list of nodes and a way to get adjacent nodes.

Breadth First Search can called directly on a graph object to retrieve a map of nodes to their respective distances from a starting node. Alternatively, depth first search can be called iteratively and recursively on a graph object as well.

Brandes' betweenness centrality algorithm and Tarjan's strongly connected components algorithm are implemented in the algorithm folder. 

The primary main file that runs all of our algorithms is also located in the algorithm folder.

The amazon dataset and the subset used for betweenness centrality are located in the data folder. Our results from running all of our algorithms are located in the results folder.


# Build and run the executable
1. Clone the repository
2. `cd` into the repository
 
Run the following commands

3. `$ chmod +x ./bake.sh`
4. `$ chmod +x ./main.sh`
5. `$ ./bake.sh`

Running the executable

6. `$ ./main.sh`


# Build and run the test suite
The test suite runs tests (in the tests folder) in parsing and algorithm
1. `$ ./bake.sh`
2. `$ ./test.sh`
