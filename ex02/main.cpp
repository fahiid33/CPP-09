/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 02:53:21 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/16 20:21:34 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>

int myAtoi(const char* str) 
{
    int sign = 1;
    int result = 0;
    while (*str == ' ') {
        str++;
    }
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        sign = 1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }
    return sign * result;
}

int is_digit(char *av)
{
    int i = 0;
    while (av[i])
    {
        if (!isdigit(av[i]))
            return (0);
        i++;
    }
    return (1);
}
bool compareStrings(const char* str1, const char* str2) 
{
    std::string s1(str1);
    std::string s2(str2);
    return s1 == s2;
}

bool duplicates(char **av, int ac)
{
    for (int i = 1; i < ac; i++) 
    {
        for (int j = i + 1; j < ac; j++) 
        {
            if (compareStrings(av[i], av[j]))
                return true;
        }
    }
    return false;
}


void    _CheckArgs(char **av, int ac)
{
    for (int i = 1; i < ac; i++)
    {
        if (!is_digit(av[i]))
        {
            std::cerr << "Error: not a positive integer" << std::endl;
            exit(1);
        }
    }
    if (duplicates(av, ac))
    {
         std::cerr << "Error: there is a duplicated numbers" << std::endl;
        exit(1);
    }
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
    while (it_left != left.end())
    {
        container.push_back(*it_left);
        it_left++;
    }
    while (it_right != right.end())
    {
        container.push_back(*it_right);
        it_right++;
    }
}


int main(int ac, char **av)
{
    if (ac <= 2)
    {
        std::cout << "Usage " << av[0] << "<number1> <number2> ..." << std::endl;
        return (1);
    }
    // _CheckArgs(av, ac);
    std::vector<int> nums;
    for (int i = 1; i < ac; ++i)
    {
        nums.push_back(atoi(av[i]));
    }
    std::vector <int>v(nums);
    std::cout << "before : ";
    print(v);
    clock_t start = clock();
    merge_insert_sort(v);
    clock_t end = clock();
    long elapsed_usec = (end - start) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "after : ";
    print(v);
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << elapsed_usec << " us\n";
    std::deque <int>d(nums.begin(), nums.end());
    std::cout << "before : ";
    print(d);
    start = clock();
    merge_insert_sort(d);
    end = clock();
    elapsed_usec = (end - start) * 1000000 / CLOCKS_PER_SEC;
    std::cout << "after : ";
    print(d);
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque: " << elapsed_usec << " us\n";
    
}