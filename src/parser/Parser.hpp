#ifndef PARSER_H_
#define PARSER_H_

class Parser{
public:
    virtual void tokenizer();
    virtual void get_input();
    virtual void construct_dom_tree();
    ~Parser();
};

#endif