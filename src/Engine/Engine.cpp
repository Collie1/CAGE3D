#include "Engine.h"

CAGEEngine::CAGEEngine() {
    // Setup context
    context.inputManager = inputManager;
    context.renderer = renderer;

    
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
