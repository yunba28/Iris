#pragma once

#include <vector>
#include <algorithm>

#include <Iris/Common/Numeric.hpp>

namespace Iris
{

	template<class Type, class Allocator = std::allocator<Type>>
	class Array
	{
	public:

		using base_type = std::vector<Type, Allocator>;

		using value_type		= typename base_type::value_type;
		using allocator_type	= typename base_type::allocator_type;
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

		explicit Array()noexcept;

		explicit Array(const Allocator& _alloc)noexcept;

		explicit Array(size_type _count, const Allocator& _alloc = Allocator{});

		Array(size_type _count, const Type& _val, const Allocator& _alloc = Allocator{});

		Array(std::initializer_list<Type> _iniList, const Allocator& _alloc = Allocator{});

		template<class Iterator>
		Array(Iterator _first, Iterator _last, const Allocator& _alloc = Allocator{});

		Array(const Array&) = default;

		Array(Array&&) = default;

		Array& operator=(std::initializer_list<Type> _iniList);

		Array& operator=(const Array&) = default;

		Array& operator=(Array&&) = default;

		reference operator[](size_type _idx)noexcept;

		const_reference operator[](size_type _idx)const noexcept;

		explicit operator bool()const noexcept;

		/// @brief 任意の位置に要素を生成する
		/// @param _where 要素を作成する配列内の場所
		/// @param ..._args 要素の作成に必要な引数
		template<class ...Args>
		void emplace(const_iterator _where, Args&& ..._args);

		/// @brief 配列の先頭に要素を生成する
		/// @param ..._args 要素の作成に必要な引数
		template<class ...Args>
		void emplaceFirst(Args&& ..._args);

		/// @brief 配列の最後に要素を生成する
		/// @param ..._args 要素の作成に必要な引数
		template<class ...Args>
		void emplaceLast(Args&& ..._args);

		/// @brief 配列の先頭に要素を追加する
		/// @param _val 追加する要素
		void addFirst(const Type& _val);

		/// @brief 配列の先頭に要素を追加する
		/// @param _val 追加する要素
		void addFirst(Type&& _val);

		/// @brief 配列の先頭に要素を追加する
		/// @param _iniList 追加する要素
		void addFirst(std::initializer_list<Type> _iniList);

		/// @brief 配列の先頭にある範囲内にある要素を追加する
		/// @param _first 範囲の先頭
		/// @param _last 範囲の最後
		template<class Iterator>
		void addFirst(Iterator _first, Iterator _last);

		/// @brief 配列の最後に要素を追加する
		/// @param _val 追加する要素
		void addLast(const Type& _val);

		/// @brief 配列の最後に要素を追加する
		/// @param _val 追加する要素
		void addLast(Type&& _val);

		/// @brief 配列の最後に要素を追加する
		/// @param _iniList 追加する要素
		void addLast(std::initializer_list<Type> _iniList);

		/// @brief 配列の最後にある範囲内にある要素を追加する
		/// @param _first 範囲の先頭
		/// @param _last 範囲の最後
		template<class Iterator>
		void addLast(Iterator _first, Iterator _last);

		/// @brief 任意の位置に要素を追加する
		/// @param _where 配列内の場所
		/// @param _val 追加する要素
		void insert(const_iterator _where, const Type& _val);

		/// @brief 任意の位置に要素を追加する
		/// @param _where 配列内の場所
		/// @param _val 追加する要素
		void insert(const_iterator _where, Type&& _val);

		/// @brief 任意の位置に要素を追加する
		/// @param _where 配列内の場所
		/// @param _iniList 追加する要素
		void insert(const_iterator _where, std::initializer_list<Type> _iniList);

		/// @brief 任意の位置にある範囲の要素を追加する
		/// @param _where 配列内の場所
		/// @param _first 範囲の先頭
		/// @param _last 範囲の最後
		template<class Iterator>
		void insert(const_iterator _where, Iterator _first, Iterator _last);

		/// @brief 配列の先頭に配列を追加する
		/// @param _array 追加する配列
		void prepend(const Array& _array);

		/// @brief 配列の先頭に配列を追加する
		/// @param _array 追加する配列
		void prepend(Array&& _array);

		/// @brief 配列の最後に配列を追加する
		/// @param _array 追加する配列
		void append(const Array& _array);

		/// @brief 配列の最後に配列を追加する
		/// @param _array 追加する配列
		void append(Array&& _array);

		/// @brief 指定した要素と等しい要素をすべて削除する
		/// @param _val 削除する要素
		void remove(const Type& _val);

		/// @brief 任意の位置の要素を削除する
		/// @param _where 配列内の場所
		void remove(const_iterator _where);

		/// @brief 配列の先頭にある要素を削除する
		void removeFirst();

		/// @brief 配列の最後にある要素を削除する
		void removeLast();

		/// @brief 配列の指定した範囲内の要素を削除する
		/// @param _first 範囲の先頭
		/// @param _last 範囲の最後
		void removeRange(const_iterator _first, const_iterator _last);

		/// @brief インデックスで指定した位置にある要素を削除する
		void removeAt(size_type _index);

		/// @brief 条件に一致した要素をすべて削除する
		/// @param _function 条件式を記述した関数
		template<class Fty>
		void removeBy(Fty _function)requires(Concept::Predicate<Fty, const Type&>);

		/// @brief 配列内のすべての要素を削除する
		void removeAll()noexcept;

		/// @brief 配列内の不要なメモリを解放する
		void shrinkToFit()noexcept;

		/// @brief 指定した要素と等しい要素がある位置のイテレータを取得する
		/// @param _val 探したい要素
		/// @return 見つからなければ'this->end()'が返る
		iterator find(const Type& _val);

		/// @brief 指定した要素と等しい要素がある位置のイテレータを取得する
		/// @param _val 探したい要素
		/// @return 見つからなければ'this->end()'が返る
		const_iterator find(const Type& _val)const;

		/// @brief インデックスで指定した位置の要素のイテレータを取得する
		/// @return インデックスが範囲外であれば'this->end()'が返る
		iterator findAt(size_type _index);

		/// @brief インデックスで指定した位置の要素のイテレータを取得する
		/// @return インデックスが範囲外であれば'this->end()'が返る
		const_iterator findAt(size_type _index)const;

		/// @brief 条件に一致する要素のイテレータを取得する
		/// @param _function 条件式を記述した関数
		/// @return 見つからなければ'this->end()'が返る
		template<class Fty>
		iterator findBy(Fty _function)requires(Concept::Predicate<Fty, const Type&>);

		/// @brief 条件に一致する要素のイテレータを取得する
		/// @param _function 条件式を記述した関数
		/// @return 見つからなければ'this->end()'が返る
		template<class Fty>
		const_iterator findBy(Fty _function)const requires(Concept::Predicate<Fty, const Type&>);

		/// @brief イテレータが指すインデックスを取得します
		/// @return 見つからなかった場合はuint64::Max()
		size_type indexOf(const_iterator _where)const noexcept;

		/// @brief 要素の先頭ポインタを取得する
		Type* data()noexcept;

		/// @brief 要素の先頭ポインタを取得する
		const Type* data()const noexcept;

		/// @brief インデックスで指定した位置の要素を取得する
		Type& at(size_type _index);

		/// @brief インデックスで指定した位置の要素を取得する
		const Type& at(size_type _index)const;

		/// @brief 配列の先頭要素を取得する
		Type& first();

		/// @brief 配列の先頭要素を取得する
		const Type& first()const;

		/// @brief 配列の最後の要素を取得する
		Type& last();

		/// @brief 配列の最後の要素を取得する
		const Type& last()const;

		/// @brief 配列のサイズを取得する
		size_type size()const noexcept;

		/// @brief 配列が確保しているメモリ要素数を取得する
		size_type capacity()const noexcept;

		/// @brief 指定した要素が配列内にいくつあるか取得する
		size_type count(const Type& _val)const;

		/// @brief 条件に一致する要素がいくつあるか取得する
		/// @param _function 条件式
		template<class Fty>
		size_type countBy(Fty _function)const requires(Concept::Predicate<Fty, const Type&>);

		void swap(Array& _other)noexcept;

		/// @brief 配列の大きさを更新する
		void resize(size_type _size);

		/// @brief 配列の大きさを更新する
		void resize(size_type _size, const Type& _val);

		/// @brief 配列の保有メモリを更新する
		void reserve(size_type _capacity);

		/// @brief 配列を昇順で並べ替える
		/// @brief 要素の順序は保証されない
		void sortBy();

		/// @brief 配列を比較式を用いて並べ替える
		/// @brief 要素の順序は保証されない
		/// @param _comparator 比較式
		template<class Comparator>
		void sortBy(Comparator _comparator);

		/// @brief 配列を昇順で並べ替える
		/// @brief 要素の順序は保証される
		void stableSortBy();

		/// @brief 配列を比較式を用いて並べ替える
		/// @brief 要素の順序は保証される
		/// @param _comparator 比較式
		template<class Comparator>
		void stableSortBy(Comparator _comparator);

		/// @brief ヒープ化された配列を昇順に並べ替える
		/// @brief 比較式はヒープ化した際に使用したものと同じでなければならない
		void heapSortBy();

		/// @brief ヒープ化された配列を比較式を用いて並べ替える
		/// @brief 比較式はヒープ化した際に使用したものと同じでなければならない
		template<class Comparator>
		void heapSortBy(Comparator _comparator);

		/// @brief 配列を昇順でヒープ化する
		void heapify();

		/// @brief 配列を比較式を用いてヒープ化する
		/// @param _comparator 比較式
		template<class Comparator>
		void heapify(Comparator _comparator);

		template<class Fty>
		Array<Type, Allocator> map(Fty _function)const requires(Concept::PredicateWith<Type, Fty, const Type&>);

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

		template<class Fty>
		void forEach(Fty _function)requires(Concept::Invocable<Fty, Type&>);

		template<class Fty>
		void forEach(Fty _function)const requires(Concept::Invocable<Fty, const Type&>);

		bool contains(const Type& _val)const;

		template<class Fty>
		bool contains(Fty _function)const requires(Concept::Predicate<Fty, const Type&>);

		template<class Fty>
		bool anyOf(Fty _function)const requires(Concept::Predicate<Fty, const Type&>);

		template<class Fty>
		bool allOf(Fty _function)const requires(Concept::Predicate<Fty, const Type&>);

		template<class Fty>
		bool noneOf(Fty _function)const requires(Concept::Predicate<Fty, const Type&>);

		bool empty()const noexcept;

		friend bool operator==(const Array& a, const Array& b);

		friend bool operator!=(const Array& a, const Array& b);

	private:

		base_type mArray;

	};

	template <class Type, class Allocator = std::allocator<Type>>
	Array(std::initializer_list<Type>, const Allocator& = Allocator{}) -> Array<Type, Allocator>;
}

namespace Iris
{
	template<class Type, class Allocator>
	inline Array<Type, Allocator>::Array() noexcept
		: mArray()
	{}

	template<class Type, class Allocator>
	inline Array<Type, Allocator>::Array(const Allocator& _alloc) noexcept
		: mArray(_alloc)
	{}

	template<class Type, class Allocator>
	inline Array<Type, Allocator>::Array(size_type _count, const Allocator& _alloc)
		: mArray(*_count, _alloc)
	{}

	template<class Type, class Allocator>
	inline Array<Type, Allocator>::Array(size_type _count, const Type& _val, const Allocator& _alloc)
		: mArray(*_count, _val, _alloc)
	{}

	template<class Type, class Allocator>
	inline Array<Type, Allocator>::Array(std::initializer_list<Type> _iniList, const Allocator& _alloc)
		: mArray(_iniList, _alloc)
	{}

	template<class Type, class Allocator> template<class Iterator>
	inline Array<Type, Allocator>::Array(Iterator _first, Iterator _last, const Allocator& _alloc)
		: mArray(_first,_last, _alloc)
	{}

	template<class Type, class Allocator>
	inline Array<Type, Allocator>& Array<Type, Allocator>::operator=(std::initializer_list<Type> _iniList)
	{
		mArray = _iniList; return *this;
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::reference Array<Type, Allocator>::operator[](size_type _idx) noexcept
	{
		return mArray[*_idx];
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_reference Array<Type, Allocator>::operator[](size_type _idx) const noexcept
	{
		return mArray[*_idx];
	}

	template<class Type, class Allocator>
	inline Array<Type, Allocator>::operator bool() const noexcept
	{
		return !mArray.empty();
	}

	template<class Type, class Allocator> template<class ...Args>
	inline void Array<Type, Allocator>::emplace(const_iterator _where,Args&& ..._args)
	{
		mArray.emplace(_where, std::forward<Args>(_args)...);
	}

	template<class Type, class Allocator> template<class ...Args>
	inline void Array<Type, Allocator>::emplaceFirst(Args&& ..._args)
	{
		mArray.emplace(mArray.cbegin(), std::forward<Args>(_args)...);
	}

	template<class Type, class Allocator> template<class ...Args>
	inline void Array<Type, Allocator>::emplaceLast(Args&& ..._args)
	{
		mArray.emplace_back(std::forward<Args>(_args)...);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::addFirst(const Type& _val)
	{
		mArray.insert(mArray.cbegin(), _val);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::addFirst(Type&& _val)
	{
		mArray.insert(mArray.cbegin(), std::forward<Type>(_val));
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::addFirst(std::initializer_list<Type> _iniList)
	{
		mArray.insert(mArray.cbegin(), _iniList);
	}

	template<class Type, class Allocator> template<class Iterator>
	inline void Array<Type, Allocator>::addFirst(Iterator _first,Iterator _last)
	{
		mArray.insert(mArray.cbegin(), _first, _last);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::addLast(const Type& _val)
	{
		mArray.push_back(_val);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::addLast(Type&& _val)
	{
		mArray.push_back(std::forward<Type>(_val));
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::addLast(std::initializer_list<Type> _iniList)
	{
		mArray.insert(mArray.cend(), _iniList);
	}

	template<class Type, class Allocator> template<class Iterator>
	inline void Array<Type, Allocator>::addLast(Iterator _first, Iterator _last)
	{
		mArray.insert(mArray.cend(), _first, _last);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::insert(const_iterator _where, const Type& _val)
	{
		mArray.insert(_where, _val);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::insert(const_iterator _where, Type&& _val)
	{
		mArray.insert(_where, std::forward<Type>(_val));
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::insert(const_iterator _where, std::initializer_list<Type> _iniList)
	{
		mArray.insert(_where, _iniList);
	}

	template<class Type, class Allocator> template<class Iterator>
	inline void Array<Type, Allocator>::insert(const_iterator _where, Iterator _first, Iterator _last)
	{
		mArray.insert(_where, _first, _last);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::prepend(const Array& _array)
	{
		mArray.insert(mArray.cbegin(), _array.begin(), _array.end());
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::prepend(Array&& _array)
	{
		mArray.insert(mArray.cbegin(), _array.begin(), _array.end());
		_array.clear();
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::append(const Array& _array)
	{
		mArray.insert(mArray.cend(), _array.begin(), _array.end());
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::append(Array&& _array)
	{
		mArray.insert(mArray.cend(), _array.begin(), _array.end());
		_array.clear();
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::remove(const Type& _val)
	{
		auto ret = std::remove(mArray.begin(), mArray.end(), _val);

		if (ret != mArray.end())
		{
			mArray.erase(ret, mArray.end());
		}
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::remove(const_iterator _where)
	{
		mArray.erase(_where);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::removeFirst()
	{
		mArray.erase(mArray.cbegin());
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::removeLast()
	{
		mArray.pop_back();
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::removeRange(const_iterator _first, const_iterator _last)
	{
		mArray.erase(_first, _last);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::removeAt(size_type _index)
	{
		auto ret = findAt(_index);

		if (ret != mArray.end())
		{
			mArray.erase(ret);
		}
	}

	template<class Type, class Allocator> template<class Fty>
	inline void Array<Type, Allocator>::removeBy(Fty _function)requires(Concept::Predicate<Fty, const Type&>)
	{
		auto ret = std::remove_if(mArray.begin(), mArray.end(), _function);

		if (ret != mArray.end())
		{
			mArray.erase(ret, mArray.end());
		}
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::removeAll() noexcept
	{
		mArray.clear();
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::shrinkToFit() noexcept
	{
		mArray.shrink_to_fit();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::iterator Array<Type, Allocator>::find(const Type& _val)
	{
		return std::find(mArray.begin(), mArray.end(), _val);
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_iterator Array<Type, Allocator>::find(const Type& _val) const
	{
		return std::find(mArray.cbegin(), mArray.cend(), _val);
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::iterator Array<Type, Allocator>::findAt(size_type _index)
	{
		if (_index > mArray.size())
			return mArray.end();

		return mArray.begin() + *_index;
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_iterator Array<Type, Allocator>::findAt(size_type _index) const
	{
		if (_index > mArray.size())
			return mArray.cend();

		return mArray.cbegin() + *_index;
	}

	template<class Type, class Allocator> template<class Fty>
	inline typename Array<Type, Allocator>::iterator Array<Type, Allocator>::findBy(Fty _function) requires(Concept::Predicate<Fty, const Type&>)
	{
		return std::find_if(mArray.begin(), mArray.end(), _function);
	}

	template<class Type, class Allocator> template<class Fty>
	inline typename Array<Type, Allocator>::const_iterator Array<Type, Allocator>::findBy(Fty _function) const requires(Concept::Predicate<Fty, const Type&>)
	{
		return std::find_if(mArray.cbegin(), mArray.cend(), _function);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::sortBy()
	{
		std::sort(mArray.begin(), mArray.end());
	}

	template<class Type, class Allocator>
	template<class Comparator>
	inline void Array<Type, Allocator>::sortBy(Comparator _comparator)
	{
		std::sort(mArray.begin(), mArray.end(), _comparator);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::stableSortBy()
	{
		std::stable_sort(mArray.begin(), mArray.end());
	}

	template<class Type, class Allocator>
	template<class Comparator>
	inline void Array<Type, Allocator>::stableSortBy(Comparator _comparator)
	{
		std::stable_sort(mArray.begin(), mArray.end(), _comparator);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::heapSortBy()
	{
		std::sort_heap(mArray.begin(), mArray.end());
	}

	template<class Type, class Allocator>
	template<class Comparator>
	inline void Array<Type, Allocator>::heapSortBy(Comparator _comparator)
	{
		std::sort_heap(mArray.begin(), mArray.end(), _comparator);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::heapify()
	{
		std::make_heap(mArray.begin(), mArray.end());
	}

	template<class Type, class Allocator>
	template<class Comparator>
	inline void Array<Type, Allocator>::heapify(Comparator _comparator)
	{
		std::make_heap(mArray.begin(), mArray.end(), _comparator);
	}

	template<class Type, class Allocator>
	template<class Fty>
	inline Array<Type, Allocator> Array<Type, Allocator>::map(Fty _function) const requires(Concept::PredicateWith<Type,Fty,const Type&>)
	{
		Array<Type, Allocator> result;
		result.reserve(mArray.size());
		std::transform(mArray.cbegin(), mArray.cend(), std::back_inserter(result.mArray), _function);
		return result;
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::size_type Array<Type, Allocator>::indexOf(const_iterator _where) const noexcept
	{
		size_type i = 0;

		auto it = mArray.begin();
		auto e = mArray.end();

		while (it != e)
		{
			if (it == _where)
				return i;
			++it;
			++i;
		}

		return size_type(UINT64_MAX);
	}

	template<class Type, class Allocator>
	inline Type* Array<Type, Allocator>::data()noexcept
	{
		return mArray.data();
	}

	template<class Type, class Allocator>
	inline const Type* Array<Type, Allocator>::data()const noexcept
	{
		return mArray.data();
	}

	template<class Type, class Allocator>
	inline Type& Array<Type, Allocator>::at(size_type _index)
	{
		return mArray.at(*_index);
	}

	template<class Type, class Allocator>
	inline const Type& Array<Type, Allocator>::at(size_type _index) const
	{
		return mArray.at(*_index);
	}

	template<class Type, class Allocator>
	inline Type& Array<Type, Allocator>::first()
	{
		return mArray.front();
	}

	template<class Type, class Allocator>
	inline const Type& Array<Type, Allocator>::first() const
	{
		return mArray.front();
	}

	template<class Type, class Allocator>
	inline Type& Array<Type, Allocator>::last()
	{
		return mArray.back();
	}

	template<class Type, class Allocator>
	inline const Type& Array<Type, Allocator>::last() const
	{
		return mArray.back();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::size_type Array<Type, Allocator>::size() const noexcept
	{
		return mArray.size();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::size_type Array<Type, Allocator>::capacity() const noexcept
	{
		return mArray.capacity();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::size_type Array<Type, Allocator>::count(const Type& _val) const
	{
		return std::count(mArray.begin(), mArray.end(), _val);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::swap(Array& _other) noexcept
	{
		mArray.swap(_other.mArray);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::resize(size_type _size)
	{
		mArray.resize(_size);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::resize(size_type _size, const Type& _val)
	{
		mArray.resize(_size, _val);
	}

	template<class Type, class Allocator>
	inline void Array<Type, Allocator>::reserve(size_type _capacity)
	{
		mArray.reserve(_capacity);
	}

	template<class Type, class Allocator>
	template<class Fty>
	inline typename Array<Type, Allocator>::size_type Array<Type, Allocator>::countBy(Fty _function) const requires(Concept::Predicate<Fty,const Type&>)
	{
		return std::count_if(mArray.begin(), mArray.end(), _function);
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::iterator Array<Type, Allocator>::begin() noexcept
	{
		return mArray.begin();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_iterator Array<Type, Allocator>::begin() const noexcept
	{
		return mArray.cbegin();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::iterator Array<Type, Allocator>::end() noexcept
	{
		return mArray.end();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_iterator Array<Type, Allocator>::end() const noexcept
	{
		return mArray.cend();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_iterator Array<Type, Allocator>::cbegin() const noexcept
	{
		return mArray.cbegin();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_iterator Array<Type, Allocator>::cend() const noexcept
	{
		return mArray.cend();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::reverse_iterator Array<Type, Allocator>::rbegin() noexcept
	{
		return mArray.rbegin();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_reverse_iterator Array<Type, Allocator>::rbegin() const noexcept
	{
		return mArray.crbegin();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::reverse_iterator Array<Type, Allocator>::rend() noexcept
	{
		return mArray.rend();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_reverse_iterator Array<Type, Allocator>::rend() const noexcept
	{
		return mArray.crend();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_reverse_iterator Array<Type, Allocator>::crbegin() const noexcept
	{
		return mArray.crbegin();
	}

	template<class Type, class Allocator>
	inline typename Array<Type, Allocator>::const_reverse_iterator Array<Type, Allocator>::crend() const noexcept
	{
		return mArray.crend();
	}

	template<class Type, class Allocator> template<class Fty>
	inline void Array<Type, Allocator>::forEach(Fty _function) requires(Concept::Invocable<Fty, Type&>)
	{
		for (auto& elem : mArray)
			_function(elem);
	}

	template<class Type, class Allocator> template<class Fty>
	inline void Array<Type, Allocator>::forEach(Fty _function) const  requires(Concept::Invocable<Fty, const Type&>)
	{
		for (const auto& elem : mArray)
			_function(elem);
	}

	template<class Type, class Allocator>
	inline bool Array<Type, Allocator>::contains(const Type& _val) const
	{
		return std::count(mArray.begin(), mArray.end(), _val) > 0;
	}

	template<class Type, class Allocator>
	template<class Fty>
	inline bool Array<Type, Allocator>::contains(Fty _function) const requires(Concept::Predicate<Fty,const Type&>)
	{
		return std::count_if(mArray.begin(), mArray.end(), _function) > 0;
	}

	template<class Type, class Allocator>
	template<class Fty>
	inline bool Array<Type, Allocator>::anyOf(Fty _function) const requires(Concept::Predicate<Fty, const Type&>)
	{
		return std::any_of(mArray.begin(), mArray.end(), _function);
	}

	template<class Type, class Allocator>
	template<class Fty>
	inline bool Array<Type, Allocator>::allOf(Fty _function) const requires(Concept::Predicate<Fty, const Type&>)
	{
		return std::all_of(mArray.begin(), mArray.end(), _function);
	}

	template<class Type, class Allocator>
	template<class Fty>
	inline bool Array<Type, Allocator>::noneOf(Fty _function) const requires(Concept::Predicate<Fty, const Type&>)
	{
		return std::none_of(mArray.begin(), mArray.end(), _function);
	}

	template<class Type, class Allocator>
	inline bool Array<Type, Allocator>::empty() const noexcept
	{
		return mArray.empty();
	}

	template<class Type, class Allocator>
	inline bool operator==(const Array<Type, Allocator>& a, const Array<Type, Allocator>& b)
	{
		return a.mArray == b.mArray;
	}

	template<class Type, class Allocator>
	inline bool operator!=(const Array<Type, Allocator>& a, const Array<Type, Allocator>& b)
	{
		return a.mArray != b.mArray;
	}
}