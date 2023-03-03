#include <Iris/Math/Quaternion.hpp>
#include <Iris/Math/Vector3.hpp>
#include <iris/Math/Matrix4x4.hpp>

namespace Iris
{
	Quaternion::Quaternion(value_type _w, const Vector3& _vector) noexcept
		: w(_w), x(_vector.x), y(_vector.y), z(_vector.z)
	{}

	Quaternion Quaternion::Slerp(const Quaternion& from, const Quaternion& to, float32 t)
	{
		auto cosTheta = from.dot(to);
		Quaternion oq = to;

		if (cosTheta < 0.f)
		{
			oq = -to;
			cosTheta = -cosTheta;
		}

		const auto DotThreshold = 0.9995f;

		if (cosTheta > DotThreshold)
		{
			return Lerp(from, oq, t).normalize();
		}

		const auto theta = Math::ArcCos(cosTheta);
		const auto invSinTheta = 1.f / Math::Sin(theta);
		const auto w1 = Math::Sin((1.f - t) * theta) * invSinTheta;
		const auto w2 = Math::Sin(t * theta) * invSinTheta;

		return ((from * w1) + (oq * w2)).normalize();
	}

	Quaternion Quaternion::FromAxisAngle(const Vector3& axis, float32 radian) noexcept
	{
		const auto halfAngle = radian * 0.5f;
		const auto sin = Math::Sin(halfAngle);
		return Quaternion{ Math::Cos(halfAngle),axis * sin };
	}

	Quaternion Quaternion::FromMatrix4x4(const Matrix4x4& matrix)
	{
		const auto trace = matrix.m00 + matrix.m11 + matrix.m22;

		Quaternion result{};

		if (trace > 0.f)
		{
			const auto s = 0.5f / Math::Sqrt(trace + 1.f);
			result.w = 0.25f / s;
			result.x = (matrix.m21 - matrix.m12) * s;
			result.y = (matrix.m02 - matrix.m20) * s;
			result.z = (matrix.m10 - matrix.m01) * s;
		}
		else
		{
			if (matrix.m00 > matrix.m11 && matrix.m00 > matrix.m22) {
				const auto s = 2.f * Math::Sqrt(1.f + matrix.m00 - matrix.m11 - matrix.m22);
				result.w = (matrix.m21 - matrix.m12) / s;
				result.x = 0.25f * s;
				result.y = (matrix.m01 + matrix.m10) / s;
				result.z = (matrix.m02 + matrix.m20) / s;
			}
			else if (matrix.m11 > matrix.m22)
			{
				const auto s = 2.f * Math::Sqrt(1.f + matrix.m11 - matrix.m00 - matrix.m22);
				result.w = (matrix.m02 - matrix.m20) / s;
				result.x = (matrix.m01 + matrix.m10) / s;
				result.y = 0.25f * s;
				result.z = (matrix.m12 + matrix.m21) / s;
			}
			else 
			{
				const auto s = 2.f * Math::Sqrt(1.f + matrix.m22 - matrix.m00 - matrix.m11);
				result.w = (matrix.m10 - matrix.m01) / s;
				result.x = (matrix.m02 + matrix.m20) / s;
				result.y = (matrix.m12 + matrix.m21) / s;
				result.z = 0.25f * s;
			}
		}

		return result.normalize();
	}
}