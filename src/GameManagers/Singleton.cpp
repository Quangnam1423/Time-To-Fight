#include "Singleton.h"

Singleton* Singleton::m_instance = nullptr;

Singleton::Singleton()
{
    std::cout << "Singleton instance created" << std::endl;
}

Singleton &Singleton::getInstance()
{
    // TODO: insert return statement here
    return *m_instance;
}
