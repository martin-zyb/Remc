#pragma once

#include <glm/glm.hpp>

#include "Remc/Core/KeyCodes.h"
#include "Remc/Core/MouseCodes.h"

namespace Remc {

	class REMC_API Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};

}