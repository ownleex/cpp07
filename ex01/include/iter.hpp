/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 23:35:53 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/26 00:28:42 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T* array, size_t length, void (*func)(T&)) {
    if (array == NULL || func == NULL)
        return ;
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}
#endif