#include "VertexBuffer.h"

VertexBuffer::VertexBuffer()
{
}

void VertexBuffer::createVertexBuffer(VkDevice device, VkPhysicalDevice physicalDevice,
                                      VkCommandPool commandPool, VkQueue graphicsQueue,
                                      const std::vector<Vertex> &vertices,
                                      VkBuffer &vertexBuffer, VkDeviceMemory &vertexBufferMemory)
{

    VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

    // 1. Create staging buffer
    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    createBuffer(device, physicalDevice, bufferSize,
                 VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
                 VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
                 stagingBuffer, stagingBufferMemory);

    // 2. Copy vertex data
    void *data;
    vkMapMemory(device, stagingBufferMemory, 0, bufferSize, 0, &data);
    memcpy(data, vertices.data(), (size_t)bufferSize);
    vkUnmapMemory(device, stagingBufferMemory);

    // 3. Create device-local buffer
    createBuffer(device, physicalDevice, bufferSize,
                 VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
                 VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
                 vertexBuffer, vertexBufferMemory);

    // 4. Copy from staging to GPU
    copyBuffer(device, commandPool, graphicsQueue, stagingBuffer, vertexBuffer, bufferSize);

    // 5. Cleanup staging
    vkDestroyBuffer(device, stagingBuffer, nullptr);
    vkFreeMemory(device, stagingBufferMemory, nullptr);
}

VertexBuffer::~VertexBuffer()
{
}
