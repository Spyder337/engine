#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include <System/EntitySystem.hpp>

class GameWindow{
private:
    GLFWwindow* m_window;
    int m_height;
    int m_width;
    std::string m_name;

public:
    GameWindow(std::string, int, int);
    void ProcessInput(GLFWwindow*);
    int Start();
    void Stop();
    ~GameWindow();
};