#include <Iris/Math/Matrix4x4.hpp>
#include <Iris/Math/Vector3.hpp>

namespace Iris
{
	float32 Matrix4x4::determinant() const noexcept
	{
		
		return m00 * m11 * m22 * m33 + m00 * m12 * m23 * m31 + m00 * m13 * m21 * m32
			 + m01 * m10 * m23 * m32 + m01 * m12 * m20 * m33 + m01 * m13 * m22 * m30
			 + m02 * m10 * m21 * m33 + m02 * m11 * m23 * m30 + m02 * m13 * m20 * m31
			 + m03 * m10 * m22 * m31 + m03 * m11 * m20 * m32 + m03 * m12 * m21 * m30
			 - m00 * m11 * m23 * m32 - m00 * m12 * m21 * m33 - m00 * m13 * m22 * m31
			 - m01 * m10 * m22 * m33 - m01 * m12 * m23 * m30 - m01 * m13 * m20 * m32
			 - m02 * m10 * m23 * m31 - m02 * m11 * m20 * m33 - m02 * m13 * m21 * m30
			 - m03 * m10 * m21 * m32 - m03 * m11 * m22 * m30 - m03 * m12 * m20 * m31;
	}

	Matrix4x4 Matrix4x4::adjoint() const
	{
		Matrix4x4 adjoint{};

		adjoint.m[0][0] = m[1][1] * m[2][2] * m[3][3] + m[1][2] * m[2][3] * m[3][1] + m[1][3] * m[2][1] * m[3][2] - m[1][1] * m[2][3] * m[3][2] - m[1][2] * m[2][1] * m[3][3] - m[1][3] * m[2][2] * m[3][1];
		adjoint.m[0][1] = m[0][1] * m[2][3] * m[3][2] + m[0][2] * m[2][1] * m[3][3] + m[0][3] * m[2][2] * m[3][1] - m[0][1] * m[2][2] * m[3][3] - m[0][2] * m[2][3] * m[3][1] - m[0][3] * m[2][1] * m[3][2];
		adjoint.m[0][2] = m[0][1] * m[1][2] * m[3][3] + m[0][2] * m[1][3] * m[3][1] + m[0][3] * m[1][1] * m[3][2] - m[0][1] * m[1][3] * m[3][2] - m[0][2] * m[1][1] * m[3][3] - m[0][3] * m[1][2] * m[3][1];
		adjoint.m[0][3] = m[0][1] * m[1][3] * m[2][2] + m[0][2] * m[1][1] * m[2][3] + m[0][3] * m[1][2] * m[2][1] - m[0][1] * m[1][2] * m[2][3] - m[0][2] * m[1][3] * m[2][1] - m[0][3] * m[1][1] * m[2][2];

		adjoint.m[1][0] = m[1][0] * m[2][3] * m[3][2] + m[1][2] * m[2][0] * m[3][3] + m[1][3] * m[2][2] * m[3][0] - m[1][0] * m[2][2] * m[3][3] - m[1][2] * m[2][3] * m[3][0] - m[1][3] * m[2][0] * m[3][2];
		adjoint.m[1][1] = m[0][0] * m[2][2] * m[3][3] + m[0][2] * m[2][3] * m[3][0] + m[0][1] * m[2][0] * m[3][2] - m[0][0] * m[2][3] * m[3][2] - m[0][2] * m[2][0] * m[3][3] - m[0][3] * m[2][2] * m[3][0];
		adjoint.m[1][2] = m[0][0] * m[1][3] * m[3][2] + m[0][2] * m[1][0] * m[3][3] + m[0][3] * m[1][2] * m[3][0] - m[0][0] * m[1][2] * m[3][3] - m[0][2] * m[1][3] * m[3][0] - m[0][3] * m[1][0] * m[3][2];
		adjoint.m[1][3] = m[0][0] * m[1][2] * m[2][3] + m[0][2] * m[1][3] * m[2][0] + m[0][3] * m[1][0] * m[2][2] - m[0][0] * m[1][3] * m[2][2] - m[0][2] * m[1][0] * m[2][3] - m[0][3] * m[1][2] * m[2][0];

		adjoint.m[2][0] = m[1][0] * m[2][1] * m[3][3] + m[1][1] * m[2][3] * m[3][0] + m[1][3] * m[2][0] * m[3][1] - m[1][0] * m[2][3] * m[3][1] - m[1][1] * m[2][0] * m[3][3] - m[1][3] * m[2][1] * m[3][0];
		adjoint.m[2][1] = m[0][0] * m[2][3] * m[3][1] + m[0][1] * m[2][0] * m[3][3] + m[0][3] * m[2][1] * m[3][0] - m[0][0] * m[2][1] * m[3][3] - m[0][1] * m[2][3] * m[3][0] - m[0][3] * m[2][0] * m[3][1];
		adjoint.m[2][2] = m[0][0] * m[1][1] * m[3][3] + m[0][1] * m[1][3] * m[3][0] + m[0][3] * m[1][0] * m[3][1] - m[0][0] * m[1][3] * m[3][1] - m[0][1] * m[1][0] * m[3][3] - m[0][3] * m[1][1] * m[3][0];
		adjoint.m[2][3] = m[0][0] * m[1][3] * m[2][1] + m[0][1] * m[1][0] * m[2][3] + m[0][3] * m[1][1] * m[2][0] - m[0][0] * m[1][1] * m[2][3] - m[0][1] * m[1][3] * m[2][0] - m[0][3] * m[1][0] * m[2][1];
		
		adjoint.m[3][0] = m[1][0] * m[2][2] * m[3][1] + m[1][1] * m[2][0] * m[3][2] + m[1][2] * m[2][1] * m[3][0] - m[1][0] * m[2][1] * m[3][2] - m[1][1] * m[2][2] * m[3][0] - m[1][2] * m[2][0] * m[3][1];
		adjoint.m[3][1] = m[0][0] * m[2][1] * m[3][2] + m[0][1] * m[2][2] * m[3][0] + m[0][2] * m[2][0] * m[3][1] - m[0][0] * m[2][2] * m[3][1] - m[0][1] * m[2][0] * m[3][2] - m[0][2] * m[2][1] * m[3][0];
		adjoint.m[3][2] = m[0][0] * m[1][2] * m[3][1] + m[0][1] * m[1][0] * m[3][2] + m[0][2] * m[1][1] * m[3][0] - m[0][0] * m[1][1] * m[3][2] - m[0][1] * m[1][2] * m[3][0] - m[0][2] * m[1][0] * m[3][1];
		adjoint.m[3][3] = m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] - m[0][0] * m[1][2] * m[2][1] - m[0][1] * m[1][0] * m[2][2] - m[0][2] * m[1][1] * m[2][0];

		return adjoint;
	}

	Matrix4x4 Matrix4x4::transpose() const noexcept
	{
		Matrix4x4 result;

		result.m[0][1] = m[1][0];
		result.m[0][2] = m[2][0];
		result.m[0][3] = m[3][0];

		result.m[1][0] = m[0][1];
		result.m[1][2] = m[2][1];
		result.m[1][3] = m[3][1];

		result.m[2][0] = m[0][2];
		result.m[2][1] = m[1][2];
		result.m[2][3] = m[3][2];

		result.m[3][0] = m[0][3];
		result.m[3][1] = m[1][3];
		result.m[3][2] = m[2][3];

		return result;
	}

	Matrix4x4 Matrix4x4::inverse() const
	{
		const auto det = determinant();

		if (det == 0.f)
		{
			return Matrix4x4::Identity();
		}

		const auto adj = adjoint();

		return adj * (1.f / det);
	}

	Matrix4x4 Matrix4x4::Translate(const Vector3& vector) noexcept
	{
		Matrix4x4 result{};

		result.m[3][0] = vector.x;
		result.m[3][1] = vector.y;
		result.m[3][2] = vector.z;

		return result;
	}

	Matrix4x4 Matrix4x4::RotateX(float32 radian)
	{
		const auto cos = Math::Cos(radian);
		const auto sin = Math::Sin(radian);

		return Matrix4x4
		{
			1.f,0.f,0.f,0.f,
			0.f,cos,sin,0.f,
			0.f,-sin,cos,0.f,
			0.f,0.f,0.f,1.f
		};
	}

	Matrix4x4 Matrix4x4::RotateY(float32 radian)
	{
		const auto cos = Math::Cos(radian);
		const auto sin = Math::Sin(radian);

		return Matrix4x4
		{
			cos,0.f,-sin,0.f,
			0.f,1.f,0.f,0.f,
			sin,0.f,cos,0.f,
			0.f,0.f,0.f,1.f
		};
	}

	Matrix4x4 Matrix4x4::RotateZ(float32 radian)
	{
		const auto cos = Math::Cos(radian);
		const auto sin = Math::Sin(radian);

		return Matrix4x4
		{
			cos,sin,0.f,0.f,
			-sin,cos,0.f,0.f,
			0.f,0.f,1.f,0.f,
			0.f,0.f,0.f,1.f
		};
	}

	Matrix4x4 Matrix4x4::Scaling(const Vector3& vector) noexcept
	{
		return Matrix4x4
		{
			vector.x,0.f,0.f,0.f,
			0.f,vector.y,0.f,0.f,
			0.f,0.f,vector.z,0.f,
			0.f,0.f,0.f,1.f
		};
	}

	Matrix4x4 Matrix4x4::Scaling(float32 scale) noexcept
	{
		return Matrix4x4
		{
			scale,0.f,0.f,0.f,
			0.f,scale,0.f,0.f,
			0.f,0.f,scale,0.f,
			0.f,0.f,0.f,1.f
		};
	}

	Matrix4x4 Matrix4x4::FromAxisAngle(const Vector3& axis, float32 radian)
	{
		const auto cos = Math::Cos(radian);
		const auto sin = Math::Sin(radian);

		const auto t = 1.f - cos;

		const auto [x, y, z] = axis.data;

		const auto xx = x * x;
		const auto yy = y * y;
		const auto zz = z * z;
		const auto xy = x * y;
		const auto xz = x * z;
		const auto yz = y * z;

		Matrix4x4 result{};

		result.m00 = t * xx + cos;
		result.m01 = t * xy + sin * z;
		result.m02 = t * xz - sin * y;

		result.m10 = t * xy - sin * z;
		result.m11 = t * yy + cos;
		result.m12 = t * yz + sin * x;

		result.m20 = t * xz + sin * y;
		result.m21 = t * yz - sin * x;
		result.m22 = t * zz + cos;

		return result;
	}

	Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right) noexcept
	{
		Matrix4x4 result{};

		result.m00 = left.m00 * right.m00 + left.m01 * right.m10 + left.m02 * right.m20 + left.m03 * right.m30;
		result.m01 = left.m00 * right.m01 + left.m01 * right.m11 + left.m02 * right.m21 + left.m03 * right.m31;
		result.m02 = left.m00 * right.m02 + left.m01 * right.m12 + left.m02 * right.m22 + left.m03 * right.m32;
		result.m03 = left.m00 * right.m03 + left.m01 * right.m13 + left.m02 * right.m23 + left.m03 * right.m33;

		result.m10 = left.m10 * right.m00 + left.m11 * right.m10 + left.m12 * right.m20 + left.m13 * right.m30;
		result.m11 = left.m10 * right.m01 + left.m11 * right.m11 + left.m12 * right.m21 + left.m13 * right.m31;
		result.m12 = left.m10 * right.m02 + left.m11 * right.m12 + left.m12 * right.m22 + left.m13 * right.m32;
		result.m13 = left.m10 * right.m03 + left.m11 * right.m13 + left.m12 * right.m23 + left.m13 * right.m33;

		result.m20 = left.m20 * right.m00 + left.m21 * right.m10 + left.m22 * right.m20 + left.m23 * right.m30;
		result.m21 = left.m20 * right.m01 + left.m21 * right.m11 + left.m22 * right.m21 + left.m23 * right.m31;
		result.m22 = left.m20 * right.m02 + left.m21 * right.m12 + left.m22 * right.m22 + left.m23 * right.m32;
		result.m23 = left.m20 * right.m03 + left.m21 * right.m13 + left.m22 * right.m23 + left.m23 * right.m33;

		result.m30 = left.m30 * right.m00 + left.m31 * right.m10 + left.m32 * right.m20 + left.m33 * right.m30;
		result.m31 = left.m30 * right.m01 + left.m31 * right.m11 + left.m32 * right.m21 + left.m33 * right.m31;
		result.m32 = left.m30 * right.m02 + left.m31 * right.m12 + left.m32 * right.m22 + left.m33 * right.m32;
		result.m33 = left.m30 * right.m03 + left.m31 * right.m13 + left.m32 * right.m23 + left.m33 * right.m33;

		return result;
	}

	Matrix4x4 operator*(const Matrix4x4& left, float32 right) noexcept
	{
		Matrix4x4 result;

		result.m00 = left.m00 * right; result.m01 = left.m01 * right; result.m02 = left.m02 * right; result.m03 = left.m03 * right;
		result.m10 = left.m10 * right; result.m11 = left.m11 * right; result.m12 = left.m12 * right; result.m13 = left.m13 * right;
		result.m20 = left.m20 * right; result.m21 = left.m21 * right; result.m22 = left.m22 * right; result.m23 = left.m23 * right;
		result.m30 = left.m30 * right; result.m31 = left.m31 * right; result.m32 = left.m32 * right; result.m33 = left.m33 * right;

		return result;
	}

	Matrix4x4& operator*=(Matrix4x4& left, const Matrix4x4& right) noexcept
	{
		left.m00 = left.m00 * right.m00 + left.m01 * right.m10 + left.m02 * right.m20 + left.m03 * right.m30;
		left.m01 = left.m00 * right.m01 + left.m01 * right.m11 + left.m02 * right.m21 + left.m03 * right.m31;
		left.m02 = left.m00 * right.m02 + left.m01 * right.m12 + left.m02 * right.m22 + left.m03 * right.m32;
		left.m03 = left.m00 * right.m03 + left.m01 * right.m13 + left.m02 * right.m23 + left.m03 * right.m33;

		left.m10 = left.m10 * right.m00 + left.m11 * right.m10 + left.m12 * right.m20 + left.m13 * right.m30;
		left.m11 = left.m10 * right.m01 + left.m11 * right.m11 + left.m12 * right.m21 + left.m13 * right.m31;
		left.m12 = left.m10 * right.m02 + left.m11 * right.m12 + left.m12 * right.m22 + left.m13 * right.m32;
		left.m13 = left.m10 * right.m03 + left.m11 * right.m13 + left.m12 * right.m23 + left.m13 * right.m33;

		left.m20 = left.m20 * right.m00 + left.m21 * right.m10 + left.m22 * right.m20 + left.m23 * right.m30;
		left.m21 = left.m20 * right.m01 + left.m21 * right.m11 + left.m22 * right.m21 + left.m23 * right.m31;
		left.m22 = left.m20 * right.m02 + left.m21 * right.m12 + left.m22 * right.m22 + left.m23 * right.m32;
		left.m23 = left.m20 * right.m03 + left.m21 * right.m13 + left.m22 * right.m23 + left.m23 * right.m33;

		left.m30 = left.m30 * right.m00 + left.m31 * right.m10 + left.m32 * right.m20 + left.m33 * right.m30;
		left.m31 = left.m30 * right.m01 + left.m31 * right.m11 + left.m32 * right.m21 + left.m33 * right.m31;
		left.m32 = left.m30 * right.m02 + left.m31 * right.m12 + left.m32 * right.m22 + left.m33 * right.m32;
		left.m33 = left.m30 * right.m03 + left.m31 * right.m13 + left.m32 * right.m23 + left.m33 * right.m33;

		return left;
	}

	Matrix4x4& operator*=(Matrix4x4& left, float32 right) noexcept
	{
		left.m00 *= right; left.m01 *= right; left.m02 *= right; left.m03 *= right;
		left.m10 *= right; left.m11 *= right; left.m12 *= right; left.m13 *= right;
		left.m20 *= right; left.m21 *= right; left.m22 *= right; left.m23 *= right;
		left.m30 *= right; left.m31 *= right; left.m32 *= right; left.m33 *= right;
		return left;
	}
}