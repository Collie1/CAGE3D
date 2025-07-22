#pragma

#include <vector>

class IndexBuffer{
public:
    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() { return m_Count; }

    IndexBuffer(const std::vector<unsigned int>& data);
    ~IndexBuffer();
private:
    unsigned int m_RendererID;
    unsigned int m_Count;
};