#pragma once

namespace Remc
{
	typedef enum class KeyCode : uint16_t
	{
		// From glfw3.h
		Space               = 32,
		Apostrophe          = 39, /* ' */
		Comma               = 44, /* , */
		Minus               = 45, /* - */
		Period              = 46, /* . */
		Slash               = 47, /* / */

		D0                  = 48, /* 0 */
		D1                  = 49, /* 1 */
		D2                  = 50, /* 2 */
		D3                  = 51, /* 3 */
		D4                  = 52, /* 4 */
		D5                  = 53, /* 5 */
		D6                  = 54, /* 6 */
		D7                  = 55, /* 7 */
		D8                  = 56, /* 8 */
		D9                  = 57, /* 9 */

		Semicolon           = 59, /* ; */
		Equal               = 61, /* = */

		A                   = 65,
		B                   = 66,
		C                   = 67,
		D                   = 68,
		E                   = 69,
		F                   = 70,
		G                   = 71,
		H                   = 72,
		I                   = 73,
		J                   = 74,
		K                   = 75,
		L                   = 76,
		M                   = 77,
		N                   = 78,
		O                   = 79,
		P                   = 80,
		Q                   = 81,
		R                   = 82,
		S                   = 83,
		T                   = 84,
		U                   = 85,
		V                   = 86,
		W                   = 87,
		X                   = 88,
		Y                   = 89,
		Z                   = 90,

		LeftBracket         = 91,  /* [ */
		Backslash           = 92,  /* \ */
		RightBracket        = 93,  /* ] */
		GraveAccent         = 96,  /* ` */

		World1              = 161, /* non-US #1 */
		World2              = 162, /* non-US #2 */

		/* Function keys */
		Escape              = 256,
		Enter               = 257,
		Tab                 = 258,
		Backspace           = 259,
		Insert              = 260,
		Delete              = 261,
		Right               = 262,
		Left                = 263,
		Down                = 264,
		Up                  = 265,
		PageUp              = 266,
		PageDown            = 267,
		Home                = 268,
		End                 = 269,
		CapsLock            = 280,
		ScrollLock          = 281,
		NumLock             = 282,
		PrintScreen         = 283,
		Pause               = 284,
		F1                  = 290,
		F2                  = 291,
		F3                  = 292,
		F4                  = 293,
		F5                  = 294,
		F6                  = 295,
		F7                  = 296,
		F8                  = 297,
		F9                  = 298,
		F10                 = 299,
		F11                 = 300,
		F12                 = 301,
		F13                 = 302,
		F14                 = 303,
		F15                 = 304,
		F16                 = 305,
		F17                 = 306,
		F18                 = 307,
		F19                 = 308,
		F20                 = 309,
		F21                 = 310,
		F22                 = 311,
		F23                 = 312,
		F24                 = 313,
		F25                 = 314,

		/* Keypad */
		KP0                 = 320,
		KP1                 = 321,
		KP2                 = 322,
		KP3                 = 323,
		KP4                 = 324,
		KP5                 = 325,
		KP6                 = 326,
		KP7                 = 327,
		KP8                 = 328,
		KP9                 = 329,
		KPDecimal           = 330,
		KPDivide            = 331,
		KPMultiply          = 332,
		KPSubtract          = 333,
		KPAdd               = 334,
		KPEnter             = 335,
		KPEqual             = 336,

		LeftShift           = 340,
		LeftControl         = 341,
		LeftAlt             = 342,
		LeftSuper           = 343,
		RightShift          = 344,
		RightControl        = 345,
		RightAlt            = 346,
		RightSuper          = 347,
		Menu                = 348
	} Key;

	inline std::ostream& operator<<(std::ostream& os, KeyCode keyCode)
	{
		os << static_cast<int32_t>(keyCode);
		return os;
	}
}

// From glfw3.h
#define REMC_KEY_SPACE           ::Remc::Key::Space
#define REMC_KEY_APOSTROPHE      ::Remc::Key::Apostrophe    /* ' */
#define REMC_KEY_COMMA           ::Remc::Key::Comma         /* , */
#define REMC_KEY_MINUS           ::Remc::Key::Minus         /* - */
#define REMC_KEY_PERIOD          ::Remc::Key::Period        /* . */
#define REMC_KEY_SLASH           ::Remc::Key::Slash         /* / */
#define REMC_KEY_0               ::Remc::Key::D0
#define REMC_KEY_1               ::Remc::Key::D1
#define REMC_KEY_2               ::Remc::Key::D2
#define REMC_KEY_3               ::Remc::Key::D3
#define REMC_KEY_4               ::Remc::Key::D4
#define REMC_KEY_5               ::Remc::Key::D5
#define REMC_KEY_6               ::Remc::Key::D6
#define REMC_KEY_7               ::Remc::Key::D7
#define REMC_KEY_8               ::Remc::Key::D8
#define REMC_KEY_9               ::Remc::Key::D9
#define REMC_KEY_SEMICOLON       ::Remc::Key::Semicolon     /* ; */
#define REMC_KEY_EQUAL           ::Remc::Key::Equal         /* = */
#define REMC_KEY_A               ::Remc::Key::A
#define REMC_KEY_B               ::Remc::Key::B
#define REMC_KEY_C               ::Remc::Key::C
#define REMC_KEY_D               ::Remc::Key::D
#define REMC_KEY_E               ::Remc::Key::E
#define REMC_KEY_F               ::Remc::Key::F
#define REMC_KEY_G               ::Remc::Key::G
#define REMC_KEY_H               ::Remc::Key::H
#define REMC_KEY_I               ::Remc::Key::I
#define REMC_KEY_J               ::Remc::Key::J
#define REMC_KEY_K               ::Remc::Key::K
#define REMC_KEY_L               ::Remc::Key::L
#define REMC_KEY_M               ::Remc::Key::M
#define REMC_KEY_N               ::Remc::Key::N
#define REMC_KEY_O               ::Remc::Key::O
#define REMC_KEY_P               ::Remc::Key::P
#define REMC_KEY_Q               ::Remc::Key::Q
#define REMC_KEY_R               ::Remc::Key::R
#define REMC_KEY_S               ::Remc::Key::S
#define REMC_KEY_T               ::Remc::Key::T
#define REMC_KEY_U               ::Remc::Key::U
#define REMC_KEY_V               ::Remc::Key::V
#define REMC_KEY_W               ::Remc::Key::W
#define REMC_KEY_X               ::Remc::Key::X
#define REMC_KEY_Y               ::Remc::Key::Y
#define REMC_KEY_Z               ::Remc::Key::Z
#define REMC_KEY_LEFT_BRACKET    ::Remc::Key::LeftBracket   /* [ */
#define REMC_KEY_BACKSLASH       ::Remc::Key::Backslash     /* \ */
#define REMC_KEY_RIGHT_BRACKET   ::Remc::Key::RightBracket  /* ] */
#define REMC_KEY_GRAVE_ACCENT    ::Remc::Key::GraveAccent   /* ` */
#define REMC_KEY_WORLD_1         ::Remc::Key::World1        /* non-US #1 */
#define REMC_KEY_WORLD_2         ::Remc::Key::World2        /* non-US #2 */

/* Function keys */
#define REMC_KEY_ESCAPE          ::Remc::Key::Escape
#define REMC_KEY_ENTER           ::Remc::Key::Enter
#define REMC_KEY_TAB             ::Remc::Key::Tab
#define REMC_KEY_BACKSPACE       ::Remc::Key::Backspace
#define REMC_KEY_INSERT          ::Remc::Key::Insert
#define REMC_KEY_DELETE          ::Remc::Key::Delete
#define REMC_KEY_RIGHT           ::Remc::Key::Right
#define REMC_KEY_LEFT            ::Remc::Key::Left
#define REMC_KEY_DOWN            ::Remc::Key::Down
#define REMC_KEY_UP              ::Remc::Key::Up
#define REMC_KEY_PAGE_UP         ::Remc::Key::PageUp
#define REMC_KEY_PAGE_DOWN       ::Remc::Key::PageDown
#define REMC_KEY_HOME            ::Remc::Key::Home
#define REMC_KEY_END             ::Remc::Key::End
#define REMC_KEY_CAPS_LOCK       ::Remc::Key::CapsLock
#define REMC_KEY_SCROLL_LOCK     ::Remc::Key::ScrollLock
#define REMC_KEY_NUM_LOCK        ::Remc::Key::NumLock
#define REMC_KEY_PRINT_SCREEN    ::Remc::Key::PrintScreen
#define REMC_KEY_PAUSE           ::Remc::Key::Pause
#define REMC_KEY_F1              ::Remc::Key::F1
#define REMC_KEY_F2              ::Remc::Key::F2
#define REMC_KEY_F3              ::Remc::Key::F3
#define REMC_KEY_F4              ::Remc::Key::F4
#define REMC_KEY_F5              ::Remc::Key::F5
#define REMC_KEY_F6              ::Remc::Key::F6
#define REMC_KEY_F7              ::Remc::Key::F7
#define REMC_KEY_F8              ::Remc::Key::F8
#define REMC_KEY_F9              ::Remc::Key::F9
#define REMC_KEY_F10             ::Remc::Key::F10
#define REMC_KEY_F11             ::Remc::Key::F11
#define REMC_KEY_F12             ::Remc::Key::F12
#define REMC_KEY_F13             ::Remc::Key::F13
#define REMC_KEY_F14             ::Remc::Key::F14
#define REMC_KEY_F15             ::Remc::Key::F15
#define REMC_KEY_F16             ::Remc::Key::F16
#define REMC_KEY_F17             ::Remc::Key::F17
#define REMC_KEY_F18             ::Remc::Key::F18
#define REMC_KEY_F19             ::Remc::Key::F19
#define REMC_KEY_F20             ::Remc::Key::F20
#define REMC_KEY_F21             ::Remc::Key::F21
#define REMC_KEY_F22             ::Remc::Key::F22
#define REMC_KEY_F23             ::Remc::Key::F23
#define REMC_KEY_F24             ::Remc::Key::F24
#define REMC_KEY_F25             ::Remc::Key::F25

/* Keypad */
#define REMC_KEY_KP_0            ::Remc::Key::KP0
#define REMC_KEY_KP_1            ::Remc::Key::KP1
#define REMC_KEY_KP_2            ::Remc::Key::KP2
#define REMC_KEY_KP_3            ::Remc::Key::KP3
#define REMC_KEY_KP_4            ::Remc::Key::KP4
#define REMC_KEY_KP_5            ::Remc::Key::KP5
#define REMC_KEY_KP_6            ::Remc::Key::KP6
#define REMC_KEY_KP_7            ::Remc::Key::KP7
#define REMC_KEY_KP_8            ::Remc::Key::KP8
#define REMC_KEY_KP_9            ::Remc::Key::KP9
#define REMC_KEY_KP_DECIMAL      ::Remc::Key::KPDecimal
#define REMC_KEY_KP_DIVIDE       ::Remc::Key::KPDivide
#define REMC_KEY_KP_MULTIPLY     ::Remc::Key::KPMultiply
#define REMC_KEY_KP_SUBTRACT     ::Remc::Key::KPSubtract
#define REMC_KEY_KP_ADD          ::Remc::Key::KPAdd
#define REMC_KEY_KP_ENTER        ::Remc::Key::KPEnter
#define REMC_KEY_KP_EQUAL        ::Remc::Key::KPEqual

#define REMC_KEY_LEFT_SHIFT      ::Remc::Key::LeftShift
#define REMC_KEY_LEFT_CONTROL    ::Remc::Key::LeftControl
#define REMC_KEY_LEFT_ALT        ::Remc::Key::LeftAlt
#define REMC_KEY_LEFT_SUPER      ::Remc::Key::LeftSuper
#define REMC_KEY_RIGHT_SHIFT     ::Remc::Key::RightShift
#define REMC_KEY_RIGHT_CONTROL   ::Remc::Key::RightControl
#define REMC_KEY_RIGHT_ALT       ::Remc::Key::RightAlt
#define REMC_KEY_RIGHT_SUPER     ::Remc::Key::RightSuper
#define REMC_KEY_MENU            ::Remc::Key::Menu
