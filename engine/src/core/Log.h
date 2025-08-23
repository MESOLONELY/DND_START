#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

namespace engine
{
    class ENGINE_API Log
    {
    public:
        static void Init();
        static std::shared_ptr<spdlog::logger>& Core()   { return s_CoreLogger; }
        static std::shared_ptr<spdlog::logger>& Client() { return s_ClientLogger; }
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;   
        static std::shared_ptr<spdlog::logger> s_ClientLogger; 
    };
    
}

// core log macros
#define ENGINE_CORE_FATAL(...)    ::engine::Log::Core()->fatal(__VA_ARGS__)
#define ENGINE_CORE_ERROR(...)    ::engine::Log::Core()->error(__VA_ARGS__)
#define ENGINE_CORE_WARN(...)     ::engine::Log::Core()->warn(__VA_ARGS__)
#define ENGINE_CORE_INFO(...)     ::engine::Log::Core()->info(__VA_ARGS__)
#define ENGINE_CORE_TRACE(...)    ::engine::Log::Core()->trace(__VA_ARGS__)

// core log macros
#define ENGINE_FATAL(...)    ::engine::Log::Client()->fatal(__VA_ARGS__)
#define ENGINE_ERROR(...)    ::engine::Log::Client()->error(__VA_ARGS__)
#define ENGINE_WARN(...)     ::engine::Log::Client()->warn(__VA_ARGS__)
#define ENGINE_INFO(...)     ::engine::Log::Client()->info(__VA_ARGS__)
#define ENGINE_TRACE(...)    ::engine::Log::Client()->trace(__VA_ARGS__)