/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 02:39:13 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/18 02:42:47 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
