#include "PmergeMe.hpp"


int main(int ac, char **av)
{

    try{
        std::vector<int> vec;
        vec = parce_params(ac, av);

        std::cout << "parced numbers : " ;
        for(int i = 0; i < vec.size(); i++)
            std::cout << vec[i] << " ";
        std::cout << std::endl;        
        splitter(vec);
    }

    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}