#pragma once
#include "LogHComponent.h"

namespace LogH
{
    class ShapeComponent : public Component
    {
    public:
		ShapeComponent();
		ShapeComponent(Enums::E_ColliderType _Type);
		~ShapeComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		virtual void OnCollisionOnEnter(ShapeComponent* Other);
		virtual void OnCollisionOnStay(ShapeComponent* Other);
		virtual void OnCollisionOnExit(ShapeComponent* Other);

		Vector2 GetRoot() { return Root; }
		void SetRoot(Vector2 _Root) { Root = _Root; }

		UINT32 GetID() { return ID; }

		Vector2 GetSize() { return Size; }
		void SetSize(Vector2 _Size) { Size = _Size; }

		Enums::E_ColliderType GetType() { return Type; }

	private:
		static UINT32 CollisionID;
		UINT32 ID;

		Vector2 Root;
		Vector2 Size;

		Enums::E_ColliderType Type;
    };
}