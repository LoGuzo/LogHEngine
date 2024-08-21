#pragma once
#include "LogHComponent.h"

namespace LogH
{
    class ShapeComponent : public Component
    {
    public:
		ShapeComponent();
		~ShapeComponent();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC Hdc) override;

		Vector2 GetRoot() { return Root; }
		void SetRoot(Vector2 _Root) { Root = _Root; }

	private:
		Vector2 Root;
    };
}