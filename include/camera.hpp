#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

enum MovementDirection {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Camera {
public:

    Camera();
    ~Camera();

    glm::mat4 get_view_matrix();
    void process_keyboard(MovementDirection dir, float delta_time);
    void process_mouse(float x_offset, float y_offset);
private:
    void update_camera_vectors();

    glm::vec3 m_camera_pos, m_camera_front, m_camera_up, m_camera_right, m_world_up;
    float m_yaw, m_pitch, m_move_speed, m_mouse_sens;
};