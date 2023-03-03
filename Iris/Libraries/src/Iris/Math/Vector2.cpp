#include <Iris/Math/Vector2.hpp>

namespace Iris
{

	Vector2 Vector2::Slerp(const Vector2& from, const Vector2& to, float32 t)
	{
		auto v1 = from.normalize();
		auto v2 = to.normalize();

		auto dotProduct = v1.dot(v2);

		if (dotProduct < 0.f)
		{
			v2 = v2.inverse();
			dotProduct = -dotProduct;
		}

		const auto DotThreshold = 0.99995f;

		if (dotProduct > DotThreshold)
		{
			return Lerp(from, to, t);
		}

		const auto theta = Math::ArcCos(dotProduct) * t;

		const auto relativeVec = (v2 - (v1 * dotProduct)).normalize();

		const auto len1 = from.length();
		const auto len2 = to.length();

		const auto newLength = len1 + (len2 - len1) * t;

		return (v1 * Math::Cos(theta) + relativeVec * Math::Sin(theta)) * newLength;
	}
}