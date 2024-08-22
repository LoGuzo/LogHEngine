#pragma once
#include <cmath>

namespace LogH::Math
{
#define PI 3.141592f
	struct Vector2
	{
		static Vector2 Rotate(Vector2 Vector, float Degree)
		{
			float Radian = (Degree / 180.f) * PI;
			Vector.normalize();
			float X = cosf(Radian) * Vector.x - sinf(Radian) * Vector.y;
			float Y = sinf(Radian) * Vector.x - cosf(Radian) * Vector.y;

			return Vector2(X, Y);
		}

		static float Dot(Vector2& V1, Vector2& V2)
		{
			return (V1.x * V2.x) + (V1.y * V2.y);
		}

		static float Cross(Vector2& V1, Vector2& V2)
		{
			return (V1.x * V2.y) - (V1.y * V2.x);
		}

		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;

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

		Vector2 operator - ()
		{
			return Vector2(-x, -y);
		}

		Vector2 operator - (Vector2 Other)
		{
			return Vector2(x - Other.x, y - Other.y);
		}

		Vector2 operator + (Vector2 Other)
		{
			return Vector2(x + Other.x, y + Other.y);
		}

		void operator += (Vector2 Other)
		{
			x += Other.x;
			y += Other.y;
		}

		void operator -= (Vector2 Other)
		{
			x -= Other.x;
			y -= Other.y;
		}

		void operator *= (Vector2 Other)
		{
			x *= Other.x;
			y *= Other.y;
		}

		void operator *= (float value)
		{
			x *= value;
			y *= value;
		}

		Vector2 operator * (float value)
		{
			return Vector2(x * value, y * value);
		}

		Vector2 operator * (Vector2 Other)
		{
			return Vector2(x * Other.x, y * Other.y);
		}

		Vector2 operator / (float value)
		{
			return Vector2(x / value, y / value);
		}

		bool operator == (Vector2 Other)
		{
			return (x == Other.x) && (y == Other.y);
		}

		void Clear()
		{
			x = 0.f;
			y = 0.f;
		}

		float Length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2 normalize()
		{
			float Len = Length();
			x /= Len;
			y /= Len;

			return *this;
		}
	};

}