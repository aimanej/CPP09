#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include <vector>
#include <sstream>
#include <exception>
#include <sys/time.h>
#include "deque"

class Parcing_issue : public std::exception{
    const char *what() const throw()
    {
        return "Error";
    }
};

std::vector<int> parce_params(int ac, char **av);
bool is_dup(std::vector<int> vec, int n);
std::vector<int> splitter(std::vector<int> vec);
std::vector<int> insert_order(int size);
std::vector<int> thaler(int n);

std::deque<int> param_parcer_dq(int ac, char **av);
bool is_dup(std::deque<int> cont, int n);
std::deque<int> sequence(int n);
std::deque<int> insert_order_dq(int size);
std::deque<int> splitter(std::deque<int> vec);
#endif