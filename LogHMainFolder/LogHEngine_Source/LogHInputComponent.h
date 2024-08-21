#pragma once
#include "LogHComponent.h"

namespace LogH
{
	class ShapeComponent;

    class InputComponent : public Component
    {
	public:
		InputComponent();
		~InputComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		virtual void OnCollisionOnEnter(ShapeComponent* Other);
		virtual void OnCollisionOnStay(ShapeComponent* Other);
		virtual void OnCollisionOnExit(ShapeComponent* Other);

	private:
    };
}