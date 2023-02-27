#pragma once

#include <unordered_map>

namespace Iris
{
	#define DECLARE_HASHMAP_TEMPLATE template<class Key, class Vty, class Hasher = std::hash<Key>, class Equaler = std::equal_to<Key>, class Allocator = std::allocator<std::pair<const Key,Vty>>>
	#define HASHMAP_TEMPLATE template<class Key, class Vty, class Hasher, class Equaler, class Allocator>

	DECLARE_HASHMAP_TEMPLATE
	class HashMap : protected std::unordered_map<Key, Vty, Hasher, Equaler, Allocator>
	{
	public:

		using base_type = std::unordered_map<Key, Vty, Hasher, Equaler, Allocator>;

        using typename base_type::hasher;
        using typename base_type::key_type;
        using typename base_type::mapped_type;
        using typename base_type::key_equal;

        using typename base_type::value_type;
        using typename base_type::allocator_type;
        using typename base_type::size_type;
        using typename base_type::difference_type;
        using typename base_type::pointer;
        using typename base_type::const_pointer;
        using typename base_type::reference;
        using typename base_type::const_reference;
        using typename base_type::iterator;
        using typename base_type::const_iterator;

        using typename base_type::local_iterator;
        using typename base_type::const_local_iterator;

        using base_type::unordered_map;
        using base_type::operator=;
        using base_type::operator[];

        using base_type::emplace;
        using base_type::insert;

        using base_type::begin;
        using base_type::end;
        using base_type::cbegin;
        using base_type::cend;

        using base_type::at;

        using base_type::swap;
        using base_type::clear;

        using base_type::size;

        using base_type::empty;

	};
}