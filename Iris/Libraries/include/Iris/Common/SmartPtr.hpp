#pragma once

#include <memory>

namespace Iris
{

	template<class T, class Deleter = std::default_delete<T>>
	class UniquePtr : protected std::unique_ptr<T, Deleter>
	{
	public:

		using Base_t = std::unique_ptr<T, Deleter>;

		using Base_t::unique_ptr;
		using Base_t::operator=;
		using Base_t::swap;
		using Base_t::reset;
		using Base_t::operator*;
		using Base_t::operator->;
		using Base_t::operator bool;

		bool empty()const noexcept;

	};

	template<class T, class Deleter>
	class UniquePtr<T[], Deleter> : protected std::unique_ptr<T[], Deleter>
	{
	public:

		using Base_t = std::unique_ptr<T[], Deleter>;

		using Base_t::unique_ptr;
		using Base_t::operator=;
		using Base_t::swap;
		using Base_t::reset;
		using Base_t::operator[];
		using Base_t::operator bool;

		bool empty()const noexcept;

	};

	template<class T, class Deleter>
	bool UniquePtr<T, Deleter>::empty()const noexcept
	{
		return not this->operator bool();
	}

	template<class T, class ...Args, std::enable_if_t<not std::is_array_v<T>, int> = 0>
	UniquePtr<T> MakeUnique(Args&& ...args)
	{
		return UniquePtr<T>{new T{ std::forward<Args>(args)... }};
	}

	template<class T, std::enable_if_t<std::is_array_v<T> and std::extent_v<T> == 0, int> = 0>
	UniquePtr<T> MakeUnique(const size_t size)
	{
		using Element = std::remove_extent_t<T>;
		return UniquePtr<T>{new Element[size]()};
	}

	template<class T, class ...Args, std::enable_if_t<std::extent_v<T> != 0, int> = 0>
	void MakeUnique(Args&&...) = delete;
}

namespace Iris
{

	template<class T>
	class SharedPtr;

	template<class T>
	class WeakPtr;

	template<class T>
	class PtrHandle;

	template<class T>
	class SharedPtr final
	{
	public:

		explicit SharedPtr()noexcept;

		explicit SharedPtr(std::nullptr_t)noexcept;

		template<class U>
		explicit SharedPtr(U* _ptr);

		template<class U>
		explicit SharedPtr(const SharedPtr<U>& _other);

		template<class U, class Deleter>
		SharedPtr(U* _ptr, Deleter _deleter);

		template<class U, class Deleter, class Allocator>
		SharedPtr(U* _ptr, Deleter _deleter, Allocator _allocator);

		template<class Deleter>
		SharedPtr(std::nullptr_t, Deleter _deleter);

		template<class Deleter, class Allocator>
		SharedPtr(std::nullptr_t, Deleter _deleter, Allocator _allocator);

		SharedPtr(const SharedPtr<T>&) = default;

		SharedPtr(SharedPtr<T>&&)noexcept = default;

		template<class U>
		SharedPtr(SharedPtr<U>&& _other);

		template<class U>
		SharedPtr(const WeakPtr<U>& _weak);

		~SharedPtr() = default;

		SharedPtr<T>& operator=(const SharedPtr<T>&) = default;

		template<class U>
		SharedPtr<T>& operator=(const SharedPtr<U>& _other);

		SharedPtr<T>& operator=(SharedPtr<T>&&) = default;

		template<class U>
		SharedPtr<T>& operator=(SharedPtr<U>&& _other);

		SharedPtr<T>& operator=(std::nullptr_t)noexcept;

		void swap(SharedPtr& _other)noexcept;

		void reset()noexcept;

		template<class U>
		void reset(U* _ptr);

		template<class U, class Deleter>
		void reset(U* _ptr, Deleter _deleter);

		template<class U, class Deleter, class Allocator>
		void reset(U* _ptr, Deleter _deleter, Allocator _allocator);

		WeakPtr<T> weak()const noexcept;

		template<class U>
		WeakPtr<U> weak()const;

		PtrHandle<T> lock()const noexcept;

		template<class U>
		PtrHandle<U> lock()const;

		T& operator*()noexcept;

		const T& operator*()const noexcept;

		T* operator->()const noexcept;

		bool empty()const noexcept;

		explicit operator bool()const noexcept;

	private:

		SharedPtr(std::shared_ptr<T>&& _shared)noexcept;

	private:

		std::shared_ptr<T> mPtr;

		template<class U>
		friend class SharedPtr;
		template<class U>
		friend class WeakPtr;

		template<class T, class ...Args>
		friend std::enable_if_t<not std::is_array_v<T>, SharedPtr<T>> MakeShared(Args&& ...args);

		template<class T, class Allocator, class ...Args>
		friend std::enable_if_t<not std::is_array_v<T>, SharedPtr<T>> AllocateShared(const Allocator& allocator, Args&& ...args);

		template<class To, class From>
		friend SharedPtr<To> Cast(const SharedPtr<From>&);

		template<class T>
		friend bool operator==(const WeakPtr<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator==(const PtrHandle<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator==(const SharedPtr<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator==(const SharedPtr<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator==(const SharedPtr<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator==(const SharedPtr<T>& a, std::nullptr_t);

		template<class T>
		friend bool operator!=(const WeakPtr<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator!=(const PtrHandle<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator!=(const SharedPtr<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator!=(const SharedPtr<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator!=(const SharedPtr<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator!=(const SharedPtr<T>& a, std::nullptr_t);
	};

	template<class T>
	class WeakPtr final
	{
	public:

		WeakPtr()noexcept;

		WeakPtr(std::nullptr_t)noexcept;

		WeakPtr(const WeakPtr<T>&)noexcept = default;

		template<class U>
		WeakPtr(const WeakPtr<U>& _other)noexcept;

		WeakPtr(WeakPtr<T>&&)noexcept = default;

		template<class U>
		WeakPtr(WeakPtr<U>&& _other)noexcept;

		template<class U>
		WeakPtr(const SharedPtr<U>& _shared);

		WeakPtr& operator=(const WeakPtr&)noexcept = default;

		template<class U>
		WeakPtr& operator=(const WeakPtr<U>& _other)noexcept;

		WeakPtr& operator=(WeakPtr&&)noexcept = default;

		template<class U>
		WeakPtr& operator=(WeakPtr<U>&& _other)noexcept;

		void reset()noexcept;

		void swap(WeakPtr<T>& _other)noexcept;

		PtrHandle<T> lock()const noexcept;

		template<class U>
		PtrHandle<U> lock()const noexcept;

		bool expired() const noexcept;

		bool empty()const noexcept;

		explicit operator bool()const noexcept;

	private:

		std::weak_ptr<T> mWeak;

		template<class U>
		friend class SharedPtr;
		template<class U>
		friend class WeakPtr;
		template<class U>
		friend class PtrHandle;

		template<class To, class From>
		friend WeakPtr<To> Cast(const WeakPtr<From>&);

		template<class T>
		friend bool operator==(const SharedPtr<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator==(const PtrHandle<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator==(const WeakPtr<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator==(const WeakPtr<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator==(const WeakPtr<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator==(const WeakPtr<T>& a, std::nullptr_t);

		template<class T>
		friend bool operator!=(const SharedPtr<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator!=(const PtrHandle<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator!=(const WeakPtr<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator!=(const WeakPtr<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator!=(const WeakPtr<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator!=(const WeakPtr<T>& a, std::nullptr_t);
	};

	template<class T>
	class PtrHandle final
	{
	public:

		PtrHandle() = delete;

		PtrHandle(const PtrHandle&) = delete;

		PtrHandle(PtrHandle&&) = default;

		PtrHandle& operator=(const PtrHandle&) = delete;

		PtrHandle& operator=(PtrHandle&&) = default;

		~PtrHandle()noexcept = default;

		T& operator*()noexcept;

		const T& operator*()const noexcept;

		T* operator->()const noexcept;

		bool empty()const noexcept;

		explicit operator bool()const noexcept;

	private:

		std::shared_ptr<T> mShared;

		template<class U>
		friend class SharedPtr;
		template<class U>
		friend class WeakPtr;
		template<class U>
		friend class PtrHandle;

		PtrHandle(const std::shared_ptr<T>& _shared)noexcept;

		template<class U>
		PtrHandle(const std::shared_ptr<U>& _shared)noexcept;

		template<class T>
		friend bool operator==(const SharedPtr<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator==(const WeakPtr<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator==(const PtrHandle<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator==(const PtrHandle<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator==(const PtrHandle<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator==(const PtrHandle<T>& a, std::nullptr_t);

		template<class T>
		friend bool operator!=(const SharedPtr<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator!=(const WeakPtr<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator!=(const PtrHandle<T>& a, const SharedPtr<T>& b);

		template<class T>
		friend bool operator!=(const PtrHandle<T>& a, const WeakPtr<T>& b);

		template<class T>
		friend bool operator!=(const PtrHandle<T>& a, const PtrHandle<T>& b);

		template<class T>
		friend bool operator!=(const PtrHandle<T>& a, std::nullptr_t);
	};

	template<class T, class ...Args>
	std::enable_if_t<not std::is_array_v<T>, SharedPtr<T>> MakeShared(Args&& ...args);

	template<class T, class Allocator, class ...Args>
	std::enable_if_t<not std::is_array_v<T>, SharedPtr<T>> AllocateShared(const Allocator& allocator, Args&& ...args);

	template<class To, class From>
	SharedPtr<To> Cast(const SharedPtr<From>& from);

	template<class To, class From>
	WeakPtr<To> Cast(const WeakPtr<From>& from);

	template<class T>
	bool operator==(const SharedPtr<T>& a, const SharedPtr<T>& b);

	template<class T>
	bool operator==(const SharedPtr<T>& a, const WeakPtr<T>& b);

	template<class T>
	bool operator==(const SharedPtr<T>& a, const PtrHandle<T>& b);

	template<class T>
	bool operator==(const WeakPtr<T>& a, const SharedPtr<T>& b);

	template<class T>
	bool operator==(const WeakPtr<T>& a, const WeakPtr<T>& b);

	template<class T>
	bool operator==(const WeakPtr<T>& a, const PtrHandle<T>& b);

	template<class T>
	bool operator==(const PtrHandle<T>& a, const SharedPtr<T>& b);

	template<class T>
	bool operator==(const PtrHandle<T>& a, const WeakPtr<T>& b);

	template<class T>
	bool operator==(const PtrHandle<T>& a, const PtrHandle<T>& b);

	template<class T>
	bool operator==(const SharedPtr<T>& a, std::nullptr_t);

	template<class T>
	bool operator==(const WeakPtr<T>& a, std::nullptr_t);

	template<class T>
	bool operator==(const PtrHandle<T>& a, std::nullptr_t);

	template<class T>
	bool operator!=(const SharedPtr<T>& a, const SharedPtr<T>& b);

	template<class T>
	bool operator!=(const SharedPtr<T>& a, const WeakPtr<T>& b);

	template<class T>
	bool operator!=(const SharedPtr<T>& a, const PtrHandle<T>& b);

	template<class T>
	bool operator!=(const WeakPtr<T>& a, const SharedPtr<T>& b);

	template<class T>
	bool operator!=(const WeakPtr<T>& a, const WeakPtr<T>& b);

	template<class T>
	bool operator!=(const WeakPtr<T>& a, const PtrHandle<T>& b);

	template<class T>
	bool operator!=(const PtrHandle<T>& a, const SharedPtr<T>& b);

	template<class T>
	bool operator!=(const PtrHandle<T>& a, const WeakPtr<T>& b);

	template<class T>
	bool operator!=(const PtrHandle<T>& a, const PtrHandle<T>& b);

	template<class T>
	bool operator!=(const SharedPtr<T>& a, std::nullptr_t);

	template<class T>
	bool operator!=(const WeakPtr<T>& a, std::nullptr_t);

	template<class T>
	bool operator!=(const PtrHandle<T>& a, std::nullptr_t);
}

namespace Iris
{

	template<class T>
	inline SharedPtr<T>::SharedPtr()noexcept
		: mPtr()
	{

	}

	template<class T>
	inline SharedPtr<T>::SharedPtr(std::nullptr_t)noexcept
		: mPtr()
	{

	}

	template<class T>
	template<class U>
	inline SharedPtr<T>::SharedPtr(U* _ptr)
		: mPtr(_ptr)
	{

	}

	template<class T>
	template<class U, class Deleter>
	inline SharedPtr<T>::SharedPtr(U* _ptr, Deleter _deleter)
		: mPtr(_ptr, _deleter)
	{

	}

	template<class T>
	template<class U, class Deleter, class Allocator>
	inline SharedPtr<T>::SharedPtr(U* _ptr, Deleter _deleter, Allocator _allocator)
		: mPtr(_ptr, _deleter, _allocator)
	{

	}

	template<class T>
	template<class Deleter>
	inline SharedPtr<T>::SharedPtr(std::nullptr_t, Deleter _deleter)
		: mPtr(std::nullptr_t, _deleter)
	{

	}

	template<class T>
	template<class Deleter, class Allocator>
	inline SharedPtr<T>::SharedPtr(std::nullptr_t, Deleter _deleter, Allocator _allocator)
		: mPtr(std::nullptr_t, _deleter, _allocator)
	{

	}

	template<class T>
	template<class U>
	inline SharedPtr<T>::SharedPtr(const SharedPtr<U>& _other)
		: mPtr(_other.mPtr)
	{

	}

	template<class T>
	template<class U>
	inline SharedPtr<T>::SharedPtr(SharedPtr<U>&& _other)
		: mPtr(std::forward<decltype(_other.mPtr)>(_other.mPtr))
	{

	}

	template<class T>
	template<class U>
	inline SharedPtr<T>::SharedPtr(const WeakPtr<U>& _weak)
		: mPtr(_weak.mWeak)
	{

	}

	template<class T>
	template<class U>
	inline SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr<U>& _other)
	{
		mPtr = _other.mPtr;
		return *this;
	}

	template<class T>
	template<class U>
	inline SharedPtr<T>& SharedPtr<T>::operator=(SharedPtr<U>&& _other)
	{
		mPtr = std::move(_other.mPtr);
		return *this;
	}

	template<class T>
	inline SharedPtr<T>& SharedPtr<T>::operator=(std::nullptr_t)noexcept
	{
		mPtr.reset();
		return *this;
	}

	template<class T>
	inline void SharedPtr<T>::swap(SharedPtr& _other)noexcept
	{
		mPtr.swap(_other.mPtr);
	}

	template<class T>
	inline void SharedPtr<T>::reset()noexcept
	{
		mPtr.rest();
	}

	template<class T>
	template<class U>
	inline void SharedPtr<T>::reset(U* _ptr)
	{
		mPtr.reset(_ptr);
	}

	template<class T>
	template<class U, class Deleter>
	inline void SharedPtr<T>::reset(U* _ptr, Deleter _deleter)
	{
		mPtr.reset(_ptr, _deleter);
	}

	template<class T>
	template<class U, class Deleter, class Allocator>
	inline void SharedPtr<T>::reset(U* _ptr, Deleter _deleter, Allocator _allocator)
	{
		mPtr.reset(_ptr, _deleter, _allocator);
	}

	template<class T>
	inline WeakPtr<T> SharedPtr<T>::weak()const noexcept
	{
		return WeakPtr<T>{*this};
	}

	template<class T>
	template<class U>
	inline WeakPtr<U> SharedPtr<T>::weak()const
	{
		return WeakPtr<U>{Cast<U>(*this)};
	}

	template<class T>
	inline PtrHandle<T> SharedPtr<T>::lock()const noexcept
	{
		return PtrHandle<T>{mPtr};
	}

	template<class T>
	template<class U>
	inline PtrHandle<U> SharedPtr<T>::lock()const
	{
		return PtrHandle<U>{Cast<U>(*this).mPtr};
	}

	template<class T>
	inline T& SharedPtr<T>::operator*()noexcept
	{
		return *mPtr;
	}

	template<class T>
	inline const T& SharedPtr<T>::operator*()const noexcept
	{
		return *mPtr;
	}

	template<class T>
	inline T* SharedPtr<T>::operator->()const noexcept
	{
		return mPtr.get();
	}

	template<class T>
	inline bool SharedPtr<T>::empty()const noexcept
	{
		return not mPtr.operator bool();
	}

	template<class T>
	inline SharedPtr<T>::operator bool()const noexcept
	{
		return mPtr.operator bool();
	}

	template<class T>
	inline SharedPtr<T>::SharedPtr(std::shared_ptr<T>&& _shared)noexcept
		: mPtr(std::forward<std::shared_ptr<T>>(_shared))
	{

	}

	template<class T>
	inline WeakPtr<T>::WeakPtr()noexcept
		: mWeak()
	{

	}

	template<class T>
	inline WeakPtr<T>::WeakPtr(std::nullptr_t)noexcept
		: mWeak()
	{

	}

	template<class T>
	template<class U>
	inline WeakPtr<T>::WeakPtr(const WeakPtr<U>& _other)noexcept
		: mWeak(_other.mWeak)
	{

	}

	template<class T>
	template<class U>
	inline WeakPtr<T>::WeakPtr(WeakPtr<U>&& _other)noexcept
		: mWeak(std::forward<decltype(_other.mWeak)>(_other.mWeak))
	{

	}

	template<class T>
	template<class U>
	inline WeakPtr<T>::WeakPtr(const SharedPtr<U>& _other)
		: mWeak(_other.mPtr)
	{

	}

	template<class T>
	template<class U>
	inline WeakPtr<T>& WeakPtr<T>::operator=(const WeakPtr<U>& _other) noexcept
	{
		mWeak = _other.mWeak;
		return *this;
	}

	template<class T>
	template<class U>
	inline WeakPtr<T>& WeakPtr<T>::operator=(WeakPtr<U>&& _other) noexcept
	{
		mWeak = std::forward<decltype(_other.mWeak)>(_other.mWeak);
		return *this;
	}

	template<class T>
	inline void WeakPtr<T>::reset()noexcept
	{
		mWeak.reset();
	}

	template<class T>
	inline void WeakPtr<T>::swap(WeakPtr<T>& _other)noexcept
	{
		mWeak.swap(_other.mWeak);
	}

	template<class T>
	inline PtrHandle<T> WeakPtr<T>::lock()const noexcept
	{
		return PtrHandle<T>{mWeak.lock()};
	}

	template<class T>
	template<class U>
	inline PtrHandle<U> WeakPtr<T>::lock()const noexcept
	{
		return PtrHandle<U>{Cast<U>(*this).mWeak.lock()};
	}

	template<class T>
	inline bool WeakPtr<T>::expired()const noexcept
	{
		return mWeak.expired();
	}

	template<class T>
	inline bool WeakPtr<T>::empty()const noexcept
	{
		return mWeak.expired();
	}

	template<class T>
	inline WeakPtr<T>::operator bool()const noexcept
	{
		return not mWeak.expired();
	}

	template<class T>
	inline T& PtrHandle<T>::operator*()noexcept
	{
		return *mShared;
	}

	template<class T>
	inline const T& PtrHandle<T>::operator*()const noexcept
	{
		return *mShared;
	}

	template<class T>
	inline T* PtrHandle<T>::operator->()const noexcept
	{
		return mShared.get();
	}

	template<class T>
	inline bool PtrHandle<T>::empty()const noexcept
	{
		return not mShared.operator bool();
	}

	template<class T>
	inline PtrHandle<T>::operator bool()const noexcept
	{
		return mShared.operator bool();
	}

	template<class T>
	inline PtrHandle<T>::PtrHandle(const std::shared_ptr<T>& _shared)noexcept
		: mShared(_shared)
	{

	}

	template<class T>
	template<class U>
	inline PtrHandle<T>::PtrHandle(const std::shared_ptr<U>& _shared)noexcept
		: mShared(_shared)
	{

	}
}

namespace Iris
{

	template<class T, class ...Args>
	std::enable_if_t<not std::is_array_v<T>, SharedPtr<T>> MakeShared(Args&& ...args)
	{
		return SharedPtr<T>{std::make_shared<T>(std::forward<Args>(args)...)};
	}

	template<class T, class Allocator, class ...Args>
	std::enable_if_t<not std::is_array_v<T>, SharedPtr<T>> AllocateShared(const Allocator& allocator, Args&& ...args)
	{
		return SharedPtr<T>{std::allocate_shared<T>(allocator, std::forward<Args>(args)...)};
	}

	template<class To, class From>
	SharedPtr<To> Cast(const SharedPtr<From>& from)
	{
		if constexpr (std::is_same_v<To, From>)
		{
			return from;
		}
		else if constexpr (std::is_base_of_v<To, From>)
		{
			return SharedPtr<To>{std::static_pointer_cast<To>(from.mPtr)};
		}
		else if constexpr (std::is_base_of_v<From, To>)
		{
			return SharedPtr<To>{std::dynamic_pointer_cast<To>(from.mPtr)};
		}
		else if constexpr (std::is_convertible_v<To*, From*>)
		{
			return SharedPtr<To>{std::reinterpret_pointer_cast<To>(from.mPtr)};
		}
		else
		{
			throw std::bad_cast{ "bad-cast" };
		}
	}

	template<class To, class From>
	WeakPtr<To> Cast(const WeakPtr<From>& from)
	{
		if constexpr (std::is_same_v<To, From>)
		{
			return from;
		}

		WeakPtr<To> to{};
		auto sp = from.mWeak.lock();

		if constexpr (std::is_base_of_v<To, From>)
		{
			to.mWeak = std::static_pointer_cast<To>(sp);
			return to;
		}
		else if constexpr (std::is_base_of_v<From, To>)
		{
			to.mWeak = std::dynamic_pointer_cast<To>(sp);
			return to;
		}
		else if constexpr (std::is_convertible_v<To*, From*>)
		{
			to.mWeak = std::reinterpret_pointer_cast<To>(sp);
			return to;
		}
		else
		{
			throw std::bad_cast{ "bad-cast" };
		}
	}
}

namespace Iris
{
	template<class T>
	bool operator==(const SharedPtr<T>& a, const SharedPtr<T>& b)
	{
		return a.mPtr == b.mPtr;
	}

	template<class T>
	bool operator==(const SharedPtr<T>& a, const WeakPtr<T>& b)
	{
		return a.mPtr == b.mWeak.lock();
	}

	template<class T>
	bool operator==(const SharedPtr<T>& a, const PtrHandle<T>& b)
	{
		return a.mPtr == b.mShared;
	}

	template<class T>
	bool operator==(const WeakPtr<T>& a, const SharedPtr<T>& b)
	{
		return a.mWeak.lock() == b.mPtr;
	}

	template<class T>
	bool operator==(const WeakPtr<T>& a, const WeakPtr<T>& b)
	{
		return a.mWeak.lock() == b.mWeak.lock();
	}

	template<class T>
	bool operator==(const WeakPtr<T>& a, const PtrHandle<T>& b)
	{
		return a.mWeak.lock() == b.mShared;
	}

	template<class T>
	bool operator==(const PtrHandle<T>& a, const SharedPtr<T>& b)
	{
		return a.mShared == b.mPtr;
	}

	template<class T>
	bool operator==(const PtrHandle<T>& a, const WeakPtr<T>& b)
	{
		return a.mShared == b.mWeak.lock();
	}

	template<class T>
	bool operator==(const PtrHandle<T>& a, const PtrHandle<T>& b)
	{
		return a.mShared == b.mShared;
	}

	template<class T>
	bool operator==(const SharedPtr<T>& a, std::nullptr_t)
	{
		return a.mPtr == nullptr;
	}

	template<class T>
	bool operator==(const WeakPtr<T>& a, std::nullptr_t)
	{
		return a.expired();
	}

	template<class T>
	bool operator==(const PtrHandle<T>& a, std::nullptr_t)
	{
		return a.mShared == nullptr;
	}

	template<class T>
	bool operator!=(const SharedPtr<T>& a, const SharedPtr<T>& b)
	{
		return a.mPtr != b.mPtr;
	}

	template<class T>
	bool operator!=(const SharedPtr<T>& a, const WeakPtr<T>& b)
	{
		return a.mPtr != b.mWeak.lock();
	}

	template<class T>
	bool operator!=(const SharedPtr<T>& a, const PtrHandle<T>& b)
	{
		return a.mPtr != b.mShared;
	}

	template<class T>
	bool operator!=(const WeakPtr<T>& a, const SharedPtr<T>& b)
	{
		return a.mWeak.lock() != b.mPtr;
	}

	template<class T>
	bool operator!=(const WeakPtr<T>& a, const WeakPtr<T>& b)
	{
		return a.mWeak.lock() != b.mWeak.lock();
	}

	template<class T>
	bool operator!=(const WeakPtr<T>& a, const PtrHandle<T>& b)
	{
		return a.mWeak.lock() != b.mShared;
	}

	template<class T>
	bool operator!=(const PtrHandle<T>& a, const SharedPtr<T>& b)
	{
		return a.mShared != b.mPtr;
	}

	template<class T>
	bool operator!=(const PtrHandle<T>& a, const WeakPtr<T>& b)
	{
		return a.mShared != b.mWeak.lock();
	}

	template<class T>
	bool operator!=(const PtrHandle<T>& a, const PtrHandle<T>& b)
	{
		return a.mShared != b.mShared;
	}

	template<class T>
	bool operator!=(const SharedPtr<T>& a, std::nullptr_t)
	{
		return a.mPtr != nullptr;
	}

	template<class T>
	bool operator!=(const WeakPtr<T>& a, std::nullptr_t)
	{
		return not a.expired();
	}

	template<class T>
	bool operator!=(const PtrHandle<T>& a, std::nullptr_t)
	{
		return a.mShared != nullptr;
	}
}