#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <memory>

template<typename T>
class Singleton
{   
public:
    static T* getInstance()
    {
        static T* instance;
        return instance;
    }
    // delete constructor
    Singleton(const Singleton&) = delete;

    // delete operator = to prevent copying instance
    Singleton& operator = (const Singleton&) = delete;

    // delete constructor;
    static Singleton& getInstance();
protected:
    //constructor
    Singleton() = default;
    //destructor
    virtual ~Singleton() = default;
};

#endif