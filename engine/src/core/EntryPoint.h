#pragma once

#ifdef PLATFORM_WINDOWS

class Sandbox;

extern engine::Application* engine::CreateApplication();

int main(int argc, char** argv)
{
    engine::Log::Init();
    ENGINE_CORE_WARN("Initialized Log!");
    int a = 5;
    ENGINE_INFO("Hello! Var={0}", a);
    
    auto app = engine::CreateApplication();
    app->Run();
    delete app;
}


#endif