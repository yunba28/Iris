#include <Actor.hpp>

namespace Iris
{
	Actor::Actor()
		: mActiveActor(true)
		, mIsStarted(false)
		, mPendingKill(false)
		, enableUpdate(true)
	{
	}

	Actor::~Actor()
	{
	}

	void Actor::setActive(bool _active) noexcept
	{
		if (mActiveActor == _active)
			return;

		if (mPendingKill)
			return;

		mActiveActor = _active;
	}

	bool Actor::isActive() const noexcept
	{
		return mActiveActor;
	}

	void Actor::awake()
	{
	}

	void Actor::dispose()
	{
	}

	void Actor::start()
	{
	}

	void Actor::update(float)
	{
	}

	void Actor::_internalAwake()
	{
		awake();
	}

	void Actor::_internalDispose()
	{
		dispose();
	}

	void Actor::_internalUpdate(float _delta)
	{
		if (enableUpdate)
		{
			if (!mIsStarted)
			{
				start();
				mIsStarted = true;
			}

			update(_delta);
		}
	}

	void Actor::Destroy(Actor& actor) noexcept
	{
		actor._internalDispose();
		actor.mActiveActor = false;
		actor.mPendingKill = true;
	}
}