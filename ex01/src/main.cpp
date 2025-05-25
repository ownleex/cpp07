/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:35:12 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/26 00:07:01 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(T& x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T& x) {
    x++;
}

void toUpper(char& c) {
    if (c >= 'a' && c <= 'z') {
        c = c - 'a' + 'A';
    }
}

int main(void) {
    // Test avec des entiers
    std::cout << "Test avec des entiers:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    int intLength = 5;
    
    std::cout << "Tableau original: ";
    ::iter(intArray, intLength, print<int>);
    std::cout << std::endl;
    
    ::iter(intArray, intLength, increment<int>);
    std::cout << "Après incrémentation: ";
    ::iter(intArray, intLength, print<int>);
    std::cout << std::endl << std::endl;
    
    // Test avec des doubles
    std::cout << "Test avec des doubles:" << std::endl;
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    int doubleLength = 5;
    
    std::cout << "Tableau original: ";
    ::iter(doubleArray, doubleLength, print<double>);
    std::cout << std::endl;
    
    ::iter(doubleArray, doubleLength, increment<double>);
    std::cout << "Après incrémentation: ";
    ::iter(doubleArray, doubleLength, print<double>);
    std::cout << std::endl << std::endl;
    
    // Test avec des caractères
    std::cout << "Test avec des caractères:" << std::endl;
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    int charLength = 5;
    
    std::cout << "Tableau original: ";
    ::iter(charArray, charLength, print<char>);
    std::cout << std::endl;
    
    ::iter(charArray, charLength, toUpper);
    std::cout << "En majuscules: ";
    ::iter(charArray, charLength, print<char>);
    std::cout << std::endl << std::endl;
    
    // Test avec des strings
    std::cout << "Test avec des strings:" << std::endl;
    std::string stringArray[] = {"hello", "world", "template", "test"};
    int stringLength = 4;
    
    std::cout << "Tableau de strings: ";
    ::iter(stringArray, stringLength, print<std::string>);
    std::cout << std::endl;
    
    return 0;
}