#include <Common.hpp>

class ShaderComponent{
private:
    GLuint m_handle;

public:
    ShaderComponent(std::string vertexPath, std::string fragPath);
    void Use(){ glUseProgram(m_handle); }
    ~ShaderComponent();
};