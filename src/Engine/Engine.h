#pragma once


#include "InputManager.h"
#include "Renderer.h"
#include "Window.h"

// This struct gives clean access to engine systems
struct EngineContext {
    Renderer& renderer;
    InputManager& inputManager;
    Window& window;
    // Add more systems as needed (AudioManager, Physics, etc.)
};

// Your main engine class
class CAGEEngine {
public:
    CAGEEngine();
    ~CAGEEngine();

    void Initialize();
    void Shutdown();
    void Update();
    void Render();

    EngineContext& GetContext();

private:
    Window window;
    Renderer renderer;
    InputManager inputManager;
    
    EngineContext context;
};
