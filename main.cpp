
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if(ac == 2)
    {

        std::map<std::string, float> map;
        try{

            map_parsing(map);
            
            input_validity(av[1]);
        }
        catch(std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
        // for(std::map<std::string, float>::iterator it = map.begin(); it != map.end(); it++)
    // {
    //     std::cout << it->first << " " << it->second << std::endl;
    // }
    
}