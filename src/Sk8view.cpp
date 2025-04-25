#include "Sk8view.h"

void Sk8ViewApp::run()
{
    if (initWindow() && initVulkan())
    {
        mainLoop();
        cleanup();
    }
}

bool Sk8ViewApp::initWindow()
{
    Log::Info("Sk8ViewApp", "Initializing SDL2 window...");

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        Log::Error("Sk8ViewApp", "SDL_Init failed: " + std::string(SDL_GetError()));
        return false;
    }

    m_window = SDL_CreateWindow(
        APP_NAME,
        APP_XPOS,
        APP_YPOS,
        APP_WIDTH, APP_HEIGHT,
        SDL_WINDOW_VULKAN | SDL_WINDOW_SHOWN);

    if (!m_window)
    {
        Log::Error("Sk8ViewApp", "SDL_CreateWindow failed: " + std::string(SDL_GetError()));
        return false;
    }

    return true;
}

bool Sk8ViewApp::initVulkan()
{
    Log::Info("Sk8ViewApp", "Initializing Vulkan...");

    // In reality we need to set up:

    /*

    Swapchain
    Render Pass
    Framebuffers
    Command Buffers
    Graphics Pipeline
    etc
    etc

    */

    return true;
}

void Sk8ViewApp::sdlEventFlush()
{
    SDL_Event e;

    while (SDL_PollEvent(&e))
    {
        if (e.type == SDL_QUIT)
            m_running = false;
    }
}

void Sk8ViewApp::mainLoop()
{
    Log::Info("Sk8ViewApp", "Entering main loop...");

    while (m_running)
    {
        sdlEventFlush();
    }
}

void Sk8ViewApp::cleanup()
{
    Log::Info("Sk8ViewApp", "Cleaning up...");

    SDL_DestroyWindow(m_window);
    SDL_Quit();
}
