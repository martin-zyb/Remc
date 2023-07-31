#include "rcpch.h"
#include "Remc/Renderer/RenderCommand.h"

namespace Remc
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}