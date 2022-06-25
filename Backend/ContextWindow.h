#ifndef CONTEXTWINDOW_H
#define CONTEXTWINDOW_H

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include <stdio.h>          // printf, fprintf
#include <stdlib.h>         // abort
#define GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <vulkan/vulkan.h>

#include <mutex>


class ContextWindow
{
public:
	ContextWindow();
	int Init();
	int Run();
	void Deinit();
	~ContextWindow();
private:
	VkAllocationCallbacks* g_Allocator = NULL;
	VkInstance               g_Instance = VK_NULL_HANDLE;
	VkPhysicalDevice         g_PhysicalDevice = VK_NULL_HANDLE;
	VkDevice                 g_Device = VK_NULL_HANDLE;
	uint32_t                 g_QueueFamily = (uint32_t)-1;
	VkQueue                  g_Queue = VK_NULL_HANDLE;
	VkDebugReportCallbackEXT g_DebugReport = VK_NULL_HANDLE;
	VkPipelineCache          g_PipelineCache = VK_NULL_HANDLE;
	VkDescriptorPool         g_DescriptorPool = VK_NULL_HANDLE;
	ImGui_ImplVulkanH_Window g_MainWindowData;
	int                      g_MinImageCount = 2;
	bool                     g_SwapChainRebuild = false;

	VkResult err;
	GLFWwindow* window;
	ImGui_ImplVulkanH_Window* wd;

	//
	static void check_vk_result(VkResult err);
	void SetupVulkan(const char** extensions, uint32_t extensions_count);
	void SetupVulkanWindow(ImGui_ImplVulkanH_Window* wd, VkSurfaceKHR surface, int width, int height);
	void CleanupVulkan();
	void CleanupVulkanWindow();
	void FrameRender(ImGui_ImplVulkanH_Window* wd, ImDrawData* draw_data);
	void FramePresent(ImGui_ImplVulkanH_Window* wd);
	static void glfw_error_callback(int error, const char* description);


};

#endif //CONTEXTWINDOW_H