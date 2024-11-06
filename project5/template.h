#pragma once

// class template
template <class T>
class StaticStack {
    private:
        T *stackArray;
        int capacity;
        int top;
    public:
        StaticStack(int capacity) // constructor
            : capacity(capacity), top(0) { // initializer list
            stackArray = new T[capacity];
        }
        
        ~StaticStack() { // destructor
            delete[] stackArray;
        }

        // member functions
        void push(T value) { // add value to top
            if (top == capacity) throw Overflow();
            stackArray[top++] = value;
        }

        void pop(T &value) { // remove value at top of stack
            if (isEmpty()) throw Underflow();
            value = stackArray[--top];
        }

        bool isEmpty() const { // check if stack is empty
            return top == 0;
        }

        int getCapacity() const { // get capacity from private
            return capacity;
        }

        // exception classes
        class Overflow {};
        class Underflow {};
};