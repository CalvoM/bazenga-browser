#ifndef NODE_HPP_
#define NODE_HPP_
#include <iostream>
#include <vector>

#include "NodeType.hpp"
/**
 * @brief Node for node structure in the dom tree
 * Each node has an associated node document, set upon creation
 *
 */
class Node {
public:
    Node();
    std::vector<Node> children;
    std::string node_name;
    Node* parent_node;
    NodeType node_type;
};
#endif