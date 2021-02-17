#pragma once

class CMatrix2x3
{
public:
	float			e[2][3];

	CMatrix2x3() {}
	CMatrix2x3(
		float m00, float m01, float m02,
		float m10, float m11, float m12);

	float *			operator[](const int i);
	const float *	operator[](const int i) const;

	CMatrix2x3 &	operator=(const CMatrix2x3& m);

	CMatrix2x3 &	operator+=(const CMatrix2x3& m);
	CMatrix2x3 &	operator-=(const CMatrix2x3& m);
	CMatrix2x3 &	operator*=(const float f);
	CMatrix2x3 &	operator/=(const float f);

	CMatrix2x3		operator+(const CMatrix2x3& m) const;
	CMatrix2x3		operator-(const CMatrix2x3& m) const;
	CMatrix2x3		operator*(const float f) const;
	CMatrix2x3		operator/(const float f) const;

	bool			operator==(const CMatrix2x3& m) const;
	bool			operator!=(const CMatrix2x3& m) const;

	void			Negate();
	bool			IsValid() const;
	bool			IsZero(const float tolerance = 0.01f) const;
};

class CMatrix3x4
{
public:
	float			e[3][4];

					CMatrix3x4() {}
					CMatrix3x4(
						float m00, float m01, float m02, float m03,
						float m10, float m11, float m12, float m13,
						float m20, float m21, float m22, float m23);

	float *			operator[](const int i);
	const float *	operator[](const int i) const;

	CMatrix3x4 &	operator=(const CMatrix3x4& m);

	CMatrix3x4 &	operator+=(const CMatrix3x4& m);
	CMatrix3x4 &	operator-=(const CMatrix3x4& m);
	CMatrix3x4 &	operator*=(const float f);
	CMatrix3x4 &	operator/=(const float f);

	CMatrix3x4		operator+(const CMatrix3x4& m) const;
	CMatrix3x4		operator-(const CMatrix3x4& m) const;
	CMatrix3x4		operator*(const float f) const;
	CMatrix3x4		operator/(const float f) const;

	bool			operator==(const CMatrix3x4& m) const;
	bool			operator!=(const CMatrix3x4& m) const;

	void			Negate();
	bool			IsValid() const;
	bool			IsZero(const float tolerance = 0.01f) const;
};