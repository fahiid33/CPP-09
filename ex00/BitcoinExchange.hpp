/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:12:00 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/15 01:04:59 by fstitou          ###   ########.fr       */
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
		BitcoinExchange(const std::string& filename);
		double get_price(const std::string& date_str) const;
		void exchange(const std::string& input_filename) const;
};


#endif