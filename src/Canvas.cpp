#include "Colour.hpp"
#include "Vector.hpp"
#include "Canvas.hpp"
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include "Math.hpp"

void NCanvas::Text(std::string print_string, size_t size, const CVec2& position, CColour colour, CColour outline_colour, bool bold /* = false */, float outline_thickness /* = 0.f*/)
{
	sf::Font temp_font;
	temp_font.loadFromFile("helvetica.ttf");

	const sf::Texture & texture = temp_font.getTexture(size);

	char prev_char = '\0';

	float advancement = 0;
	for (char c : print_string)
	{
		advancement += temp_font.getKerning(prev_char, c, size);

		if (outline_thickness != 0.f)
		{
			sf::Glyph glyph = temp_font.getGlyph(c, size, bold, outline_thickness);

			sf::Sprite sprite(texture, glyph.textureRect);
			sprite.setPosition(position.x + advancement + glyph.bounds.left - outline_thickness, position.y + glyph.bounds.top - outline_thickness);
			sprite.setColor(outline_colour.ToSFColour());

			Win->draw(sprite);
		}

		sf::Glyph glyph = temp_font.getGlyph(c, size, bold, 0.f);

		sf::Sprite sprite(texture, glyph.textureRect);
		sprite.setPosition(position.x + advancement + glyph.bounds.left, position.y + glyph.bounds.top);
		sprite.setColor(colour.ToSFColour());

		advancement += glyph.advance;

		Win->draw(sprite);

		prev_char = c;
	}
}


void NCanvas::Rect(const CVec2 & position, const CVec2 & size, CColour colour)
{
	static sf::RectangleShape Temp(sf::Vector2f(0.f, 0.f));
	Temp.setSize(sf::Vector2f(size.x, size.y));
	Temp.setPosition(position.x, position.y);
	Temp.setFillColor(sf::Color(colour.ToSFColour()));

	Win->draw(Temp);
}

void NCanvas::Circle(const CVec2 & position, float size, CColour colour)
{
	static sf::CircleShape Temp(0.f);
	Temp.setRadius(size);
	Temp.setPosition(position.x, position.y);
	Temp.setFillColor(sf::Color(colour.ToSFColour()));

	Win->draw(Temp);
}

void NCanvas::Line(const CVec2 & position_1, const CVec2 & position_2, CColour colour)
{
	static sf::RectangleShape Temp(sf::Vector2f(0.f, 0.f));

	CVec2 diff = position_2 - position_1;

	Temp.setSize(sf::Vector2f(1.f, diff.Length()));
	Temp.setPosition(position_1.x, position_1.y);
	Temp.setRotation(-90.f + CMath::RadToDeg(CMath::ATan2(diff.y, diff.x)));
	Temp.setFillColor(sf::Color(colour.ToSFColour()));

	Win->draw(Temp);
}

void NCanvas::OutlinedRect(const CVec2 & position, const CVec2 & size, CColour rectangle_colour, CColour outline_colour)
{
	static sf::RectangleShape Temp(sf::Vector2f(0.f, 0.f));
	Temp.setSize(sf::Vector2f(size.x, size.y));
	Temp.setPosition(position.x, position.y);
	Temp.setFillColor(sf::Color(rectangle_colour.ToSFColour()));
	Temp.setOutlineColor(sf::Color(outline_colour.ToSFColour()));
	Temp.setOutlineThickness(1.f);

	Win->draw(Temp);
}

void NCanvas::Box(const CVec3 & position, const  CVec3 & size, CColour colour) {}
