#pragma once
#include <cstdint>
#include <SFML/Graphics/Color.hpp>

class CHSB;

class CColour
{
public:

	uint8_t				r, g, b, a;

						CColour() :	r(0), g(0), b(0), a(0) {}

						CColour(const int x, const int y, const int z) 
							: r(static_cast<uint8_t>(x)), g(static_cast<uint8_t>(y)), b(static_cast<uint8_t>(z)), a(255) {}

						CColour(const int x, const int y, const int z, int w) 
							: r(static_cast<uint8_t>(x)), g(static_cast<uint8_t>(y)), b(static_cast<uint8_t>(z)), a(static_cast<uint8_t>(w)) {}

						CColour(const uint32_t c);

	uint8_t &			operator[](const int i);
	uint8_t				operator[](const int i) const;

	uint8_t *			Base();
	uint8_t const *		Base() const;

	void				CopyToArray(uint8_t* c) const;

	CColour &			operator=(const CColour c);

	bool				operator==(const CColour c) const;
	bool				operator!=(const CColour c) const;

	uint32_t			ToD3DColour() const;
	sf::Color			ToSFColour() const;
	CHSB				ToHSB() const;

	uint32_t &			AsRawColour();
	const uint32_t &	AsRawColour() const;

	float				Hue() const;
	float				Saturation() const;
	float				Brightness() const;

	static CColour		Black;
	static CColour		White;
	static CColour		Red;
	static CColour		Green;
	static CColour		Blue;
	static CColour		Yellow;
	static CColour		Cyan;
	static CColour		Magneta;
};

class CHSB
{
public:

	float			h, s, b;

					CHSB() : h(0.0f), s(0.0f), b(0.0f) {}

					CHSB(const float x, const float y, const float z) : h(x), s(y), b(z) {}

	float &			operator[](const int i);
	float			operator[](const int i) const;

	float *			Base();
	float const *	Base() const;

	void			CopyToArray(float* f) const;

	CHSB &			operator=(const CHSB c);

	bool			operator==(const CHSB c) const;
	bool			operator!=(const CHSB c) const;

	CColour			ToColour() const;
};
