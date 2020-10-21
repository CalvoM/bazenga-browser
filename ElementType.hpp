#ifndef ELEMENT_TYPE_HPP_
#define ELEMENT_TYPE_HPP_
#include <iostream>
#include <map>
#include <string>

#include "NodeType.hpp"

/**
 * @brief ElementType : Node of type Element
 * 
 */
class ElementType : public NodeType {
public:
    ElementType();

private:
    std::string tag_name;
    std::map<std::string, std::string> attrs; //https://dom.spec.whatwg.org/#attr
};

#endif