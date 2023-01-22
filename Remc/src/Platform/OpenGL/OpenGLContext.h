#pragma once

#include "Remc\Renderer\GraphicsContext.h"

struct GLFWwindow;

namespace Remc
{
	class OpenGLContext : public GraphicsContext
	{
	private:
		GLFWwindow* m_WindowHandle;
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	};
}