#include <Component.hpp>

namespace Iris
{
	Component::Component()
		: mEnableComponent(true)
		, mIsStarted(false)
		, mPendingKill(false)
		, enableUpdate(true)
	{
	}

	Component::~Component()
	{
	}

	void Component::setEnable(bool _enabled)
	{
		if (mEnableComponent == _enabled)
			return;

		if (mPendingKill)
			return;

		mEnableComponent = _enabled;

		mEnableComponent ? onEnable() : onDisable();
	}

	bool Component::isEnable() const noexcept
	{
		return mEnableComponent;
	}

	void Component::awake()
	{
	}

	void Component::dispose()
	{
	}

	void Component::start()
	{
	}

	void Component::update(float)
	{
	}

	void Component::_internalAwake()
	{
		awake();
	}

	void Component::_internalDispose()
	{
		dispose();
	}

	void Component::_internalUpdate(float _delta)
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

	void Component::Destroy(Component& component) noexcept
	{
		component._internalDispose();
		component.mEnableComponent = false;
		component.mPendingKill = true;
	}
}