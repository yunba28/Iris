#pragma once

#include <map>

namespace Iris
{
#define DECLARE_SORTEDMAP_TEMPLATE template<class Key, class Vty, class Comparator = std::less<Key>, class Allocator = std::allocator<std::pair<const Key,Vty>>>
#define SORTEDMAP_TEMPLATE template<class Key, class Vty, class Comparator, class Allocator>

	DECLARE_SORTEDMAP_TEMPLATE
	class SortedMap : protected std::map<Key, Vty, Comparator, Allocator>
	{
	public:

        using base_type = std::map<Key, Vty, Comparator, Allocator>;

        using typename base_type::key_type;
        using typename base_type::mapped_type;
        using typename base_type::key_compare;

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
        using typename base_type::reverse_iterator;
        using typename base_type::const_reverse_iterator;

        using base_type::map;
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