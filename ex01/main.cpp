#include "RPN.hpp"



int main(int ac, char **av)
{
    if(ac != 2)
        return std::cerr << "inverted Polish mathematical expression is to be privided as a prameter alone" << std::endl, 1;
    try{
        std::string exp = av[1];
        polishing_the_pole(exp);
        rpn_prime(exp);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}