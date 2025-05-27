/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:35:12 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/27 21:29:24 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



    // Test avec des floats
    std::cout << "Test avec des floats:" << std::endl;
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    int floatLenght = 5;
    
    std::cout << "Tableau original: ";
    ::iter(floatArray, floatLenght, print<float>);
    std::cout << std::endl;
    
    ::iter(floatArray, floatLenght, increment<float>);
    std::cout << "Après incrémentation: ";
    ::iter(floatArray, floatLenght, print<float>);
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
    std::cout << std::endl << "Après incrémentation: ";
    ::iter(charArray, charLength, increment<char>);
    ::iter(charArray, charLength, print<char>);
    std::cout << std::endl << std::endl;
    

    
    // Test avec des strings
    std::cout << "Test avec des strings (this - is - hello - world):" << std::endl;
    std::string stringArray[] = {"this", "is", "hello", "world"};
    int stringLength = 4;
    
    std::cout << "Tableau de strings: ";
    ::iter(stringArray, stringLength, print<std::string>);
    std::cout << std::endl;
    
    return 0;
}