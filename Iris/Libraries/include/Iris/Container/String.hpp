#pragma once

#include <string>
#include <algorithm>

#include <Iris/Common/Numeric.hpp>

namespace Iris
{

	class String
	{
	public:

		using base_type = std::u32string;

		using traits_type		= typename base_type::traits_type;
		using allocator_type	= typename base_type::allocator_type;
		using value_type		= typename base_type::value_type;
		using pointer			= typename base_type::pointer;
		using const_pointer		= typename base_type::const_pointer;
		using reference			= typename base_type::reference;
		using const_reference	= typename base_type::const_reference;
		using size_type			= uint64;
		using difference_type	= uint64;

		using iterator					= typename base_type::iterator;
		using const_iterator			= typename base_type::const_iterator;
		using reverse_iterator			= typename base_type::reverse_iterator;
		using const_reverse_iterator	= typename base_type::const_reverse_iterator;

		using char_type = typename base_type::value_type;
		using raw_type	= typename base_type::const_pointer;
		using view_type = std::basic_string_view<value_type, std::char_traits<value_type>>;

		static constexpr size_type npos = base_type::npos;

		explicit String()noexcept;

		explicit String(const allocator_type& _alloc)noexcept;

		String(size_type _count, char_type _ch, const allocator_type& _alloc);

		String(raw_type _raw, const allocator_type& _alloc = allocator_type{});

		String(std::initializer_list<char_type> _iniList, const allocator_type& _alloc = allocator_type{});

		template<class Iterator>
		String(Iterator _first, Iterator _last, const allocator_type& _alloc);

		String(const base_type& _string);

		String(base_type&& _string);

		String(const String&) = default;

		String(String&&) = default;

		String& operator=(char_type _ch);

		String& operator=(raw_type _raw);

		String& operator=(std::initializer_list<char_type> _iniList);

		String& operator=(const String&) = default;

		String& operator=(String&&) = default;

		reference operator[](size_type _idx)noexcept;

		const_reference operator[](size_type _idx)const noexcept;

		base_type& operator*()noexcept;

		const base_type& operator*()const noexcept;

		explicit operator bool()const noexcept;

		void addFirst(char_type _ch);

		void addFirst(raw_type _raw);

		void addFirst(std::initializer_list<char_type> _iniList);

		template<class Iterator>
		void addFirst(Iterator _first, Iterator _last);

		void addLast(char_type _ch);

		void addLast(raw_type _raw);

		void addLast(std::initializer_list<char_type> _iniList);

		template<class Iterator>
		void addLast(Iterator _first, Iterator _last);

		void insert(const_iterator _where, char_type _ch);

		void insert(const_iterator _where, raw_type _raw);

		void insert(const_iterator _where, std::initializer_list<char_type> _iniList);

		template<class Iterator>
		void insert(Iterator _first, Iterator _last);

		void insert(const_iterator _where, const String& _string);

		void insert(const_iterator _where, String&& _string);

		void prepend(const String& _string);

		void prepend(String&& _string);

		void append(const String& _string);

		void append(String&& _string);

		void remove(char_type _ch);

		void remove(raw_type _raw);

		void remove(const String& _string);

		void remove(const_iterator _where);

		void removeFirst();

		void removeLast();

		void removeRange(const_iterator _first, const_iterator _last);

		void removeAt(size_type _index, size_type _count = 0);

		template<class Fty>
		void removeBy(Fty _function)requires(Concept::Predicate<Fty, typename String::char_type>);

		void removeAll()noexcept;

		void shrinkToFit()noexcept;

		iterator find(char_type _ch);

		const_iterator find(char_type _ch)const;

		std::pair<iterator, iterator> find(raw_type _raw);

		std::pair<const_iterator, const_iterator> find(raw_type _raw)const;

		std::pair<iterator, iterator> find(const String& _string);

		std::pair<const_iterator, const_iterator> find(const String& _string)const;

		iterator rfind(char_type _ch);

		const_iterator rfind(char_type _ch)const;

		std::pair<iterator, iterator> rfind(raw_type _raw);

		std::pair<const_iterator, const_iterator> rfind(raw_type _raw)const;

		std::pair<iterator, iterator> rfind(const String& _string);

		std::pair<const_iterator, const_iterator> rfind(const String& _string)const;

		iterator findAt(size_type _index);

		const_iterator findAt(size_type _index)const;

		size_type indexOf(const_iterator _where)const noexcept;

		pointer data()noexcept;

		const_pointer data()const noexcept;

		reference at(size_type _idx);

		const_reference at(size_type _idx)const;

		reference first()noexcept;

		const_reference first()const noexcept;

		reference last()noexcept;

		const_reference last()const noexcept;

		raw_type raw()const noexcept;

		size_type size()const noexcept;

		size_type length()const noexcept;

		size_type capacity()const noexcept;

		void swap(String& _string);

		void resize(size_type _count);

		void resize(size_type _count, char_type _ch);

		void reserve(size_type _capacity);

		void replace(char_type _old, char_type _new);

		void replace(raw_type _old, raw_type _new);

		void replace(const String& _old, const String& _new);

		template<class Fty>
		void replaceBy(Fty _function, char_type _ch)requires(Concept::Predicate<Fty, typename String::char_type>);

		template<class Fty>
		void replaceBy(Fty _function, raw_type _raw)requires(Concept::Predicate<Fty, typename String::char_type>);

		template<class Fty>
		void replaceBy(Fty _function, const String& _string)requires(Concept::Predicate<Fty, typename String::char_type>);

		template<class Fty>
		String map(Fty _function)const requires(Concept::PredicateWith<typename String::char_type, Fty, typename String::char_type>);

		iterator begin()noexcept;

		const_iterator begin()const noexcept;

		iterator end()noexcept;

		const_iterator end()const noexcept;

		const_iterator cbegin()const noexcept;

		const_iterator cend()const noexcept;

		reverse_iterator rbegin()noexcept;

		const_reverse_iterator rbegin()const noexcept;

		reverse_iterator rend()noexcept;

		const_reverse_iterator rend()const noexcept;

		const_reverse_iterator crbegin()const noexcept;

		const_reverse_iterator crend()const noexcept;

		bool empty()const noexcept;

		friend String operator+(const String& left, const String& right);

		friend String operator+(const String& string, String::char_type ch);

		friend String operator+(const String& string, String::raw_type raw);

		friend String operator+(const String& string, std::initializer_list<char_type> iniList);

		friend String& operator+=(String& left, const String& right);

		friend String& operator+=(String& string, String::char_type ch);

		friend String& operator+=(String& string, String::raw_type raw);

		friend String& operator+=(String& string, std::initializer_list<char_type> iniList);

		friend bool operator==(const String& a, const String& b);

		friend bool operator==(const String& a, String::char_type ch);

		friend bool operator==(const String& a, String::raw_type raw);

		friend bool operator!=(const String& a, const String& b);

		friend bool operator!=(const String& a, String::char_type ch);

		friend bool operator!=(const String& a, String::raw_type raw);

	private:

		static size_t GetRawLength(const String& string, raw_type raw)noexcept;

	private:

		base_type mString;

	};
}

namespace Iris
{
	inline String::String() noexcept
		: mString()
	{}

	inline String::String(const allocator_type& _alloc) noexcept
		: mString(_alloc)
	{}

	inline String::String(size_type _count, char_type _ch, const allocator_type& _alloc)
		: mString(_count, _ch, _alloc)
	{}

	inline String::String(raw_type _raw, const allocator_type& _alloc)
		: mString(_raw, _alloc)
	{}

	inline String::String(std::initializer_list<char_type> _iniList, const allocator_type& _alloc)
		: mString(_iniList, _alloc)
	{}

	template<class Iterator>
	inline String::String(Iterator _first, Iterator _last, const allocator_type& _alloc)
		: mString(_first, _last, _alloc)
	{}

	inline String::String(const base_type& _string)
		: mString(_string)
	{}

	inline String::String(base_type&& _string)
		: mString(std::forward<base_type>(_string))
	{}

	inline String& String::operator=(char_type _ch)
	{
		mString = _ch; return *this;
	}

	inline String& String::operator=(raw_type _raw)
	{
		mString = _raw; return *this;
	}

	inline String& String::operator=(std::initializer_list<char_type> _iniList)
	{
		mString = _iniList; return *this;
	}

	inline typename String::reference String::operator[](size_type _idx) noexcept
	{
		return mString[_idx];
	}

	inline typename String::const_reference String::operator[](size_type _idx) const noexcept
	{
		return mString[_idx];
	}

	inline typename String::base_type& String::operator*() noexcept
	{
		return mString;
	}

	inline const typename String::base_type& String::operator*() const noexcept
	{
		return mString;
	}

	inline String::operator bool() const noexcept
	{
		return !mString.empty();
	}

	inline void String::addFirst(char_type _ch)
	{
		mString.insert(mString.cbegin(), _ch);
	}

	inline void String::addFirst(raw_type _raw)
	{
		mString.insert(0, _raw);
	}

	inline void String::addFirst(std::initializer_list<char_type> _iniList)
	{
		mString.insert(mString.cbegin(), _iniList);
	}

	template<class Iterator>
	inline void String::addFirst(Iterator _first, Iterator _last)
	{
		mString.insert(mString.cbegin(), _first, _last);
	}

	inline void String::addLast(char_type _ch)
	{
		mString.push_back(_ch);
	}

	inline void String::addLast(raw_type _raw)
	{
		mString.append(_raw);
	}

	inline void String::addLast(std::initializer_list<char_type> _iniList)
	{
		mString.append(_iniList);
	}

	template<class Iterator>
	inline void String::addLast(Iterator _first, Iterator _last)
	{
		mString.append(_first, _last);
	}

	inline void String::insert(const_iterator _where, char_type _ch)
	{
		mString.insert(_where, _ch);
	}

	inline void String::insert(const_iterator _where, raw_type _raw)
	{
		if (const auto idx = indexOf(_where);idx != String::npos)
		{
			mString.insert(idx, _raw);
		}
	}

	inline void String::insert(const_iterator _where, std::initializer_list<char_type> _iniList)
	{
		mString.insert(_where, _iniList);
	}

	template<class Iterator>
	inline void String::insert(Iterator _first, Iterator _last)
	{
		mString.insert(_first, _last);
	}

	inline void String::insert(const_iterator _where, const String& _string)
	{
		mString.insert(_where, _string.mString.begin(), _string.mString.end());
	}

	inline void String::insert(const_iterator _where, String&& _string)
	{
		mString.insert(_where, _string.mString.begin(), _string.mString.end());
	}

	inline void String::prepend(const String& _string)
	{
		mString.insert(mString.begin(), _string.mString.begin(), _string.mString.end());
	}

	inline void String::prepend(String&& _string)
	{
		mString.insert(mString.begin(), _string.mString.begin(), _string.mString.end());
	}

	inline void String::append(const String& _string)
	{
		mString.append(_string.mString);
	}

	inline void String::append(String&& _string)
	{
		mString.append(std::forward<base_type>(_string.mString));
	}

	inline void String::remove(char_type _ch)
	{
		auto ret = std::remove(mString.begin(), mString.end(), _ch);

		if (ret != mString.end())
		{
			mString.erase(ret, mString.end());
		}
	}

	inline void String::remove(raw_type _raw)
	{
		const auto len = GetRawLength(*this, _raw);

		if (len == base_type::npos)
			return;

		auto idx = mString.find(_raw);

		while (idx != base_type::npos)
		{
			mString.erase(idx, len);
			idx = mString.find(_raw);
		}
	}

	inline void String::remove(const String& _string)
	{
		const auto len = _string.mString.length();

		auto idx = mString.find(_string.mString);

		while (idx != base_type::npos)
		{
			mString.erase(idx, len);
			idx = mString.find(_string.mString);
		}
	}

	inline void String::remove(const_iterator _where)
	{
		mString.erase(_where);
	}

	inline void String::removeFirst()
	{
		mString.erase(0);
	}

	inline void String::removeLast()
	{
		mString.pop_back();
	}

	inline void String::removeRange(const_iterator _first, const_iterator _last)
	{
		mString.erase(_first, _last);
	}

	inline void String::removeAt(size_type _index, size_type _count)
	{
		mString.erase(_index, _count);
	}

	template<class Fty>
	inline void String::removeBy(Fty _function) requires(Concept::Predicate<Fty, typename String::char_type>)
	{
		auto ret = std::remove_if(mString.begin(), mString.end(), _function);

		if (ret != mString.end())
		{
			mString.erase(ret, mString.end());
		}
	}

	inline void String::removeAll() noexcept
	{
		mString.clear();
	}

	inline void String::shrinkToFit() noexcept
	{
		mString.shrink_to_fit();
	}

	inline typename String::iterator String::find(char_type _ch)
	{
		if (auto i = mString.find(_ch);i != base_type::npos)
		{
			return mString.begin() + i;
		}

		return mString.end();
	}

	inline typename String::const_iterator String::find(char_type _ch) const
	{
		if (auto i = mString.find(_ch); i != base_type::npos)
		{
			return mString.cbegin() + i;
		}

		return mString.cend();
	}

	inline std::pair<typename String::iterator, typename String::iterator> 
		String::find(raw_type _raw)
	{
		if (auto i = mString.find(_raw); i != base_type::npos)
		{
			auto len = GetRawLength(*this, _raw);
			return { mString.begin() + i,mString.begin() + i + len };
		}

		return { mString.end(), mString.end() };
	}

	inline std::pair<typename String::const_iterator, typename String::const_iterator> 
		String::find(raw_type _raw) const
	{
		if (auto i = mString.find(_raw); i != base_type::npos)
		{
			auto len = GetRawLength(*this, _raw);
			return { mString.cbegin() + i,mString.cbegin() + i + len };
		}

		return { mString.cend(), mString.cend() };
	}

	inline std::pair<typename String::iterator, typename String::iterator>
		String::find(const String& _string)
	{
		if (auto i = mString.find(_string.mString); i != base_type::npos)
		{
			auto len = _string.mString.length();
			return { mString.begin() + i,mString.begin() + i + len };
		}

		return { mString.end(), mString.end() };
	}

	inline std::pair<typename String::const_iterator, typename String::const_iterator> 
		String::find(const String& _string) const
	{
		if (auto i = mString.find(_string.mString); i != base_type::npos)
		{
			auto len = _string.mString.length();
			return { mString.cbegin() + i,mString.cbegin() + i + len };
		}

		return { mString.cend(), mString.cend() };
	}

	inline typename String::iterator String::rfind(char_type _ch)
	{
		if (auto i = mString.rfind(_ch); i != base_type::npos)
		{
			return mString.begin() + i;
		}

		return mString.end();
	}

	inline typename String::const_iterator String::rfind(char_type _ch) const
	{
		if (auto i = mString.rfind(_ch); i != base_type::npos)
		{
			return mString.cbegin() + i;
		}

		return mString.cend();
	}

	inline std::pair<typename String::iterator, typename String::iterator>
		String::rfind(raw_type _raw)
	{
		if (auto i = mString.rfind(_raw); i != base_type::npos)
		{
			auto len = GetRawLength(*this, _raw);
			return { mString.begin() + i,mString.begin() + i + len };
		}

		return { mString.end(), mString.end() };
	}

	inline std::pair<typename String::const_iterator, typename String::const_iterator>
		String::rfind(raw_type _raw) const
	{
		if (auto i = mString.rfind(_raw); i != base_type::npos)
		{
			auto len = GetRawLength(*this, _raw);
			return { mString.cbegin() + i,mString.cbegin() + i + len };
		}

		return { mString.cend(), mString.cend() };
	}

	inline std::pair<typename String::iterator, typename String::iterator>
		String::rfind(const String& _string)
	{
		if (auto i = mString.rfind(_string.mString); i != base_type::npos)
		{
			auto len = _string.mString.length();
			return { mString.begin() + i,mString.begin() + i + len };
		}

		return { mString.end(), mString.end() };
	}

	inline std::pair<typename String::const_iterator, typename String::const_iterator>
		String::rfind(const String& _string) const
	{
		if (auto i = mString.rfind(_string.mString); i != base_type::npos)
		{
			auto len = _string.mString.length();
			return { mString.cbegin() + i,mString.cbegin() + i + len };
		}

		return { mString.cend(), mString.cend() };
	}

	inline typename String::iterator String::findAt(size_type _index)
	{
		if (_index < mString.size())
			return mString.begin() + _index;

		return mString.end();
	}

	inline typename String::const_iterator String::findAt(size_type _index) const
	{
		if (_index < mString.size())
			return mString.cbegin() + _index;

		return mString.cend();
	}

	inline typename String::size_type String::indexOf(const_iterator _where) const noexcept
	{
		size_type i = 0;

		auto it = mString.begin();
		auto e = mString.end();

		while (it != e)
		{
			if (it == _where)
				return i;
			++it;
			++i;
		}

		return String::npos;
	}

	inline typename String::pointer	String::data()noexcept
	{
		return mString.data();
	}

	inline typename String::const_pointer String::data()const noexcept
	{
		return mString.data();
	}

	inline typename String::reference String::at(size_type _idx)
	{
		return mString.at(_idx);
	}

	inline typename String::const_reference String::at(size_type _idx) const
	{
		return mString.at(_idx);
	}

	inline typename String::reference String::first() noexcept
	{
		return mString.front();
	}

	inline typename String::const_reference String::first() const noexcept
	{
		return mString.front();
	}

	inline typename String::reference String::last()noexcept
	{
		return mString.back();
	}

	inline typename String::const_reference String::last()const noexcept
	{
		return mString.back();
	}

	inline typename String::raw_type String::raw()const noexcept
	{
		return mString.c_str();
	}

	inline typename String::size_type String::size()const noexcept
	{
		return mString.size();
	}

	inline typename String::size_type String::length() const noexcept
	{
		return mString.length();
	}

	inline typename String::size_type String::capacity()const noexcept
	{
		return mString.capacity();
	}

	inline void String::swap(String& _string)
	{
		mString.swap(_string.mString);
	}

	inline void String::resize(size_type _count)
	{
		mString.resize(_count);
	}

	inline void String::resize(size_type _count, char_type _ch)
	{
		mString.resize(_count, _ch);
	}

	inline void String::reserve(size_type _capacity)
	{
		mString.reserve(_capacity);
	}

	inline void String::replace(char_type _old, char_type _new)
	{
		auto f = [o = _old,n = _new](char_type ch) 
		{
			return ch == o ? n : ch;
		};

		std::transform(mString.begin(), mString.end(), mString.begin(), f);
	}

	inline void String::replace(raw_type _old, raw_type _new)
	{
		auto oldLen = GetRawLength(*this, _old);

		// 置換元の文字列が空
		if (oldLen == 0 || oldLen == base_type::npos)
			return;

		// 置換後の文字列が不適切
		if (GetRawLength(*this, _new) == base_type::npos)
			return;

		auto idx = mString.find(_old);

		while (idx != base_type::npos)
		{
			mString.replace(idx, oldLen, _new);
			idx = mString.find(_old);
		}
	}

	inline void String::replace(const String& _old, const String& _new)
	{
		if (_old.empty())
			return;

		auto idx = mString.find(_old.mString);

		while (idx != base_type::npos)
		{
			mString.replace(idx, _old.mString.length(), _new.raw());
			idx = mString.find(_old.mString);
		}
	}

	template<class Fty>
	inline void String::replaceBy(Fty _function, char_type _ch) requires(Concept::Predicate<Fty, typename String::char_type>)
	{
		auto it = mString.begin();
		auto e = mString.end();

		while (it != e)
		{
			if (_function(*it))
			{
				(*it) = _ch;
			}
		}
	}

	template<class Fty>
	inline void String::replaceBy(Fty _function, raw_type _raw) requires(Concept::Predicate<Fty, typename String::char_type>)
	{
		auto len = GetRawLength(*this, _raw);

		if (len == base_type::npos)
			return;

		auto it = mString.begin();

		while (it != mString.end())
		{
			if (_function(*it))
			{
				auto idx = indexOf(it);

				it = mString.erase(it);

				if (idx < mString.size())
				{
					this->insert(it, _raw);
				}
				else
				{
					mString.append(_raw);
					return;
				}

				it = mString.begin() + (idx + len);
			}
			else
			{
				++it;
			}
		}
	}

	template<class Fty>
	inline void String::replaceBy(Fty _function, const String& _string) requires(Concept::Predicate<Fty, typename String::char_type>)
	{
		auto len = _string.mString.length();

		auto it = mString.begin();

		while (it != mString.end())
		{
			if (_function(*it))
			{
				auto idx = indexOf(it);

				it = mString.erase(it);

				if (idx < mString.size())
				{
					this->insert(it, _string.raw());
				}
				else
				{
					mString.append(_string.raw());
					return;
				}

				it = mString.begin() + (idx + len);
			}
			else
			{
				++it;
			}
		}
	}

	template<class Fty>
	inline String String::map(Fty _function) const requires(Concept::PredicateWith<typename String::char_type, Fty, typename String::char_type>)
	{
		String result{};
		result.reserve(mString.size());
		std::transform(mString.cbegin(), mString.cend(), std::back_inserter(result.mString), _function);
		return result;
	}

	inline typename String::iterator String::begin()noexcept
	{
		return mString.begin();
	}

	inline typename String::const_iterator String::begin()const noexcept
	{
		return mString.cbegin();
	}

	inline typename String::iterator String::end()noexcept
	{
		return mString.end();
	}

	inline typename String::const_iterator String::end()const noexcept
	{
		return mString.cend();
	}

	inline typename String::const_iterator String::cbegin()const noexcept
	{
		return mString.cbegin();
	}

	inline typename String::const_iterator String::cend()const noexcept
	{
		return mString.cend();
	}

	inline typename String::reverse_iterator String::rbegin()noexcept
	{
		return mString.rbegin();
	}

	inline typename String::const_reverse_iterator String::rbegin()const noexcept
	{
		return mString.crbegin();
	}

	inline typename String::reverse_iterator String::rend()noexcept
	{
		return mString.rend();
	}

	inline typename String::const_reverse_iterator String::rend()const noexcept
	{
		return mString.crend();
	}

	inline typename String::const_reverse_iterator String::crbegin()const noexcept
	{
		return mString.crbegin();
	}

	inline typename String::const_reverse_iterator String::crend()const noexcept
	{
		return mString.crend();
	}

	inline bool String::empty()const noexcept
	{
		return mString.empty();
	}

	inline size_t String::GetRawLength(const String& string, raw_type raw) noexcept
	{
		auto i = 0ui64;
		const auto e = string.mString.max_size();

		while (i < e)
		{
			if (raw[i] == U'\0')
				return i;
			++i;
		}

		return base_type::npos;
	}

	inline String operator+(const String& left, const String& right)
	{
		return String{ left.mString + right.mString };
	}

	inline String operator+(const String& string, String::char_type ch)
	{
		return String{ string.mString + ch };
	}

	inline String operator+(const String& string, String::raw_type raw)
	{
		return String{ string.mString + raw };
	}

	inline String operator+(const String& string, std::initializer_list<String::char_type> iniList)
	{
		return String{ string.mString + iniList };
	}

	inline String& operator+=(String& left, const String& right)
	{
		left.mString += right.mString;
		return left;
	}

	inline String& operator+=(String& string, String::char_type ch)
	{
		string.mString += ch;
		return string;
	}

	inline String& operator+=(String& string, String::raw_type raw)
	{
		string.mString += raw;
		return string;
	}

	inline String& operator+=(String& string, std::initializer_list<String::char_type> iniList)
	{
		string.mString += iniList;
		return string;
	}

	inline bool operator==(const String& left, const String& right)
	{
		return left.mString == right.mString;
	}

	inline bool operator==(const String& string, String::char_type ch)
	{
		return string.mString == ch;
	}

	inline bool operator==(const String& string, String::raw_type raw)
	{
		return string.mString == raw;
	}

	inline bool operator!=(const String& left, const String& right)
	{
		return !(left == right);
	}

	inline bool operator!=(const String& string, String::char_type ch)
	{
		return !(string == ch);
	}

	inline bool operator!=(const String& string, String::raw_type raw)
	{
		return !(string == raw);
	}
}

namespace Iris
{
	inline constexpr bool IsLower(char32_t ch) noexcept
	{
		return InRange(ch, U'a', U'z');
	}

	inline constexpr bool IsUpper(char32_t ch) noexcept
	{
		return InRange(ch, U'A', U'Z');
	}

	inline constexpr bool IsDigit(char32_t ch) noexcept
	{
		return InRange(ch, U'0', U'9');
	}

	inline constexpr bool IsXdigit(char32_t ch) noexcept
	{
		return InRange(ch, U'0', U'9') || InRange(ch, U'a', U'f') || InRange(ch, U'A', U'F');
	}

	inline constexpr bool IsAlpha(char32_t ch) noexcept
	{
		return InRange(ch, U'a', U'z') || InRange(ch, U'A', U'Z');
	}

	inline constexpr bool IsAlnum(char32_t ch) noexcept
	{
		return IsDigit(ch) || IsAlpha(ch);
	}

	inline constexpr char32_t ToLower(char32_t ch) noexcept
	{
		return IsUpper(ch) ? ch + 32 : ch;
	}

	inline constexpr char32_t ToUpper(char32_t ch) noexcept
	{
		return IsLower(ch) ? ch - 32 : ch;
	}
}

template<>
struct std::hash<Iris::String>
{
	size_t operator()(const Iris::String& _string) const
	{
		using base_hasher = std::hash<Iris::String::base_type>;
		return base_hasher{}(*_string);
	}
};