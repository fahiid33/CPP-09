/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:11:56 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/15 05:57:38 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange() {return;}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) { *this = src; return;}

BitcoinExchange::~BitcoinExchange() {return;}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs){this->database = rhs.database; return *this;}

BitcoinExchange::BitcoinExchange(std::string filename) 
{
    std::ifstream infile(filename);
    std::string line;
    std::string date_str;
    float price;
    if (!infile.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::getline(infile, line);
    while (std::getline(infile, line)) 
    {
        std::istringstream iss(line);
        date_str = line.substr(0, 10);
        price = std::stof(line.substr(11, line.size()));
        database[date_str] = price;
    }
    // print database
    // for (std::map<std::string, double>::iterator it = database.begin(); it != database.end(); ++it)
    // 	std::cout << it->first << " => " << it->second << std::endl;
    infile.close();
}

double  BitcoinExchange::get_price(std::string date_str) 
{
    std::map<std::string, double>::const_iterator it = database.find(date_str);
    if (it != database.end())
        return it->second;
    else 
    {
        std::map<std::string, double>::const_iterator lower_it = database.lower_bound(date_str);
        if (lower_it == database.begin())
            return 0.0;
        else 
        {
            --lower_it;
            return lower_it->second;
        }
    }
}

int isDateValid(const std::string& dateStr) 
{
    if (dateStr.size() != 10 || dateStr[4] != '-' || dateStr[7] != '-')
        return 1;
    std::string year = dateStr.substr(0, 4);
    std::string M = dateStr.substr(5, 2);
    std::string D = dateStr.substr(8, 2);
    try
    {
        if (stoi(year) < 2009 || stoi(M) <= 0 || stoi(M) > 12 || stoi(D) <= 0 || stoi(D) > 31)
            return (1);
    }
    catch(std::exception &e)
    {
        return (1);
    }
    return 0;
}
float  check_value(std::string line)
{
    std::string value = line.substr(line.find("|") + 1, line.size());
    std::string values[2];
    int j = -1;
    if (value.empty())
        return (-1);
    while(isblank(value[++j]));
    value = value.substr(j, value.size());
    values[0] = value.substr(0, value.find(" "));
    value = value.substr(values[0].size(), value.size());
    if (!value.empty())
    {
        while (value[++j])
            if (value[j] != ' ')
                return -1;
    }
    values[0].replace(values[0].find(","), 1, ".");
    return (stof(values[0]));
}

int error_handlig(std::string line, std::string &date_str, char &sep, float &value)
{
    std::istringstream iss(line);
    if (!(iss >> date_str >> sep >> value) || sep != '|') 
    {
        std::cerr << "Error: bad input ==> " << line << std::endl;
        return(1);
    }
    if ((value = check_value(line)) == -1)
    {
        std::cerr << "Error: bad input ==> " << line << std::endl;
        return(1);
    }
    
    if (value < 0.0)
    {
        std::cerr << "Error: not a positive number."  << std::endl;
        return(1);
    }
    if (value > 1000.0)
    {
        std::cerr << "Error: too large a number."  << std::endl;
        return(1);
    }
    if (isDateValid(date_str))
    {
        std::cerr << "Error: invalid Date."  << std::endl;
        return(1);
    }
    return (0);
}

void BitcoinExchange::exchange(std::string input_filename) 
{
    std::cout.setf(std::ios::fixed);
    std::cout.precision(2);
    std::ifstream infile(input_filename);
    if (!infile.is_open()) 
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    while (std::getline(infile, line)) 
    {
        std::string date_str;
        float value;
        char sep;
        if (error_handlig(line, date_str, sep, value))
            continue ;
        double price = get_price(date_str);
        double exchange_rate = 0.0;
        if (price > 0.0) {
            exchange_rate = value * price;
        }
        std::cout << date_str << " => " << value << " = " << exchange_rate << std::endl;
    }
    infile.close();
}