/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:34:22 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/27 17:15:37 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

// Constructeur par défaut
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

// Constructeur avec taille
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n) {}

// Constructeur de copie
template <typename T>
Array<T>::Array(const Array& other) : _data(NULL), _size(0) {
    *this = other;
}

// Destructeur
template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

// Opérateur d'affectation
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        if (_size > 0) {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; i++) {
                _data[i] = other._data[i];
            }
        } else {
            _data = NULL;
        }
    }
    return *this;
}

// Opérateur d'accès aux éléments
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::exception();
    }
    return _data[index];
}

// Opérateur d'accès aux éléments (version const)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::exception();
    }
    return _data[index];
}

// Fonction membre size()
template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif