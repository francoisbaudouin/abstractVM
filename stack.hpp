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

        T& getNode(int pos) const;
        int size() const;

        void push(const T& value);
        void pop();
        void clear();
        void dup();
        void swap();
        void dump() const;
        bool assert(T) const;
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        // load v
        // store v
        // print
        // exit
    private:
        Node<T>* CreateNode(const T& value);
        Node<T>* _top;
        int _compt;
};

#endif /* !STACK_HPP_ */
