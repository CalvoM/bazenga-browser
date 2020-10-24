#include "HTMLParser.hpp"

void HTMLParser::get_input(std::string input){
    this->input_data = input;
}
enum HTMLParser::encoding HTMLParser::bom_sniff(){
    std::vector<int>bom={input_data[0],input_data[1],input_data[2]};
    std::map<encoding,std::vector<char>>::iterator check{bom_maps.find(encoding::utf8)};
    if(bom==check.second){
        return check.first;
    }else{
        if(bom[0]==0xfe){
            return encoding::utf16be;
        }else if(bom[0]==0xff){
            return encoding::utf16le;
        }else{
            return encoding::none;
        }
    }

}
std::tuple<enum HTMLParser::encoding,enum HTMLParser::confidence> HTMLParser::get_encoding(){
    encoding bom_encoding = this->bom_sniff();
    if(bom_encoding!=encoding::none){
        return std::make_tuple(bom_encoding,confidence::certain);
    }
}