#include "Application.h"
#include "iostream"

namespace IonixEngine {
    Application* Application::s_Instance = nullptr;
}

namespace IonixEngine
{
    Application& Application::Get() { return *s_Instance; }

    Application::Application()
        : m_Window(new Window())
    {
        s_Instance = this;

        //Initialise layers...
        layerEditor = new LayerEditor();
        m_LayerStack.PushLayer(layerEditor);

        layerInput = new LayerInput();
        m_LayerStack.PushLayer(layerInput);

    }

    Application::~Application() 
    {
        delete m_Window;
        m_Window = nullptr;
    }

    void Application::OnEvent(IonixEvent& e)
    {
        for (auto layer : m_LayerStack.GetLayers()) {
            layer->OnEvent(e);
            if (e.Handled)
                break;
        }
    }

    void Application::Run()
    {
        int tempX = 0;
        int tempY = 0;
        m_Running = true;

        while (m_Running)
        {
            for (auto layer : m_LayerStack.GetLayers())
            {
                if(layer)
                    layer->OnUpdate();


                MouseCoords mc = layerInput->m_Input->GetMousePosition();

                if (mc.x != tempX || mc.y != tempY)
                {
                    system("cls");
                    std::cout << "Mouse X Pos: " << mc.x << std::endl;
                    tempX = mc.x;
                    std::cout << "Mouse Y Pos: " << mc.y << std::endl;
                    tempY = mc.y;
                }

                
            }

            m_Window->OnUpdate();
        }
    }
}