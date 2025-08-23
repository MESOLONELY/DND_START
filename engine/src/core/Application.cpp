#include "Application.h"

#include <iostream>

namespace engine
{
    Application::Application()
    {
        std::cout << "Application created!" << std::endl;
    }

    Application::~Application()
    {
        std::cout << "Application destroyed!" << std::endl;
    }

    void Application::Run()
    {
        while(true)
        {
            
        }
    }

}
