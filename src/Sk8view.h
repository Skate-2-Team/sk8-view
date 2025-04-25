#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>

#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"
#include "Log.h"

#define APP_NAME "Sk8View"
#define APP_WIDTH 1280
#define APP_HEIGHT 720
#define APP_XPOS SDL_WINDOWPOS_CENTERED
#define APP_YPOS SDL_WINDOWPOS_CENTERED

class Sk8ViewApp
{
public:
    void run();

private:
    SDL_Window *m_window;
    bool m_running = true;

    bool initWindow();
    bool initVulkan();
    void sdlEventFlush();
    void mainLoop();
    void cleanup();
};