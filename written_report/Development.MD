# Development

## Week 1
We had problems working with GDB, so we worked on it to debug our tests. We talked with the CA and they advised us to examine Makefiles, and then we looked through Google for a while. We went to office hours and they helped us figure the problem out.

## Week 2
We worked on creating the base Edge class and created the Parser. We imported the data as well. We had issues with Git, specifically making sure everyone had the same code when merging code from Github. We almost deleted a lot of code from Github, so we reverted to an old commit. We added the Makefiles to the .gitignore and because they are different for every user, the code almost got deleted.

## Week 3
We fixed the Parser to work with our Graph class. Moreover, we cleaned up minor bugs and added boilerplate code for our BFS algorithm. Added some initial test cases. We implemented Betweeness Centrality and created an algorithms folder (moving BFS into it).

## Week 4
We finished implementing BFS and Tarjan's algorithm as well as their test cases. However, while our recursive version of Tarjans algorithm was passing all our tests, we were running into stack overflow related seg faults on our large graph. So, we had to rewrite Tarjans algorithm to be iterative. We also implemented an iterative version of DFS this week to test whether we could run DFS on our graph.

## Week 5
This week, we added Tarjan's algorithm to main and got Betweenness Centrality working on both directed and undirected graphs. We spent a long time this week walking over the betweenness algorithm to better understand how it was implemented. Since Brandes's algorithm used directed graphs, on instances of undirected graphs, we realized we would get twice the betweenness value for each node. After we implemented the algorithm, we decided we needed to make our code much more efficient in order to be able to run Brandes's algorithm on the entire Amazon dataset. To achieve this, we decided to use node ID's instead of Node objects to calculate and store betweenness values.
