#include "LogHComponent.h"
#include "LogHGameObject.h"

namespace LogH
{
    Component::Component()
        : Owner(nullptr)
    {

    }

    Component::~Component()
    {

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