#pragma once

#include "DampEngine/Core/Base.hpp"
#include "DampEngine/Events.hpp"

#ifndef DE_FLAG_WARN_EVENT_HANDLER_NOT_IMPLEMENTED
#define DE_FLAG_WARN_EVENT_HANDLER_NOT_IMPLEMENTED
#endif //DE_FLAG_WARN_EVENT_HANDLER_NOT_IMPLEMENTED

#ifdef DE_FLAG_WARN_EVENT_HANDLER_NOT_IMPLEMENTED
#define DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, event_type) STRINGFY(DE_ENGINE_WARN("{0} not implemented in {1}", DE_EVENT_GET_DISPATCH_FUNCTION(event_type) CAT(On, event_type)))
#else
#define DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, event_type) //This method is overridden;  
#endif //DE_FLAG_WARN_EVENT_HANDLER_NOT_IMPLEMENTED

namespace DampEngine
{
    class IEventHandler
    {
    public:
        //Key related
        virtual bool OnKeyPressed(KeyPressedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, KeyPressed); return false; }
        virtual bool OnKeyReleased(KeyReleasedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, KeyReleased); return false; }
        virtual bool OnKeyTyped(KeyTypedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, KeyTyped); return false; }

        //Mouse related
        virtual bool OnMouseEnteredWindow(MouseEnteredWindowEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, MouseEnteredWindow); return false; }
        virtual bool OnMouseLeftWindow(MouseLeftWindowEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, MouseLeftWindow); return false; }
        virtual bool OnMouseMoved(MouseMovedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, MouseMoved); return false; }

        virtual bool OnMouseButtonPressed(MouseButtonPressedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, MouseButtonPressed); return false; }
        virtual bool OnMouseButtonReleased(MouseButtonReleasedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, MouseButtonReleased); return false; }

        virtual bool OnMouseScrolled(MouseScrolledEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, MouseScrolled); return false; }

        //Window related
        virtual bool OnWindowClosed(WindowClosedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowClosed); return false; }
        virtual bool OnWindowFocused(WindowFocusedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowFocused); return false; }
        virtual bool OnWindowBlurred(WindowBlurredEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowBlurred); return false; }

        virtual bool OnWindowMinimized(WindowMinimizedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowMinimized); return false; }
        virtual bool OnWindowMaximized(WindowMaximizedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowMaximized); return false; }
        virtual bool OnWindowRestored(WindowRestoredEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowRestored); return false; }
        virtual bool OnWindowMoved(WindowMovedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowMoved); return false; }
        virtual bool OnWindowRefreshed(WindowRefreshedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowRefreshed); return false; }
        virtual bool OnWindowResized(WindowResizedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowResized); return false; }
        virtual bool OnWindowContentScaled(WindowContentScaledEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, WindowContentScaled); return false; }

        //Fullscreen
        virtual bool OnMonitorConnected(MonitorConnectedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, MonitorConnected); return false; }
        virtual bool OnMonitorDisconnected(MonitorDisconnectedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, MonitorDisconnected); return false; }

        //Joystick
        virtual bool OnJoystickConnected(JoystickConnectedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, JoystickConnected); return false; }
        virtual bool OnJoystickDisconnected(JoystickDisconnectedEvent &event) { DE_EVENT_HANDLER_NOT_IMPLEMENTED(event, JoystickDisconnected); return false; }


        void OnEvent(Event& event) {
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, KeyPressed);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, KeyReleased);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, KeyTyped);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, MouseEnteredWindow);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, MouseLeftWindow);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, MouseMoved);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, MouseButtonPressed);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, MouseButtonReleased);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, MouseScrolled);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowClosed);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowFocused);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowBlurred);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowMinimized);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowMaximized);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowRestored);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowMoved);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowRefreshed);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowResized);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, WindowContentScaled);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, MonitorConnected);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, MonitorDisconnected);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, JoystickConnected);
            DE_DISPATCH_EVENT_BIND(IEventHandler, event, JoystickDisconnected);
        }
    };

} // namespace DampEngine



