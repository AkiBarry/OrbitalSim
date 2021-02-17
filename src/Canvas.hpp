#pragma once

#include <d3dx9.h>
#include <d3d9.h>
#include <string>
#include "Vector.hpp"
#include "Colour.hpp"
#include <SFML/Graphics.hpp>

namespace NCanvas
{
	void Text(std::string print_string, size_t size, const CVec2& position, CColour colour, CColour outline_colour, bool bold = false, float outline_thickness = 0.f);

	void Rect(const CVec2& position, const CVec2& size, CColour colour);

	void Circle(const CVec2& position, float size, CColour colour);

	void Line(const CVec2& position_1, const CVec2& position_2, CColour colour);

	void OutlinedRect(const CVec2& position, const CVec2& size, CColour rect_colour, CColour outline_colour);

	void Box(const CVec3& position, const CVec3& size, CColour colour);

	inline size_t screen_width, screen_height;

	inline sf::RenderWindow * Win;
};
