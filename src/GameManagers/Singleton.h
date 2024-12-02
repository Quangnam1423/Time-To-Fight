#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <memory>

class Singleton
{   
public:
    //constructor
    Singleton();

    //destructor

    virtual ~Singleton() = default;
    // delete constructor
    Singleton(const Singleton&) = delete;

    // delete operator = to prevent copying instance
    Singleton& operator = (const Singleton&) = delete;

    // delete constructor;
    static Singleton& getInstance();

private:
    static Singleton* m_instance;
};

#endif