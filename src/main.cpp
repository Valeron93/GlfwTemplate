#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <spdlog/spdlog.h>


static void gameMain() {

	spdlog::set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");
	spdlog::info("Starting application...");

	glfwSetErrorCallback([](int errorCode, const char* description) {
		spdlog::critical("GLFW Error: Code {} Description: ", errorCode, description);
		std::exit(EXIT_FAILURE);
	});

	glfwInit();

	spdlog::info("Creating window...");

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Template", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	spdlog::info("Loading OpenGL...");

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	spdlog::info("OpenGL Version: {}", (const char *)glGetString(GL_VERSION));
	spdlog::info("OpenGL Renderer: {}", (const char*)glGetString(GL_RENDERER));

	glfwSwapInterval(1);

	while (!glfwWindowShouldClose(window)) {

		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

}


int main(int argc, char **argv) {

	(void)argc;
	(void)argv;

	gameMain();
	return 0;
}