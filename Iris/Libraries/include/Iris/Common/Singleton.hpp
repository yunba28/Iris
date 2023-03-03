#pragma once

namespace Iris
{
	template<class T>
	class Singleton
	{
	protected:

		Singleton() = default;

		Singleton(const Singleton&) = delete;
		
		Singleton& operator=(const Singleton&) = delete;

	public:

		using Managements = T;

		~Singleton() = default;

		static bool Create() noexcept
		{
			if (sInstance == nullptr)
			{
				sInstance = new T();
				return true;
			}
			return false;
		}

		static bool Destroy() noexcept
		{
			if (sInstance != nullptr)
			{
				delete sInstance;
				return true;
			}
			return false;
		}

		static T& Instance() noexcept
		{
			if (sInstance == nullptr)
				Create();
			return *sInstance;
		}

	private:

		static T* sInstance;

	};

	template<class T>
	inline T* Singleton<T>::sInstance = nullptr;

#define CLASS_IRIS_ENGINE(name) class Iris_##name final : public Iris::Singleton<Iris_##name>

#define IRIS_ENGINE(name) Iris::Iris_##name::Instance()
}