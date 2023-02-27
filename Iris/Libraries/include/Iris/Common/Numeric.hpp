#pragma once

#include <cstdint>
#include <limits>

#include <Iris/Common/Concepts.hpp>
#include <Iris/Common/Exceptions.hpp>

namespace Iris
{
	template <Concept::Arithmetic T>
	struct Numeric final
	{
		using value_type = std::conditional_t<std::is_same_v<T, bool>, std::int8_t, T>;

		explicit constexpr Numeric()noexcept;

		constexpr Numeric(T _value)noexcept;

		template<class U>
		constexpr Numeric(U _value)noexcept;

		constexpr Numeric(const Numeric<T>&)noexcept = default;

		template<class U>
		constexpr Numeric(const Numeric<U>& _numeric)noexcept;

		constexpr Numeric(Numeric<T>&&)noexcept = default;

		template<class U>
			constexpr Numeric(Numeric<U>&& _numeric)noexcept;

		constexpr ~Numeric()noexcept = default;

		constexpr Numeric& operator=(T _value)noexcept;

		template<class U>
		constexpr Numeric& operator=(U _value)noexcept;

		constexpr Numeric& operator=(const Numeric<T>&)noexcept = default;

		template<class U>
		constexpr Numeric& operator=(const Numeric<U>& _numeric)noexcept;

		constexpr Numeric& operator=(Numeric<T>&&)noexcept = default;

		template<class U>
		constexpr Numeric& operator=(Numeric<U>&& _numeric)noexcept;

		constexpr Numeric& operator++()noexcept;

		constexpr Numeric& operator++(int)noexcept;

		constexpr Numeric& operator--()noexcept;

		constexpr Numeric& operator--(int)noexcept;

		constexpr Numeric operator+()const noexcept;

		constexpr Numeric operator-()const noexcept;

		constexpr bool operator!()const noexcept;

		constexpr value_type operator*()const noexcept;

		explicit constexpr operator value_type ()const noexcept;

		explicit constexpr operator bool ()const noexcept;

		template<class T, class U>
		friend constexpr auto operator+(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr auto operator+(Numeric<T> left, U right)noexcept;

		template<class T, class U>
		friend constexpr auto operator-(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr auto operator-(Numeric<T> left, U right)noexcept;

		template<class T, class U>
		friend constexpr auto operator*(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr auto operator*(Numeric<T> left, U right)noexcept;

		template<class T, class U>
		friend constexpr auto operator/(Numeric<T> left, Numeric<U> right);

		template<class T, Concept::Arithmetic U>
		friend constexpr auto operator/(Numeric<T> left, U right);

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr auto operator%(Numeric<T> left, Numeric<U> right);

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr auto operator%(Numeric<T> left, U right);

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr auto operator&(Numeric<T> left, Numeric<U> right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr auto operator&(Numeric<T> left, U right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr auto operator|(Numeric<T> left, Numeric<U> right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr auto operator|(Numeric<T> left, U right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr auto operator^(Numeric<T> left, Numeric<U> right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr auto operator^(Numeric<T> left, U right)noexcept;

		template<Concept::Integral T>
		friend constexpr auto operator~(Numeric<T> numeric)noexcept;

		template<Concept::Integral T>
		friend constexpr auto operator<<(Numeric<T> numeric, size_t shift)noexcept;

		template<Concept::Integral T>
		friend constexpr auto operator<<(Numeric<T> numeric, Numeric<size_t> shift)noexcept;

		template<Concept::Integral T>
		friend constexpr auto operator>>(Numeric<T> numeric, size_t shift)noexcept;

		template<Concept::Integral T>
		friend constexpr auto operator>>(Numeric<T> numeric, Numeric<size_t> shift)noexcept;

		template<class T, class U>
		friend constexpr Numeric<T>& operator+=(Numeric<T>& left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr Numeric<T>& operator+=(Numeric<T>& left, U right)noexcept;

		template<class T, class U>
		friend constexpr Numeric<T>& operator-=(Numeric<T>& left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr Numeric<T>& operator-=(Numeric<T>& left, U right)noexcept;

		template<class T, class U>
		friend constexpr Numeric<T>& operator*=(Numeric<T>& left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr Numeric<T>& operator*=(Numeric<T>& left, U right)noexcept;

		template<class T, class U>
		friend constexpr Numeric<T>& operator/=(Numeric<T>& left, Numeric<U> right);

		template<class T, Concept::Arithmetic U>
		friend constexpr Numeric<T>& operator/=(Numeric<T>& left, U right);

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr Numeric<T>& operator%=(Numeric<T>& left, Numeric<U> right);

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr Numeric<T>& operator%=(Numeric<T>& left, U right);

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr Numeric<T>& operator&=(Numeric<T>& left, Numeric<U> right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr Numeric<T>& operator&=(Numeric<T>& left, U right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr Numeric<T>& operator|=(Numeric<T>& left, Numeric<U> right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr Numeric<T>& operator|=(Numeric<T>& left, U right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr Numeric<T>& operator^=(Numeric<T>& left, Numeric<U> right)noexcept;

		template<Concept::Integral T, Concept::Integral U>
		friend constexpr Numeric<T>& operator^=(Numeric<T>& left, U right)noexcept;

		template<Concept::Integral T>
		friend constexpr Numeric<T>& operator<<=(Numeric<T> numeric, size_t shift)noexcept;

		template<Concept::Integral T>
		friend constexpr Numeric<T>& operator<<=(Numeric<T> numeric, Numeric<size_t> shift)noexcept;

		template<Concept::Integral T>
		friend constexpr Numeric<T>& operator>>=(Numeric<T> numeric, size_t shift)noexcept;

		template<Concept::Integral T>
		friend constexpr Numeric<T>& operator>>=(Numeric<T> numeric, Numeric<size_t> shift)noexcept;

		template<class T, class U>
		friend constexpr bool operator==(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr bool operator==(Numeric<T> left, U right)noexcept;

		template<class T, class U>
		friend constexpr bool operator!=(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr bool operator!=(Numeric<T> left, U right)noexcept;

		template<class T, class U>
		friend constexpr bool operator<(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr bool operator<(Numeric<T>left, U right)noexcept;

		template<class T, class U>
		friend constexpr bool operator>(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr bool operator>(Numeric<T> left, U right)noexcept;

		template<class T, class U>
		friend constexpr bool operator<=(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr bool operator<=(Numeric<T> left, U right)noexcept;

		template<class T, class U>
		friend constexpr bool operator>=(Numeric<T> left, Numeric<U> right)noexcept;

		template<class T, Concept::Arithmetic U>
		friend constexpr bool operator>=(Numeric<T> left, U right)noexcept;

		static constexpr Numeric<T> Min()noexcept;

		static constexpr Numeric<T> Max()noexcept;

	private:

		value_type mVal;

		template<Concept::Arithmetic U>
		friend struct Numeric;

	};

	template<Concept::Arithmetic T>
	Numeric(T) -> Numeric<T>;

	template <Concept::Arithmetic T>
	inline constexpr Numeric<T>::Numeric()noexcept
		: mVal(0)
	{}

	template <Concept::Arithmetic T>
	inline constexpr Numeric<T>::Numeric(T _value)noexcept
		: mVal(_value)
	{}

	template <Concept::Arithmetic T>
	template<class U>
	inline constexpr Numeric<T>::Numeric(U _value)noexcept
		: mVal(static_cast<T>(_value))
	{}

	template <Concept::Arithmetic T>
	template<class U>
	inline constexpr Numeric<T>::Numeric(const Numeric<U>& _numeric)noexcept
		: mVal(static_cast<T>(_numeric.mVal))
	{}

	template <Concept::Arithmetic T>
	template<class U>
	inline constexpr Numeric<T>::Numeric(Numeric<U>&& _numeric)noexcept
		: mVal(static_cast<T>(std::move(_numeric.mVal)))
	{}

	template <Concept::Arithmetic T>
	inline constexpr Numeric<T>& Numeric<T>::operator=(T _value)noexcept
	{
		mVal = _value; return *this;
	}

	template <Concept::Arithmetic T>
	template<class U>
	inline constexpr Numeric<T>& Numeric<T>::operator=(U _value)noexcept
	{
		mVal = static_cast<T>(_value); return *this;
	}

	template <Concept::Arithmetic T>
	template<class U>
	inline constexpr Numeric<T>& Numeric<T>::operator=(const Numeric<U>& _numeric)noexcept
	{
		mVal = static_cast<T>(_numeric.mVal); return *this;
	}

	template <Concept::Arithmetic T>
	template<class U>
	inline constexpr Numeric<T>& Numeric<T>::operator=(Numeric<U>&& _numeric)noexcept
	{
		mVal = static_cast<T>(std::move(_numeric.mVal)); return *this;
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T>& Numeric<T>::operator++() noexcept
	{
		++mVal; return *this;
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T>& Numeric<T>::operator++(int) noexcept
	{
		mVal++; return *this;
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T>& Numeric<T>::operator--() noexcept
	{
		--mVal; return *this;
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T>& Numeric<T>::operator--(int) noexcept
	{
		mVal--; return *this;
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T> Numeric<T>::operator+() const noexcept
	{
		return Numeric<T>{+mVal};
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T> Numeric<T>::operator-() const noexcept
	{
		return Numeric<T>{-mVal};
	}

	template<Concept::Arithmetic T>
	inline constexpr bool Numeric<T>::operator!() const noexcept
	{
		return !this->operator bool();
	}

	template<Concept::Arithmetic T>
	inline constexpr typename Numeric<T>::value_type Numeric<T>::operator*() const noexcept
	{
		return mVal;
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T>::operator value_type() const noexcept
	{
		return mVal;
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T>::operator bool() const noexcept
	{
		return mVal != 0;
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T> Numeric<T>::Min() noexcept
	{
		return Numeric<T>{std::numeric_limits<value_type>::min()};
	}

	template<Concept::Arithmetic T>
	inline constexpr Numeric<T> Numeric<T>::Max() noexcept
	{
		return Numeric<T>{std::numeric_limits<value_type>::max()};
	}

	template<class T, class U>
	inline constexpr auto operator+(Numeric<T> left, Numeric<U> right) noexcept
	{
		using Rty = decltype(left.mVal + right.mVal);
		return Numeric<Rty>{left.mVal + right.mVal};
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr auto operator+(Numeric<T> left, U right) noexcept
	{
		using Rty = decltype(left.mVal + right);
		return Numeric<Rty>{left.mVal + right};
	}

	template<class T, class U>
	inline constexpr auto operator-(Numeric<T> left, Numeric<U> right) noexcept
	{
		using Rty = decltype(left.mVal - right.mVal);
		return Numeric<Rty>{left.mVal - right.mVal};
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr auto operator-(Numeric<T> left, U right) noexcept
	{
		using Rty = decltype(left.mVal - right);
		return Numeric<Rty>{left.mVal - right};
	}

	template<class T, class U>
	inline constexpr auto operator*(Numeric<T> left, Numeric<U> right) noexcept
	{
		using Rty = decltype(left.mVal * right.mVal);
		return Numeric<Rty>{left.mVal * right.mVal};
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr auto operator*(Numeric<T> left, U right) noexcept
	{
		using Rty = decltype(left.mVal * right);
		return Numeric<Rty>{left.mVal * right};
	}

	template<class T, class U>
	inline constexpr auto operator/(Numeric<T> left, Numeric<U> right)
	{
		if (right.mVal == 0)
			throw Error::ZeroDivisionException{ "operator/(Numeric,Numeric)" };
		using Rty = decltype(left.mVal / right.mVal);
		return Numeric<Rty>{left.mVal / right.mVal};
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr auto operator/(Numeric<T> left, U right)
	{
		if (right == 0)
			throw Error::ZeroDivisionException{ "operator/(Numeric,U)" };
		using Rty = decltype(left.mVal / right);
		return Numeric<Rty>{left.mVal / right};
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr auto operator%(Numeric<T> left, Numeric<U> right)
	{
		if (right.mVal == 0)
			throw Error::ZeroDivisionException{ "operator%(Numeric,Numeric)" };
		using Rty = decltype(left.mVal % right.mVal);
		return Numeric<Rty>{left.mVal % right.mVal};
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr auto operator%(Numeric<T> left, U right)
	{
		if (right == 0)
			throw Error::ZeroDivisionException{ "operator%(Numeric,U)" };
		using Rty = decltype(left.mVal % right);
		return Numeric<Rty>{left.mVal % right};
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr auto operator&(Numeric<T> left, Numeric<U> right) noexcept
	{
		using Rty = decltype(left.mVal & right.mVal);
		return Numeric<Rty>{left.mVal & right.mVal};
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr auto operator&(Numeric<T> left, U right) noexcept
	{
		using Rty = decltype(left.mVal & right);
		return Numeric<Rty>{left.mVal & right};
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr auto operator|(Numeric<T> left, Numeric<U> right) noexcept
	{
		using Rty = decltype(left.mVal | right.mVal);
		return Numeric<Rty>{left.mVal | right.mVal};
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr auto operator|(Numeric<T> left, U right) noexcept
	{
		using Rty = decltype(left.mVal | right);
		return Numeric<Rty>{left.mVal | right};
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr auto operator^(Numeric<T> left, Numeric<U> right) noexcept
	{
		using Rty = decltype(left.mVal ^ right.mVal);
		return Numeric<Rty>{left.mVal ^ right.mVal};
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr auto operator^(Numeric<T> left, U right) noexcept
	{
		using Rty = decltype(left.mVal ^ right);
		return Numeric<Rty>{left.mVal ^ right};
	}
	
	template<Concept::Integral T>
	inline constexpr auto operator~(Numeric<T> numeric)noexcept
	{
		return Numeric<T>{~(numeric.mVal)};
	}

	template<Concept::Integral T>
	inline constexpr auto operator<<(Numeric<T> numeric, size_t shift)noexcept
	{
		using Rty = decltype(numeric.mVal << shift);
		return Numeric<Rty>{numeric.mVal << shift};
	}

	template<Concept::Integral T>
	inline constexpr auto operator<<(Numeric<T> numeric, Numeric<size_t> shift)noexcept
	{
		using Rty = decltype(numeric.mVal << shift.mVal);
		return Numeric<Rty>{numeric.mVal << shift.mVal};
	}

	template<Concept::Integral T>
	inline constexpr auto operator>>(Numeric<T> numeric, size_t shift)noexcept
	{
		using Rty = decltype(numeric.mVal >> shift);
		return Numeric<Rty>{numeric.mVal >> shift};
	}

	template<Concept::Integral T>
	inline constexpr auto operator>>(Numeric<T> numeric, Numeric<size_t> shift)noexcept
	{
		using Rty = decltype(numeric.mVal >> shift.mVal);
		return Numeric<Rty>{numeric.mVal >> shift.mVal};
	}

	template<class T, class U>
	inline constexpr Numeric<T>& operator+=(Numeric<T>& left, Numeric<U> right)noexcept
	{
		left.mVal += right.mVal; return left;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr Numeric<T>& operator+=(Numeric<T>& left, U right)noexcept
	{
		left.mVal += right; return left;
	}

	template<class T, class U>
	inline constexpr Numeric<T>& operator-=(Numeric<T>& left, Numeric<U> right)noexcept
	{
		left.mVal -= right.mVal; return left;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr Numeric<T>& operator-=(Numeric<T>& left, U right)noexcept
	{
		left.mVal -= right; return left;
	}

	template<class T, class U>
	inline constexpr Numeric<T>& operator*=(Numeric<T>& left, Numeric<U> right)noexcept
	{
		left.mVal *= right.mVal; return left;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr Numeric<T>& operator*=(Numeric<T>& left, U right)noexcept
	{
		left.mVal *= right; return left;
	}

	template<class T, class U>
	inline constexpr Numeric<T>& operator/=(Numeric<T>& left, Numeric<U> right)
	{
		if (right.mVal == 0)
			throw Error::ZeroDivisionException{ "operator/=(Numeric,Numeric)" };
		left.mVal /= right.mVal; 
		return left;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr Numeric<T>& operator/=(Numeric<T>& left, U right)
	{
		if (right == 0)
			throw Error::ZeroDivisionException{ "operator/=(Numeric,U)" };
		left.mVal /= right;
		return left;
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr Numeric<T>& operator%=(Numeric<T>& left, Numeric<U> right)
	{
		if (right.mVal == 0)
			throw Error::ZeroDivisionException{ "operator%=(Numeric,Numeric)" };
		left.mVal %= right.mVal;
		return left;
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr Numeric<T>& operator%=(Numeric<T>& left, U right)
	{
		if (right == 0)
			throw Error::ZeroDivisionException{ "operator%=(Numeric,U)" };
		left.mVal %= right;
		return left;
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr Numeric<T>& operator&=(Numeric<T>& left, Numeric<U> right)noexcept
	{
		left.mVal &= right.mVal; return left;
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr Numeric<T>& operator&=(Numeric<T>& left, U right)noexcept
	{
		left.mVal &= right; return left;
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr Numeric<T>& operator|=(Numeric<T>& left, Numeric<U> right)noexcept
	{
		left.mVal |= right.mVal; return left;
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr Numeric<T>& operator|=(Numeric<T>& left, U right)noexcept
	{
		left.mVal |= right; return left;
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr Numeric<T>& operator^=(Numeric<T>& left, Numeric<U> right)noexcept
	{
		left.mVal ^= right.mVal; return left;
	}

	template<Concept::Integral T, Concept::Integral U>
	inline constexpr Numeric<T>& operator^=(Numeric<T>& left, U right)noexcept
	{
		left.mVal ^= right; return left;
	}

	template<Concept::Integral T>
	inline constexpr Numeric<T>& operator<<=(Numeric<T> numeric, size_t shift)noexcept
	{
		numeric.mVal <<= shift; return numeric;
	}

	template<Concept::Integral T>
	inline constexpr Numeric<T>& operator<<=(Numeric<T> numeric, Numeric<size_t> shift)noexcept
	{
		numeric.mVal <<= shift.mVal; return numeric;
	}

	template<Concept::Integral T>
	inline constexpr Numeric<T>& operator>>=(Numeric<T> numeric, size_t shift)noexcept
	{
		numeric.mVal >>= shift; return numeric;
	}

	template<Concept::Integral T>
	inline constexpr Numeric<T>& operator>>=(Numeric<T> numeric, Numeric<size_t> shift)noexcept
	{
		numeric.mVal >>= shift.mVal; return numeric;
	}

	template<class T, class U>
	inline constexpr bool operator==(Numeric<T> left, Numeric<U> right)noexcept
	{
		return left.mVal == right.mVal;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr bool operator==(Numeric<T> left, U right)noexcept
	{
		return left.mVal == right;
	}

	template<class T, class U>
	inline constexpr bool operator!=(Numeric<T> left, Numeric<U> right)noexcept
	{
		return left.mVal != right.mVal;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr bool operator!=(Numeric<T> left, U right)noexcept
	{
		return left.mVal != right;
	}

	template<class T, class U>
	inline constexpr bool operator<(Numeric<T> left, Numeric<U> right)noexcept
	{
		return left.mVal < right.mVal;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr bool operator<(Numeric<T> left, U right)noexcept
	{
		return left.mVal < right;
	}

	template<class T, class U>
	inline constexpr bool operator>(Numeric<T> left, Numeric<U> right)noexcept
	{
		return left.mVal > right.mVal;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr bool operator>(Numeric<T> left, U right)noexcept
	{
		return left.mVal > right;
	}

	template<class T, class U>
	inline constexpr bool operator<=(Numeric<T> left, Numeric<U> right)noexcept
	{
		return left.mVal <= right.mVal;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr bool operator<=(Numeric<T> left, U right)noexcept
	{
		return left.mVal <= right;
	}

	template<class T, class U>
	inline constexpr bool operator>=(Numeric<T> left, Numeric<U> right)noexcept
	{
		return left.mVal >= right.mVal;
	}

	template<class T, Concept::Arithmetic U>
	inline constexpr bool operator>=(Numeric<T> left, U right)noexcept
	{
		return left.mVal >= right;
	}
}

namespace Iris
{
	using int8  = Numeric<std::int8_t>;
	using int16 = Numeric<std::int16_t>;
	using int32 = Numeric<std::int32_t>;
	using int64 = Numeric<std::int64_t>;

	using uint8  = Numeric<std::uint8_t>;
	using uint16 = Numeric<std::uint16_t>;
	using uint32 = Numeric<std::uint32_t>;
	using uint64 = Numeric<std::uint64_t>;

	using float32 = Numeric<float>;
	using float64 = Numeric<double>;

	namespace NumericLiterals
	{
		inline constexpr int8 operator"" _i8(size_t n) noexcept
		{
			return int8{ n };
		}

		inline constexpr int8 operator"" _i16(size_t n) noexcept
		{
			return int16{ n };
		}

		inline constexpr int8 operator"" _i32(size_t n) noexcept
		{
			return int32{ n };
		}

		inline constexpr int8 operator"" _i64(size_t n) noexcept
		{
			return int64{ n };
		}

		inline constexpr uint8 operator"" _ui8(size_t n) noexcept
		{
			return uint8{ n };
		}

		inline constexpr uint8 operator"" _ui16(size_t n) noexcept
		{
			return uint16{ n };
		}

		inline constexpr uint8 operator"" _ui32(size_t n) noexcept
		{
			return uint32{ n };
		}

		inline constexpr uint8 operator"" _ui64(size_t n) noexcept
		{
			return uint64{ n };
		}

		inline constexpr float32 operator"" _f32(size_t n) noexcept
		{
			return float32{ n };
		}

		inline constexpr float32 operator"" _f32(long double n) noexcept
		{
			return float32{ n };
		}

		inline constexpr float32 operator"" _f64(size_t n) noexcept
		{
			return float64{ n };
		}

		inline constexpr float32 operator"" _f64(long double n) noexcept
		{
			return float64{ n };
		}
	}
}

using namespace Iris::NumericLiterals;

namespace Iris
{
	template<class T>
	inline constexpr Numeric<T> Max(T a, T b) noexcept
	{
		return a > b ? a : b;
	}

	template<class T>
	inline constexpr Numeric<T> Max(Numeric<T> a, T b) noexcept
	{
		return a > b ? a : b;
	}

	template<class T>
	inline constexpr Numeric<T> Max(T a, Numeric<T> b) noexcept
	{
		return b < a ? b : a;
	}

	template<class T>
	inline constexpr Numeric<T> Max(Numeric<T> a, Numeric<T> b) noexcept
	{
		return a > b ? a : b;
	}

	template<class T>
	inline constexpr Numeric<T> Min(T a, T b) noexcept
	{
		return a < b ? a : b;
	}

	template<class T>
	inline constexpr Numeric<T> Min(Numeric<T> a, T b) noexcept
	{
		return a < b ? a : b;
	}

	template<class T>
	inline constexpr Numeric<T> Min(T a, Numeric<T> b) noexcept
	{
		return b > a ? b : a;
	}

	template<class T>
	inline constexpr Numeric<T> Min(Numeric<T> a, Numeric<T> b) noexcept
	{
		return a < b ? a : b;
	}

	template<class T>
	inline constexpr Numeric<T> Clamp(T value, T min, T max) noexcept
	{
		return (value < min) ? min : (max < value) ? max : value;
	}

	template<class T>
	inline constexpr Numeric<T> Clamp(Numeric<T> value, T min, T max) noexcept
	{
		return (value < min) ? min : (max < value) ? max : value;
	}

	template<class T>
	inline constexpr Numeric<T> Clamp(T value, Numeric<T> min, Numeric<T> max) noexcept
	{
		return (value < min) ? min : (max < value) ? max : value;
	}

	template<class T>
	inline constexpr Numeric<T> Clamp(Numeric<T> value, Numeric<T> min, Numeric<T> max) noexcept
	{
		return (value < min) ? min : (max < value) ? max : value;
	}

	template<class T>
	inline constexpr bool InRange(T value, T min, T max) noexcept
	{
		return min <= value && value <= max;
	}

	template<class T>
	inline constexpr bool InRange(Numeric<T> value, T min, T max) noexcept
	{
		return min <= value && value <= max;
	}

	template<class T>
	inline constexpr bool InRange(T value, Numeric<T> min, Numeric<T> max) noexcept
	{
		return min <= value && value <= max;
	}

	template<class T>
	inline constexpr bool InRange(Numeric<T> value, Numeric<T> min, Numeric<T> max) noexcept
	{
		return min <= value && value <= max;
	}
}