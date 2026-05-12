#ifndef RPN_HPP
#define RPN_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <exception>
#include <stack>

void polishing_the_pole(const std::string &exp);
int is_token(int c);
void rpn_prime(std::string &exp);
int calculate(int right, int left, char op);

class ErrorException : public std::exception
{
    virtual const char *what() const throw();
};


#endif