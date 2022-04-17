#include <Rendering/GameWindow.hpp>

using namespace std;

GameWindow::GameWindow(string title, int width, int height){
    m_name = title;
    m_width = width;
    m_height = height;
}

void GameWindow::ProcessInput(GLFWwindow* window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

int GameWindow::Start(){
	glfwInit();
    m_window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
	if (m_window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(m_window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}    

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    float* vertices = new float[9];
    vertices[0] = -0.5f;
    vertices[1] = -0.5f;
    vertices[2] = 0.0f;
    vertices[3] = 0.5f;
    vertices[4] = -0.5f;
    vertices[5] = 0.0f;
    vertices[6] = 0.0f;
    vertices[7] = 0.5f;
    vertices[8] = 0.0f;

	while (!glfwWindowShouldClose(m_window))
	{
		ProcessInput(m_window);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_window);
		glfwPollEvents();
	}

    return 0;
}

void GameWindow::Stop(){
    delete this;
    cout << "Deleted window." << endl;
}

GameWindow::~GameWindow(){
    glfwTerminate();
}