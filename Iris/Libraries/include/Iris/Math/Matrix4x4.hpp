#pragma once

#include <Iris/Math/Math.hpp>

namespace Iris
{
	struct Vector3;

	struct alignas(16) Matrix4x4 final
	{
		using value_type = float32;

		constexpr Matrix4x4()noexcept;

		template<Concept::Arithmetic T>
		constexpr Matrix4x4(
			T _00, T _01, T _02, T _03,
			T _10, T _11, T _12, T _13,
			T _20, T _21, T _22, T _23,
			T _30, T _31, T _32, T _33)noexcept;

		constexpr value_type* operator[](size_t _index);

		constexpr const value_type* operator[](size_t _index)const;

		float32 determinant()const noexcept;

		Matrix4x4 adjoint()const;

		Matrix4x4 transpose()const noexcept;

		Matrix4x4 inverse()const;

		static constexpr Matrix4x4 Identity()noexcept;

		static Matrix4x4 Translate(const Vector3& vector)noexcept;

		static Matrix4x4 RotateX(float32 radian);

		static Matrix4x4 RotateY(float32 radian);

		static Matrix4x4 RotateZ(float32 radian);

		static Matrix4x4 Scaling(const Vector3& vector)noexcept;

		static Matrix4x4 Scaling(float32 scale)noexcept;

		static Matrix4x4 FromAxisAngle(const Vector3& axis, float32 radian);

		union
		{
			struct
			{
				value_type m0[4];
				value_type m1[4];
				value_type m2[4];
				value_type m3[4];
			};

			struct
			{
				value_type m00, m01, m02, m03;
				value_type m10, m11, m12, m13;
				value_type m20, m21, m22, m23;
				value_type m30, m31, m32, m33;
			};

			value_type m[4][4];

			value_type data[16];
		};
	};
}

namespace Iris
{
	Matrix4x4 operator*(const Matrix4x4& left, const Matrix4x4& right)noexcept;

	Matrix4x4 operator*(const Matrix4x4& left, float32 right)noexcept;

	Matrix4x4& operator*=(Matrix4x4& left, const Matrix4x4& right)noexcept;

	Matrix4x4& operator*=(Matrix4x4& left, float32 right)noexcept;
}

namespace Iris
{
	inline constexpr Matrix4x4::Matrix4x4() noexcept
		: m0{ 1,0,0,0 }
		, m1{ 0,1,0,0 }
		, m2{ 0,0,1,0 }
		, m3{ 0,0,0,1 }
	{}

	template<Concept::Arithmetic T>
	inline constexpr Matrix4x4::Matrix4x4(
		T _00, T _01, T _02, T _03,
		T _10, T _11, T _12, T _13,
		T _20, T _21, T _22, T _23,
		T _30, T _31, T _32, T _33) noexcept
		: m0{ static_cast<value_type>(_00),static_cast<value_type>(_01),static_cast<value_type>(_02),static_cast<value_type>(_03) }
		, m1{ static_cast<value_type>(_10),static_cast<value_type>(_11),static_cast<value_type>(_12),static_cast<value_type>(_13) }
		, m2{ static_cast<value_type>(_20),static_cast<value_type>(_21),static_cast<value_type>(_22),static_cast<value_type>(_23) }
		, m3{ static_cast<value_type>(_30),static_cast<value_type>(_31),static_cast<value_type>(_32),static_cast<value_type>(_33) }
	{}

	inline constexpr typename Matrix4x4::value_type* Matrix4x4::operator[](size_t _index)
	{
		if (_index < 4)
		{
			return m[_index];
		}

		throw Error::OutOfRange{"Matrix4x4::operator[](size_t)"};
	}

	inline constexpr const typename Matrix4x4::value_type* Matrix4x4::operator[](size_t _index) const
	{
		if (_index < 4)
		{
			return m[_index];
		}

		throw Error::OutOfRange{ "Matrix4x4::operator[](size_t)const" };
	}

	inline constexpr Matrix4x4 Matrix4x4::Identity() noexcept
	{
		return Matrix4x4
		{
			1,0,0,0,
			0,1,0,0,
			0,0,1,0,
			0,0,0,1
		};
	}
}