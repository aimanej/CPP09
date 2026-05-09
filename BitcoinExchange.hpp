#ifndef BITCOINEXCHANGE
#define BITCOINEXCHANGE

#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <exception>
#include <sstream>
#include <cstdlib>
#include <string>

class FileNotOpen : public std::exception
{
    virtual const char *what() const throw()
    {
        return "File does not exist or could not be opened !";
    }
};

class FormatNotAccepted : public std::exception
{
    virtual const char *what() const throw()
    {
        return "input text format not tolerated ! ";
    }
};

class DateNotAccepted : public std::exception
{
    virtual const char *what() const throw()
    {
        return "Date not in file ! ";
    }
};

void input_validity(char *input);
void map_parsing(std::map<std::string, float> &map);
void valid_date(std::string str);
void valid_value(std::string str);
void white_space_remover(std::string &str);

#endif