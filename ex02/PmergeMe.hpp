#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include <vector>
#include <sstream>
#include <exception>

class Parcing_issue : public std::exception{
    const char *what() const throw()
    {
        return "Error";
    }
};


std::vector<int> parce_params(int ac, char **av);
std::vector<int> splitter(std::vector<int> vec);
std::vector<int> insert_order(int size);
std::vector<int> thaler(int n);

#endif