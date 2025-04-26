#pragma once

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <set>

#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "VertexBuffer/VertexBuffer.h"
#include "IndexBuffer/IndexBuffer.h"
#include "Log.h"
#include "VulkanUtils.h"

class Sk8ViewApp
{
public:
    void run();

private:
    const char *m_appName = "Sk8View";
    const int m_width = 1280;
    const int m_height = 720;
    const int m_xpos = SDL_WINDOWPOS_CENTERED;
    const int m_ypos = SDL_WINDOWPOS_CENTERED;
    const int m_maxFramesInFlight = 2;

    SDL_Window *m_window = nullptr;
    bool m_running = true;

    // Vulkan related variables
    const bool m_useValLayers = true;
    int m_currentFrame = 0;
    VkInstance m_vInstance = VK_NULL_HANDLE;
    VkDebugUtilsMessengerEXT m_debugMessenger = VK_NULL_HANDLE;

    VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
    VkDevice m_device = VK_NULL_HANDLE;
    VkQueue m_graphicsQueue = VK_NULL_HANDLE;
    VkSurfaceKHR m_surface = VK_NULL_HANDLE;
    VkQueue m_presentQueue = VK_NULL_HANDLE;
    VkSwapchainKHR m_swapChain = VK_NULL_HANDLE;
    VkRenderPass m_renderPass = VK_NULL_HANDLE;
    VkPipelineLayout m_pipelineLayout = VK_NULL_HANDLE;
    VkPipeline m_graphicsPipeline = VK_NULL_HANDLE;
    VkCommandPool m_commandPool = VK_NULL_HANDLE;

    std::vector<VkCommandBuffer> m_commandBuffers = {};
    std::vector<VkSemaphore> m_imageAvailableSemaphores = {};
    std::vector<VkSemaphore> m_renderFinishedSemaphores = {};
    std::vector<VkFence> m_inFlightFences = {};
    std::vector<VkImage> m_swapChainImages = {};
    std::vector<VkImageView> m_swapChainImageViews = {};
    std::vector<VkFramebuffer> m_swapChainFramebuffers = {};

    VkFormat m_swapChainImageFormat = VK_FORMAT_UNDEFINED;
    VkExtent2D m_swapChainExtent = {};

    const std::vector<const char *> m_validationLayers = {
        "VK_LAYER_KHRONOS_validation",
    };

    const std::vector<const char *> m_deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME,
    };

    bool initWindow();
    bool initVulkan();
    bool checkValidationLayerSupport();

    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);

    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    VkShaderModule createShaderModule(const std::vector<char> &code);

    void createInstance();
    void createLogicalDevice();
    void createSurface();
    void createSwapChain();
    void createImageViews();
    void createGraphicsPipeline();
    void createRenderPass();
    void createFramebuffers();
    void createCommandPool();
    void createCommandBuffer();
    void createSyncObjects();

    void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

    void drawFrame();
    void pickPhysicalDevice();
    void setupDebugMessenger();
    void sdlEventFlush();
    void mainLoop();
    void cleanup();
};