/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <vector>
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node <T>* next;
    Node <T>* prev;
};

template <typename T>
class Liste {
    public:
        Liste();
        ~Liste();
        void push(const T& value);
        void pop();
        T& getNode(int pos) const;
        void show() const;
        int size() const;
    private:
        Node<T>* CreateNode(const T& value);
        Node<T>* _top;
        int _compt;
};

#endif /* !STACK_HPP_ */
