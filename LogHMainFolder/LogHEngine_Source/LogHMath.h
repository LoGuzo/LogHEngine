#pragma once

namespace LogH::Math
{
	
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;

		float x;
		float y;

		Vector2()
			: x(0.f)
			, y(0.f)
		{

		}

		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{

		}

		Vector2 operator - (Vector2 Other)
		{
			return Vector2(x - Other.x, y - Other.y);
		}

		Vector2 operator + (Vector2 Other)
		{
			return Vector2(x + Other.x, y + Other.y);
		}

		Vector2 operator * (float value)
		{
			return Vector2(x * value, y * value);
		}

		Vector2 operator / (float value)
		{
			return Vector2(x / value, y / value);
		}
	};
}