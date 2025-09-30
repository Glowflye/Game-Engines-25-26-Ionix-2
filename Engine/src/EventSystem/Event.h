#pragma once
#include "Architecture/Macros.h"

namespace IonixEngine
{
    enum class IonixEventType
    {
        None = 0,
        WindowClosed,
        WindowMinimised
        // ...
    };

    // Event class
    class IonixEvent
    {
    public:
        IonixEventType Type = IonixEventType::None;
        bool Handled = false;

        IonixEvent(IonixEventType type) : Type(type) {}
        virtual ~IonixEvent() = default;
    };

    // Window Events
    class WindowClosedEvent : public IonixEvent
    {
    public:
        WindowClosedEvent() : IonixEvent(IonixEventType::WindowClosed) {}
    };

    class WindowMinimisedEvent : public IonixEvent
    {
    public:
        WindowMinimisedEvent() : IonixEvent(IonixEventType::WindowMinimised) {}
    };

    // .. add more as needed...
}