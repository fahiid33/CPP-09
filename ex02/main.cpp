/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 02:53:21 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/16 04:09:31 by fstitou          ###   ########.fr       */
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
        cout << *it << " ";
    }
    std::cout << endl;
}
template <typename T>



int main(int ac, char **av)
{
    if (ac <= 2)
    {
        std::cout << "Usage " << av[0] << "<number1> <number2> ..." << std::endl;
        return (1);
    }
    _CheckArgs(av, ac);
    std::vector<int> nums;
    for (int i = 1; i < ac; ++i)
    {
        nums.push_back(atoi(av[i]));
    }
    std::vector v(nums);
    std::cout << "before : ";
    print(v);
    clock_t t1 = clock();
    merge_insert_sort(v);
    clock_t t2 = clock();
    std::cout << "after : ";
    print(v);
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector: " << ((t2 - t1) / static_cast<double>(CLOCKS_PER_SEC) * 1000000) << " us\n";
    
    
    
}