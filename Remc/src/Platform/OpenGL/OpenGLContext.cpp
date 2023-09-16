#include "rcpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW\glfw3.h>
#include <GLad/glad.h>

namespace Remc
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		REMC_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		REMC_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		REMC_CORE_ASSERT(status, "Failed to initialize Glad!");
		REMC_CORE_INFO("OpenGL Info:");
		REMC_CORE_INFO("   Vendor: {0}", GLubyteToString(glGetString(GL_VENDOR)));
		REMC_CORE_INFO("   Renderer: {0}", GLubyteToString(glGetString(GL_RENDERER)));
		REMC_CORE_INFO("   Version: {0}", GLubyteToString(glGetString(GL_VERSION)));

		REMC_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Remc requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		REMC_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

	std::string OpenGLContext::GLubyteToString(const unsigned char* glbyte)
	{
		std::string str;
		str.append(reinterpret_cast<const char*>(glbyte));
		return str;
	}
}