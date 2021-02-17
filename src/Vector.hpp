#pragma once

class CColour;
class CVec3;
class CAng;
class CMatrix3x4;

class CVec2
{
public:
	float			x, y;

					CVec2() : x(0.0f), y(0.0f) {}
					CVec2(const float a, const float b) : x(a), y(b) {}

	float &			operator[](const int i);
	float			operator[](const int i) const;

	float *			Base();
	float const *	Base() const;

	void			CopyToArray(float *f) const;

	CVec2 &			operator=(const CVec2& v);

	CVec2 &			operator+=(const CVec2& v);
	CVec2 &			operator-=(const CVec2& v);
	CVec2 &			operator*=(const float f);
	CVec2 &			operator/=(const float f);

	CVec2			operator+(const CVec2& v) const;
	CVec2			operator-(const CVec2& v) const;
	CVec2			operator*(const float f) const;
	CVec2			operator/(const float f) const;

	bool			operator==(const CVec2& v) const;
	bool			operator!=(const CVec2& v) const;

	float			Length() const;
	float			LengthSqr() const;

	bool			IsLengthGreaterThan(const float val) const;
	bool			IsLengthLesserThan(const float val) const;

	float			DistTo(const CVec2& v) const;
	float			DistToSqr(const CVec2& v) const;

	CVec2			Rotated(const float radians) const;
	void			RotateInPlace(const float radians);

	bool			WithinAARect(const CVec2& min, const CVec2& max) const;

	float			ToAng() const;

	CVec3 &			AsVec3();
	const CVec3 &	AsVec3() const;

	void			Negate();
	bool			IsValid() const;
	bool			IsZero(const float tolerance = 0.01f) const;

	float			Dot(const CVec2& v) const;

	CVec2			Min(const CVec2& v) const;
	CVec2			Max(const CVec2& v) const;
	CVec2			Clamp(const CVec2& min, const CVec2& max) const;

	void			Randomize(const CVec2& min, const CVec2& max);
	void			Lerp(const CVec2& v, const float factor);

	CVec2			Normalized() const;
	float			NormalizeInPlace();
};

class CVec3
{
public:
	float			x, y, z;

					CVec3() : x(0.0f), y(0.0f), z(0.0f) {}
					CVec3(const float a, const float b, const float c) : x(a), y(b), z(c) {}

	float &			operator[](const int i);
	float			operator[](const int i) const;

	float *			Base();
	float const *	Base() const;

	void			CopyToArray(float *f) const;

	CVec3 &			operator=(const CVec3& v);

	CVec3 &			operator+=(const CVec3& v);
	CVec3 &			operator-=(const CVec3& v);
	CVec3 &			operator*=(float f);
	CVec3 &			operator/=(float f);

	CVec3			operator+(const CVec3& v) const;
	CVec3			operator-(const CVec3& v) const;
	CVec3			operator*(const float f) const;
	CVec3			operator/(const float f) const;

	bool			operator==(const CVec3& v) const;
	bool			operator!=(const CVec3& v) const;

	float			Length() const;
	float			LengthSqr() const;
	float			Length2D() const;
	float			Length2DSqr() const;

	bool			IsLengthGreaterThan(const float val) const;
	bool			IsLengthLesserThan(const float val) const;

	float			DistTo(const CVec3& v) const;
	float			DistToSqr(const CVec3& v) const;

	CVec3			Rotated(const CAng& a) const;
	void			RotateInPlace(const CAng &a);
	CVec3			Rotated2D(const float f) const;
	void			Rotate2DInPlace(const float f);

	bool			WithinAABox(const CVec3& min, const CVec3& max) const;

	CAng			ToAng() const;
	CColour			ToColour() const;

	CVec2 &			AsVec2();
	const CVec2 &	AsVec2() const;

	void			Negate();
	bool			IsValid() const;
	bool			IsZero(const float tolerance = 0.01f) const;

	CVec3			Cross(const CVec3& v) const;
	float			Dot(const CVec3& v) const;

	CVec3			Min(const CVec3& v) const;
	CVec3			Max(const CVec3& v) const;
	CVec3			Clamp(const CVec3& min, const CVec3& max) const;

	void			Randomize(const CVec3& min, const CVec3& max);
	void			Lerp(const CVec3& v, const float factor);

	CVec3			Normalized() const;
	float			NormalizeInPlace();
};

class CAng
{
public:
	float			x, y, z;

					CAng() : x(0.0f), y(0.0f), z(0.0f) {}
					CAng(const float a, const float b, const float c) : x(a), y(b), z(c) {}

	float &			operator[](const int i);
	float			operator[](const int i) const;

	float *			Base();
	float const *	Base() const;

	void			CopyToArray(float *f) const;

	CAng &			operator=(const CAng &a);

	CAng &			operator+=(const CAng &a);
	CAng &			operator-=(const CAng &a);
	CAng &			operator*=(const float f);
	CAng &			operator/=(const float f);

	CAng			operator+(const CAng &a) const;
	CAng			operator-(const CAng &a) const;
	CAng			operator*(const float f) const;
	CAng			operator/(const float f) const;

	bool			operator==(const CAng &a) const;
	bool			operator!=(const CAng &a) const;

	float			Length() const;
	float			LengthSqr() const;
	float			Length2D() const;
	float			Length2DSqr() const;

	CVec3			ToVec3() const;
	CVec3			Forward() const;
	CVec3			Right() const;
	CVec3			Up() const;
	CMatrix3x4		ToMatrix3x4() const;

	void			Negate();
	bool			IsValid() const;

	CAng			Min(const CAng &a) const;
	CAng			Max(const CAng &a) const;
	CAng			Clamp(const CAng &min, const CAng &max) const;

	void			Randomize(const CAng &min, const CAng &max);
	void			Lerp(const CAng &a, const float factor);

	CAng			Normalized() const;
	void			NormalizeInPlace();
};
