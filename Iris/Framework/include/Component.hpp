#pragma once

#include <IObject.hpp>

#include <Iris/Common/Numeric.hpp>

namespace Iris
{
	class Component : public IObject
	{
	public:

		Component();

		virtual ~Component();

		void setEnable(bool _enabled);

		bool isEnable()const noexcept;

	protected:

		virtual void awake();

		virtual void dispose();

		virtual void start();

		virtual void update(float);

		virtual void _internalAwake();

		virtual void _internalDispose();

		virtual void _internalUpdate(float _delta);

		virtual void onEnable() {}

		virtual void onDisable() {}

	public:

		static void Destroy(Component& component)noexcept;

	private:

		bool mEnableComponent;

		bool mIsStarted;

		bool mPendingKill;

	protected:

		/// @brief true‚ÌŽž‚Ì‚Ý'update(float)'‚ðŒÄ‚Ñ‚¾‚·
		bool enableUpdate;

	};
}