#pragma once
#include <vulkan/vulkan.h>
#include <vector>
#include <cstring>

#include "../BufferUtils/BufferUtils.h"
#include "../Vertex/Vertex.h"

class VertexBuffer
{
public:
    VertexBuffer(VkDevice device, VkPhysicalDevice physicalDevice,
        VkCommandPool commandPool, VkQueue graphicsQueue,
        const std::vector<Vertex>& vertices,
        VkBuffer& vertexBuffer, VkDeviceMemory& vertexBufferMemory);
	~VertexBuffer();
};