#ifndef DOM_TOKEN_LIST_HPP_
#define DOM_TOKEN_LIST_HPP_

#include "DOMException.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
enum class customBool {
    False,
    True,
    Null
};
/**
 * @brief DOMTokenList Holds list of DOM token types 
 * https://dom.spec.whatwg.org/#interface-domtokenlist
 * 
 */
class DomTokenList {
public:
    int length;
    DomTokenList()
    {
        length = 0;
    }
    /**
     * @brief Check if the dom token list has the specific token
     * 
     * @param token item to be checked in the token list
     * @return true if present
     * @return false if not present
     */
    bool contains(std::string token)
    {
        return std::find(tokenList.begin(), tokenList.end(), token) != tokenList.end();
    }
    /**
     * @brief Add the tokens to the list of dom tokens
     * 
     * @param tokens list of tokens to be added
     */
    void add(std::vector<std::string> tokens)
    {
        modify(tokens, ops::add);
        length = tokenList.size();
    }
    /**
     * @brief Remove the tokens from the list of tokens
     * 
     * @param tokens list of tokens to be removed
     */
    void remove(std::vector<std::string> tokens)
    {
        modify(tokens, ops::remove);
        length = tokenList.size();
    }
    /**
     * @brief Change the token provided either present or absent 
     * 
     * @param token Item to be changed
     * @param force setermines the changing i.e. either removal or addition
     * @return true if item is added
     * @return false if item is removed
     */
    bool toggle(std::string token, customBool force = customBool::Null)
    {
        std::vector<std::string> temp { token };
        if (force == customBool::True) {
            this->add(temp);
            return true;
        } else if (force == customBool::False) {
            this->remove(temp);
            return false;
        } else {
            if (this->contains(token)) {
                this->remove(temp);
                return false;
            } else {
                this->add(temp);
                return true;
            }
        }
    }
    /**
     * @brief Replace specific token in the dom token list
     * 
     * @param old_token item to be replaced in the dom list
     * @param new_token new item to replace the old value 
     * @return true if replaced
     * @return false if not replaced
     */
    bool replace(std::string old_token, std::string new_token)
    {
        if (old_token.size() < 1 or new_token.size() < 1) {
            throw DOMException("SyntaxError");
        } else if (old_token.find(" ") == std::string::npos or new_token.find(" ") == std::string::npos) {
            throw DOMException("InvalidCharacterError");
        }
        if (this->contains(old_token)) {
            auto it = std::find(tokenList.begin(), tokenList.end(), old_token);
            int index = std::distance(tokenList.begin(), it);
            tokenList[index] = new_token;
            return true;
        } else {
            return false;
        }
    }
    std::string operator[](int index)
    {
        if (index > this->length) {
            throw DOMException("Index is out of range");
        } else {
            return tokenList[index];
        }
    }

private:
    enum class ops {
        remove,
        add
    };
    std::vector<std::string> tokenList;
    void modify(std::vector<std::string> tokens, ops sign)
    {
        if (std::find(tokens.begin(), tokens.end(), "") != tokens.end()) {
            throw DOMException("SyntaxError");
        }
        for (auto t : tokens) {
            if (t.find(" ") != std::string::npos) {
                throw DOMException("InvalidCharacterError");
            }
            if (sign == ops::add)
                tokenList.push_back(t);
            else if (sign == ops::remove) {
               std::remove(tokenList.begin(), tokenList.end(), t);
            }
        }
    }
};
#endif