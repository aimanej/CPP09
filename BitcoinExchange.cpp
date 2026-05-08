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
        float val;
        ss >> val;
        map[po] = val;
    }
    data.close();
}

void valid_date(std::string str)
{
    int t = 0;
    // std::cout << str.size() << std::endl;
    // std::cout << str << std::endl;
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
    std::string ye = str.substr(0, 4);
    int year = std::atoi(ye.c_str());
    
    std::cout << "year : " << year << std::endl;
}

void valid_value(std::string str)
{
    std::stringstream ss(str);
    float val;
    if(ss >> val)
    {
        if(ss.peek() != EOF || val > 1000 || val < 0)
        {
            std::cout << "threw here 55" <<std::endl;
            throw FormatNotAccepted();
        }
    }

}

void white_space_remover(std::string &str)
{ 
    std::cout << str << std::endl;
    std::cout << " size " << str.size() << std::endl;
    std::string::iterator it = str.begin();
    while(it != str.end())
    {
        std::cout << *it << std::endl;
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
        std::cout << line << std::endl;
        if(line.find('|', 0) != 10)
        {
            std::cout << "threw here" <<std::endl;
            throw FormatNotAccepted();
        }
        valid_date(line.substr(0, 9));
        valid_value(line.substr(12, line.size()));
        std::cout << "input " << std::endl;

    }
}

