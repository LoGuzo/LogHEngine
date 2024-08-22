#include "LogHRigidbodyComponent.h"
#include "LogHTime.h"
#include "LogHTransformComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
	RigidbodyComponent::RigidbodyComponent()
		:Component(Enums::E_ComponentType::Rigidbody)
		, IsGround(false)
		, Mass(1.f)
		, Friction(40.f)
		, Force(Vector2::Zero)
		, Accelation(Vector2::Zero)
		, Velocity(Vector2::Zero)
		, LimitVelocity(Vector2(200.f, 1000.f))
		, Gravity(Vector2(0.f, 800.f))
	{
	}

	RigidbodyComponent::~RigidbodyComponent()
	{
	}

	void RigidbodyComponent::Initialize()
	{
	}

	void RigidbodyComponent::Update()
	{
		Accelation = Force / Mass;

		Velocity += Accelation * Time::GetDeltaTime();

		if (IsGround)
		{
			Vector2 gravity = Gravity;
			gravity.normalize();

			float dot = Vector2::Dot(Velocity, gravity);
			Velocity -= gravity * dot;
		}
		else
		{
			Velocity += Gravity * Time::GetDeltaTime();
		}

		Vector2 gravity = Gravity;
		gravity.normalize();
		float dot = Vector2::Dot(Velocity, gravity);
		gravity = gravity * dot;

		Vector2 SideVelocity = Velocity - gravity;

		if (LimitVelocity.y < gravity.Length())
		{
			gravity.normalize();
			gravity *= LimitVelocity.y;
		}

		if (LimitVelocity.x < SideVelocity.Length())
		{
			SideVelocity.normalize();
			SideVelocity *= LimitVelocity.x;
		}

		Velocity = gravity + SideVelocity;

		if (!(Velocity == Vector2::Zero))
		{
			Vector2 friction = -Velocity;
			friction = friction.normalize() * Friction * Mass * Time::GetDeltaTime();

			if (Velocity.Length() <= friction.Length())
				Velocity = Vector2::Zero;
			else
				Velocity += friction;
		}

		TransformComponent* Tc = GetOwner()->GetComponent<TransformComponent>();
		Vector2 Pos = Tc->GetPosition();
		Pos = Pos + Velocity * Time::GetDeltaTime();
		Tc->SetPosition(Pos);

		Force.Clear();
	}

	void RigidbodyComponent::LateUpdate()
	{
	}

	void RigidbodyComponent::Render(HDC Hdc)
	{
	}
}