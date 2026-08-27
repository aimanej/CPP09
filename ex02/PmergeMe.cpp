#include "PmergeMe.hpp"


bool is_dup(std::vector<int> vec, int n)
{
    for(size_t i = 0; i < vec.size(); i++)
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
    while(tmp.back() < n)
    {
        tmp.push_back(tmp[tmp.size() - 1] + tmp[tmp.size() - 2] * 2);
    }
    return tmp;
}

std::vector<int> insert_order(int size)
{
    if(size == 0)
        return std::vector<int>();
    std::vector<int> jacob = thaler(size);
    std::vector<int> order;

    int prev = 0;
    for(size_t i = 1; i < jacob.size(); i++)
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
        return vec;
    int plus = -1;
    bool has_plus = !(vec.size() % 2 == 0);

    if(has_plus)
    {
        plus = vec.back();
        vec.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;

    for(size_t t = 0; t + 1 < vec.size(); t += 2)
    {
        int a = vec[t];
        int b = vec[t + 1];
        if(a > b)
            std::swap(a, b);
        pairs.push_back(std::pair<int,int>(a,b));
    }
    std::vector<int> winners;
    for(size_t t = 0; t < pairs.size(); t++)
    {
        winners.push_back(pairs[t].second);
    }

    winners = splitter(winners);

    //pairing again

    std::vector<std::pair<int, int> > sorted_pairs;

    for(size_t t = 0; t < winners.size(); t++)
    {
        for(size_t i = 0; i < pairs.size(); i++)
        {
            if(pairs[i].second == winners[t])
                sorted_pairs.push_back(pairs[i]);
        }
    }

    pairs = sorted_pairs;

    std::vector<int> chain;
    chain.push_back(pairs[0].first);

    for(size_t t = 0; t < pairs.size(); t++)
    {
        chain.push_back(pairs[t].second);
    }

    std::vector<int> pending;

    for(size_t t = 1; t < pairs.size(); t++)
    {
        pending.push_back(pairs[t].first);
    }

    std::vector<int> order = insert_order(pending.size());

    for(size_t t = 0; t < order.size(); t++)
    {
        int index = order[t];
        int val = pending[index];
        int win_val = pairs[index + 1].second;

        std::vector<int>::iterator win_pos = std::lower_bound(chain.begin(), chain.end(), win_val);
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), win_pos, val);

        chain.insert(pos, val);

    }

    if(has_plus)
    {
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), plus);
        chain.insert(pos, plus);
    }   

    return chain;
}

//dequeeeeeee

bool is_dup(std::deque<int> cont, int n)
{
    for(size_t i = 0; i < cont.size(); i++)
    {
        if(n == cont[i])
            return true;
    }
    return false;
}

std::deque<int> param_parcer_dq(int ac, char **av)
{
    std::deque<int> cont;

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

std::deque<int> sequence(int n)
{
    std::deque<int> tmp;

    tmp.push_back(1);
    tmp.push_back(1);
    while(tmp.back() < n)
    {
        tmp.push_back(tmp[tmp.size() - 1] + tmp[tmp.size() - 2] * 2);
    }
    return tmp;
}

std::deque<int> insert_order_dq(int size)
{
    if(size == 0)
        return std::deque<int>();
    std::deque<int> jacob = sequence(size);
    std::deque<int> order;

    int prev = 0;
    for(size_t i = 1; i < jacob.size(); i++)
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

std::deque<int> splitter(std::deque<int> vec)
{
    if (vec.size() == 1)
        return vec;
    int plus = -1;
    bool has_plus = !(vec.size() % 2 == 0);

    if(has_plus)
    {
        plus = vec.back();
        vec.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;

    for(size_t t = 0; t + 1 < vec.size(); t += 2)
    {
        int a = vec[t];
        int b = vec[t + 1];
        if(a > b)
            std::swap(a, b);
        pairs.push_back(std::pair<int,int>(a,b));
    }
    std::deque<int> winners;
    for(size_t t = 0; t < pairs.size(); t++)
    {
        winners.push_back(pairs[t].second);
    }

    winners = splitter(winners);

    //pairing again

    std::deque<std::pair<int, int> > sorted_pairs;

    for(size_t t = 0; t < winners.size(); t++)
    {
        for(size_t i = 0; i < pairs.size(); i++)
        {
            if(pairs[i].second == winners[t])
                sorted_pairs.push_back(pairs[i]);
        }
    }

    pairs = sorted_pairs;

    std::deque<int> chain;
    chain.push_back(pairs[0].first);

    for(size_t t = 0; t < pairs.size(); t++)
    {
        chain.push_back(pairs[t].second);
    }

    std::deque<int> pending;

    for(size_t t = 1; t < pairs.size(); t++)
    {
        pending.push_back(pairs[t].first);
    }

    std::deque<int> order = insert_order_dq(pending.size());

    for(size_t t = 0; t < order.size(); t++)
    {
        int index = order[t];
        int val = pending[index];
        int win_val = pairs[index + 1].second;

        std::deque<int>::iterator win_pos = std::lower_bound(chain.begin(), chain.end(), win_val);
        std::deque<int>::iterator pos = std::lower_bound(chain.begin(), win_pos, val);

        chain.insert(pos, val);

    }

    if(has_plus)
    {
        std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), plus);
        chain.insert(pos, plus);
    }   

    return chain;
}