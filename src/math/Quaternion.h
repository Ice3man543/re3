#pragma once

// TODO: actually implement this
class CQuaternion
{
public:
	float x, y, z, w;
	CQuaternion(void) {}
	CQuaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	float Magnitude(void) const { return Sqrt(x*x + y*y + z*z + w*w); }
	float MagnitudeSqr(void) const { return x*x + y*y + z*z + w*w; }
	void Normalise(void) {
		float sq = MagnitudeSqr();
		if(sq == 0.0f)
			w = 1.0f;
		else{
			float invsqrt = RecipSqrt(sq);
			x *= invsqrt;
			y *= invsqrt;
			z *= invsqrt;
			w *= invsqrt;
		}
	}

	const CQuaternion &operator+=(CQuaternion const &right) {
		x += right.x;
		y += right.y;
		z += right.z;
		w += right.w;
		return *this;
	}

	const CQuaternion &operator-=(CQuaternion const &right) {
		x -= right.x;
		y -= right.y;
		z -= right.z;
		w -= right.w;
		return *this;
	}

	const CQuaternion &operator*=(float right) {
		x *= right;
		y *= right;
		z *= right;
		w *= right;
		return *this;
	}

	const CQuaternion &operator/=(float right) {
		x /= right;
		y /= right;
		z /= right;
		w /= right;
		return *this;
	}

	CQuaternion operator-() const {
		return CQuaternion(-x, -y, -z, -w);
	}

	void Slerp(const CQuaternion &q1, const CQuaternion &q2, float theta, float invSin, float t);
	void Get(RwMatrix *matrix);
};

inline float
DotProduct(const CQuaternion &q1, const CQuaternion &q2)
{
	return q1.x*q2.x + q1.y*q2.y + q1.z*q2.z + q1.w*q2.w;
}

inline CQuaternion operator+(const CQuaternion &left, const CQuaternion &right)
{
	return CQuaternion(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.w);
}

inline CQuaternion operator-(const CQuaternion &left, const CQuaternion &right)
{
	return CQuaternion(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.w);
}

inline CQuaternion operator*(const CQuaternion &left, float right)
{
	return CQuaternion(left.x * right, left.y * right, left.z * right, left.w * right);
}

inline CQuaternion operator*(float left, const CQuaternion &right)
{
	return CQuaternion(left * right.x, left * right.y, left * right.z, left * right.w);
}

inline CQuaternion operator/(const CQuaternion &left, float right)
{
	return CQuaternion(left.x / right, left.y / right, left.z / right, left.w / right);
}
