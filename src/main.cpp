#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Function that monitores the escape key state, closing the window if it is pressed
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(){
    glfwInit();

    //Tell GLFW which version of OpenGl is being used
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    //Tell GLFW we are using core version
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    //Creating a window and checking if it is null
    GLFWwindow* window = glfwCreateWindow(800, 800, "Interactive Graphics", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    //Introduce the window into the current context
    glfwMakeContextCurrent(window);

    //Passing GLAD the function to load the address of OpenGl function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //Specify the viewport of OpenGl
    glViewport(0, 0, 800, 800);

    //Setting viewport color and updating the windows buffer
    glClearColor(0.84f, 0.87f, 0.87f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);

    glfwSetKeyCallback(window, key_callback);

    //Main loop for window
    while(!glfwWindowShouldClose(window)){
        glfwPollEvents();
    }

    //Clearing memory and terminating process
    glfwDestroyWindow(window);
    glfwTerminate();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}