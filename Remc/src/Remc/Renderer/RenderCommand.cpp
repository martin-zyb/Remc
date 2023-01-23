#include "rcpch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Remc
{
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}