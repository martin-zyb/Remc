#pragma once

#include "rcpch.h"

#include "Remc/Core.h"
#include "Remc/Events/Event.h"

namespace Remc
{

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Remc Engine",
			unsigned int width = 1120,
			unsigned int height = 630)
			: Title(title), Width(width), Height(height) {}

	};

	// Interface representing a desktop system basic Window
	class REMC_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());

	};

}