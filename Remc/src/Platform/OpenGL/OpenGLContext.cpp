#include "rcpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW\glfw3.h>
#include <GLad/glad.h>
#include <gl/GL.h>

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

		#ifdef REMC_ENABLE_ASSERTS
				int versionMajor;
				int versionMinor;
				glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
				glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

				REMC_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Remc requires at least OpenGL version 4.5!");
		#endif
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