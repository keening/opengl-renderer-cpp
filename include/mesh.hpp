#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <vector>

class Mesh {
public:
	Mesh(std::vector<float> vertices);
    ~Mesh();

    void draw();
    void setup_vbo();

private:
    uint32_t m_vbo = 0, m_vao = 0;
    std::vector<float> m_vertices = { 0 };
};

#endif
