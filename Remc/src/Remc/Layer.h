#pragma once

#include "rcpch.h"

#include "Remc/Core.h"
#include "Remc/Events/Event.h"

namespace Remc
{

	class REMC_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

	protected:
		std::string m_DebugName;
	};

}