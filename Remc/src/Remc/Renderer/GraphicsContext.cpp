#include "rcpch.h"
#include "Remc/Renderer/GraphicsContext.h"

#include "Remc/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Remc {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    REMC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		REMC_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}