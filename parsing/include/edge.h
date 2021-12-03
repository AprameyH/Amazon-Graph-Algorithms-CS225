// #pragma once

// #include <stdint.h>
// #include <string>
// #include "node.h"

// namespace Parser {
//   class Edge {
//     private:
//       /**
//        * @brief ID for the edge.
//        * 
//        */
//       unsigned id;
      
//       /**
//        * @brief The source node where the edge starts from.
//        * 
//        */
//       Node* _source;

//       /**
//        * @brief The destination node where the edge finishes.
//        * 
//        */
//       Node* _dest;

//     public:
//       /**
//        * @brief Construct a new Edge object.
//        * 
//        * @param source The source node.
//        * @param dest The destination node.
//        */
//       Edge(Node* source, Node* dest);

//       /**
//        * @brief Destroy the Edge object
//        * 
//        */
//       ~Edge();

//       /**
//        * @brief Get ID for the Edge.
//        * 
//        * @return unsigned id.
//        */
//       unsigned getID();

//       /**
//        * @brief Get the Source Node for the Edge.
//        * 
//        * @return Node* _source.
//        */
//       Node* getSource();

//       /**
//        * @brief Get the Destination Node for the Edge.
//        * 
//        * @return Node* _dest.
//        */
//       Node* getDestination();
//   }; 
// }