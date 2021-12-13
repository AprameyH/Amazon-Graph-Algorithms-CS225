#pragma once

#include <stdint.h>
#include <string>
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
      
      bool operator< (const Node other)  const {
        if (other.id_ < this->id_) {
          return true;
        }
        return false;
      };
      bool operator==(const Node other) const {
        return this->id_ == other.id_;
      }
    private:
        unsigned id_ = 0;
        static unsigned num_nodes_;
        std::vector<Node*> neighbors;
  };
}
