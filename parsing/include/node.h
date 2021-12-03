#pragma once

#include <stdint.h>
#include <string>
#include "edge.h"
#include <vector>

namespace Parser {

  class Node {
    public:
      /**
       * @brief Construct a new Node object.
       * 
       * @param id 
       */
      Node(int id);
      Node();

      /**
       * @brief Destroy the Node object
       * 
       */
      ~Node();

      /**
       * @brief Get the ID for the Node.
       * 
       * @return unsigned 
       */
      unsigned getID();


      static unsigned num_nodes_;
      std::vector<Node*> neighbors;

      void addNeighbor(Node* neighbor);

    private:
        unsigned id_ = 0;
  
  };
}
