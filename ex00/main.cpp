
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {

        std::map<std::string, float> map;

        if(!map_parsing(map))
            return 1;
        if(!input_validity(av[1], map))
            return 1;
        int t = 0;
        // for(std::map<std::string, float>::iterator it = map.begin(); it != map.end(); it++)
        // {
        //     std::cout << it->first << " " << std::fixed << std::setprecision(2)<< it->second << std::endl;
        //     t++;
        // }
        // std::cout << " iterator val " << map["2020-06-13"] << std::endl;
        // std::cout << t << " value of this bitch " << map.max_size() << std::endl;
        // std::map<std::string, float>::iterator it = map.upper_bound("2009-01-06");
        // if(it != map.begin() && it->first != "2009-01-06")
        //     it--;
        // std::cout << it->first << " " << it->second << std::endl;
    }
    else
        std::cout << "no input file detected" << std::endl;
    return 0;
}