#pragma once

#include <cstdint>

class CVec2;
class CVec3;
class CAng;
class CMatrix3x4;
class CMatrix2x3;

class CMath
{
public:
	static void			RandSeed(uint64_t a, uint64_t b);
	static void			RandSeed(uint64_t a);

	static uint64_t		Rand();
	static int			RandInt(const int min, const int max);
	static float		RandFloat(const float min, const float max);

	static float		Sin(const float f);
	static double		Sin(const double f);
	static float		Cos(const float f);
	static double		Cos(const double f);
	static float		Tan(const float f);
	static double		Tan(const double f);
	static void			SinCos(const float f, float& s, float& c);
	static void			SinCos(const double d, double& s, double& c);

	static float		ASin(const float f);
	static float		ACos(const float f);
	static float		ATan(const float f);
	static float		ATan2(const float y, const float x);

	static float		Sqrt(const float f);
	static float		Cbrt(const float f);
	static float		InvSqrt(const float f);
	static float		InvCbrt(const float f);

	static float		Exp(const float f);
	static float		Ln(const float f);
	static float		Pow(const float a, const float b);

	template <class T>
	static T			Sign(const T f);
	template <class T>
	static T			Abs(const T f);

	template <class T>
	static T			Min(const T a, const T b);
	template <class T>
	static T			Max(const T a, const T b);
	template <class T>
	static T			Clamp(const T x, const T min, const T max);

	static float		Mod(const float a, const float b);

	static float		Floor(const float f);
	static float		Floor(const float f, const float radix);
	static float		Ceil(const float f);
	static float		Ceil(const float f, const float radix);
	static float		Trunc(const float f);
	static float		Trunc(const float f, const float radix);
	static float		Round(const float f);
	static float		Round(const float f, const float radix);

	static bool			IsNormal(const float f);
	static bool			IsFinite(const float f);
	static bool			IsNan(const float f);
	static bool			IsInf(const float f);

	static float		Hypot(const float x, const float y);
	static float		Hypot(const float x, const float y, const float z);

	static void			CVec3ToCAng(const CVec3& v, CAng& a);
	static void			CAngToCVec3(const CAng& a, CVec3* forward, CVec3* right, CVec3* up);

	static float		NormalizeAng180(float f);
	static float		NormalizeAng360(float f);

	static float		AngleDelta(const float a, const float b);

	template <class T>
	static T			Lerp(const T initial, const T final, const T factor);
	static float		LerpAng(const float initial, const float final, const float factor);

	static float		DegToRad(const float f);
	static float		RadToDeg(const float f);

	static CMatrix2x3	AngToMatrix2x3(const float radians);
	static CVec2		Vec2Rotate(const CMatrix2x3& m, const CVec2& v);
	static CVec2		Vec2Transform(const CMatrix3x4& m, const CVec2& v);
	static CVec3		Vec3Rotate(const CMatrix3x4& m, const CVec3& v);
	static CVec3		Vec3Transform(const CMatrix3x4& m, const CVec3& v);

	static const float	PI;
	static const float	INV_PI;
	static const float	E;
	static const float	EPSILON;

private:
	static uint64_t		RotL(const uint64_t x, const int k);

	static uint64_t		seed[2];
};

template <class T>
T CMath::Sign(const T t)
{
	if (!t)
	{
		return 0;
	}
	return t > 0 ? 1 : -1;
}

template <class T>
T CMath::Abs(const T t)
{
	return t < 0 ? -t : t;
}

template <class T>
T CMath::Min(const T a, const T b)
{
	return a < b ? a : b;
}

template <class T>
T CMath::Max(const T a, const T b)
{
	return a > b ? a : b;
}

template <class T>
T CMath::Clamp(const T x, const T min, const T max)
{
	return x > max ? max : x < min ? min : x;
}
