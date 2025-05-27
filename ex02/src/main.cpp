/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:45:58 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/26 18:39:55 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Array.hpp"

#define MAX_VAL 5

int main()
{
    // 1) Test du constructeur par défaut et size()
    std::cout << "Test du constructeur par défaut et size()" << std::endl;
    Array<int> empty;
    std::cout << "✅ Tableau vide créé avec succès" << std::endl;
    std::cout << "empty.size() = " << empty.size() << std::endl;
    
    
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
    
    std::cout << "Remplissage du tableau avec des valeurs aléatoires..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = mirror[i] = rand();
    }
    std::cout << "Remplissage terminé." << std::endl;
    
    std::cout << "Test de copie dans un scope local..." << std::endl;
    {
        Array<int> tmp = numbers;        // Test constructeur de copie
        Array<int> test(tmp);           // Test constructeur de copie
        std::cout << "Copies créées avec succès dans le scope." << std::endl;
        std::cout << "tmp.size() = " << tmp.size() << std::endl;
        std::cout << "test.size() = " << test.size() << std::endl;
        
        // Vérification que les copies contiennent les mêmes valeurs
        std::cout << "Vérification des valeurs copiées:" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "Index " << i << ": original=" << numbers[i] 
                      << ", tmp=" << tmp[i] << ", test=" << test[i] << std::endl;
        }
        
        // TEST CRUCIAL: Modifier les copies ne doit PAS affecter l'original
        std::cout << "Test d'indépendance des copies (deep copy)..." << std::endl;
        int original_val_0 = numbers[0];
        int original_val_1 = numbers[1];
        
        tmp[0] = 999999;     // Modifier la première copie
        test[1] = 888888;    // Modifier la deuxième copie
        
        if (numbers[0] != original_val_0) {
            std::cerr << "❌ ERREUR: Modification de tmp[0] a affecté l'original !" << std::endl;
            std::cerr << "Original était: " << original_val_0 << ", maintenant: " << numbers[0] << std::endl;
            delete[] mirror;
            return 1;
        }
        
        if (numbers[1] != original_val_1) {
            std::cerr << "❌ ERREUR: Modification de test[1] a affecté l'original !" << std::endl;
            std::cerr << "Original était: " << original_val_1 << ", maintenant: " << numbers[1] << std::endl;
            delete[] mirror;
            return 1;
        }
        
        std::cout << "✅ Test d'indépendance réussi: les modifications des copies n'affectent pas l'original" << std::endl;
        std::cout << "Original[0]: " << numbers[0] << " (inchangé)" << std::endl;
        std::cout << "Original[1]: " << numbers[1] << " (inchangé)" << std::endl;
        std::cout << "tmp[0]: " << tmp[0] << " (modifié)" << std::endl;
        std::cout << "test[1]: " << test[1] << " (modifié)" << std::endl;
    }
    std::cout << "Sortie du scope - destructeurs appelés." << std::endl;
    
    std::cout << "Vérification de l'intégrité après destruction des copies..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "Erreur de copie profonde à l'index " << i << " !" << std::endl;
            std::cerr << "Attendu: " << mirror[i] << ", obtenu: " << numbers[i] << std::endl;
            delete[] mirror;
            return 1;
        }
    }
    std::cout << "✅ Test de copie profonde réussi - toutes les valeurs sont intactes !" << std::endl;
    std::cout << std::endl;

    // 4) Test exceptions hors bornes
    std::cout << "Test exceptions hors bornes" << std::endl;
    try { 
        numbers[-2] = 0; 
    } catch(const std::exception& e) {
        std::cerr << "numbers[-2] : " << e.what() << std::endl;
    }
    try { 
        numbers[6] = 0; 
    } catch(const std::exception& e) {
        std::cerr << "numbers[6] : " << e.what() << std::endl;
    }
    std::cout << std::endl;

    // 5) Test sur un type non trivial
    std::cout << "Test sur un type non trivial" << std::endl;
    Array<std::string> words(3);
    words[0] = "foo"; 
    words[1] = "bar"; 
    words[2] = "baz";
    for (unsigned i = 0; i < words.size(); i++)
        std::cout << words[i] << ' ';
    std::cout << std::endl;

    delete[] mirror;
    return 0;
}