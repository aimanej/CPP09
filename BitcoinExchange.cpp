#include "BitcoinExchange.hpp"
#include <cstdlib>
void map_parsing(std::map<std::string, float> &map)
{
    std::ifstream data("data.csv");
    if(!data.is_open())
        throw FileNotOpen();
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
        // std::cout << "string value : " << ss.str() << std::endl;
        map[po] = val;
    }
    
    std::cout << " after parsing : " << t << std::endl ;
    data.close();
}

int valid_date(std::string str_y, std::string str_v, std::map<std::string, float> map)
{
    int t = 0;
    // std::cout << str.size() << std::endl;
    // std::cout << "strr  : " << str << std::endl;
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
    // std::string ye = str.substr(0, 4);
    int year = std::atoi(str_y.substr(0, 4).c_str());
    int month = std::atoi(str_y.substr(5, 2).c_str());
    int day = std::atoi(str_y.substr(8, 2).c_str());

    // std::cout << "year taken : " << year << std::endl;
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
    // std::cout << "value of str " << str << std::endl;
    if(ss >> val)
    {
        // std::cout << "vaaal " << val << std::endl;
        if(ss.peek() != EOF || val > 1000 || val < 0)
        {
            // std::cout << "threw here 55" <<std::endl;
            return std::cout << "value not accepted " << std::endl, 0;
        }
        // std::cout << "value " << val << std::endl;
    }
    else
        return std::cout << "value not valuing " << str_v << std::endl, 0;
    std::map<std::string, float>::iterator it = map.upper_bound(str_y);
    if(it != map.begin() && it->first != str_y)
            it--;
    // std::cout << "checking : " << val << " " << it->second << std::endl; 
    std::cout << year << " => " << val * it->second << std::endl;
    // std::cout << str << std::endl;
    return 1;
    // std::cout << "year : " << year <<  " month : " << month << " day = " << day << std::endl;
    
    // std::cout << "year : " << year << std::endl;
}

// int valid_value(std::string str)
// {
//     std::stringstream ss(str);
//     float val;
//     // std::cout << "value of str " << str << std::endl;
//     if(ss >> val)
//     {
//         if(ss.peek() != EOF || val > 1000 || val < 0)
//         {
//             // std::cout << "threw here 55" <<std::endl;
//             return std::cout << "value not accepted " << std::endl, 0;
//         }
//         // std::cout << "value " << val << std::endl;
//     }
//     else
//         return std::cout << "value not valuing " << str << std::endl, 0;
    
//     return 1;
 

// }

void white_space_remover(std::string &str)
{ 
    // std::cout << str << std::endl;
    // std::cout << " size " << str.size() << std::endl;
    std::string::iterator it = str.begin();
    while(it != str.end())
    {
        if(std::isspace(*it))
            it = str.erase(it);
        else
            it++;
    }
}

void input_validity(char *input, std::map<std::string, float> map)
{
    std::ifstream data(input);
    if(!data.is_open())
        throw FileNotOpen();
    std::string line;
    std::getline(data, line);
    while(std::getline(data, line))
    {
        white_space_remover(line);
        // std::cout << line << std::endl;
        if(line.find('|', 0) != 10)
        {
            std::cout << "format not accepted " << std::endl;
            continue;
            // throw FormatNotAccepted();
        }
        if(!valid_date(line.substr(0, 10), line.substr(11, line.size()), map))
            continue;
        
        
        // std::cout << "input " << std::endl;

    }
}

