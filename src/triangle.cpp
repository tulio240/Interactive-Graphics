// #include <iostream>
// #include <glad/glad.h>
// #include <GLFW/glfw3.h>
// #include <math.h>

// //Function that monitores the escape key state, closing the window if it is pressed
// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// // Vertex Shader source code
// const char* vertexShaderSource = "#version 330 core\n"
// "layout (location = 0) in vec3 aPos;\n"
// "void main()\n"
// "{\n"
// "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
// "}\0";
// //Fragment Shader source code
// const char* fragmentShaderSource = "#version 330 core\n"
// "out vec4 FragColor;\n"
// "void main()\n"
// "{\n"
// "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
// "}\n\0";

// int main(){
//     glfwInit();

//     //Tell GLFW which version of OpenGl is being used
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

//     //Tell GLFW we are using core version
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

//     //Creating a window and checking if it is null
//     GLFWwindow* window = glfwCreateWindow(800, 800, "Interactive Graphics", NULL, NULL);
//     if (window == NULL){
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }

//     //Introduce the window into the current context
//     glfwMakeContextCurrent(window);

//     //Passing GLAD the function to load the address of OpenGl function pointers
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }

//     //Specify the viewport of OpenGl
//     glViewport(0, 0, 800, 800);

//     GLfloat vertices[] = {
//         -0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
// 		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
// 		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
// 		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
// 		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
// 		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
//     };

//     GLuint indices[] = {
//         0, 3, 5, //Lower left
//         3, 2, 4, //Top
//         5, 4, 1 //Lower right
//     };

//     //Create vertex shader
//     GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
//     //Attach vertex shader source to the vertex shader object
//     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//     //Compile vertex shader into machine code
//     glCompileShader(vertexShader);

//     //Create fragment shader
//     GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     //Attach fragment shader source to the fragment shader object
//     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//     //Compile fragment shader into machine code
//     glCompileShader(fragmentShader);

//     //Create Shader Program Object
//     GLuint shaderProgram = glCreateProgram();

//     //Attach the Vertex and Fragment Shaders to the Shader Program
//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     //Link all the shaders together in the shader program
//     glLinkProgram(shaderProgram);

//     //Delete the used shaders
//     glDeleteShader(fragmentShader);
//     glDeleteShader(vertexShader);

//     //Vertex Array Object and Vertex Buffer Object

//     GLuint VAO;
//     GLuint VBO;

//     //Generation of VAO and VBO with only 1 object
//     glGenVertexArrays(1, &VAO);
//     glGenBuffers(1, &VBO);

//     //Bind VAO to make it the current Vertex Array Object
//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER, VBO);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);

//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);

//     //Setting viewport color and updating the windows buffer
//     glClearColor(0.84f, 0.87f, 0.87f, 1.0f);
//     glClear(GL_COLOR_BUFFER_BIT);
//     glfwSwapBuffers(window);

//     glfwSetKeyCallback(window, key_callback);

//     //Main loop for window
//     while(!glfwWindowShouldClose(window)){

//         glClearColor(0.84f, 0.87f, 0.87f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);
//         glUseProgram(shaderProgram);
//         glBindVertexArray(VAO);
//         glDrawArrays(GL_TRIANGLES, 0, 3);
//         glfwSwapBuffers(window);

//         //Process all gl events in the program
//         glfwPollEvents();
//     }

//     glDeleteVertexArrays(1, &VBO);
//     glDeleteBuffers(1, &VAO);
//     glDeleteProgram(shaderProgram);

//     //Clearing memory and terminating process
//     glfwDestroyWindow(window);
//     glfwTerminate();
// }

// void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
//     if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, GLFW_TRUE);
// }