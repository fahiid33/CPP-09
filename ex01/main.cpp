/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstitou <fstitou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 20:42:57 by fstitou           #+#    #+#             */
/*   Updated: 2023/03/15 20:47:10 by fstitou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

int evaluate_infix_expression(string expression) {
    stack<int> stack;
    int operand1, operand2;

    for (size_t i = 0; i < expression.length(); i++) {
        if (isdigit(expression[i])) {
            stack.push(expression[i] - '0');
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            operand2 = stack.top();
            stack.pop();
            operand1 = stack.top();
            stack.pop();

            switch (expression[i]) {
                case '+':
                    stack.push(operand1 + operand2);
                    break;
                case '-':
                    stack.push(operand1 - operand2);
                    break;
                case '*':
                    stack.push(operand1 * operand2);
                    break;
                case '/':
                    stack.push(operand1 / operand2);
                    break;
            }
        }
    }

    return stack.top();
}

int main() {
    string expression = "12 * 2 / 5 + 46 * 6 / 8 * 2 / + 2 * 2-";
    int result = evaluate_infix_expression(expression);

    cout << "Result: " << result << endl;

    return 0;
}
