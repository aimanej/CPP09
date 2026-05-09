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
        std::stringstream ss(line.substr(11, line.size()));
        std::string po = line.substr(0, 9);
        double val;
        ss >> val;
        // std::cout << "string value : " << ss.str() << std::endl;
        map[po] = val;
    }
    data.close();
}

void valid_date(std::string str)
{
    int t = 0;
    // std::cout << str.size() << std::endl;
    // std::cout << "strr  : " << str << std::endl;
    while(t < str.size() - 1)
    {
             t++;
        if((t == 4 || t == 7) && str.at(t) != '-')
        {
            std::cout << "threw here3" <<std::endl;

            throw FormatNotAccepted();
        }
        if(!std::isdigit(str.at(t)) && t != 4 && t != 7)
        {
            std::cout << "was here 4" << std::endl;
            throw FormatNotAccepted();
        }
   
    }
    // std::string ye = str.substr(0, 4);
    int year = std::atoi(str.substr(0, 4).c_str());
    int month = std::atoi(str.substr(5, 2).c_str());
    int day = std::atoi(str.substr(8, 2).c_str());

    // std::cout << "year taken : " << year << std::endl;
    if(year  > 2022 || year < 2009)
        throw DateNotAccepted();
    if(month < 1 || month > 12)
        throw DateNotAccepted();
    int max[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((year % 4 == 0 &&  year % 100 != 0 )|| year % 400 == 0)
        max[1] = 29;
    if(day < 0 || day > max[month - 1])
    {
        std::cout << max[month - 1] << " day : " << day << std::endl;
        throw DateNotAccepted();
    }
    std::cout << str << std::endl;
    // std::cout << "year : " << year <<  " month : " << month << " day = " << day << std::endl;
    
    // std::cout << "year : " << year << std::endl;
}

void valid_value(std::string str)
{
    std::stringstream ss(str);
    float val;
    // std::cout << "value of str " << str << std::endl;
    if(ss >> val)
    {
        if(ss.peek() != EOF || val > 1000 || val < 0)
        {
            // std::cout << "threw here 55" <<std::endl;
            throw FormatNotAccepted();
        }
        // std::cout << "value " << val << std::endl;
    }
    else
        throw FormatNotAccepted(); 

}

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

void input_validity(char *input)
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
            std::cout << "threw here" <<std::endl;
            throw FormatNotAccepted();
        }
        valid_date(line.substr(0, 10));
        valid_value(line.substr(11, line.size()));
        // std::cout << "input " << std::endl;

    }
}

