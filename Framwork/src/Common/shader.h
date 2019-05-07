#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "configure.h"
#include "transform.h"
#include "camera.h"
#include "light.h"

class Shader
{
public:
	Shader(const std::string& filename);
	virtual ~Shader();

    void checkActiveUniform(const GLuint program);
    GLuint loadShader(GLenum type, const char *shaderSrc);
    GLuint create_default();
    GLuint create_program(const char *vertexShader,
                        const char *fragShader);
	void bind();
	void unbind();
	void bindAttribute(GLuint location, const std::string& name);

	std::string loadShader(const std::string& filename);
	void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& message);
	GLuint createShader(const std::string& text, GLenum type);

	void addUniform(const std::string& name);

	void setUniformMat4fv(const std::string& name, const glm::mat4& mat);
	void setUniform4fv(const std::string& name, const glm::vec4& vec);
	void setUniform3fv(const std::string& name, const glm::vec3& vec);
	void setUniform2fv(const std::string& name, const glm::vec2& vec);
	void setUniform1f(const std::string& name, float& value);
	void setUniform1i(const std::string& name, int value);

	inline GLuint getProgram() { return m_program; }

private:
	static const unsigned int NUM_SHADERS = 2;

	GLuint m_program;
	GLuint m_shaders[NUM_SHADERS];

	std::map<std::string, GLuint> m_uniforms;
};

