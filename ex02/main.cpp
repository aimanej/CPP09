#include "PmergeMe.hpp"


int main(int ac, char **av)
{

    try{
        if(ac < 3)
            throw Parcing_issue();
        std::vector<int> vec;

        struct timeval v_start, v_end;        
        gettimeofday(&v_start, NULL);
        vec = parce_params(ac, av);

        std::vector<int> ret = splitter(vec);
        gettimeofday(&v_end, NULL);
        int v_duration = (v_end.tv_sec - v_start.tv_sec) * 1000000 + (v_end.tv_usec - v_start.tv_usec);
        
        
        std::cout << "Before: ";
        for (size_t i = 0; i < vec.size(); i++)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "After: ";
        for(size_t t = 0; t < ret.size(); t++)
        {
            std::cout << ret[t] << " " ;
        }
        std::cout << std::endl;

        std::deque<int> de;

        struct timeval dq_start, dq_end; 
        gettimeofday(&dq_start, NULL);

        de = param_parcer_dq(ac, av);
        std::deque<int> res = splitter(de);

        gettimeofday(&dq_end, NULL);
        int dq_duration = (dq_end.tv_sec - dq_start.tv_sec) * 1000000 + (dq_end.tv_usec - dq_start.tv_usec);
        
        std::cout << "Time to process a range of " << vec.size() << " with std::vector : " << v_duration << " us" << std::endl;
        std::cout << "Time to process a range of " << vec.size() << " with std::deque : " << dq_duration << " us" << std::endl;
    }

    catch(std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}