/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:42:57 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/16 01:31:40 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

void    _CheckArgs(std::string expression)
{
    for(size_t i = 0; i < expression.length(); i++)
    {
        if (!isdigit(expression[i]) && expression[i] != '+' 
            && expression[i] != '-' && expression[i] != '*' 
            && expression[i] != '/' && !isblank(expression[i]))
        {
            std::cerr << "Error : Bad args" << std::endl;
            exit(1);
        }
        else if (expression[i] == ')' || expression[i] == '(')
        {
            std::cerr << "Error : Bad args" << std::endl;
            exit(1);
        }
    }
}

int evaluate_rpn(std::string expression) 
{
    std::stack<int> stack;
    int operand1, operand2;
    _CheckArgs(expression);
    for (size_t i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) 
        {
            stack.push(expression[i] - '0');
        } 
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') 
        {
            operand2 = stack.top();
            // std::cout << "------" << std::endl;
            // std::cout << "stack" << std::endl;
            // std::cout << stack.top() << std::endl;
            stack.pop();
            operand1 = stack.top();
            // std::cout << stack.top() << std::endl;
            // std::cout <<"token = " << expression[i] << std::endl;
            // std::cout << "------" << std::endl;
            stack.pop();

            switch (expression[i]) 
            {
                case '+':
                {
                    // std::cout << operand1<< " + "<< operand2 << " = ";
                    // std::cout << (operand1 + operand2) <<std::endl;
                    stack.push(operand1 + operand2);
                    break;
                }
                case '-':
                {
                    // std::cout << operand1<< " - "<< operand2 << " = ";
                    // std::cout << (operand1 - operand2) <<std::endl;
                    stack.push(operand1 - operand2);
                    break;
                    
                }
                case '*':
                {
                    // std::cout << operand1<< " * "<< operand2 << " = ";
                    // std::cout << (operand1 * operand2) <<std::endl;
                    stack.push(operand1 * operand2);
                    break;
                    
                }
                case '/':
                {
                    // std::cout << operand1<< " / "<< operand2 << " = ";
                    // std::cout << (operand1 / operand2) <<std::endl;
                    stack.push(operand1 / operand2);
                    break;
                    
                }
            }
        }
    }
    return stack.top();
}

int main(int ac, char **av) 
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <inverted Polish mathematical expression>" << std::endl;
        return (1);
    }
    std::string expression = av[1];
    int result = evaluate_rpn(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
