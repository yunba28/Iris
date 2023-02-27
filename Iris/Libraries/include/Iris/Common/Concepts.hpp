#pragma once

#include <concepts>
#include <type_traits>

namespace Iris::Concept
{

	template<class T>
	concept Integral = std::is_integral_v<T>;

	template<class T>
	concept Floating = std::is_floating_point_v<T>;

	template<class T>
	concept Arithmetic = std::is_arithmetic_v<T>;

	template<class T, class ...Args>
	concept Constructible = std::is_constructible_v<T, Args...>;

	template<class Fty, class ...Args>
	concept Invocable = std::is_invocable_v<Fty, Args...>;

	template<class Fty, class ...Args>
	concept Predicate = std::is_invocable_r_v<bool, Fty, Args...>;

	template<class Rty, class Fty, class ...Args>
	concept PredicateWith = std::is_invocable_r_v<Rty, Fty, Args...>;

	template<class Base, class Derived>
	concept BaseOf = std::is_base_of_v<Base, Derived>;

	template<class T, class U>
	concept LineageOf = std::is_base_of_v<T, U> || std::is_base_of_v<U, T>;
}