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

      /**
       * @brief Construct a new Node object
       * 
       */
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

      void addNeighbor(Node* neighbor);

      std::vector<Node*> getNeighbors();

    private:
        unsigned id_ = 0;
        static unsigned num_nodes_;
        std::vector<Node*> neighbors;
  };
}
