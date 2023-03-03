#pragma once

#ifndef _USE_MATH_DEFINES
	#define _USE_MATH_DEFINES
#endif

#include <cmath>

#include <Iris/Common/Numeric.hpp>

namespace Iris::Math
{
	static constexpr float32 Pi = static_cast<float32>(M_PI);

	static constexpr float32 ToRadian = Pi / 180.f;

	static constexpr float32 ToDegree = 180.f / Pi;

	static constexpr float32 Epsilon = std::numeric_limits<float32>::epsilon();

	template<class T>
	inline constexpr float32 Square(T x)
	{
		return x * x;
	}

	template<class T>
	inline float32 Sqrt(T x)
	{
		return std::sqrtf(x);
	}

	template<class T>
	inline float32 Sin(T x)
	{
		return std::sinf(x);
	}

	template<class T>
	inline float32 Cos(T x)
	{
		return std::cosf(x);
	}

	template<class T>
	inline float32 Tan(T x)
	{
		return std::tanf(x);
	}

	template<class T>
	inline float32 ArcSin(T x)
	{
		return std::asinf(x);
	}

	template<class T>
	inline float32 ArcCos(T x)
	{
		return std::acosf(x);
	}

	template<class T>
	inline float32 ArcTan(T x)
	{
		return std::atanf(x);
	}

	template<class T>
	inline float32 ArcTan2(T x, T y)
	{
		return std::atan2f(y, x);
	}
}

namespace Iris::MathLiterals
{
	inline constexpr float32 operator"" _rad(size_t n) noexcept
	{
		return static_cast<float32>(Math::ToRadian * n);
	}

	inline constexpr float32 operator"" _rad(long double n) noexcept
	{
		return static_cast<float32>(Math::ToRadian * n);
	}

	inline constexpr float32 operator"" _deg(size_t n) noexcept
	{
		return static_cast<float32>(Math::ToDegree * n);
	}

	inline constexpr float32 operator"" _deg(long double n) noexcept
	{
		return static_cast<float32>(Math::ToDegree * n);
	}
}

using namespace Iris::MathLiterals;