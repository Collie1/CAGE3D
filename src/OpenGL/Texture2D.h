#pragma once

class Texture2D{
public:
    void Bind(int slot = 0);
    void Unbind();
    inline int getTexture() { return m_Slot; } 
    Texture2D(const char* filePath);
    ~Texture2D();
private:
    unsigned int m_Slot;
    unsigned int m_RendererID;
};