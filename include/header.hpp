// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#define STACK_UNDERFLOW -2

#include <cstdlib>
#include <iostream>
#include <new>

using std::cout;
using std::endl;

template <typename T>
class stack
{
private:
    T *stackPtr;    // указатель на стек
    int count;      // размер стека (количество элементов в стеке)

public:
    stack() {       // конструктор
        stackPtr = nullptr;
        count = 0;
    }

    ~stack() {       // деструктор
        delete[] stackPtr;  // удаляем стек
    }

    void push(T&& value) {
        cout << "Значение" << endl;
        T* tmpPtr;             // временный указатель
        tmpPtr = stackPtr;     // указатель указывает на arrStack
        stackPtr = new T[count + 1];    // выделить память на 1 элемент больше, чем было выделено до этого
        count++;            // увеличить количество элементов в стеке на 1

        for (int i = 0; i < count - 1; i++) {
            stackPtr[i] = tmpPtr[i];   // скопировать данные из памяти, на которую указывает tmp в память, на которую указывает arrStack
        }
        stackPtr[count - 1] = value;    // добавить последний элемент

        if (count > 1) delete[] tmpPtr;    // освободить память, удалить tmp
    }

    void push(const T& value) {
        cout << "Переменная" << endl;
        T* tmpPtr;             // временный указатель
        tmpPtr = stackPtr;     // указатель указывает на arrStack
        stackPtr = new T[count + 1];    // выделить память на 1 элемент больше, чем было выделено до этого
        count++;            // увеличить количество элементов в стеке на 1

        for (int i = 0; i < count - 1; i++) {
            stackPtr[i] = tmpPtr[i];   // скопировать данные из памяти, на которую указывает tmp в память, на которую указывает arrStack
        }
        stackPtr[count - 1] = value;    // добавить последний элемент

        if (count > 1) delete[] tmpPtr;    // освободить память, удалить tmp
    }

    void pop() {
        if (count == 0) {
            cout << "stack underflow" << endl;
            exit(STACK_UNDERFLOW);
        }

        T *tmpPtr;             // временный указатель
        tmpPtr = stackPtr;     // указатель указывает на arrStack
        stackPtr = new T[count - 1];    // выделить память на 1 элемент меньше, чем было выделено до этого
        count--;            // уменьшить количество элементов в стеке на 1

        for (int i = 0; i < count - 1; i++) {
            stackPtr[i] = tmpPtr[i];   // скопировать данные из памяти, на которую указывает tmp в память, на которую указывает arrStack
        }

        if (count > 1) delete[] tmpPtr;    // освободить память, удалить tmp
    }

    const T& head() const {
        if (count == 0) {
            cout << "stack underflow" << endl;
            exit(STACK_UNDERFLOW);
        }
        return stackPtr[count-1];
    }
};

#endif // INCLUDE_HEADER_HPP_
