#pragma once

namespace Remc
{
	typedef enum class MouseCode : uint16_t
	{
		// From glfw3.h
		Button0                = 0,
		Button1                = 1,
		Button2                = 2,
		Button3                = 3,
		Button4                = 4,
		Button5                = 5,
		Button6                = 6,
		Button7                = 7,

		ButtonLast             = Button7,
		ButtonLeft             = Button0,
		ButtonRight            = Button1,
		ButtonMiddle           = Button2
	} Mouse;
	
	inline std::ostream& operator<<(std::ostream& os, MouseCode mouseCode)
	{
		os << static_cast<int32_t>(mouseCode);
		return os;
	}
}

#define REMC_MOUSE_BUTTON_0      ::Remc::Mouse::Button0
#define REMC_MOUSE_BUTTON_1      ::Remc::Mouse::Button1
#define REMC_MOUSE_BUTTON_2      ::Remc::Mouse::Button2
#define REMC_MOUSE_BUTTON_3      ::Remc::Mouse::Button3
#define REMC_MOUSE_BUTTON_4      ::Remc::Mouse::Button4
#define REMC_MOUSE_BUTTON_5      ::Remc::Mouse::Button5
#define REMC_MOUSE_BUTTON_6      ::Remc::Mouse::Button6
#define REMC_MOUSE_BUTTON_7      ::Remc::Mouse::Button7
#define REMC_MOUSE_BUTTON_LAST   ::Remc::Mouse::ButtonLast
#define REMC_MOUSE_BUTTON_LEFT   ::Remc::Mouse::ButtonLeft
#define REMC_MOUSE_BUTTON_RIGHT  ::Remc::Mouse::ButtonRight
#define REMC_MOUSE_BUTTON_MIDDLE ::Remc::Mouse::ButtonMiddle
