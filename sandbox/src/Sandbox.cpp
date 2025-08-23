#include <Engine.h>

class Sandbox : public engine::Application
{
public:
    Sandbox()
    = default;

    ~Sandbox() override
    = default;
};

engine::Application* engine::CreateApplication()
{
    return new Sandbox();
}