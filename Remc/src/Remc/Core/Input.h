#pragma once

#include "Remc/Core/Base.h"

#include "Remc/Core/KeyCodes.h"
#include "Remc/Core/MouseCodes.h"

namespace Remc {

	class REMC_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}