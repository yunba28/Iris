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

		/// @brief �C�ӂ̈ʒu�ɗv�f�𐶐�����
		/// @param _where �v�f���쐬����z����̏ꏊ
		/// @param ..._args �v�f�̍쐬�ɕK�v�Ȉ���
		template<class ...Args>
		void emplace(const_iterator _where, Args&& ..._args);

		/// @brief �z��̐擪�ɗv�f�𐶐�����
		/// @param ..._args �v�f�̍쐬�ɕK�v�Ȉ���
		template<class ...Args>
		void emplaceFirst(Args&& ..._args);

		/// @brief �z��̍Ō�ɗv�f�𐶐�����
		/// @param ..._args �v�f�̍쐬�ɕK�v�Ȉ���
		template<class ...Args>
		void emplaceLast(Args&& ..._args);

		/// @brief �z��̐擪�ɗv�f��ǉ�����
		/// @param _val �ǉ�����v�f
		void addFirst(const Type& _val);

		/// @brief �z��̐擪�ɗv�f��ǉ�����
		/// @param _val �ǉ�����v�f
		void addFirst(Type&& _val);

		/// @brief �z��̐擪�ɗv�f��ǉ�����
		/// @param _iniList �ǉ�����v�f
		void addFirst(std::initializer_list<Type> _iniList);

		/// @brief �z��̐擪�ɂ���͈͓��ɂ���v�f��ǉ�����
		/// @param _first �͈͂̐擪
		/// @param _last �͈͂̍Ō�
		template<class Iterator>
		void addFirst(Iterator _first, Iterator _last);

		/// @brief �z��̍Ō�ɗv�f��ǉ�����
		/// @param _val �ǉ�����v�f
		void addLast(const Type& _val);

		/// @brief �z��̍Ō�ɗv�f��ǉ�����
		/// @param _val �ǉ�����v�f
		void addLast(Type&& _val);

		/// @brief �z��̍Ō�ɗv�f��ǉ�����
		/// @param _iniList �ǉ�����v�f
		void addLast(std::initializer_list<Type> _iniList);

		/// @brief �z��̍Ō�ɂ���͈͓��ɂ���v�f��ǉ�����
		/// @param _first �͈͂̐擪
		/// @param _last �͈͂̍Ō�
		template<class Iterator>
		void addLast(Iterator _first, Iterator _last);

		/// @brief �C�ӂ̈ʒu�ɗv�f��ǉ�����
		/// @param _where �z����̏ꏊ
		/// @param _val �ǉ�����v�f
		void insert(const_iterator _where, const Type& _val);

		/// @brief �C�ӂ̈ʒu�ɗv�f��ǉ�����
		/// @param _where �z����̏ꏊ
		/// @param _val �ǉ�����v�f
		void insert(const_iterator _where, Type&& _val);

		/// @brief �C�ӂ̈ʒu�ɗv�f��ǉ�����
		/// @param _where �z����̏ꏊ
		/// @param _iniList �ǉ�����v�f
		void insert(const_iterator _where, std::initializer_list<Type> _iniList);

		/// @brief �C�ӂ̈ʒu�ɂ���͈̗͂v�f��ǉ�����
		/// @param _where �z����̏ꏊ
		/// @param _first �͈͂̐擪
		/// @param _last �͈͂̍Ō�
		template<class Iterator>
		void insert(const_iterator _where, Iterator _first, Iterator _last);

		/// @brief �z��̐擪�ɔz���ǉ�����
		/// @param _array �ǉ�����z��
		void prepend(const Array& _array);

		/// @brief �z��̐擪�ɔz���ǉ�����
		/// @param _array �ǉ�����z��
		void prepend(Array&& _array);

		/// @brief �z��̍Ō�ɔz���ǉ�����
		/// @param _array �ǉ�����z��
		void append(const Array& _array);

		/// @brief �z��̍Ō�ɔz���ǉ�����
		/// @param _array �ǉ�����z��
		void append(Array&& _array);

		/// @brief �w�肵���v�f�Ɠ������v�f�����ׂč폜����
		/// @param _val �폜����v�f
		void remove(const Type& _val);

		/// @brief �C�ӂ̈ʒu�̗v�f���폜����
		/// @param _where �z����̏ꏊ
		void remove(const_iterator _where);

		/// @brief �z��̐擪�ɂ���v�f���폜����
		void removeFirst();

		/// @brief �z��̍Ō�ɂ���v�f���폜����
		void removeLast();

		/// @brief �z��̎w�肵���͈͓��̗v�f���폜����
		/// @param _first �͈͂̐擪
		/// @param _last �͈͂̍Ō�
		void removeRange(const_iterator _first, const_iterator _last);

		/// @brief �C���f�b�N�X�Ŏw�肵���ʒu�ɂ���v�f���폜����
		void removeAt(size_type _index);

		/// @brief �����Ɉ�v�����v�f�����ׂč폜����
		/// @param _function ���������L�q�����֐�
		template<class Fty>
		void removeBy(Fty _function)requires(Concept::Predicate<Fty, const Type&>);

		/// @brief �z����̂��ׂĂ̗v�f���폜����
		void removeAll()noexcept;

		/// @brief �z����̕s�v�ȃ��������������
		void shrinkToFit()noexcept;

		/// @brief �w�肵���v�f�Ɠ������v�f������ʒu�̃C�e���[�^���擾����
		/// @param _val �T�������v�f
		/// @return ������Ȃ����'this->end()'���Ԃ�
		iterator find(const Type& _val);

		/// @brief �w�肵���v�f�Ɠ������v�f������ʒu�̃C�e���[�^���擾����
		/// @param _val �T�������v�f
		/// @return ������Ȃ����'this->end()'���Ԃ�
		const_iterator find(const Type& _val)const;

		/// @brief �C���f�b�N�X�Ŏw�肵���ʒu�̗v�f�̃C�e���[�^���擾����
		/// @return �C���f�b�N�X���͈͊O�ł����'this->end()'���Ԃ�
		iterator findAt(size_type _index);

		/// @brief �C���f�b�N�X�Ŏw�肵���ʒu�̗v�f�̃C�e���[�^���擾����
		/// @return �C���f�b�N�X���͈͊O�ł����'this->end()'���Ԃ�
		const_iterator findAt(size_type _index)const;

		/// @brief �����Ɉ�v����v�f�̃C�e���[�^���擾����
		/// @param _function ���������L�q�����֐�
		/// @return ������Ȃ����'this->end()'���Ԃ�
		template<class Fty>
		iterator findBy(Fty _function)requires(Concept::Predicate<Fty, const Type&>);

		/// @brief �����Ɉ�v����v�f�̃C�e���[�^���擾����
		/// @param _function ���������L�q�����֐�
		/// @return ������Ȃ����'this->end()'���Ԃ�
		template<class Fty>
		const_iterator findBy(Fty _function)const requires(Concept::Predicate<Fty, const Type&>);

		/// @brief �C�e���[�^���w���C���f�b�N�X���擾���܂�
		/// @return ������Ȃ������ꍇ��uint64::Max()
		size_type indexOf(const_iterator _where)const noexcept;

		/// @brief �v�f�̐擪�|�C���^���擾����
		Type* data()noexcept;

		/// @brief �v�f�̐擪�|�C���^���擾����
		const Type* data()const noexcept;

		/// @brief �C���f�b�N�X�Ŏw�肵���ʒu�̗v�f���擾����
		Type& at(size_type _index);

		/// @brief �C���f�b�N�X�Ŏw�肵���ʒu�̗v�f���擾����
		const Type& at(size_type _index)const;

		/// @brief �z��̐擪�v�f���擾����
		Type& first();

		/// @brief �z��̐擪�v�f���擾����
		const Type& first()const;

		/// @brief �z��̍Ō�̗v�f���擾����
		Type& last();

		/// @brief �z��̍Ō�̗v�f���擾����
		const Type& last()const;

		/// @brief �z��̃T�C�Y���擾����
		size_type size()const noexcept;

		/// @brief �z�񂪊m�ۂ��Ă��郁�����v�f�����擾����
		size_type capacity()const noexcept;

		/// @brief �w�肵���v�f���z����ɂ������邩�擾����
		size_type count(const Type& _val)const;

		/// @brief �����Ɉ�v����v�f���������邩�擾����
		/// @param _function ������
		template<class Fty>
		size_type countBy(Fty _function)const requires(Concept::Predicate<Fty, const Type&>);

		void swap(Array& _other)noexcept;

		/// @brief �z��̑傫�����X�V����
		void resize(size_type _size);

		/// @brief �z��̑傫�����X�V����
		void resize(size_type _size, const Type& _val);

		/// @brief �z��ۗ̕L���������X�V����
		void reserve(size_type _capacity);

		/// @brief �z��������ŕ��בւ���
		/// @brief �v�f�̏����͕ۏ؂���Ȃ�
		void sortBy();

		/// @brief �z����r����p���ĕ��בւ���
		/// @brief �v�f�̏����͕ۏ؂���Ȃ�
		/// @param _comparator ��r��
		template<class Comparator>
		void sortBy(Comparator _comparator);

		/// @brief �z��������ŕ��בւ���
		/// @brief �v�f�̏����͕ۏ؂����
		void stableSortBy();

		/// @brief �z����r����p���ĕ��בւ���
		/// @brief �v�f�̏����͕ۏ؂����
		/// @param _comparator ��r��
		template<class Comparator>
		void stableSortBy(Comparator _comparator);

		/// @brief �q�[�v�����ꂽ�z��������ɕ��בւ���
		/// @brief ��r���̓q�[�v�������ۂɎg�p�������̂Ɠ����łȂ���΂Ȃ�Ȃ�
		void heapSortBy();

		/// @brief �q�[�v�����ꂽ�z����r����p���ĕ��בւ���
		/// @brief ��r���̓q�[�v�������ۂɎg�p�������̂Ɠ����łȂ���΂Ȃ�Ȃ�
		template<class Comparator>
		void heapSortBy(Comparator _comparator);

		/// @brief �z��������Ńq�[�v������
		void heapify();

		/// @brief �z����r����p���ăq�[�v������
		/// @param _comparator ��r��
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