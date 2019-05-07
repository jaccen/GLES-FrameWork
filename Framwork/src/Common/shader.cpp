#include "shader.h"

Shader::Shader(const std::string& filename)
{
    if (filename.empty())
    {
        m_program = create_default();
        return;
    }
	m_program = glCreateProgram();
	m_shaders[0] = createShader(loadShader(filename + "_VS.glsl"), GL_VERTEX_SHADER);
	m_shaders[1] = createShader(loadShader(filename + "_FS.glsl"), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; ++i)
		glAttachShader(m_program, m_shaders[i]);

	glLinkProgram(m_program);
	checkShaderError(m_program, GL_LINK_STATUS, true, "Shader Error: program linking failed.");

	glValidateProgram(m_program);
	checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Shader Error: the program is invalid.");
}

GLuint Shader::createShader(const std::string& text, GLenum type)
{
	GLuint shader = glCreateShader(type);

	if (shader == 0)
		std::cerr << "Shader Error: shader creation failed." << std::endl;

	const GLchar* sourceStrings[1];
	GLint sourceStringLengths[1];
	sourceStrings[0] = text.c_str();
	sourceStringLengths[0] = text.length();

	glShaderSource(shader, 1, sourceStrings, sourceStringLengths);
	glCompileShader(shader);

	checkShaderError(shader, GL_COMPILE_STATUS, false, "Shader Error: shader compilation failed.");

	return shader;
}

void Shader::addUniform(const std::string& name)
{
	m_uniforms[name] = glGetUniformLocation(m_program, name.c_str());
}

void Shader::setUniformMat4fv(const std::string& name, const glm::mat4& mat)
{
	glUniformMatrix4fv(m_uniforms[name], 1, GL_FALSE, &mat[0][0]);
}

void Shader::setUniform4fv(const std::string& name, const glm::vec4& vec)
{
	glUniform4fv(m_uniforms[name], 1, &vec[0]);
}

void Shader::setUniform3fv(const std::string& name, const glm::vec3& vec)
{
	glUniform3fv(m_uniforms[name], 1, &vec[0]);
}

void Shader::setUniform2fv(const std::string& name, const glm::vec2& vec)
{
	glUniform2fv(m_uniforms[name], 1, &vec[0]);
}

void Shader::setUniform1f(const std::string& name, float& value)
{
	glUniform1f(m_uniforms[name], value);
}

void Shader::setUniform1i(const std::string& name, int value)
{
	glUniform1i(m_uniforms[name], value);
}

GLuint Shader::loadShader(GLenum type, const char *shaderSrc)
{
    GLuint shader;
    GLint compiled;
    // 创建shader
    shader = glCreateShader(type);
    if (shader == 0)
    {
        return 0;
    }
    // 加载着色器的源码
    glShaderSource(shader, 1, &shaderSrc, NULL);
    
    // 编译源码
    glCompileShader(shader);
    
    // 检查编译状态
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    
    if (!compiled)
    {
        GLint infoLen = 0;
        // 查询日志的长度判断是否有日志产生
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);
        
        if (infoLen > 1)
        {
            // 分配一个足以存储日志信息的字符串
            char *infoLog = (char *)malloc(sizeof(char) * infoLen);
            // 检索日志信息
            glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
            //  ALOGE("Error compiling shader:\n%s\n", infoLog);
            // 使用完成后需要释放字符串分配的内存
            free(infoLog);
        }
        // 删除编译出错的着色器释放内存
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

/**
 * 查询活动的统一变量uniform
 * @param program
 */
void Shader::checkActiveUniform(const GLuint program)
{
    GLint maxLen;
    GLint numUniforms;
    char *uniformName;
    
    glGetProgramiv(program, GL_ACTIVE_UNIFORMS, &numUniforms);
    glGetProgramiv(program, GL_ACTIVE_ATTRIBUTE_MAX_LENGTH, &maxLen);
    
    uniformName = (char *)malloc(sizeof(char) * maxLen);
    
    for (int i = 0; i < numUniforms; ++i)
    {
        GLint size;
        GLenum type;
        GLint location;
        
        glGetActiveUniform(program, i, maxLen, NULL, &size, &type, uniformName);
        
        location = glGetUniformLocation(program, uniformName);
        
        // ALOGD("location:", location);
        
        switch (type)
        {
            case GL_FLOAT:
                // ALOGD("type : GL_FLOAT");
                break;
            case GL_FLOAT_VEC2:
                // ALOGD("type : GL_FLOAT_VEC2");
                break;
            case GL_FLOAT_VEC3:
                // ALOGD("type : GL_FLOAT_VEC3");
                break;
            case GL_FLOAT_VEC4:
                // ALOGD("type : GL_FLOAT_VEC4");
                break;
            case GL_INT:
                // ALOGD("type : GL_INT");
                break;
        }
    }
}
GLuint Shader::create_default()
{
        char vertexShader[] =
        "attribute vec3 vPosition;\n"
        "attribute vec2 aTexCoord;\n"   //顶点纹理位置
        "varying vec2 vTextureCoord;\n" //用于传递给片元着色器的易变变量
        "uniform mat4 View;\n"
        "uniform mat4 Proj;\n"
        "uniform mat4 World;\n"
        "void main() {\n"
        "  gl_Position = Proj * View * World * vec4(vPosition, 1.0);\n"
        "vTextureCoord = aTexCoord;\n"
        "}\n";
        
        char fragmentShader[] =
        "precision mediump float;\n"
        "varying vec2 vTextureCoord;\n"
        "uniform sampler2D sTexture;\n"
        "void main() {\n"
        " gl_FragColor= texture2D(sTexture,vTextureCoord);\n"
        //"  gl_FragColor = vec4(1.0, 0.0, 0.0, 0.0);\n"
        // "gl_FragColor = vec4(1.0, 0.0, 0.0, 0.2);\n"
        "}\n";
        
        return create_program(vertexShader, fragmentShader);
}
    GLuint Shader::create_program(const char *vertexShader,
                                  const char *fragShader)
    {
        GLuint vertex;
        GLuint fragment;
        GLuint program;
        GLint linked;
        
        //加载顶点shader
        vertex = loadShader(GL_VERTEX_SHADER, vertexShader);
        if (vertex == 0)
        {
            return 0;
        }
        // 加载片元着色器
        fragment = loadShader(GL_FRAGMENT_SHADER, fragShader);
        if (fragment == 0)
        {
            glDeleteShader(vertex);
            return 0;
        }
        // 创建program
        program = glCreateProgram();
        if (program == 0)
        {
            glDeleteShader(vertex);
            glDeleteShader(fragment);
            return 0;
        }
        // 绑定shader
        glAttachShader(program, vertex);
        glAttachShader(program, fragment);
        
        // 链接program程序
        glLinkProgram(program);
        // 检查链接状态
        glGetProgramiv(program, GL_LINK_STATUS, &linked);
        if (!linked)
        {
            GLint infoLen = 0;
            // 检查日志信息长度
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLen);
            if (infoLen > 1)
            {
                // 分配一个足以存储日志信息的字符串
                char *infoLog = (char *)malloc(sizeof(char) * infoLen);
                // 检索日志信息
                glGetProgramInfoLog(program, infoLen, NULL, infoLog);
                // ALOGE("Error linking program:\n%s\n", infoLog);
                // 使用完成后需要释放字符串分配的内存
                free(infoLog);
            }
            // 删除着色器释放内存
            glDeleteShader(vertex);
            glDeleteShader(fragment);
            glDeleteProgram(program);
            return 0;
        }
        // 删除着色器释放内存
        glDeleteShader(vertex);
        glDeleteShader(fragment);
        m_program = program;
        return program;
    }

void Shader::bind()
{
	glUseProgram(m_program);
}	
void Shader::unbind()
{
	glUseProgram(0);
}

void Shader::bindAttribute(GLuint location, const std::string& name)
{
	glBindAttribLocation(m_program, location, name.c_str());
}

std::string Shader::loadShader(const std::string& filename)
{
	std::ifstream file;
	file.open(filename.c_str());

	std::string output;
	std::string line;

	if (file.is_open()) {
		while (file.good()) {
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else {
		std::cerr << "Unable to load shader: " << filename << std::endl;
	}

	return output;
}

void Shader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& message)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };

	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);

	if (success == GL_FALSE) {
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);

		std::cerr << message << ": '" << error << "'" << std::endl;
	}
}

Shader::~Shader()
{
	for (unsigned int i = 0; i < NUM_SHADERS; ++i) {
		glDetachShader(m_program, m_shaders[i]);
		glDeleteShader(m_shaders[i]);
	}

	glDeleteProgram(m_program);
}
