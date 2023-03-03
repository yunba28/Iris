#include <Iris/Math/Vector3.hpp>
#include <Iris/Math/Quaternion.hpp>
#include <Iris/Math/Matrix4x4.hpp>

namespace Iris
{
	Vector3 Vector3::rotate(const Quaternion& _quaternion) const noexcept
	{
		const Quaternion qv{ 0,*this };
		const auto rv = _quaternion * qv * _quaternion.inverse();
		return Vector3{ rv.x,rv.y,rv.z };
	}

	Vector3 Vector3::transform(const Matrix4x4& _matrix) const
	{
		float32 nx = x * _matrix.m[0][0] + y * _matrix.m[1][0] + z * _matrix.m[2][0] + _matrix.m[3][0];
		float32 ny = x * _matrix.m[0][1] + y * _matrix.m[1][1] + z * _matrix.m[2][1] + _matrix.m[3][1];
		float32 nz = x * _matrix.m[0][2] + y * _matrix.m[1][2] + z * _matrix.m[2][2] + _matrix.m[3][2];
		float32 nw = x * _matrix.m[0][3] + y * _matrix.m[1][3] + z * _matrix.m[2][3] + _matrix.m[3][3];

		if (nw != 0.f)
		{
			nx /= nw;
			ny /= nw;
			nz /= nw;
		}

		return Vector3{ nx,ny,nz };
	}

	Vector3 Vector3::Slerp(const Vector3& from, const Vector3& to, float32 t)
	{
		auto v1 = from.normalize();
		auto v2 = to.normalize();

		auto dotProduct = v1.dot(v2);

		if (dotProduct < 0.f)
		{
			v2 = v2.inverse();
			dotProduct = -dotProduct;
		}

		const auto DotThreshold = 0.99995f;

		if (dotProduct > DotThreshold)
		{
			return Lerp(from, to, t);
		}

		const auto theta = Math::ArcCos(dotProduct) * t;

		const auto relativeVec = (v2 - (v1 * dotProduct)).normalize();

		const auto len1 = from.length();
		const auto len2 = to.length();

		const auto newLength = len1 + (len2 - len1) * t;

		return (v1 * Math::Cos(theta) + relativeVec * Math::Sin(theta)) * newLength;
	}
}