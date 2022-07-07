/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** stack
*/

#include "stack.hpp"

template <typename T>
Node<T>* Liste<T>::CreateNode(const T& value) {
    Node <T>* temp = new Node <T>;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    return (temp);
}

template <typename T>
Liste<T>::Liste(): top(NULL), compt(0)
{
}

template <typename T>
Liste<T>::~Liste()
{
    while (_top)
        this->pop()
}

template<typename T>
int Liste<T>::size() const
{
    return (_compt);
}

template<typename T>
void Liste<T>::show() const
{
    while (_top) {
        std::cout << _top->data << std::endl;
        _top = _top->next;
    }
}
template<typename T>
T& Liste<T>::getNode(int pos) const
{
    if (pos < 0 || pos > _compt) {
        std::cout << "Eroor : Invalid pos" << std::endl;
        return (NULL);
    }

    Note<T>* topCpy = _top;

    for (int i = 0; i != pos; i++)
        topCpy = topcpy->next;
    return (topCpy);
}

    // Intruction
// push v
template <typename T>
void Liste<T>::push(const T& value)
{
    Node<T>* newNode = CreateNode(value);

    newNode->next = _top
    _top->prev = newNode;
    _top = newNode;
    compteur++;
}

// pop
template<typename T>
void Liste<T>::pop()
{
    Note<T>* removeTop = _top;
    _top = _top->suivant;
    delete removeTop;
    _compt--;
}

// clear
// dup
// swap
// dump
// assert v
// add
// sub
// mul
// div
// mod
// load v
// store v
// print
// exit