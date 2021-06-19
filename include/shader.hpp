#ifndef SHADER_H
#define SHADER_H

#include <iostream>
#include <fstream>

#include <GL/glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    Shader(const char *vertex_path, const char *frag_path);
    ~Shader();
   
    void use();
    uint32_t get_id();
	void set_mat4(const std::string &name, const glm::mat4 &mat);

private:
	uint32_t m_program = 0;
};

#endif
