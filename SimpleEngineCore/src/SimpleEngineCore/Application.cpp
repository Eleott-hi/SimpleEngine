#include "SimpleEngineCore/Log.hpp"
#include "SimpleEngineCore/Application.hpp"
#include "SimpleEngineCore/Window.hpp"
#include <iostream>

namespace SimpleEngine {

    Application::Application() {
        LOG_INFO("Starting Application");
       }
    Application::~Application() {
        LOG_INFO("Closing Application");
    }

	int Application::start(unsigned int widow_width, unsigned int window_height, const char* title) {
        m_pWindow = std::make_unique<Window>(title, widow_width, window_height);
        m_pWindow->set_event_callback(
            [](Event& event)
            {
                LOG_INFO("[EVENT] Changed size to {0}x{1}", event.width, event.height);
            });

        while (true)
        {
            m_pWindow->on_update();
            on_update();

        }

        return 0;
	}

}