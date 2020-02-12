// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <cstdlib>
#include <iostream>
#include <new>

using std::cout;
using std::endl;

template <typename T>
class stack
{
private:
    T* arrStack;    // Динамический масив-указатель на стек
    int count;      // Вершина стека - количество элементов типа T в стеке

public:

    stack() {       // конструктор
        arrStack = nullptr;
        count = 0;  // количество элементов в стеке определяется по значению count
    }


    void push(T &&value)    // Помещаем элемент в стек
    {
        T* tmp; // временный указатель
        // блок try необходим для перехвата исключения, если память не выделится

            tmp = arrStack; // указатель указывает на arrStack
            arrStack = new T[count + 1];    // выделить память на 1 элемент больше, чем было выделено до этого
            count++;    // увеличить количество элементов в стеке на 1

            for (int i = 0; i < count - 1; i++) {
                arrStack[i] = tmp[i];   // скопировать данные из памяти, на которую указывает tmp в память, на которую указывает arrStack
            }

            arrStack[count - 1] = value;    // добавить последний элемент

            // освободить память, выделенную перед этим для arrStack,
            // на эту память указывает tmp
            if (count > 1)
                delete[] tmp;

    }

    void push(const T &value)
    {
        T* tmp; // временный указатель
        // блок try необходим для перехвата исключения, если память не выделится

            tmp = arrStack; // указатель указывает на arrStack
            arrStack = new T[count + 1];    // выделить память на 1 элемент больше, чем было выделено до этого
            count++;    // увеличить количество элементов в стеке на 1

            for (int i = 0; i < count - 1; i++) {
                arrStack[i] = tmp[i];   // скопировать данные из памяти, на которую указывает tmp в память, на которую указывает arrStack
            }

            arrStack[count - 1] = value;    // добавить последний элемент

            // освободить память, выделенную перед этим для arrStack,
            // на эту память указывает tmp
            if (count > 1)
                delete[] tmp;

    }


    // Вытащить элемент из стека (запопопать)
    // При вытягивании элемента из стека память не переопределяется
    T pop() {
        if (count == 0)
            return 0; // стек пуст
        count--;
        return arrStack[count];
    }

    // Просмотр элемента в вершине стека
    const T &head() const
    {
//        if (count == 0)
//            return 0;
        return arrStack[count - 1];
    }

    // Деструктор - освобождает память
    ~stack()
    {
        if (count > 0)
            delete[] arrStack;
    }

};

#endif // INCLUDE_HEADER_HPP_
