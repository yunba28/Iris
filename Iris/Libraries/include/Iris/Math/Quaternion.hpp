#pragma once

#include <Iris/Math/Math.hpp>

namespace Iris
{
	struct Vector3;
	struct Matrix4x4;

	struct Quaternion final
	{
		using value_type = float32;

		constexpr Quaternion()noexcept;

		template<Concept::Arithmetic W, Concept::Arithmetic X, Concept::Arithmetic Y, Concept::Arithmetic Z>
		constexpr Quaternion(W _w, X _x, Y _y, Z _z)noexcept;

		constexpr Quaternion(std::initializer_list<value_type> _iniList);

		Quaternion(value_type _w, const Vector3& _vector)noexcept;

		constexpr Quaternion(const Quaternion&)noexcept = default;

		constexpr Quaternion(Quaternion&&)noexcept = default;

		constexpr ~Quaternion()noexcept = default;

		constexpr Quaternion& operator=(std::initializer_list<value_type> _iniList);

		constexpr Quaternion& operator=(const Quaternion&)noexcept = default;

		constexpr Quaternion& operator=(Quaternion&&)noexcept = default;

		constexpr Quaternion operator-()const noexcept;

		explicit constexpr operator bool()const noexcept;

		constexpr float32 lengthSq()const noexcept;

		float32 length()const noexcept;

		constexpr float32 dot(const Quaternion& _other)const noexcept;

		constexpr Quaternion inverse()const noexcept;

		constexpr Quaternion conjugate()const noexcept;

		Quaternion normalize()const noexcept;

		Quaternion normalize(float32 _threshold)const noexcept;

		static constexpr Quaternion Identity()noexcept;

		static Quaternion FromAxisAngle(const Vector3& axis, float32 radian)noexcept;

		static Quaternion FromMatrix4x4(const Matrix4x4& matrix);
			
		static constexpr Quaternion Lerp(const Quaternion& from, const Quaternion& to, float32 t)noexcept;

		static Quaternion Slerp(const Quaternion& from, const Quaternion& to, float32 t);

		union
		{
			struct
			{
				value_type w;
				value_type x;
				value_type y;
				value_type z;
			};

			value_type data[4];
		};
	};
}

namespace Iris
{
	inline constexpr Quaternion operator+(const Quaternion& left, const Quaternion& right) noexcept
	{
		return Quaternion
		{
			left.w + right.w,
			left.x + right.x,
			left.y + right.y,
			left.z + right.z
		};
	}

	inline constexpr Quaternion operator-(const Quaternion& left, const Quaternion& right) noexcept
	{
		return Quaternion
		{
			left.w - right.w,
			left.x - right.x,
			left.y - right.y,
			left.z - right.z
		};
	}

	inline constexpr Quaternion operator*(const Quaternion& left, const Quaternion& right) noexcept
	{
		return Quaternion
		{
			left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z,
			left.w * right.x + left.x * right.w + left.y * right.z - left.z * right.y,
			left.w * right.y - left.x * right.z + left.y * right.w + left.z * right.x,
			left.w * right.z + left.x * right.y - left.y * right.x + left.z * right.w
		};
	}

	inline constexpr Quaternion operator*(const Quaternion& left, float32 right) noexcept
	{
		return Quaternion
		{
			left.w * right,
			left.x * right,
			left.y * right,
			left.z * right
		};
	}

	inline constexpr Quaternion operator/(const Quaternion& left, float32 right)
	{
		if (right == 0)
			throw Error::ZeroDivisionException{ "operator/(Quaternion,float32)" };

		return Quaternion
		{
			left.w / right,
			left.x / right,
			left.y / right,
			left.z / right
		};
	}

	inline constexpr Quaternion& operator+=(Quaternion& left, const Quaternion& right) noexcept
	{
		left.w += right.w;
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		return left;
	}

	inline constexpr Quaternion& operator-=(Quaternion& left, const Quaternion& right) noexcept
	{
		left.w -= right.w;
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;
		return left;
	}

	inline constexpr Quaternion& operator*=(Quaternion& left, const Quaternion& right) noexcept
	{
		left = Quaternion
		{
			left.w * right.w - left.x * right.x - left.y * right.y - left.z * right.z,
			left.w * right.x + left.x * right.w + left.y * right.z - left.z * right.y,
			left.w * right.y - left.x * right.z + left.y * right.w + left.z * right.x,
			left.w * right.z + left.x * right.y - left.y * right.x + left.z * right.w
		};

		return left;
	}

	inline constexpr Quaternion& operator*=(Quaternion& left, float32 right) noexcept
	{
		left.w *= right;
		left.x *= right;
		left.y *= right;
		left.z *= right;
		return left;
	}

	inline constexpr Quaternion& operator/=(Quaternion& left, float32 right)
	{
		if (right == 0)
			throw Error::ZeroDivisionException{ "operator/=(Quaternion,float32)" };

		left.w /= right;
		left.x /= right;
		left.y /= right;
		left.z /= right;
		return left;
	}

	inline constexpr bool operator==(const Quaternion& left, const Quaternion& right) noexcept
	{
		return (left.w == right.w) && (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
	}

	inline constexpr bool operator!=(const Quaternion& left, const Quaternion& right) noexcept
	{
		return !(left == right);
	}
}

namespace Iris
{
	inline constexpr Quaternion::Quaternion() noexcept
		: w(1), x(0), y(0), z(0)
	{}

	template<Concept::Arithmetic W, Concept::Arithmetic X, Concept::Arithmetic Y, Concept::Arithmetic Z>
	inline constexpr Quaternion::Quaternion(W _w, X _x, Y _y, Z _z) noexcept
		: w(_w), x(_x), y(_y), z(_z)
	{}

	inline constexpr Quaternion::Quaternion(std::initializer_list<value_type> _iniList)
		: w(*(_iniList.begin() + 0))
		, x(*(_iniList.begin() + 1))
		, y(*(_iniList.begin() + 2))
		, z(*(_iniList.begin() + 3))
	{}

	inline constexpr Quaternion& Quaternion::operator=(std::initializer_list<value_type> _iniList)
	{
		w = *(_iniList.begin() + 0);
		x = *(_iniList.begin() + 1);
		y = *(_iniList.begin() + 2);
		z = *(_iniList.begin() + 3);
		return *this;
	}

	inline constexpr Quaternion Quaternion::operator-() const noexcept
	{
		return Quaternion{ -w,-x,-y,-z };
	}

	inline constexpr Quaternion::operator bool() const noexcept
	{
		return w != 0 || x != 0 || y != 0 || z != 0;
	}

	inline constexpr float32 Quaternion::lengthSq() const noexcept
	{
		return (w * w) + (x * x) + (y * y) + (z * z);
	}

	inline float32 Quaternion::length() const noexcept
	{
		return Math::Sqrt(lengthSq());
	}

	inline constexpr float32 Quaternion::dot(const Quaternion& _other) const noexcept
	{
		return (w * w) + (x * x) + (y * y) + (z * z);
	}

	inline constexpr Quaternion Quaternion::inverse() const noexcept
	{
		return conjugate() / lengthSq();
	}

	inline constexpr Quaternion Quaternion::conjugate() const noexcept
	{
		return Quaternion{ w,-x,-y,-z };
	}

	inline Quaternion Quaternion::normalize() const noexcept
	{
		const auto myLength = length();

		if (myLength < Math::Epsilon)
			return *this;

		return (*this) / myLength;
	}

	inline Quaternion Quaternion::normalize(float32 _threshold) const noexcept
	{
		const auto myLength = length();

		if (myLength < _threshold)
			return *this;

		return (*this) / myLength;
	}

	inline constexpr Quaternion Quaternion::Lerp(const Quaternion& from, const Quaternion& to, float32 t)noexcept
	{
		const auto invt = 1.f - t;
		return Quaternion
		{
			invt * from.w + t * to.w,
			invt * from.x + t * to.x,
			invt * from.y + t * to.y,
			invt * from.z + t * to.z
		};
	}

	inline constexpr Quaternion Quaternion::Identity() noexcept
	{
		return Quaternion{ 1,0,0,0 };
	}
}