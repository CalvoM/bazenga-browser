#ifndef PARSER_H_
#define PARSER_H_
#include <iostream>
#include <string>
class Parser{
public:
    virtual void tokenizer();
    virtual void get_input(std::string);
    virtual void construct_dom_tree();
    virtual ~Parser();
};

#endif