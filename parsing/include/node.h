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
      Node() {};

      /**
       * @brief Get the ID for the Node.
       * 
       * @return unsigned 
       */
      unsigned getID();

      /**
       * @brief Add a neighbor node to the current node.
       * 
       * @param neighbor The neighbor node to add.
       */
      void addNeighbor(Node* neighbor);

      /**
       * @brief Get the vector of neighbor nodes.
       * 
       * @return std::vector<Node*> the vector of neighbors.
       */
      std::vector<Node*> getNeighbors();
      
      /**
       * @brief Less than operator for comparing two nodes.
       * 
       * @param other The other node to compare against.
       * @return true Returned if the id_ of other is less than the current node's id_.
       * @return false Returned if the id_ of the current node is less than the other node.
       */
      bool operator< (const Node other)  const {
        if (other.id_ < this->id_) {
          return true;
        }
        return false;
      };
      
      /**
       * @brief Equals operator that compares two nodes.
       * 
       * @param other The other node to compare to.
       * @return true Returned if the id_ of both nodes are equal.
       * @return false Returned if the id_ of both nods are not equal.
       */
      bool operator==(const Node other) const {
        return this->id_ == other.id_;
      }
    
    private:
        /**
         * @brief The id of the node.
         * 
         */
        unsigned id_ = 0;

        /**
         * @brief The vector of Node pointers that are the neighbors to the current node.
         * 
         */
        std::vector<Node*> neighbors;
  };
}
