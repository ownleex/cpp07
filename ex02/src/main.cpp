/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:45:58 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/27 19:13:08 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Array.hpp"

#define MAX_VAL 5

int main()
{
    std::cout << "=== Tests du template Array ===" << std::endl << std::endl;

    // 1) Test constructeur par défaut
    std::cout << "1. Test constructeur par défaut" << std::endl;
    Array<int> empty;
    std::cout << "Taille du tableau vide: " << empty.size() << std::endl;
    std::cout << "✅ Constructeur par défaut OK" << std::endl << std::endl;


    
    // 2) Test constructeur avec taille
    std::cout << "2. Test constructeur avec taille" << std::endl;
    Array<int> numbers(MAX_VAL);
    std::cout << "Taille du tableau: " << numbers.size() << std::endl;
    
    // Vérification de l'initialisation par défaut
    std::cout << "Valeurs par défaut: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "✅ Constructeur avec taille OK" << std::endl << std::endl;



    // 3) Test d'accès et modification
    std::cout << "3. Test d'accès et modification" << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = (i + 1) * 10;
    }
    
    std::cout << "Après modification: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "✅ Accès et modification OK" << std::endl << std::endl;



    // 4) Test de copie profonde (deep copy)
    std::cout << "4. Test de copie profonde" << std::endl;
    
    // Test constructeur de copie
    Array<int> copy1(numbers);
    std::cout << "Constructeur de copie (copy1) - taille: " << copy1.size() << std::endl;
    
    // Test opérateur d'affectation
    Array<int> copy2;
    copy2 = numbers;
    std::cout << "Opérateur d'affectation (copy2) - taille: " << copy2.size() << std::endl;
    
    // Vérification que les valeurs sont identiques
    std::cout << "Valeurs identiques ? ";
    bool identical = true;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        if (numbers[i] != copy1[i] || numbers[i] != copy2[i]) {
            identical = false;
            break;
        }
    }
    std::cout << (identical ? "OUI" : "NON") << std::endl;
    
    // TEST CRUCIAL: Modification des copies ne doit pas affecter l'original
    std::cout << "Test d'indépendance des copies:" << std::endl;
    std::cout << "Avant modification - Original[0]: " << numbers[0] << "   Copy1[0]: " << copy1[0] << "    Copy2[0]: " << copy2[0] << std::endl;
    std::cout << "                     Original[1]: " << numbers[1] << "   Copy1[0]: " << copy1[1] << "    Copy2[0]: " << copy2[1] << std::endl;
    std::cout << "                     Original[2]: " << numbers[2] << "   Copy1[0]: " << copy1[2] << "    Copy2[0]: " << copy2[2] << std::endl;
    
    copy1[0] = 999;
    copy2[0] = 888;
    copy1[1] = 9999;
    copy2[1] = 8888;
    
    std::cout << "Après modification - Original[0]: " << numbers[0] << "   Copy1[0]: " << copy1[0] << "   Copy2[0]: " << copy2[0] << std::endl;
    std::cout << "                     Original[1]: " << numbers[1] << "   Copy1[0]: " << copy1[1] << "  Copy2[0]: " << copy2[1] << std::endl;
    std::cout << "                     Original[2]: " << numbers[2] << "   Copy1[0]: " << copy1[2] << "    Copy2[0]: " << copy2[2] << std::endl;
    
    if (numbers[0] == 10) { // La valeur originale était 10 ((i + 1) * 10 avec i = 0)
        std::cout << "✅ Deep copy OK - L'original n'a pas été modifié" << std::endl;
    } else {
        std::cout << "❌ Erreur - L'original a été modifié !" << std::endl;
    }
    std::cout << std::endl;



    // 5) Test des exceptions (accès hors limites)
    std::cout << "5. Test des exceptions" << std::endl;
    
    try {
        std::cout << "Tentative d'accès à l'index " << "6" << ": ";
        numbers[6] = 42;
        std::cout << "❌ Aucune exception lancée !" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "✅ Exception attrapée: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "Tentative d'accès à l'index -1 (cast en unsigned): ";
        numbers[static_cast<unsigned int>(-1)] = 42;
        std::cout << "❌ Aucune exception lancée !" << std::endl;
    } catch(const std::exception& e) {
        std::cout << "✅ Exception attrapée: " << e.what() << std::endl;
    }
    std::cout << std::endl;



    // 6) Test avec strings
    std::cout << "6. Test avec des strings" << std::endl;
    Array<std::string> words(3);
    words[0] = "Hello";
    words[1] = "World";
    words[2] = "Template";
    
    std::cout << "Tableau de strings: ";
    for (unsigned int i = 0; i < words.size(); i++) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
    
    // Test de copie avec strings
    Array<std::string> wordsCopy = words;
    wordsCopy[0] = "Modified";
    
    std::cout << "Original[0]: " << words[0] << ", Copie[0]: " << wordsCopy[0] << std::endl;
    std::cout << "✅ Test avec string OK" << std::endl << std::endl;

    

    std::cout << "✅ === Tous les tests terminés === ✅" << std::endl;
    return 0;
}