#pragma once

#include "Remc/Layer.h"

#include "Remc/Events/KeyEvent.h"
#include "Remc/Events/MouseEvent.h"
#include "Remc/Events/ApplicationEvent.h"

namespace Remc
{

	class REMC_API ImGuiLayer : public Layer
	{
	private:
		float m_Time = 0.0f;

	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	};

}