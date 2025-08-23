#pragma once

#include "Core.h"

namespace engine
{
    class ENGINE_API Application
    {
    public:
        Application();
        virtual ~Application();
        
        void Run();
    };

    // TO be defined in CLIENT
    Application* CreateApplication();
}