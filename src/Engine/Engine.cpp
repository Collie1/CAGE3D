#include "Engine.h"

CAGEEngine::CAGEEngine(const char* gameName, int width, int height) 
    : window(gameName, width, height), renderer(window), context(renderer,inputManager,window)
{
    // Setup context




    Initialize();

    
}

CAGEEngine::~CAGEEngine() {
    Shutdown();
}

void CAGEEngine::Initialize() {
    
}

void CAGEEngine::Shutdown() {
    
}

void CAGEEngine::Update() {
    
}

void CAGEEngine::Render() {
    
}

EngineContext& CAGEEngine::GetContext() {
    return context;
}
