/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:29:04 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/27 19:26:47 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>
#include <iostream>
#include <stdlib.h>
#include <time.h>

template <typename T>
class Array {
private:
    T* _data;
    unsigned int _size;

public:
    // Constructeur par défaut
    Array();
    
    // Constructeur avec taille
    Array(unsigned int size);
    
    // Constructeur de copie
    Array(const Array& other);
    
    // Destructeur
    ~Array();
    
    // Opérateur d'affectation
    Array& operator=(const Array& other);
    
    // Opérateur d'accès aux éléments
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    
    // Fonction membre size()
    unsigned int size() const;
};

// Inclusion de l'implémentation
#include "Array.tpp"

#endif