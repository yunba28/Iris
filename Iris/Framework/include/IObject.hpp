#pragma once

namespace Iris
{
	class IObject
	{
	public:

		IObject() = default;

		virtual ~IObject() = default;

		IObject(const IObject&) = delete;

		IObject& operator=(const IObject&) = delete;

	protected:

		virtual void awake() = 0;

		virtual void dispose() = 0;

		virtual void start() = 0;

		virtual void update(float) = 0;

		virtual void _internalAwake() = 0;

		virtual void _internalDispose() = 0;

		virtual void _internalUpdate(float _delta) = 0;

	};

}