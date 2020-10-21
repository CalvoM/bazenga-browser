#ifndef TEXT_TYPE_HPP_
#define TEXT_TYPE_HPP_
#include <iostream>
#include <string>

#include "NodeType.hpp"

class TextType : public NodeType {
public:
    TextType(std::string data = "")
        : data(data)
    {
    }
    ~TextType() { }
    std::string whole_text;
    std::string data;
};

#endif