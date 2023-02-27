#pragma once

#include <Iris/Math/Math.hpp>

namespace Iris
{
	struct Vector3 final
	{
		using value_type = float32;
		using primitive_type = typename value_type::value_type;

		constexpr Vector3()noexcept;

		template<Concept::Arithmetic X, Concept::Arithmetic Y, Concept::Arithmetic Z>
		constexpr Vector3(X _x, Y _y, Z _z)noexcept;

		constexpr Vector3(std::initializer_list<value_type> _iniList);

		constexpr Vector3(const Vector3&)noexcept = default;

		constexpr Vector3(Vector3&&)noexcept = default;

		constexpr ~Vector3()noexcept = default;

		constexpr Vector3& operator=(std::initializer_list<value_type> _iniList);

		constexpr Vector3& operator=(const Vector3&)noexcept = default;

		constexpr Vector3& operator=(Vector3&&)noexcept = default;

		constexpr Vector3 operator-()const noexcept;

		explicit constexpr operator bool()const noexcept;

		constexpr float32 lengthSq()const noexcept;

		float32 length()const noexcept;

		constexpr float32 distanceSq(const Vector3& _other)const noexcept;

		float32 distance(const Vector3& _other)const noexcept;

		constexpr float32 dot(const Vector3& _other)const noexcept;

		constexpr Vector3 cross(const Vector3& _other)const noexcept;

		constexpr Vector3 inverse()const noexcept;

		Vector3 normalize()const noexcept;

		Vector3 project(const Vector3& _other)const noexcept;

		Vector3 reflect(const Vector3& _normal)const noexcept;

		constexpr Vector3 lerp(const Vector3& _destination, float32 _progress)const noexcept;

		Vector3 slerp(const Vector3& _destination, float32 _progress)const;

		constexpr bool isZero()const noexcept;

		constexpr bool hasZero()const noexcept;

		static constexpr Vector3 Zero()noexcept;

		static constexpr Vector3 One(float32 _scale = 1.f)noexcept;

		static constexpr Vector3 Right(float32 _scale = 1.f)noexcept;

		static constexpr Vector3 Left(float32 _scale = 1.f)noexcept;

		static constexpr Vector3 Up(float32 _scale = 1.f)noexcept;

		static constexpr Vector3 Down(float32 _scale = 1.f)noexcept;

		static constexpr Vector3 Forward(float32 _scale = 1.f)noexcept;

		static constexpr Vector3 Back(float32 _scale = 1.f)noexcept;

		template<Concept::Arithmetic X, Concept::Arithmetic Y, Concept::Arithmetic Z>
		static Vector3 MakeUnit(X _x, Y _y, Z _z);

		union
		{
			struct
			{
				value_type x, y, z;
			};

			primitive_type data[3];
		};
	};
}

namespace Iris
{
	inline constexpr Vector3 operator+(const Vector3& left, const Vector3& right) noexcept
	{
		return Vector3{ left.x + right.x,left.y + right.y,left.z + right.z };
	}

	inline constexpr Vector3 operator+(const Vector3& left, float32 right) noexcept
	{
		return Vector3{ left.x + right,left.y + right,left.z + right };
	}

	inline constexpr Vector3 operator-(const Vector3& left, const Vector3& right) noexcept
	{
		return Vector3{ left.x - right.x,left.y - right.y,left.z - right.z };
	}

	inline constexpr Vector3 operator-(const Vector3& left, float32 right) noexcept
	{
		return Vector3{ left.x - right,left.y - right,left.z - right };
	}

	inline constexpr Vector3 operator*(const Vector3& left, const Vector3& right) noexcept
	{
		return Vector3{ left.x * right.x,left.y * right.y,left.z * right.z };
	}

	inline constexpr Vector3 operator*(const Vector3& left, float32 right) noexcept
	{
		return Vector3{ left.x * right,left.y * right,left.z * right };
	}

	inline constexpr Vector3 operator/(const Vector3& left, const Vector3& right)
	{
		if (right.hasZero())
			throw Error::ZeroDivisionException{ "operator/(Vector3,Vector3)" };
		return Vector3{ left.x / right.x,left.y / right.y,left.z / right.z };
	}

	inline constexpr Vector3 operator/(const Vector3& left, float32 right)
	{
		if (right == 0.f)
			throw Error::ZeroDivisionException{ "operator/(Vector3,float32)" };
		return Vector3{ left.x / right,left.y / right,left.z / right };
	}

	inline constexpr Vector3& operator+=(Vector3& left, const Vector3& right) noexcept
	{
		left.x += right.x;
		left.y += right.y;
		left.z += right.z;
		return left;
	}

	inline constexpr Vector3& operator+=(Vector3& left, float32 right) noexcept
	{
		left.x += right;
		left.y += right;
		left.z += right;
		return left;
	}

	inline constexpr Vector3& operator-=(Vector3& left, const Vector3& right) noexcept
	{
		left.x -= right.x;
		left.y -= right.y;
		left.z -= right.z;
		return left;
	}

	inline constexpr Vector3& operator-=(Vector3& left, float32 right) noexcept
	{
		left.x -= right;
		left.y -= right;
		left.z -= right;
		return left;
	}

	inline constexpr Vector3& operator*=(Vector3& left, const Vector3& right) noexcept
	{
		left.x *= right.x;
		left.y *= right.y;
		left.z *= right.z;
		return left;
	}

	inline constexpr Vector3& operator*=(Vector3& left, float32 right) noexcept
	{
		left.x *= right;
		left.y *= right;
		left.z *= right;
		return left;
	}

	inline constexpr Vector3& operator/=(Vector3& left, const Vector3& right)
	{
		if (right.hasZero())
			throw Error::ZeroDivisionException{ "operator/=(Vector3,Vector3)" };
		left.x /= right.x;
		left.y /= right.y;
		left.z /= right.z;
		return left;
	}

	inline constexpr Vector3& operator/=(Vector3& left, float32 right)
	{
		if (right == 0.f)
			throw Error::ZeroDivisionException{ "operator/=(Vector3,float32)" };
		left.x /= right;
		left.y /= right;
		left.z /= right;
		return left;
	}

	inline constexpr bool operator==(const Vector3& left, const Vector3& right) noexcept
	{
		return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
	}

	inline constexpr bool operator!=(const Vector3& left, const Vector3& right) noexcept
	{
		return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
	}

	inline constexpr bool operator<(const Vector3& left, const Vector3& right) noexcept
	{
		return left.lengthSq() < right.lengthSq();
	}

	inline constexpr bool operator>(const Vector3& left, const Vector3& right) noexcept
	{
		return left.lengthSq() > right.lengthSq();
	}

	inline constexpr bool operator<=(const Vector3& left, const Vector3& right) noexcept
	{
		return left.lengthSq() <= right.lengthSq();
	}

	inline constexpr bool operator>=(const Vector3& left, const Vector3& right) noexcept
	{
		return left.lengthSq() >= right.lengthSq();
	}
}

namespace Iris
{
	inline constexpr Vector3::Vector3() noexcept
		: x(0), y(0), z(0)
	{}

	template<Concept::Arithmetic X, Concept::Arithmetic Y, Concept::Arithmetic Z>
	inline constexpr Vector3::Vector3(X _x, Y _y, Z _z) noexcept
		: x(static_cast<value_type>(_x)), y(static_cast<value_type>(_y)), z(static_cast<value_type>(_z))
	{}

	inline constexpr Vector3::Vector3(std::initializer_list<value_type> _iniList)
		: x(*(_iniList.begin())), y(*(_iniList.begin() + 1)), z(*(_iniList.begin() + 2))
	{}

	inline constexpr Vector3& Vector3::operator=(std::initializer_list<value_type> _iniList)
	{
		x = *(_iniList.begin());
		y = *(_iniList.begin() + 1);
		z = *(_iniList.begin() + 2);
		return *this;
	}

	inline constexpr Vector3 Vector3::operator-() const noexcept
	{
		return Vector3{ -x,-y,-z };
	}

	inline constexpr Vector3::operator bool() const noexcept
	{
		return !isZero();
	}

	inline constexpr float32 Vector3::lengthSq() const noexcept
	{
		return (x * x) + (y * y) + (z * z);
	}

	inline float32 Vector3::length() const noexcept
	{
		return Math::Sqrt(lengthSq());
	}

	inline constexpr float32 Vector3::distanceSq(const Vector3& _other) const noexcept
	{
		return Math::Square(_other.x - x) + Math::Square(_other.y - y) + Math::Square(_other.z - z);
	}

	inline float32 Vector3::distance(const Vector3& _other) const noexcept
	{
		return Math::Sqrt(distanceSq(_other));
	}

	inline constexpr float32 Vector3::dot(const Vector3& _other) const noexcept
	{
		return (x * _other.x) + (y * _other.y) + (z * _other.z);
	}

	inline constexpr Vector3 Vector3::cross(const Vector3& _other) const noexcept
	{
		return Vector3
		{
			(y * _other.z) - (z * _other.y),
			(z * _other.x) - (x * _other.z),
			(x * _other.y) - (y * _other.x)
		};
	}

	inline constexpr Vector3 Vector3::inverse() const noexcept
	{
		return Vector3{ -x,-y,-z };
	}

	inline Vector3 Vector3::normalize() const noexcept
	{
		const auto myLength = length();

		if (myLength < 1.f)
			return *this;

		return (*this) / myLength;
	}

	inline Vector3 Vector3::project(const Vector3& _other) const noexcept
	{
		const auto dotProduct = dot(_other);
		const auto otherLenSq = _other.lengthSq();
		const auto scalar = dotProduct / otherLenSq;
		return _other * scalar;
	}

	inline Vector3 Vector3::reflect(const Vector3& _normal) const noexcept
	{
		const auto v = normalize();
		const auto a = v.inverse().dot(_normal);
		const auto reflected = v + (_normal * (a * 2));
		return reflected;
	}

	inline constexpr Vector3 Vector3::lerp(const Vector3& _destination, float32 _progress) const noexcept
	{
		return (*this) + ((_destination - (*this)) * _progress);
	}

	inline Vector3 Vector3::slerp(const Vector3& _destination, float32 _progress) const
	{
		auto v1 = this->normalize();
		auto v2 = _destination.normalize();

		auto dotProduct = v1.dot(v2);

		if (dotProduct < 0.f)
		{
			v2 = v2.inverse();
			dotProduct = -dotProduct;
		}

		const auto DotThreshold = 0.99995_f32;

		if (dotProduct > DotThreshold)
		{
			return lerp(_destination, _progress);
		}

		const auto theta = Math::ArcCos(dotProduct) * _progress;

		const auto relativeVec = (v2 - (v1 * dotProduct)).normalize();

		const auto len1 = this->length();
		const auto len2 = _destination.length();

		const auto newLength = len1 + (len2 - len1) * _progress;

		return (v1 * Math::Cos(theta) + relativeVec * Math::Sin(theta)) * newLength;
	}

	inline constexpr bool Vector3::isZero() const noexcept
	{
		return (x == 0) && (y == 0) && (z == 0);
	}

	inline constexpr bool Vector3::hasZero() const noexcept
	{
		return (x == 0) || (y == 0) || (z == 0);
	}

	inline constexpr Vector3 Vector3::Zero() noexcept
	{
		return Vector3{ 0,0,0 };
	}

	inline constexpr Vector3 Vector3::One(float32 _scale) noexcept
	{
		return Vector3{ 1,1,1 }*_scale;
	}

	inline constexpr Vector3 Vector3::Right(float32 _scale) noexcept
	{
		return Vector3{ 1,0,0 }*_scale;
	}

	inline constexpr Vector3 Vector3::Left(float32 _scale) noexcept
	{
		return Vector3{ -1,0,0 }*_scale;
	}

	inline constexpr Vector3 Vector3::Up(float32 _scale) noexcept
	{
		return Vector3{ 0,1,0 } *_scale;
	}

	inline constexpr Vector3 Vector3::Down(float32 _scale) noexcept
	{
		return Vector3{ 0,-1,0 } *_scale;
	}

	inline constexpr Vector3 Vector3::Forward(float32 _scale) noexcept
	{
		return Vector3{ 0,0,1 } *_scale;
	}

	inline constexpr Vector3 Vector3::Back(float32 _scale) noexcept
	{
		return Vector3{ 0,0,-1 } *_scale;
	}

	template<Concept::Arithmetic X, Concept::Arithmetic Y, Concept::Arithmetic Z>
	inline Vector3 Vector3::MakeUnit(X _x, Y _y, Z _z)
	{
		return Vector3{ _x,_y,_z }.normalize();
	}

}