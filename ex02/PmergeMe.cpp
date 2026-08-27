#include "PmergeMe.hpp"


bool is_dup(std::vector<int> vec, int n)
{
    for(int i = 0; i < vec.size(); i++)
    {
        if(n == vec[i])
            return true;
    }
    return false;
}

std::vector<int> parce_params(int ac, char **av)
{
    std::vector<int> cont;

    for(int i = 1; i < ac; i++)
    {
        std::stringstream ss(av[i]);
        std::string leftover;
        int holder = 0;
        ss >> holder;
        ss >> leftover;
        if(!(leftover.empty()) || holder <= 0 || is_dup(cont, holder))
        {
            std::cout << "argument issue -> " << av[i] << std::endl;
            throw Parcing_issue();
        }
        cont.push_back(holder);

    }
    return cont;
}

std::vector<int> thaler(int n)
{
    std::vector<int> tmp;

    tmp.push_back(1);
    tmp.push_back(1);
    for(int t = 1; t < n; t++)
    {
        tmp.push_back(tmp[t] + tmp[t- 1] * 2);
    }
    return tmp;
}

std::vector<int> insert_order(int size)
{
    if(size == 0)
        return {};
    std::vector<int> jacob = thaler(size);
    std::vector<int> order;

    int prev = 0;
    for(int i = 1; i < jacob.size(); i++)
    {
        int val = std::min(jacob[i], size);
        for(int t = val; t > prev ; t--)
        {
            order.push_back(t - 1);
        }
        prev = val;
        if(size < prev)
            break;
    }
    return order;
}

std::vector<int> splitter(std::vector<int> vec)
{
    if (vec.size() == 1)
        return {};
    int plus = -1;
    bool has_plus = !(vec.size() % 2 == 0);

    if(has_plus)
    {
        plus = vec.back();
        vec.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;

    for(int t = 0; t + 1 < vec.size(); t += 2)
    {
        int a = vec[t];
        int b = vec[t + 1];
        if(a > b)
            std::swap(a, b);
        pairs.push_back(std::pair<int,int>(a,b));
    }

    // for(int t = 0; t < pairs.size(); t++)
    // {
    //     std::cout << "(" <<  pairs[t].first << "," << pairs[t].second << ")" << " ";
    // }
    // std::cout << std::endl;

    std::vector<int> winners;
    for(int t = 0; t < pairs.size(); t++)
    {
        // std::cout << "(" <<  pairs[t].first << "," << pairs[t].second << ")" << " ";
        winners.push_back(pairs[t].second);
    }

    winners = splitter(winners);

    std::vector<std::pair<int, int> > sorted_pairs;

    // for(int t = 0; t < winners.size())

    return winners;
}