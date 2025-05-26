/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:45:58 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/26 04:38:08 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Array.hpp"

#define MAX_VAL 750

int main()
{
    // 1) Test du constructeur par défaut et size()
    std::cout << "Test du constructeur par défaut et size()" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;
    try {
        empty[0];
    } catch (const std::exception& e) {
        std::cerr << "empty[0] : " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // 2) Test de l'initialisation et de size()
    std::cout << "Test de l'initialisation et de size()" << std::endl;
    Array<int> numbers(MAX_VAL);
    std::cout << "numbers.size() = " << numbers.size() << std::endl;
    std::cout << std::endl;

    // 3) Remplissage et miroir pour vérifier deep copy
    std::cout << "Remplissage et miroir pour vérifier deep copy" << std::endl;
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = mirror[i] = rand();
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Erreur de copie profonde !" << std::endl;
            return 1;
        }
    }
    std::cout << std::endl;

    // 4) Test exceptions hors bornes
    std::cout << "Test exceptions hors bornes" << std::endl;
    try { numbers[-2] = 0; } catch(const std::exception& e) {
        std::cerr << "numbers[-2] : " << e.what() << std::endl;
    }
    try { numbers[MAX_VAL] = 0; } catch(const std::exception& e) {
        std::cerr << "numbers[MAX_VAL] : " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // 5) Test sur un type non trivial
    std::cout << "Test sur un type non trivial" << std::endl;
    Array<std::string> words(3);
    words[0] = "foo"; words[1] = "bar"; words[2] = "baz";
    for (unsigned i = 0; i < words.size(); i++)
        std::cout << words[i] << ' ';
    std::cout << std::endl;

    delete [] mirror;
    return 0;
}
