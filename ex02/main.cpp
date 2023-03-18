/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 02:53:21 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/18 02:44:08 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void    merge_insert_sort(T & container)
{
    if (container.size() <= 1)
        return;
    T left;
    T right;
    typename T::iterator it = container.begin();
    typename T::iterator ite = container.end();
    typename T::iterator mid = it + (ite - it) / 2;
    left.insert(left.begin(), it, mid);
    right.insert(right.begin(), mid, ite);
    merge_insert_sort(left);
    merge_insert_sort(right);
    container.clear();
    typename T::iterator it_left = left.begin();
    typename T::iterator it_right = right.begin();
    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left < *it_right)
        {
            container.push_back(*it_left);
            it_left++;
        }
        else
        {
            container.push_back(*it_right);
            it_right++;
        }
    }
    container.insert(container.end(), it_left, left.end());
    container.insert(container.end(), it_right, right.end());
}

template <typename T>
void print(const T& container)
{
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    if (ac <= 1)
    {
        std::cout << "Usage " << av[0] << "<number1> <number2> ..." << std::endl;
        return (1);
    }
    _CheckArgs(av, ac);
    std::vector<int> nums;
    for (int i = 1; i < ac; ++i)
    {
        nums.push_back(myAtoi(av[i]));
    }
    std::vector <int>v(nums);
    std::cout << "before : ";
    print(v);
    clock_t start = clock();
    merge_insert_sort(v);
    clock_t end = clock();
    double v_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "after : ";
    print(v);
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << v_time << " us\n";
    std::deque <int>d(nums.begin(), nums.end());
    std::cout << "before : ";
    print(d);
    start = clock();
    merge_insert_sort(d);
    end = clock();
    double d_time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "after : ";
    print(d);
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque: " << d_time << " us\n";
    
}