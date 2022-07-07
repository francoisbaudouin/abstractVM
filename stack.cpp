/*
** EPITECH PROJECT, 2022
** abstractVM
** File description:
** stack
*/

#include "stack.hpp"
#include <cassert>


int main ()
{
    Liste<int> linkedList;
    linkedList.push(1);
    linkedList.push(2);
    linkedList.push(3);
    linkedList.dump();
    std::cout << "size = " << linkedList.size() << std::endl;
    std::cout << std::endl;
    linkedList.pop();
    linkedList.dump();
    std::cout << "size = " << linkedList.size() << std::endl;
    std::cout << std::endl;
    linkedList.swap();
    linkedList.dump();
    std::cout << "size = " << linkedList.size() << std::endl;
    std::cout << std::endl;
    linkedList.dup();
    linkedList.dump();
    std::cout << "size = " << linkedList.size() << std::endl;
    std::cout << std::endl;
    linkedList.add();
    linkedList.dump();
    std::cout << "size = " << linkedList.size() << std::endl;
    std::cout << std::endl;
    linkedList.mod();
    linkedList.dump();
    std::cout << "size = " << linkedList.size() << std::endl;
    return 0;
}

template <typename T>
Node<T>* Liste<T>::CreateNode(const T& value) {
    Node <T>* temp = new Node <T>;
    temp->data = value;
    temp->next = NULL;
    temp->prev = NULL;
    return (temp);
}

template <typename T>
Liste<T>::Liste(): _top(NULL), _compt(0)
{
}

template <typename T>
Liste<T>::~Liste()
{
    while (_top)
        this->pop();
}

template<typename T>
int Liste<T>::size() const
{
    return (_compt);
}

template<typename T>
T& Liste<T>::getNode(int pos) const
{
    if (pos < 0 || pos > _compt) {
        std::cout << "Eroor : Invalid pos" << std::endl;
        return (NULL);
    }

    Node<T>* topCpy = _top;

    for (int i = 0; i != pos; i++)
        topCpy = topCpy->next;
    return (topCpy->data);
}

template <typename T>
void Liste<T>::push(const T& value)
{
    Node<T>* newNode = CreateNode(value);

    if (_top) {
        newNode->next = _top;
        _top->prev = newNode;
        _top = newNode;
    } else
        _top = CreateNode(value);
    _compt++;
}

template<typename T>
void Liste<T>::pop()
{
    Node<T>* removeTop = _top;
    _top = _top->next;
    delete removeTop;
    _compt--;
}

template <typename T>
void Liste<T>::clear()
{
    while (_top)
        this->pop();
    _compt = 0;
}

template <typename T>
void Liste<T>::dup()
{
    push(_top->data);
}

template <typename T>
void Liste<T>::swap()
{
    Node<T>* newNode1 = CreateNode(_top->data);
    Node<T>* newNode2 = CreateNode(_top->next->data);
    pop();
    pop();
    push(newNode1->data);
    push(newNode2->data);
}

template<typename T>
void Liste<T>::dump() const
{
    Node<T>* topCpy = _top;
    while (topCpy) {
        std::cout << topCpy->data << std::endl;
        if (topCpy->next)
            topCpy = topCpy->next;
        else
            break;
    }
}

// assert v

template <typename T>
void Liste<T>::add()
{
    Node<T>* newNode1 = CreateNode(_top->data);
    Node<T>* newNode2 = CreateNode(_top->next->data);
    pop();
    pop();
    push(newNode1->data + newNode2->data);
}

template <typename T>
void Liste<T>::sub()
{
    Node<T>* newNode1 = CreateNode(_top->data);
    Node<T>* newNode2 = CreateNode(_top->next->data);
    pop();
    pop();
    push(newNode1->data - newNode2->data);
}

template <typename T>
void Liste<T>::mul()
{
    Node<T>* newNode1 = CreateNode(_top->data);
    Node<T>* newNode2 = CreateNode(_top->next->data);
    pop();
    pop();
    push(newNode1->data * newNode2->data);
}

template <typename T>
void Liste<T>::div()
{
    Node<T>* newNode1 = CreateNode(_top->data);
    Node<T>* newNode2 = CreateNode(_top->next->data);
    pop();
    pop();
    push(newNode1->data / newNode2->data);
}

template <typename T>
void Liste<T>::mod()
{
    Node<T>* newNode1 = CreateNode(_top->data);
    Node<T>* newNode2 = CreateNode(_top->next->data);
    pop();
    pop();
    push(newNode1->data % newNode2->data);
}

// load v
// store v
// print
// exit