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


int input_validity(char *input, std::map<std::string, float> map);
int map_parsing(std::map<std::string, float> &map);
int valid_date(std::string str_y, std::string str_v, std::map<std::string, float> map);
void white_space_remover(std::string &str);

#endif