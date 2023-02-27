#pragma once

#include <stdexcept>
#include <cstdio>

namespace Iris::Error
{
	class Exception
	{
	public:

		Exception() noexcept
			: mMsg()
		{}

		Exception(const char* _msg) noexcept
		{
			MakeMessage(mMsg, "Error:", _msg);
		}

		Exception(const char* _title, const char* _msg) noexcept
		{
			MakeMessage(mMsg, _title, _msg);
		}

		virtual ~Exception()
		{
			if (mMsg.used)
			{
				delete[] mMsg.text;
			}
		}

		virtual const char* what() const
		{
			return mMsg.used ? mMsg.text : "Undefined Exception.";
		}

	private:

		struct Message
		{
			char* text = nullptr;
			bool  used = false;
		};

		static void MakeMessage(Message& msg, const char* title, const char* text)
		{
			size_t buf = (sizeof(title) + sizeof(text)) * CHAR_BIT;
			msg.text = new char[buf];
			msg.used = true;
			sprintf_s(msg.text, buf, "%s %s", title, text);
		}

	private:

		Message mMsg;

	};

	class ZeroDivisionException : public Exception
	{
	public: 
		ZeroDivisionException(const char* _msg) : Exception("ZeroDivisionException:", _msg) {}
	};

	class OutOfRange : public Exception
	{
	public:
		OutOfRange(const char* _msg) : Exception("OutOfRange:", _msg) {}
	};

	class NullReference : public Exception
	{
	public:
		NullReference(const char* _msg) : Exception("NullReference:", _msg) {}
	};
}