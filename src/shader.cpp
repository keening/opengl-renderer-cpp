#include "../include/shader.hpp"

#include <iostream>
#include <sstream>
#include <string>

Shader::Shader(const char *vertex_path, const char *frag_path) {
    std::ifstream vertex_file, frag_file;
    std::string vertex_code, frag_code;
    std::stringstream vertex_string, frag_string;

    vertex_file.open(vertex_path);
    vertex_string << vertex_file.rdbuf();
    vertex_file.close();
    vertex_code = vertex_string.str();
    
    const char *vertex_shader_src = vertex_code.c_str();
    uint32_t vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_src, NULL);
    glCompileShader(vertex_shader);

    frag_file.open(frag_path);
    frag_string << frag_file.rdbuf();
    frag_file.close();
    frag_code = frag_string.str();

    const char *frag_shader_src = frag_code.c_str();
    uint32_t frag_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_shader, 1, &frag_shader_src, NULL);
    glCompileShader(frag_shader);

    frag_file.close();

    m_program = glCreateProgram();

    glAttachShader(m_program, vertex_shader);
    glAttachShader(m_program, frag_shader);
    glLinkProgram(m_program);

    glDeleteShader(vertex_shader);
    glDeleteShader(frag_shader);
}

Shader::~Shader() {
}

void Shader::use() {
    glUseProgram(m_program);
}

uint32_t Shader::get_id() {
    return m_program;
}

void Shader::set_mat4(const std::string &name, const glm::mat4 &mat) {
	glUniformMatrix4fv(glGetUniformLocation(m_program, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
