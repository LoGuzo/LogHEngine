#pragma once
#include "LogHInputComponent.h"

namespace LogH
{
    class TileScriptComponent : public InputComponent
    {
	public:
		TileScriptComponent();
		~TileScriptComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		virtual void OnCollisionOnEnter(ShapeComponent* Other) override;
		virtual void OnCollisionOnStay(ShapeComponent* Other) override;
		virtual void OnCollisionOnExit(ShapeComponent* Other) override;
    };
}