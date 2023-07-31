#include "rcpch.h"
#include "Remc/Renderer/VertexArray.h"

#include "Remc/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Remc
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    REMC_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		REMC_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}