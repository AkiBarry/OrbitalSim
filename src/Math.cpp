#include <math.h>
#include "Math.hpp"
#include "Matrix.hpp"
#include "Vector.hpp"
#include <cmath>

const float CMath::PI = 3.14159265358979323846f;
const float CMath::INV_PI = 1.0f / PI;
const float CMath::E = 2.71828182845904523536f;
const float CMath::EPSILON = 1.1754944e-038f;

uint64_t CMath::seed[2] = {987654321, 123456789};

uint64_t CMath::RotL(const uint64_t x, const int k)
{
	return (x << k) | (x >> (64 - k));
}

void CMath::RandSeed(const uint64_t a, const uint64_t b)
{
	seed[0] = a;
	seed[1] = b;
}

void CMath::RandSeed(const uint64_t x)
{
	seed[0] = x;
	seed[1] = x;
}

uint64_t CMath::Rand()
{
	uint64_t temp0 = seed[0];
	uint64_t temp1 = seed[1];
	uint64_t result = temp0 + temp1;

	temp1 ^= temp0;
	seed[0] = RotL(temp0, 55) ^ temp1 ^ (temp1 << 14);
	seed[1] = RotL(temp1, 36);
	return result;
}

int CMath::RandInt(const int min, const int max)
{
	return static_cast<int>(min + Rand() % (max - min + 1));
}

float CMath::RandFloat(const float min, const float max)
{
	float Frac = static_cast<float>(Rand()) / UINT64_MAX;
	return min + Frac * (max - min);
}

float CMath::Sin(const float f)
{
	return sinf(f);
}

double CMath::Sin(const double d)
{
	return sin(d);
}

float CMath::Cos(const float f)
{
	return cosf(f);
}

double CMath::Cos(const double d)
{
	return cos(d);
}

float CMath::Tan(const float f)
{
	return tanf(f);
}

double CMath::Tan(const double d)
{
	return tan(d);
}

void CMath::SinCos(const float f, float& s, float& c)
{
	s = Sin(f);
	c = Cos(f);
}

void CMath::SinCos(const double d, double& s, double& c)
{
	s = Sin(d);
	c = Cos(d);
}

float CMath::ASin(const float f)
{
	return asinf(f);
}

float CMath::ACos(const float f)
{
	return acosf(f);
}

float CMath::ATan(const float f)
{
	return atanf(f);
}

float CMath::ATan2(const float y, const float x)
{
	return atan2f(y, x);
}

float CMath::Sqrt(const float f)
{
	return sqrtf(f);
}

float CMath::Cbrt(const float f)
{
	return cbrtf(f);
}

float CMath::InvSqrt(const float f)
{
	return 1.0f / Sqrt(f);
}

float CMath::InvCbrt(const float f)
{
	return 1.0f / Cbrt(f);
}

float CMath::Exp(const float f)
{
	return expf(f);
}

float CMath::Ln(const float f)
{
	return logf(f);
}

float CMath::Pow(const float a, const float b)
{
	return powf(a, b);
}

float CMath::Mod(const float a, const float b)
{
	return fmodf(a, b);
}

float CMath::Floor(const float f)
{
	return floorf(f);
}

float CMath::Floor(const float f, const float radix)
{
	float temp = Pow(10.0f, radix);
	return floorf(f * temp) / temp;
}

float CMath::Ceil(const float f)
{
	return ceilf(f);
}

float CMath::Ceil(const float f, const float radix)
{
	float temp = Pow(10.0f, radix);
	return ceilf(f * temp) / temp;
}

float CMath::Trunc(const float f)
{
	return truncf(f);
}

float CMath::Trunc(const float f, const float radix)
{
	float temp = Pow(10.0f, radix);
	return truncf(f * temp) / temp;
}

float CMath::Round(const float f)
{
	return roundf(f);
}

float CMath::Round(const float f, const float radix)
{
	float temp = Pow(10.0f, radix);
	return roundf(f * temp) / temp;
}

bool CMath::IsNormal(const float f)
{
	uint32_t temp = *reinterpret_cast<const uint32_t*>(&f);
	return temp & 0x7f800000
		&& temp != 0x7f800000;
}

bool CMath::IsFinite(const float f)
{
	uint32_t temp = *reinterpret_cast<const uint32_t*>(&f);
	return (temp & 0x7f800000) != 0x7f800000;
}

bool CMath::IsNan(const float f)
{
	uint32_t temp = *reinterpret_cast<const uint32_t*>(&f);
	return (temp & 0x7f800000) == 0x7f800000
		&& temp & 0x7fffff;
}

bool CMath::IsInf(const float f)
{
	uint32_t a = *reinterpret_cast<const uint32_t*>(&f);

	return (a & 0x7f800000) == 0x7f800000
		&& !(a & 0x7fffff);
}

float CMath::Hypot(const float x, const float y)
{
	float absx = Abs(x);
	float absy = Abs(y);
	float absmax = Max(absx, absy);
	float absmin = Min(absx, absy);
	float ratio = absmin / absmax;

	return absmax * Sqrt(1.0f + ratio * ratio);
}

float CMath::Hypot(const float x, const float y, const float z)
{
	float absx = Abs(x);
	float absy = Abs(y);
	float absz = Abs(z);
	float absmax = Max(absx, Max(absy, absz));
	float altx = absx / absmax;
	float alty = absy / absmax;
	float altz = absz / absmax;

	return absmax * Sqrt(altx * altx + alty * alty + altz * altz);
}

void CMath::CVec3ToCAng(const CVec3& v, CAng& a)
{
	a.z = 0.0f;
	if (v.x == 0.0f && v.y == 0.0f)
	{
		a.x = v.z > 0.0f ? a.x = -90.0f : a.x = 90.0f;
		a.y = 0.0f;

		return;
	}
	a.x = -RadToDeg(ASin(v.z / (v.Length() + EPSILON)));
	a.y = RadToDeg(ATan2(v.y, v.x));
}

void CMath::CAngToCVec3(const CAng& a, CVec3* forward, CVec3* right, CVec3* up)
{
	float cx;
	float cy;
	float cz;
	float sx;
	float sy;
	float sz;

	SinCos(DegToRad(a.x), sx, cx);
	SinCos(DegToRad(a.y), sy, cy);
	SinCos(DegToRad(a.z), sz, cz);

	if (forward)
	{
		forward->x = sx * cy;
		forward->y = sx * sy;
		forward->z = cx;
	}

	if (right)
	{
		right->x = cx * sy;
		right->y = (sx * sy * sz) + (cy * cz);
		right->z = (sx * sy * cz) - (cy * sz);
	}

	if (up)
	{
		up->x = -sx;
		up->y = cx * sz;
		up->z = cx * cz;
	}
}

template <class T>
T CMath::Lerp(const T initial, const T final, const T factor)
{
	return initial + (final - initial) * factor;
}

float CMath::NormalizeAng360(float f)
{
	if ((f >= 360.0f) || (f < 0.0f))
	{
		f -= Floor(f * (1.0f / 360.0f)) * 360.0f;
	}
	return f;
}

float CMath::NormalizeAng180(float f)
{
	f = NormalizeAng360(f);
	if (f > 180.0f)
	{
		f -= 360.0f;
	}
	return f;
}

float CMath::AngleDelta(const float a, const float b)
{
	return NormalizeAng180(b - a);
}

float CMath::LerpAng(const float initial, const float final, const float factor)
{
	return initial + AngleDelta(initial, final) * factor;
}

float CMath::DegToRad(const float f)
{
	return f * PI / 180.0f;
}

float CMath::RadToDeg(const float f)
{
	return f * 180.0f / PI;
}

CMatrix2x3 CMath::AngToMatrix2x3(const float radians)
{
	CMatrix2x3 temp;

	float s, c;

	SinCos(radians, s, c);

	temp[0][0] = c;
	temp[0][1] = -s;
	temp[0][2] = 0.f;
	temp[1][0] = s;
	temp[1][1] = c;
	temp[1][2] = 0.f;

	return temp;
}

CVec2 CMath::Vec2Rotate(const CMatrix2x3& m, const CVec2& v)
{
	CVec2 temp;

	temp.x = v.Dot(CVec2(m[0][0], m[0][1]));
	temp.y = v.Dot(CVec2(m[1][0], m[1][1]));

	return temp;
}

CVec2 CMath::Vec2Transform(const CMatrix3x4& m, const CVec2& v)
{
	CVec2 temp;

	temp.x = v.Dot(CVec2(m[0][0], m[0][1])) + m[0][2];
	temp.y = v.Dot(CVec2(m[1][0], m[1][1])) + m[1][2];

	return temp;
}

CVec3 CMath::Vec3Rotate(const CMatrix3x4& m, const CVec3& v)
{
	CVec3 temp;

	temp.x = v.Dot(CVec3(m[0][0], m[0][1], m[0][2]));
	temp.y = v.Dot(CVec3(m[1][0], m[1][1], m[1][2]));
	temp.z = v.Dot(CVec3(m[2][0], m[2][1], m[2][2]));

	return temp;
}

CVec3 CMath::Vec3Transform(const CMatrix3x4& m, const CVec3& v)
{
	CVec3 temp;

	temp.x = v.Dot(CVec3(m[0][0], m[0][1], m[0][2])) + m[0][3];
	temp.y = v.Dot(CVec3(m[1][0], m[1][1], m[1][2])) + m[1][3];
	temp.z = v.Dot(CVec3(m[2][0], m[2][1], m[2][2])) + m[2][3];

	return temp;
}
