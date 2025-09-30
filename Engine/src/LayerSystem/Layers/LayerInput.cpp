#include "LayerSystem/Layers/LayerInput.h"
#include "EventSystem/Event.h"
#include "Architecture/Application.h"
#include <iostream>

namespace IonixEngine
{
    void LayerInput::OnAttach() 
    {
        m_Input = new Input();
    }

    void LayerInput::OnDetach() {}

    void LayerInput::OnUpdate() {}

    void LayerInput::OnEvent(IonixEvent& e)
    {

            // Add more cases as needed.... (Note: Most engine features don't require events, they
            //                              can just be callable functions.
        
    }
}