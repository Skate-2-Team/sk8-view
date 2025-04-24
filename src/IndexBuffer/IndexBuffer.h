#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <cstring>

#include "../BufferUtils/BufferUtils.h"

class IndexBuffer
{
public:
    IndexBuffer(VkDevice device, VkPhysicalDevice physicalDevice,
        VkCommandPool commandPool, VkQueue graphicsQueue,
        const std::vector<uint32_t>& indices,
        VkBuffer& indexBuffer, VkDeviceMemory& indexBufferMemory);
	~IndexBuffer();
};
