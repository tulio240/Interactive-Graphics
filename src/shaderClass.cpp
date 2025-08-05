#include "shaderClass.h"

// Reads a text file and outputs a string with everything in the text file
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile){
    std::string vertexCode = get_file_contents(vertexFile);
    std::string fragmetCode = get_file_contents(vertexFile);

    const char* vertexSource = vertexCode.c_str();
    const char* fragmentSource = fragmetCode.c_str();

    //Create vertex shader
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    //Attach vertex shader source to the vertex shader object
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    //Compile vertex shader into machine code
    glCompileShader(vertexShader);

    //Create fragment shader
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    //Attach fragment shader source to the fragment shader object
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    //Compile fragment shader into machine code
    glCompileShader(fragmentShader);

    //Create Shader Program Object
    ID = glCreateProgram();

    //Attach the Vertex and Fragment Shaders to the Shader Program
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    //Link all the shaders together in the shader program
    glLinkProgram(ID);

    //Delete the used shaders
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
};

void Shader::Activate(){
    glUseProgram(ID);
};

void Shader::Delete(){
    glDeleteProgram(ID);
};