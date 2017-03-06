/***
 *  Author: Daniel Palacio
 */


#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <sstream>
#include <stdexcept>
#include <string>


class token {
public:

    token() : tag(UNDEF) { }


    explicit token(char c) : tag(OPER), oper(c) { }


    explicit token(double d) : tag(ARG), arg(d) { }


    bool is_operator() const { return (tag == OPER); }


    bool is_operand() const { return (tag == ARG); }


    char as_operator() const { return oper; }


    double as_operand() const { return arg; }

private:
    enum { OPER, ARG, UNDEF} tag;

    union {
        char oper;
        double arg;
    };

}; // class token



inline token to_token(const std::string& s) {
    std::istringstream is(s);
    double x;
    if (!(is >> x)) {
        if (s.size() != 1) throw std::runtime_error("incorrect token");
        if ((s[0] != '+') && (s[0] != '-') && (s[0] != '*') && (s[0] != '/')) throw std::runtime_error("incorrect token");
        return token(s[0]);
    }
    return token(x);
} // to_token

#endif // TOKEN_HPP
