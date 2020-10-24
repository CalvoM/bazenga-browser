#ifndef HTML_PARSER_H_
#define HTML_PARSER_H
#include "Parser.hpp"
#include <map>
#include <vector>
#include <tuple>
class HTMLParser:public Parser{
public:
    HTMLParser();
    void tokenizer();
    std::tuple<encoding,confidence> get_encoding();
    void get_input(std::string);
    void construct_dom_tree();
    enum encoding bom_sniff();
    ~HTMLParser();
    enum class encoding{
        utf8,
        utf16be,
        utf16le,
        none
    };
    enum class confidence{
        irrelevant,
        tentative,
        certain
    };
private:
    std::string input_data;
    std::vector<int> input_bytes; 
    const std::map<encoding,std::vector<int>>bom_maps{
        {encoding::utf8,{0xef,0xbb,0xbf}},
        {encoding::utf16be,{0xfe,0xff}},
        {encoding::utf16le,{0xff,0xfe}}
    };
};

#endif