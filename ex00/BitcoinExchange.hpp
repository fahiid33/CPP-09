/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:12:00 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/15 00:51:39 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include <iomanip>

class BitcoinExchange {
private:
    std::map<std::string, double> database;
public:
    BitcoinExchange(const std::string& filename) 
	{
        std::ifstream infile(filename);
        if (!infile.is_open()) {
            std::cerr << "Error: could not open file." << std::endl;
            return;
    }
        std::string line;
	std::string date_str;
	float price;
	std::getline(infile, line);
        while (std::getline(infile, line)) {
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

    double get_price(const std::string& date_str) const {
        std::map<std::string, double>::const_iterator it = database.find(date_str);
        if (it != database.end()) {
            return it->second;
        } else {
            std::map<std::string, double>::const_iterator lower_it = database.lower_bound(date_str);
            if (lower_it == database.begin()) {
                return 0.0;
            } else {
                --lower_it;
                return lower_it->second;
            }
        }
    }

    void exchange(const std::string& input_filename) const {
        std::ifstream infile(input_filename);
        if (!infile.is_open()) {
            std::cerr << "Error: could not open file." << std::endl;
            return;
        }

        std::string line;
        while (std::getline(infile, line)) {
            std::istringstream iss(line);
            std::string date_str;
            double value;
            char sep;
            if (!(iss >> date_str >> sep >> value) || sep != '|' || value <= 0.0 || value > 1000.0) {
                std::cerr << "Error: bad input => " << line << std::endl;
                continue;
            }
            double price = get_price(date_str);
            double exchange_rate = 0.0;
            if (price > 0.0) {
                exchange_rate = value * price;
            }
            std::cout << date_str << " => " << value << " = " << exchange_rate << std::endl;
        }
        infile.close();
    }
};


#endif