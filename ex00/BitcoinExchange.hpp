/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:12:00 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/15 01:47:25 by fstitou          ###   ########.fr       */
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
	// constructors
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange();
	// operators
		BitcoinExchange & operator=(BitcoinExchange const & rhs);
	// methods
		double get_price(std::string date_str);
		void exchange(std::string input_filename);
};


#endif