#include <Components/ShaderComponent.hpp>
#include <iostream>

using namespace std;

void checkCompileErrors(GLuint shader, std::string type)
{
    GLint success;
    GLchar infoLog[1024];
    if(type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
    else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}

ShaderComponent::ShaderComponent(string vertPath, string fragPath){
    
    auto code = ReadShaderFile(vertPath, fragPath);

    // cout << code[0] << endl;
     cout << code[1] << endl;

    const char* vShaderCode = code[0].c_str();
    const char * fShaderCode = code[1].c_str();

    // 2. compile shaders
    unsigned int vertex, fragment;
    // vertex shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkCompileErrors(vertex, "VERTEX");
    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkCompileErrors(fragment, "FRAGMENT");

    m_handle = glCreateProgram();
    glAttachShader(m_handle, vertex);
    glAttachShader(m_handle, fragment);
    glLinkProgram(m_handle);
    checkCompileErrors(m_handle, "PROGRAM");

    glUseProgram(m_handle);

    glDetachShader(m_handle, vertex);
    glDetachShader(m_handle, fragment);
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

ShaderComponent::~ShaderComponent(){
    glUseProgram(0);
    glDeleteProgram(m_handle);
}