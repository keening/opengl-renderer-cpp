#include "../include/camera.hpp"

Camera::Camera() : 
m_camera_pos { glm::vec3(0.0f, 0.0f, 3.0f) }, m_camera_up { glm::vec3(0.0f, 1.0f, 0.0f) },
m_yaw { -90.0f }, m_pitch { 0.0f }, m_move_speed { 2.5f }, m_mouse_sens { 0.1f } 
{
    update_camera_vectors();
}

Camera::~Camera() {}

void Camera::process_keyboard(MovementDirection dir, float delta_time)
{
    float velocity = m_move_speed * delta_time;
    
    if (dir == FORWARD)
        m_camera_pos += m_camera_front * velocity;
    if (dir == BACKWARD)
        m_camera_pos -= m_camera_front * velocity;
    if (dir == LEFT)
        m_camera_pos += glm::normalize(glm::cross(m_camera_up, m_camera_front)) * velocity;
    if (dir == RIGHT)
        m_camera_pos += glm::normalize(glm::cross(m_camera_front, m_camera_up)) * velocity;
}

void Camera::process_mouse(float x_offset, float y_offset)
{
    x_offset *= m_mouse_sens; y_offset *= m_mouse_sens;
    m_yaw += x_offset; m_pitch += y_offset;

    if (m_pitch >= 70.0f)
        m_pitch = 70.0f;
    if (m_pitch <= -60.0f)
        m_pitch = -60.0f;

    update_camera_vectors();
}

glm::mat4 Camera::get_view_matrix()
{
    return glm::lookAt(m_camera_pos, m_camera_pos + m_camera_front, m_camera_up);
}

void Camera::update_camera_vectors()
{
    glm::vec3 front = glm::vec3(
            cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch)),
            sin(glm::radians(m_pitch)),
            sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch))
    );
    m_camera_front = glm::normalize(front);
    /*m_camera_right = glm::normalize(glm::cross(m_camera_front, m_camera_up));
    m_camera_up = glm::normalize(glm::cross(m_camera_right, m_camera_front));*/
}