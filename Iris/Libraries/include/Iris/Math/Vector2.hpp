#pragma once

#include <Iris/Math/Math.hpp>

namespace Iris
{
	struct Vector2 final
	{
		using value_type = float32;
		using primitive_type = typename value_type::value_type;

		constexpr Vector2()noexcept;

		template<Concept::Arithmetic X, Concept::Arithmetic Y>
		constexpr Vector2(X _x, Y _y)noexcept;

		constexpr Vector2(std::initializer_list<value_type> _iniList);

		constexpr Vector2(const Vector2&)noexcept = default;

		constexpr Vector2(Vector2&&)noexcept = default;

		constexpr ~Vector2()noexcept = default;

		constexpr Vector2& operator=(std::initializer_list<value_type> _iniList);

		constexpr Vector2& operator=(const Vector2&)noexcept = default;

		constexpr Vector2& operator=(Vector2&&)noexcept = default;

		constexpr Vector2 operator-()const noexcept;

		explicit constexpr operator bool()const noexcept;

		constexpr float32 lengthSq()const noexcept;

		float32 length()const noexcept;

		constexpr float32 distanceSq(const Vector2& _other)const noexcept;

		float32 distance(const Vector2& _other)const noexcept;

		constexpr float32 dot(const Vector2& _other)const noexcept;

		constexpr float32 cross(const Vector2& _other)const noexcept;

		float32 angle(const Vector2& _base = Vector2{ 1,0 })const noexcept;

		constexpr Vector2 inverse()const noexcept;

		Vector2 normalize()const noexcept;

		Vector2 rotate(float32 _radian)const noexcept;

		Vector2 project(const Vector2& _other)const noexcept;

		Vector2 reflect(const Vector2& _normal)const noexcept;

		constexpr Vector2 lerp(const Vector2& _destination, float32 _progress)const noexcept;

		Vector2 slerp(const Vector2& _destination, float32 _progress)const noexcept;

		constexpr bool isZero()const noexcept;

		constexpr bool hasZero()const noexcept;

		static constexpr Vector2 Zero()noexcept;

		static constexpr Vector2 One(float32 _scale = 1.f)noexcept;

		static constexpr Vector2 Left(float32 _scale = 1.f)noexcept;

		static constexpr Vector2 Right(float32 _scale = 1.f)noexcept;

		static constexpr Vector2 Up(float32 _scale = 1.f)noexcept;

		static constexpr Vector2 Down(float32 _scale = 1.f)noexcept;

		template<Concept::Arithmetic X, Concept::Arithmetic Y>
		static Vector2 MakeUnit(X _x, Y _y);

		static Vector2 FromAngle(float32 _radian)noexcept;

		union
		{
			struct
			{
				value_type x, y;
			};

			primitive_type data[2];
		};

	};
}

namespace Iris
{
	inline constexpr Vector2 operator+(const Vector2& left, const Vector2& right) noexcept
	{
		return Vector2{ left.x + right.x,left.y + right.y };
	}

	inline constexpr Vector2 operator+(const Vector2& left, const float32& right) noexcept
	{
		return Vector2{ left.x + right,left.y + right };
	}

	inline constexpr Vector2 operator-(const Vector2& left, const Vector2& right) noexcept
	{
		return Vector2{ left.x - right.x,left.y - right.y };
	}

	inline constexpr Vector2 operator-(const Vector2& left, const float32& right) noexcept
	{
		return Vector2{ left.x - right,left.y - right };
	}

	inline constexpr Vector2 operator*(const Vector2& left, const Vector2& right) noexcept
	{
		return Vector2{ left.x * right.x,left.y * right.y };
	}

	inline constexpr Vector2 operator*(const Vector2& left, const float32& right) noexcept
	{
		return Vector2{ left.x * right,left.y * right };
	}

	inline constexpr Vector2 operator/(const Vector2& left, const Vector2& right)
	{
		if (right.hasZero())
			throw Error::ZeroDivisionException{ "operator/(Vector2,Vector2)" };
		return Vector2{ left.x / right.x,left.y / right.y };
	}

	inline constexpr Vector2 operator/(const Vector2& left, const float32& right)
	{
		if (right == 0.f)
			throw Error::ZeroDivisionException{ "operator/(Vector2,float32)" };
		return Vector2{ left.x / right,left.y / right };
	}

	inline constexpr Vector2& operator+=(Vector2& left, const Vector2& right) noexcept
	{
		left.x += right.x;
		left.y += right.y;
		return left;
	}

	inline constexpr Vector2& operator+=(Vector2& left, const float32& right) noexcept
	{
		left.x += right;
		left.y += right;
		return left;
	}

	inline constexpr Vector2& operator-=(Vector2& left, const Vector2& right) noexcept
	{
		left.x -= right.x;
		left.y -= right.y;
		return left;
	}

	inline constexpr Vector2& operator-=(Vector2& left, const float32& right) noexcept
	{
		left.x -= right;
		left.y -= right;
		return left;
	}

	inline constexpr Vector2& operator*=(Vector2& left, const Vector2& right) noexcept
	{
		left.x *= right.x;
		left.y *= right.y;
		return left;
	}

	inline constexpr Vector2& operator*=(Vector2& left, const float32& right) noexcept
	{
		left.x *= right;
		left.y *= right;
		return left;
	}

	inline constexpr Vector2& operator/=(Vector2& left, const Vector2& right)
	{
		if (right.hasZero())
			throw Error::ZeroDivisionException{"operator/=(Vector2,Vector2)"};
		left.x /= right.x;
		left.y /= right.y;
		return left;
	}

	inline constexpr Vector2& operator/=(Vector2& left, const float32& right)
	{
		if (right == 0.f)
			throw Error::ZeroDivisionException{ "operator/=(Vector2,float32)" };
		left.x /= right;
		left.y /= right;
		return left;
	}

	inline constexpr bool operator==(const Vector2& left, const Vector2& right) noexcept
	{
		return (left.x == right.x) && (left.y == right.y);
	}

	inline constexpr bool operator!=(const Vector2& left, const Vector2& right) noexcept
	{
		return (left.x != right.x) || (left.y != right.y);
	}

	inline constexpr bool operator<(const Vector2& left, const Vector2& right) noexcept
	{
		return left.lengthSq() < right.lengthSq();
	}

	inline constexpr bool operator>(const Vector2& left, const Vector2& right) noexcept
	{
		return left.lengthSq() > right.lengthSq();
	}

	inline constexpr bool operator<=(const Vector2& left, const Vector2& right) noexcept
	{
		return left.lengthSq() <= right.lengthSq();
	}

	inline constexpr bool operator>=(const Vector2& left, const Vector2& right) noexcept
	{
		return left.lengthSq() >= right.lengthSq();
	}
}

namespace Iris
{
	inline constexpr Vector2::Vector2() noexcept
		: x(0), y(0)
	{}

	template<Concept::Arithmetic X, Concept::Arithmetic Y>
	inline constexpr Vector2::Vector2(X _x, Y _y) noexcept
		: x(static_cast<value_type>(_x)), y(static_cast<value_type>(_y))
	{}

	inline constexpr Vector2::Vector2(std::initializer_list<value_type> _iniList)
		: x(*(_iniList.begin())), y(*(_iniList.begin() + 1))
	{}

	inline constexpr Vector2& Vector2::operator=(std::initializer_list<value_type> _iniList)
	{
		x = *(_iniList.begin());
		y = *(_iniList.begin() + 1);
		return *this;
	}

	inline constexpr Vector2 Vector2::operator-() const noexcept
	{
		return Vector2{ -x,-y };
	}

	inline constexpr Vector2::operator bool() const noexcept
	{
		return x != 0.f || y != 0.f;
	}

	inline constexpr float32 Vector2::lengthSq() const noexcept
	{
		return (x * x) + (y * y);
	}

	inline float32 Vector2::length() const noexcept
	{
		return Math::Sqrt(lengthSq());
	}

	inline constexpr float32 Vector2::distanceSq(const Vector2& _other) const noexcept
	{
		return Math::Square(_other.x - x) + Math::Square(_other.y - y);
	}

	inline float32 Vector2::distance(const Vector2& _other) const noexcept
	{
		return Math::Sqrt(distanceSq(_other));
	}

	inline constexpr float32 Vector2::dot(const Vector2& _other) const noexcept
	{
		return (x * _other.x) + (y * _other.y);
	}

	inline constexpr float32 Vector2::cross(const Vector2& _other) const noexcept
	{
		return (x * _other.y) - (y * _other.x);
	}

	inline float32 Vector2::angle(const Vector2& _base) const noexcept
	{
		const auto dotProduct = _base.dot(*this);
		const auto crossProduct = _base.cross(*this);
		const auto lengthProduct = Math::Sqrt(length() * _base.length());
		
		const auto angle = Math::ArcCos(dotProduct / lengthProduct);

		return (crossProduct < 0.f) ? -angle : angle;
	}

	inline constexpr Vector2 Vector2::inverse() const noexcept
	{
		return Vector2{ -x,-y };
	}

	inline Vector2 Vector2::normalize() const noexcept
	{
		const auto myLength = length();

		if (myLength < 1.f)
			return *this;

		return (*this) / myLength;
	}

	inline Vector2 Vector2::rotate(float32 _radian) const noexcept
	{
		const auto sin = Math::Sin(_radian);
		const auto cos = Math::Cos(_radian);

		return Vector2
		{
			(x * cos) - (y * sin),
			(x * sin) + (y * cos)
		};
	}

	inline Vector2 Vector2::project(const Vector2& _other) const noexcept
	{
		const auto dotProduct = dot(_other);
		const auto otherLenSq = _other.lengthSq();
		const auto scalar = dotProduct / otherLenSq;
		return _other * scalar;
	}

	inline Vector2 Vector2::reflect(const Vector2& _normal) const noexcept
	{
		const auto v = normalize();
		const auto a = v.inverse().dot(_normal);
		const auto reflected = v + (_normal * (a * 2));
		return reflected;
	}

	inline constexpr Vector2 Vector2::lerp(const Vector2& _destination, float32 _progress) const noexcept
	{
		return (*this) + ((_destination - (*this)) * _progress);
	}

	inline Vector2 Vector2::slerp(const Vector2& _destination, float32 _progress) const noexcept
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

	inline constexpr bool Vector2::isZero() const noexcept
	{
		return x == 0.f && y == 0.f;
	}

	inline constexpr bool Vector2::hasZero() const noexcept
	{
		return x == 0.f || y == 0.f;
	}

	inline constexpr Vector2 Vector2::Zero() noexcept
	{
		return Vector2{ 0,0 };
	}

	inline constexpr Vector2 Vector2::One(float32 _scale) noexcept
	{
		return Vector2{ 1,1 } *_scale;
	}

	inline constexpr Vector2 Vector2::Left(float32 _scale) noexcept
	{
		return Vector2{ -1,0 } * _scale;
	}

	inline constexpr Vector2 Vector2::Right(float32 _scale) noexcept
	{
		return Vector2{ 1,0 } * _scale;
	}

	inline constexpr Vector2 Vector2::Up(float32 _scale) noexcept
	{
		return Vector2{ 0,-1 } * _scale;
	}

	inline constexpr Vector2 Vector2::Down(float32 _scale) noexcept
	{
		return Vector2{ 0,1 } * _scale;
	}

	template<Concept::Arithmetic X, Concept::Arithmetic Y>
	inline Vector2 Vector2::MakeUnit(X _x, Y _y)
	{
		return Vector2{ _x,_y }.normalize();
	}

	inline Vector2 Vector2::FromAngle(float32 _radian) noexcept
	{
		return Vector2::Right().rotate(_radian);
	}
}