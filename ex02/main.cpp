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
        // splitter(vec);

        std::cout << "thaller : \n";
        std::vector<int> jacob = thaler(6);
        for(int t = 0; t < jacob.size(); t++)
            std::cout << jacob[t] << " ";
        std::cout << std::endl;

        std::vector<int> order = insert_order(14);
        std::cout << "order \n";
        for(int t = 0; t < order.size(); t++)
            std::cout << order[t] << " ";
        std::cout << std::endl;
    }

    catch(std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }
}