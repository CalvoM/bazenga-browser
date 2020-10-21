#ifndef DOM_EXCEPTION_HPP_
#define DOM_EXCEPTION_HPP_
#include <exception>
#include <iostream>

class DOMException : public std::exception {
public:
    explicit DOMException(const char* msg)
        : msg(msg)
    {
    }
    virtual ~DOMException() noexcept { }
    virtual const char* what() const noexcept
    {
        return this->msg.c_str();
    }

protected:
    std::string msg;
};

#endif