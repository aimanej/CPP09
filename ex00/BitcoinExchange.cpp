#include "BitcoinExchange.hpp"
#include <cstdlib>
int map_parsing(std::map<std::string, float> &map)
{
    std::ifstream data("data.csv");
    if(!data.is_open())
        return std::cout << "Error: could not open file." << std::endl, 0;
    std::string line;
    std::getline(data, line);
    int t = 0;
    while(std::getline(data, line))
    {
        t++;
        std::stringstream ss(line.substr(11, line.size()));
        std::string po = line.substr(0, 10);
        double val;
        ss >> val;
        map[po] = val;
    }
    
    std::cout << " after parsing : " << t << std::endl ;
    data.close();
    return 1;
}

int valid_date(std::string str_y, std::string str_v, std::map<std::string, float> map)
{
    size_t t = 0;

    while(t < str_y.size() - 1)
    {
             t++;
        if((t == 4 || t == 7) && str_y.at(t) != '-')
        {
            return std::cout << "date format not accepted " << std::endl, 0;
        }
        if(!std::isdigit(str_y.at(t)) && t != 4 && t != 7)
        {
            return std::cout << "date format not accepted " << std::endl, 0;

        }
   
    }
    int year = std::atoi(str_y.substr(0, 4).c_str());
    int month = std::atoi(str_y.substr(5, 2).c_str());
    int day = std::atoi(str_y.substr(8, 2).c_str());

    if(year  > 2022 || year < 2009)
        return std::cout << "year out of range" << std::endl, 0;
    if(month < 1 || month > 12)
        return std::cout << "month out of range" << std::endl, 0;
    int max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((year % 4 == 0 &&  year % 100 != 0 )|| year % 400 == 0)
        max[1] = 29;
    if(day < 0 || day > max[month - 1])
    {
        return std::cout << "day out of range" << std::endl, 0;
    }

    std::stringstream ss(str_v);
    float val;
    if(ss >> val)
    {
        if(val > 1000)
        {
            return std::cout << "Error: too large a number" << std::endl, 0;
        }
        else if(val < 0)
            return std::cout << "Error: not a positive number." << std::endl, 0;
        else if (ss.peek() != EOF)
            return std::cout << "Error: input contains extra characters." << std::endl, 0;        
    }
    else
        return std::cout << "value not valuing " << str_v << std::endl, 0;
    std::map<std::string, float>::iterator it = map.upper_bound(str_y);
    if(it != map.begin() && it->first != str_y)
            it--;
    long retval = val * it->second;
    std::cout << str_y << " => " << val << " = " << retval << std::endl;
    return 1;

}

void white_space_remover(std::string &str)
{
    std::string::iterator it = str.begin();
    while(it != str.end())
    {
        if(std::isspace(*it))
            it = str.erase(it);
        else if(*it == '\n')
            it = str.erase(it);
        else
            it++;
    }
}

int input_validity(char *input, std::map<std::string, float> map)
{
    std::ifstream data(input);
    if(!data.is_open())
        return std::cout << "Error: could not open file." << std::endl, 0;
    std::string line;
    std::getline(data, line);
    white_space_remover(line);
    if(line != "date|value")
        return std::cout << "first line should be (date | value)" << std::endl, 0;

    while(std::getline(data, line))
    {
        white_space_remover(line);
        if(line.find('|', 0) != 10)
        {
            std::cout << "format not accepted => " << line << std::endl;
            continue;
        }
        if(!valid_date(line.substr(0, 10), line.substr(11, line.size()), map))
            continue;
    }
    return 1;
}

