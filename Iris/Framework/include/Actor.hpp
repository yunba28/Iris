#pragma once

#include <IObject.hpp>

#include <Iris/Common/Numeric.hpp>

namespace Iris
{
	class Actor : public IObject
	{
	public:

		Actor();

		virtual ~Actor();

		void setActive(bool _active)noexcept;

		bool isActive()const noexcept;

	protected:

		virtual void awake();

		virtual void dispose();

		virtual void start();

		virtual void update(float);

		virtual void _internalAwake();

		virtual void _internalDispose();

		virtual void _internalUpdate(float _delta);

	public:

		static void Destroy(Actor& actor)noexcept;

	private:

		bool mActiveActor;

		bool mIsStarted;

		bool mPendingKill;

	protected:

		/// @brief trueの時のみ'update(float)'を呼びだす
		bool enableUpdate;

	};
}