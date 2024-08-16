#include "LogHComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
    Component::Component(Enums::E_ComponentType _Type)
        : Owner(nullptr)
        , Type(_Type)
    {

    }

    Component::~Component()
    {
        SAFE_DELETE(Owner);
    }

    void Component::Initialize()
    {

    }

    void Component::Update()
    {

    }

    void Component::LateUpdate()
    {

    }

    void Component::Render(HDC Hdc)
    {

    }

    void Component::SetOwner(GameObject* _Owner)
    {
        Owner = _Owner;
    }
}