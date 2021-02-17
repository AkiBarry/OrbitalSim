

#include "Math.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "Colour.hpp"

// CVec2 Functions

float & CVec2::operator[](const int i)
{
	return reinterpret_cast<float*>(this)[i];
}

float CVec2::operator[](const int i) const
{
	return reinterpret_cast<const float*>(this)[i];
}

float * CVec2::Base()
{
	return reinterpret_cast<float*>(this);
}

float const * CVec2::Base() const
{
	return reinterpret_cast<float const*>(this);
}

void CVec2::CopyToArray(float* f) const
{
	f[0] = x;
	f[1] = y;
}

CVec2 & CVec2::operator=(const CVec2& v)
{
	x = v.x;
	y = v.y;

	return *this;
}

CVec2 & CVec2::operator+=(const CVec2& v)
{
	x += v.x;
	y += v.y;

	return *this;
}

CVec2 & CVec2::operator-=(const CVec2& v)
{
	x -= v.x;
	y -= v.y;

	return *this;
}

CVec2 & CVec2::operator*=(const float f)
{
	x *= f;
	y *= f;

	return *this;
}

CVec2 & CVec2::operator/=(const float f)
{
	float invf = 1.0f / f;

	x *= invf;
	y *= invf;

	return *this;
}

CVec2 CVec2::operator+(const CVec2& v) const
{
	CVec2 temp;

	temp.x = x + v.x;
	temp.y = y + v.y;

	return temp;
}

CVec2 CVec2::operator-(const CVec2& v) const
{
	CVec2 temp;

	temp.x = x - v.x;
	temp.y = y - v.y;

	return temp;
}

CVec2 CVec2::operator*(const float f) const
{
	CVec2 temp;

	temp.x = x * f;
	temp.y = y * f;

	return temp;
}

CVec2 CVec2::operator/(const float f) const
{
	CVec2 temp;
	float invf = 1.0f / f;

	temp.x = x * invf;
	temp.y = y * invf;

	return temp;
}

bool CVec2::operator==(const CVec2& v) const
{
	return x == v.x
		&& y == v.y;
}

bool CVec2::operator!=(const CVec2& v) const
{
	return x != v.x
		|| y != v.y;
}

float CVec2::Length() const
{
	return CMath::Sqrt(x * x + y * y);
}

float CVec2::LengthSqr() const
{
	return x * x + y * y;
}

bool CVec2::IsLengthGreaterThan(const float val) const
{
	return LengthSqr() > val * val;
}

bool CVec2::IsLengthLesserThan(const float val) const
{
	return LengthSqr() < val * val;
}

float CVec2::DistTo(const CVec2& v) const
{
	CVec2 temp;

	temp = v - *this;

	return temp.Length();
}

float CVec2::DistToSqr(const CVec2& v) const
{
	CVec2 temp;

	temp = v - *this;

	return temp.LengthSqr();
}

CVec2 CVec2::Rotated(const float radians) const
{
	CMatrix2x3 temp = CMath::AngToMatrix2x3(radians);

	return CMath::Vec2Rotate(temp, *this);
}

void CVec2::RotateInPlace(const float radians)
{
	CMatrix2x3 temp = CMath::AngToMatrix2x3(radians);

	*this = CMath::Vec2Rotate(temp, *this);
}

bool CVec2::WithinAARect(const CVec2& min, const CVec2& max) const
{
	return min.x < x && max.x > x
		&& min.y < y && max.y > y;
}

float CVec2::ToAng() const
{
	return CMath::ATan2(y, x);
}

CVec3 & CVec2::AsVec3()
{
	return *reinterpret_cast<CVec3*>(this);
}

const CVec3 & CVec2::AsVec3() const
{
	return *reinterpret_cast<const CVec3*>(this);
}

void CVec2::Negate()
{
	x = -x;
	y = -y;
}

bool CVec2::IsValid() const
{
	return CMath::IsFinite(x)
		&& CMath::IsFinite(y);
}

bool CVec2::IsZero(const float tolerance) const
{
	return CMath::Abs(x) < tolerance
		&& CMath::Abs(y) < tolerance;
}

float CVec2::Dot(const CVec2& v) const
{
	return x * v.x + y * v.y;
}

CVec2 CVec2::Min(const CVec2& v) const
{
	CVec2 temp;

	temp.x = CMath::Min(x, v.x);
	temp.y = CMath::Min(y, v.y);

	return temp;
}

CVec2 CVec2::Max(const CVec2& v) const
{
	CVec2 temp;

	temp.x = CMath::Max(x, v.x);
	temp.y = CMath::Max(y, v.y);

	return temp;
}

CVec2 CVec2::Clamp(const CVec2& min, const CVec2& max) const
{
	CVec2 temp;

	temp.x = CMath::Clamp(x, min.x, max.x);
	temp.y = CMath::Clamp(y, min.y, max.y);

	return temp;
}

void CVec2::Randomize(const CVec2& min, const CVec2& max)
{
	x = CMath::RandFloat(min.x, max.x);
	y = CMath::RandFloat(min.y, max.y);
}

void CVec2::Lerp(const CVec2& v, const float factor)
{
	x += (v.x - x) * factor;
	y += (v.y - y) * factor;
}

CVec2 CVec2::Normalized() const
{
	CVec2 temp = *this;

	float l = Length();
	float m = 1.0f / (l + CMath::EPSILON);

	temp *= m;

	return temp;
}

float CVec2::NormalizeInPlace()
{
	float l = Length();
	float m = 1.0f / (l + CMath::EPSILON);

	*this *= m;

	return l;
}

// CVec3 Functions

float & CVec3::operator[](const int i)
{
	return reinterpret_cast<float*>(this)[i];
}

float CVec3::operator[](const int i) const
{
	return reinterpret_cast<const float*>(this)[i];
}

float * CVec3::Base()
{
	return reinterpret_cast<float*>(this);
}

float const * CVec3::Base() const
{
	return reinterpret_cast<float const*>(this);
}

void CVec3::CopyToArray(float* f) const
{
	f[0] = x;
	f[1] = y;
	f[2] = z;
}

CVec3 & CVec3::operator=(const CVec3& v)
{
	x = v.x;
	y = v.y;
	z = v.z;

	return *this;
}

CVec3 & CVec3::operator+=(const CVec3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

CVec3 & CVec3::operator-=(const CVec3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}

CVec3 & CVec3::operator*=(const float f)
{
	x *= f;
	y *= f;
	z *= f;

	return *this;
}

CVec3 & CVec3::operator/=(const float f)
{
	float invf = 1.0f / f;
	x *= invf;
	y *= invf;
	z *= invf;

	return *this;
}

CVec3 CVec3::operator+(const CVec3& v) const
{
	CVec3 temp;

	temp.x = x + v.x;
	temp.y = y + v.y;
	temp.z = z + v.z;

	return temp;
}

CVec3 CVec3::operator-(const CVec3& v) const
{
	CVec3 temp;

	temp.x = x - v.x;
	temp.y = y - v.y;
	temp.z = z - v.z;

	return temp;
}

CVec3 CVec3::operator*(const float f) const
{
	CVec3 temp;

	temp.x = x * f;
	temp.y = y * f;
	temp.z = z * f;

	return temp;
}

CVec3 CVec3::operator/(const float f) const
{
	CVec3 temp;
	float invf = 1.0f / f;

	temp.x = x * invf;
	temp.y = y * invf;
	temp.z = z * invf;

	return temp;
}

bool CVec3::operator==(const CVec3& v) const
{
	return x == v.x
		&& y == v.y
		&& z == v.y;
}

bool CVec3::operator!=(const CVec3& v) const
{
	return x != v.x
		|| y != v.y
		|| z != v.z;
}

float CVec3::Length() const
{
	return CMath::Sqrt(x * x + y * y + z * z);
}

float CVec3::LengthSqr() const
{
	return x * x + y * y + z * z;
}

float CVec3::Length2D() const
{
	return CMath::Sqrt(x * x + y * y);
}

float CVec3::Length2DSqr() const
{
	return x * x + y * y;
}

bool CVec3::IsLengthGreaterThan(const float val) const
{
	return LengthSqr() > val * val;
}

bool CVec3::IsLengthLesserThan(const float val) const
{
	return LengthSqr() < val * val;
}

float CVec3::DistTo(const CVec3& v) const
{
	CVec3 temp;

	temp = v - *this;

	return temp.Length();
}

float CVec3::DistToSqr(const CVec3& v) const
{
	CVec3 temp;

	temp = v - *this;

	return temp.LengthSqr();
}

CVec3 CVec3::Rotated(const CAng& a) const
{
	CMatrix3x4 temp = a.ToMatrix3x4();

	return CMath::Vec3Rotate(temp, *this);
}

void CVec3::RotateInPlace(const CAng& a)
{
	CMatrix3x4 temp = a.ToMatrix3x4();

	*this = CMath::Vec3Rotate(temp, *this);
}

CVec3 CVec3::Rotated2D(const float f) const
{
	return this->AsVec2().Rotated(f).AsVec3();
}

void CVec3::Rotate2DInPlace(const float f)
{
	this->AsVec2().RotateInPlace(f);
}

bool CVec3::WithinAABox(const CVec3& min, const CVec3& max) const
{
	return min.x < x && max.x > x
		&& min.y < y && max.y > y
		&& min.z < z && max.z > z;
}

CAng CVec3::ToAng() const
{
	CAng temp;

	if (x == 0.0f && y == 0.0f)
	{
		temp.x = z > 0.0f ? -90.0f : 90.0f;
		temp.y = 0.0f;
		return temp;
	}

	temp.x = -CMath::RadToDeg(CMath::ASin(z / (Length() + CMath::EPSILON)));
	temp.y = CMath::RadToDeg(CMath::ATan2(y, x));
	return temp;
}

CColour CVec3::ToColour() const
{
	int r = static_cast<int>(CMath::Clamp(x, 0.0f, 1.0f)) * 255;
	int g = static_cast<int>(CMath::Clamp(x, 0.0f, 1.0f)) * 255;
	int b = static_cast<int>(CMath::Clamp(x, 0.0f, 1.0f)) * 255;

	return CColour(r, g, b);
}

CVec2 & CVec3::AsVec2()
{
	return *reinterpret_cast<CVec2*>(this);
}

const CVec2 & CVec3::AsVec2() const
{
	return *reinterpret_cast<const CVec2*>(this);
}

void CVec3::Negate()
{
	x = -x;
	y = -y;
	z = -z;
}

bool CVec3::IsValid() const
{
	return CMath::IsFinite(x)
		&& CMath::IsFinite(y)
		&& CMath::IsFinite(z);
}

bool CVec3::IsZero(const float tolerance) const
{
	return CMath::Abs(x) < tolerance
		&& CMath::Abs(y) < tolerance
		&& CMath::Abs(z) < tolerance;
}

CVec3 CVec3::Cross(const CVec3& v) const
{
	CVec3 temp;

	temp.x = y * v.z - z * v.y;
	temp.y = z * v.x - x * v.z;
	temp.z = x * v.y - y * v.x;

	return temp;
}

float CVec3::Dot(const CVec3& v) const
{
	return x * v.x + y * v.y + z * v.z;
}

CVec3 CVec3::Min(const CVec3& v) const
{
	CVec3 temp;

	temp.x = CMath::Min(x, v.x);
	temp.y = CMath::Min(y, v.y);
	temp.z = CMath::Min(z, v.z);

	return temp;
}

CVec3 CVec3::Max(const CVec3& v) const
{
	CVec3 temp;

	temp.x = CMath::Max(x, v.x);
	temp.y = CMath::Max(y, v.y);
	temp.z = CMath::Max(z, v.z);

	return temp;
}

CVec3 CVec3::Clamp(const CVec3& min, const CVec3& max) const
{
	CVec3 temp;

	temp.x = CMath::Clamp(x, min.x, max.x);
	temp.y = CMath::Clamp(y, min.y, max.y);
	temp.z = CMath::Clamp(z, min.z, max.z);

	return temp;
}

void CVec3::Randomize(const CVec3& min, const CVec3& max)
{
	x = CMath::RandFloat(min.x, max.x);
	y = CMath::RandFloat(min.y, max.y);
	z = CMath::RandFloat(min.z, max.z);
}

void CVec3::Lerp(const CVec3& v, const float factor)
{
	x += (v.x - x) * factor;
	y += (v.y - y) * factor;
	z += (v.z - z) * factor;
}

CVec3 CVec3::Normalized() const
{
	CVec3 temp = *this;

	float l = Length();
	float m = 1.0f / (l + CMath::EPSILON);

	temp *= m;

	return temp;
}

float CVec3::NormalizeInPlace()
{
	float l = Length();
	float m = 1.0f / (l + CMath::EPSILON);

	*this *= m;

	return l;
}

// CAng Functions

float & CAng::operator[](const int i)
{
	return reinterpret_cast<float*>(this)[i];
}

float CAng::operator[](const int i) const
{
	return reinterpret_cast<const float*>(this)[i];
}

float * CAng::Base()
{
	return reinterpret_cast<float*>(this);
}

float const * CAng::Base() const
{
	return reinterpret_cast<float const*>(this);
}

void CAng::CopyToArray(float* f) const
{
	f[0] = x;
	f[1] = y;
	f[2] = z;
}

CAng & CAng::operator=(const CAng& a)
{
	x = a.x;
	y = a.y;
	z = a.z;

	return *this;
}

CAng & CAng::operator+=(const CAng& a)
{
	x += a.x;
	y += a.y;
	z += a.z;

	return *this;
}

CAng & CAng::operator-=(const CAng& a)
{
	x -= a.x;
	y -= a.y;
	z -= a.z;

	return *this;
}

CAng & CAng::operator*=(const float f)
{
	x *= f;
	y *= f;
	z *= f;

	return *this;
}

CAng & CAng::operator/=(const float f)
{
	x /= f;
	y /= f;
	z /= f;

	return *this;
}

CAng CAng::operator+(const CAng& a) const
{
	CAng temp;

	temp.x = x + a.x;
	temp.y = y + a.y;
	temp.z = z + a.z;

	return temp;
}

CAng CAng::operator-(const CAng& a) const
{
	CAng temp;

	temp.x = x - a.x;
	temp.y = y - a.y;
	temp.z = z - a.z;

	return temp;
}

CAng CAng::operator*(const float f) const
{
	CAng temp;

	temp.x = x * f;
	temp.y = y * f;
	temp.z = z * f;

	return temp;
}

CAng CAng::operator/(const float f) const
{
	CAng temp;

	temp.x = x / f;
	temp.y = y / f;
	temp.z = z / f;

	return temp;
}

bool CAng::operator==(const CAng& a) const
{
	return x == a.x
		&& y == a.y
		&& z == a.y;
}

bool CAng::operator!=(const CAng& a) const
{
	return x != a.x
		|| y != a.y
		|| z != a.y;
}

float CAng::Length() const
{
	return CMath::Sqrt(x * x + y * y + z * z);
}

float CAng::LengthSqr() const
{
	return x * x + y * y + z * z;
}

float CAng::Length2D() const
{
	return CMath::Sqrt(x * x + y * y);
}

float CAng::Length2DSqr() const
{
	return x * x + y * y;
}

CVec3 CAng::ToVec3() const
{
	return Forward();
}

CVec3 CAng::Forward() const
{
	CVec3 temp;

	float sx, cx, sy, cy;

	CMath::SinCos(CMath::DegToRad(x), sx, cx);
	CMath::SinCos(CMath::DegToRad(y), sy, cy);

	temp.x = sx * cy;
	temp.y = sx * sy;
	temp.z = cx;

	return temp;
}

CVec3 CAng::Right() const
{
	CVec3 temp;

	float sx, cx, sy, cy, sz, cz;

	CMath::SinCos(CMath::DegToRad(x), sx, cx);
	CMath::SinCos(CMath::DegToRad(y), sy, cy);
	CMath::SinCos(CMath::DegToRad(z), sz, cz);

	temp.x = cx * sy;
	temp.y = (sx * sy * sz) + (cy * cz);
	temp.z = (sx * sy * cz) - (cy * sz);

	return temp;
}

CVec3 CAng::Up() const
{
	CVec3 temp;

	float sx, cx, sz, cz;

	CMath::SinCos(CMath::DegToRad(x), sx, cx);
	CMath::SinCos(CMath::DegToRad(z), sz, cz);

	temp.x = -sx;
	temp.y = cx * sz;
	temp.z = cx * cz;

	return temp;
}

CMatrix3x4 CAng::ToMatrix3x4() const
{
	CMatrix3x4 temp;

	float sp, sy, sr, cp, cy, cr;

	CMath::SinCos(CMath::DegToRad(x), sp, cp);
	CMath::SinCos(CMath::DegToRad(y), sy, cy);
	CMath::SinCos(CMath::DegToRad(z), sr, cr);

	temp[0][0] = cp * cy;
	temp[1][0] = cp * sy;
	temp[2][0] = -sp;

	float crcy = cr * cy;
	float crsy = cr * sy;
	float srcy = sr * cy;
	float srsy = sr * sy;

	temp[0][1] = sp * srcy - crsy;
	temp[1][1] = sp * srsy + crcy;
	temp[2][1] = sr * cp;

	temp[0][2] = sp * crcy + srsy;
	temp[1][2] = sp * crsy - srcy;
	temp[2][2] = cr * cp;

	temp[0][3] = 0.0f;
	temp[1][3] = 0.0f;
	temp[2][3] = 0.0f;

	return temp;
}

void CAng::Negate()
{
	x = -x;
	y = -y;
	z = -z;
}

bool CAng::IsValid() const
{
	return CMath::IsFinite(x)
		&& CMath::IsFinite(y)
		&& CMath::IsFinite(z);
}

CAng CAng::Min(const CAng& a) const
{
	CAng temp;

	temp.x = CMath::Min(x, a.x);
	temp.y = CMath::Min(y, a.y);
	temp.z = CMath::Min(z, a.z);

	return temp;
}

CAng CAng::Max(const CAng& a) const
{
	CAng temp;

	temp.x = CMath::Max(x, a.x);
	temp.y = CMath::Max(y, a.y);
	temp.z = CMath::Max(z, a.z);

	return temp;
}

CAng CAng::Clamp(const CAng& min, const CAng& max) const
{
	CAng temp;

	temp.x = CMath::Clamp(x, min.x, max.x);
	temp.y = CMath::Clamp(y, min.y, max.y);
	temp.z = CMath::Clamp(z, min.z, max.z);

	return temp;
}

void CAng::Randomize(const CAng& min, const CAng& max)
{
	x = CMath::RandFloat(min.x, max.x);
	y = CMath::RandFloat(min.y, max.y);
	z = CMath::RandFloat(min.z, max.z);
}

void CAng::Lerp(const CAng& a, const float factor)
{
	x = CMath::LerpAng(x, a.x, factor);
	y = CMath::LerpAng(y, a.y, factor);
	z = CMath::LerpAng(z, a.z, factor);
}

CAng CAng::Normalized() const
{
	CAng temp;

	temp.x = CMath::NormalizeAng180(x);
	temp.y = CMath::NormalizeAng180(y);
	temp.z = CMath::NormalizeAng180(z);

	return temp;
}

void CAng::NormalizeInPlace()
{
	x = CMath::NormalizeAng180(x);
	y = CMath::NormalizeAng180(y);
	z = CMath::NormalizeAng180(z);
}
