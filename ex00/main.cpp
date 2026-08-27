
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
    }
    else
        std::cout << "no input file detected" << std::endl;
    return 0;
}