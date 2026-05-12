#include "RPN.hpp"

const char *ErrorException::what() const throw()
{
    return "Error";
}

int is_token(int c)
{
    return (c == '*' || c == '-' || c == '+' || c == '/') ? 1 : 0;
        
}

void polishing_the_pole(const std::string &exp)
{
    for(std::string::const_iterator it = exp.begin(); it != exp.end(); it++)
    {
        if(!isdigit(*it) && !is_token(*it) && !isspace(*it))
            throw ErrorException();
    }
}

int calculate(int right, int left, char op)
{
    switch(op)
    {
        case '+' : return left + right;
        case '-' : return left - right;
        case '*' : return left * right;
        case '/' : return right != 0 ? left / right : 0;

    }
    return 0;
}

void rpn_prime(std::string &exp)
{
    std::stack<int> stack;

    for(std::string::const_iterator it = exp.begin(); it != exp.end(); it++)
    {
        if(isdigit(*it))
        {
            int t = *it - 48;
            stack.push(t);
        }
        else if(is_token(*it))
        {
            if(stack.size() < 2)
                throw ErrorException();
            int right = stack.top();
            stack.pop();
            int left = stack.top();
            stack.pop();
            stack.push(calculate(right, left, *it));
        }
    }
    if(stack.size() != 1)
    {
        throw ErrorException();
    }
    std::cout << stack.top() << std::endl;
}