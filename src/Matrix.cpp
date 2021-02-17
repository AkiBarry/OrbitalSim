#include "Matrix.hpp"
#include "Math.hpp"

CMatrix2x3::CMatrix2x3(
	float m00, float m01, float m02,
	float m10, float m11, float m12 )
{
	e[0][0] = m00; e[0][1] = m01; e[0][2] = m02;
	e[1][0] = m10; e[1][1] = m11; e[1][2] = m12;
}

float * CMatrix2x3::operator[]( const int i )
{
	return e[i];
}

const float * CMatrix2x3::operator[]( const int i ) const
{
	return e[i];
}

CMatrix2x3 & CMatrix2x3::operator=( const CMatrix2x3& m )
{
	e[0][0] = m[0][0]; e[0][1] = m[0][1]; e[0][2] = m[0][2];
	e[1][0] = m[1][0]; e[1][1] = m[1][1]; e[1][2] = m[1][2];

	return *this;
}

CMatrix2x3 & CMatrix2x3::operator+=( const CMatrix2x3& m )
{
	e[0][0] += m[0][0]; e[0][1] += m[0][1]; e[0][2] += m[0][2];
	e[1][0] += m[1][0]; e[1][1] += m[1][1]; e[1][2] += m[1][2];

	return *this;
}

CMatrix2x3 & CMatrix2x3::operator-=( const CMatrix2x3& m )
{
	e[0][0] -= m[0][0]; e[0][1] -= m[0][1]; e[0][2] -= m[0][2];
	e[1][0] -= m[1][0]; e[1][1] -= m[1][1]; e[1][2] -= m[1][2];

	return *this;
}

CMatrix2x3 & CMatrix2x3::operator*=( const float f )
{
	e[0][0] *= f; e[0][1] *= f; e[0][2] *= f;
	e[1][0] *= f; e[1][1] *= f; e[1][2] *= f;

	return *this;
}

CMatrix2x3 & CMatrix2x3::operator/=( const float f )
{
	float invf = 1.0f / f;

	e[0][0] *= invf; e[0][1] *= invf; e[0][2] *= invf;
	e[1][0] *= invf; e[1][1] *= invf; e[1][2] *= invf;

	return *this;
}

CMatrix2x3 CMatrix2x3::operator+( const CMatrix2x3& m ) const
{
	CMatrix2x3 temp;

	temp[0][0] = e[0][0] + m[0][0]; temp[0][1] = e[0][1] + m[0][1]; temp[0][2] = e[0][2] + m[0][2];
	temp[1][0] = e[1][0] + m[1][0]; temp[1][1] = e[1][1] + m[1][1]; temp[1][2] = e[1][2] + m[1][2];

	return temp;
}

CMatrix2x3 CMatrix2x3::operator-( const CMatrix2x3& m ) const
{
	CMatrix2x3 temp;

	temp[0][0] = e[0][0] - m[0][0]; temp[0][1] = e[0][1] - m[0][1]; temp[0][2] = e[0][2] - m[0][2];
	temp[1][0] = e[1][0] - m[1][0]; temp[1][1] = e[1][1] - m[1][1]; temp[1][2] = e[1][2] - m[1][2];

	return temp;
}

CMatrix2x3 CMatrix2x3::operator*( const float f ) const
{
	CMatrix2x3 temp;

	temp[0][0] = e[0][0] * f; temp[0][1] = e[0][1] * f; temp[0][2] = e[0][2] * f;
	temp[1][0] = e[1][0] * f; temp[1][1] = e[1][1] * f; temp[1][2] = e[1][2] * f;

	return temp;
}

CMatrix2x3 CMatrix2x3::operator/( const float f ) const
{
	CMatrix2x3 temp;
	float invf = 1.0f / f;

	temp[0][0] = e[0][0] * invf; temp[0][1] = e[0][1] * invf; temp[0][2] = e[0][2] * invf;
	temp[1][0] = e[1][0] * invf; temp[1][1] = e[1][1] * invf; temp[1][2] = e[1][2] * invf;

	return temp;
}

bool CMatrix2x3::operator==( const CMatrix2x3& m ) const
{
	return e[0][0] == m[0][0] && e[0][1] == m[0][1] && e[0][2] == m[0][2]
		&& e[1][0] == m[1][0] && e[1][1] == m[1][1] && e[1][2] == m[1][2];
}

bool CMatrix2x3::operator!=( const CMatrix2x3& m ) const
{
	return e[0][0] != m[0][0] || e[0][1] != m[0][1] || e[0][2] != m[0][2]
		|| e[1][0] != m[1][0] || e[1][1] != m[1][1] || e[1][2] != m[1][2];
}

void CMatrix2x3::Negate()
{
	e[0][0] = -e[0][0]; e[0][1] = -e[0][1]; e[0][2] = -e[0][2];
	e[1][0] = -e[1][0]; e[1][1] = -e[1][1]; e[1][2] = -e[1][2];
}

bool CMatrix2x3::IsValid() const
{
	return CMath::IsFinite(e[0][0]) && CMath::IsFinite(e[0][1]) && CMath::IsFinite(e[0][2])
		&& CMath::IsFinite(e[1][0]) && CMath::IsFinite(e[1][1]) && CMath::IsFinite(e[1][2]);
}

bool CMatrix2x3::IsZero( const float tolerance ) const
{
	return CMath::Abs(e[0][0]) < tolerance && CMath::Abs(e[0][1]) < tolerance && CMath::Abs(e[0][2]) < tolerance
		&& CMath::Abs(e[1][0]) < tolerance && CMath::Abs(e[1][1]) < tolerance && CMath::Abs(e[1][2]) < tolerance;
}

CMatrix3x4::CMatrix3x4(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23 )
{
	e[0][0] = m00;
	e[0][1] = m01;
	e[0][2] = m02;
	e[0][3] = m03;
	e[1][0] = m10;
	e[1][1] = m11;
	e[1][2] = m12;
	e[1][3] = m13;
	e[2][0] = m20;
	e[2][1] = m21;
	e[2][2] = m22;
	e[2][3] = m23;
}

float * CMatrix3x4::operator[]( const int i )
{
	return e[i];
}

const float * CMatrix3x4::operator[]( const int i ) const
{
	return e[i];
}

CMatrix3x4 & CMatrix3x4::operator=( const CMatrix3x4& m )
{
	e[0][0] = m[0][0];
	e[0][1] = m[0][1];
	e[0][2] = m[0][2];
	e[0][3] = m[0][3];
	e[1][0] = m[1][0];
	e[1][1] = m[1][1];
	e[1][2] = m[1][2];
	e[1][3] = m[1][3];
	e[2][0] = m[2][0];
	e[2][1] = m[2][1];
	e[2][2] = m[2][2];
	e[2][3] = m[2][3];

	return *this;
}

CMatrix3x4 & CMatrix3x4::operator+=( const CMatrix3x4& m )
{
	e[0][0] += m[0][0];
	e[0][1] += m[0][1];
	e[0][2] += m[0][2];
	e[0][3] += m[0][3];
	e[1][0] += m[1][0];
	e[1][1] += m[1][1];
	e[1][2] += m[1][2];
	e[1][3] += m[1][3];
	e[2][0] += m[2][0];
	e[2][1] += m[2][1];
	e[2][2] += m[2][2];
	e[2][3] += m[2][3];

	return *this;
}

CMatrix3x4 & CMatrix3x4::operator-=( const CMatrix3x4& m )
{
	e[0][0] -= m[0][0];
	e[0][1] -= m[0][1];
	e[0][2] -= m[0][2];
	e[0][3] -= m[0][3];
	e[1][0] -= m[1][0];
	e[1][1] -= m[1][1];
	e[1][2] -= m[1][2];
	e[1][3] -= m[1][3];
	e[2][0] -= m[2][0];
	e[2][1] -= m[2][1];
	e[2][2] -= m[2][2];
	e[2][3] -= m[2][3];

	return *this;
}

CMatrix3x4 & CMatrix3x4::operator*=( const float f )
{
	e[0][0] *= f;
	e[0][1] *= f;
	e[0][2] *= f;
	e[0][3] *= f;
	e[1][0] *= f;
	e[1][1] *= f;
	e[1][2] *= f;
	e[1][3] *= f;
	e[2][0] *= f;
	e[2][1] *= f;
	e[2][2] *= f;
	e[2][3] *= f;

	return *this;
}

CMatrix3x4 & CMatrix3x4::operator/=( const float f )
{
	float invf = 1.0f / f;

	e[0][0] *= invf;
	e[0][1] *= invf;
	e[0][2] *= invf;
	e[0][3] *= invf;
	e[1][0] *= invf;
	e[1][1] *= invf;
	e[1][2] *= invf;
	e[1][3] *= invf;
	e[2][0] *= invf;
	e[2][1] *= invf;
	e[2][2] *= invf;
	e[2][3] *= invf;

	return *this;
}

CMatrix3x4 CMatrix3x4::operator+( const CMatrix3x4& m ) const
{
	CMatrix3x4 temp;

	temp[0][0] = e[0][0] + m[0][0];
	temp[0][1] = e[0][1] + m[0][1];
	temp[0][2] = e[0][2] + m[0][2];
	temp[0][3] = e[0][3] + m[0][3];
	temp[1][0] = e[1][0] + m[1][0];
	temp[1][1] = e[1][1] + m[1][1];
	temp[1][2] = e[1][2] + m[1][2];
	temp[1][3] = e[1][3] + m[1][3];
	temp[2][0] = e[2][0] + m[2][0];
	temp[2][1] = e[2][1] + m[2][1];
	temp[2][2] = e[2][2] + m[2][2];
	temp[2][3] = e[2][3] + m[2][3];

	return temp;
}

CMatrix3x4 CMatrix3x4::operator-( const CMatrix3x4& m ) const
{
	CMatrix3x4 temp;

	temp[0][0] = e[0][0] - m[0][0];
	temp[0][1] = e[0][1] - m[0][1];
	temp[0][2] = e[0][2] - m[0][2];
	temp[0][3] = e[0][3] - m[0][3];
	temp[1][0] = e[1][0] - m[1][0];
	temp[1][1] = e[1][1] - m[1][1];
	temp[1][2] = e[1][2] - m[1][2];
	temp[1][3] = e[1][3] - m[1][3];
	temp[2][0] = e[2][0] - m[2][0];
	temp[2][1] = e[2][1] - m[2][1];
	temp[2][2] = e[2][2] - m[2][2];
	temp[2][3] = e[2][3] - m[2][3];

	return temp;
}

CMatrix3x4 CMatrix3x4::operator*( const float f ) const
{
	CMatrix3x4 temp;

	temp[0][0] = e[0][0] * f;
	temp[0][1] = e[0][1] * f;
	temp[0][2] = e[0][2] * f;
	temp[0][3] = e[0][3] * f;
	temp[1][0] = e[1][0] * f;
	temp[1][1] = e[1][1] * f;
	temp[1][2] = e[1][2] * f;
	temp[1][3] = e[1][3] * f;
	temp[2][0] = e[2][0] * f;
	temp[2][1] = e[2][1] * f;
	temp[2][2] = e[2][2] * f;
	temp[2][3] = e[2][3] * f;

	return temp;
}

CMatrix3x4 CMatrix3x4::operator/( const float f ) const
{
	CMatrix3x4 temp;
	float invf = 1.0f / f;

	temp[0][0] = e[0][0] * invf;
	temp[0][1] = e[0][1] * invf;
	temp[0][2] = e[0][2] * invf;
	temp[0][3] = e[0][3] * invf;
	temp[1][0] = e[1][0] * invf;
	temp[1][1] = e[1][1] * invf;
	temp[1][2] = e[1][2] * invf;
	temp[1][3] = e[1][3] * invf;
	temp[2][0] = e[2][0] * invf;
	temp[2][1] = e[2][1] * invf;
	temp[2][2] = e[2][2] * invf;
	temp[2][3] = e[2][3] * invf;

	return temp;
}

bool CMatrix3x4::operator==( const CMatrix3x4& m ) const
{
	return e[0][0] == m[0][0] && e[0][1] == m[0][1] && e[0][2] == m[0][2] && e[0][3] == m[0][3]
		&& e[1][0] == m[1][0] && e[1][1] == m[1][1] && e[1][2] == m[1][2] && e[1][3] == m[1][3]
		&& e[2][0] == m[2][0] && e[2][1] == m[2][1] && e[2][2] == m[2][2] && e[2][3] == m[2][3];
}

bool CMatrix3x4::operator!=( const CMatrix3x4& m ) const
{
	return e[0][0] != m[0][0] || e[0][1] != m[0][1] || e[0][2] != m[0][2] || e[0][3] != m[0][3]
		|| e[1][0] != m[1][0] || e[1][1] != m[1][1] || e[1][2] != m[1][2] || e[1][3] != m[1][3]
		|| e[2][0] != m[2][0] || e[2][1] != m[2][1] || e[2][2] != m[2][2] || e[2][3] != m[2][3];
}

void CMatrix3x4::Negate()
{
	e[0][0] = -e[0][0];
	e[0][1] = -e[0][1];
	e[0][2] = -e[0][2];
	e[0][3] = -e[0][3];
	e[1][0] = -e[1][0];
	e[1][1] = -e[1][1];
	e[1][2] = -e[1][2];
	e[1][3] = -e[1][3];
	e[2][0] = -e[2][0];
	e[2][1] = -e[2][1];
	e[2][2] = -e[2][2];
	e[2][3] = -e[2][3];
}

bool CMatrix3x4::IsValid() const
{
	return CMath::IsFinite(e[0][0]) && CMath::IsFinite(e[0][1]) && CMath::IsFinite(e[0][2]) && CMath::IsFinite(e[0][3])
		&& CMath::IsFinite(e[1][0]) && CMath::IsFinite(e[1][1]) && CMath::IsFinite(e[1][2]) && CMath::IsFinite(e[1][3])
		&& CMath::IsFinite(e[2][0]) && CMath::IsFinite(e[2][1]) && CMath::IsFinite(e[2][2]) && CMath::IsFinite(e[2][3]);
}

bool CMatrix3x4::IsZero( const float tolerance ) const
{
	return CMath::Abs(e[0][0]) < tolerance && CMath::Abs(e[0][1]) < tolerance && CMath::Abs(e[0][2]) < tolerance && CMath::Abs(e[0][3]) < tolerance
		&& CMath::Abs(e[1][0]) < tolerance && CMath::Abs(e[1][1]) < tolerance && CMath::Abs(e[1][2]) < tolerance && CMath::Abs(e[1][3]) < tolerance
		&& CMath::Abs(e[2][0]) < tolerance && CMath::Abs(e[2][1]) < tolerance && CMath::Abs(e[2][2]) < tolerance && CMath::Abs(e[2][3]) < tolerance;
}
