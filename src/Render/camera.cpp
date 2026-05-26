#include "camera.h"
Camera::Camera() {
	updateCameraVectors();
}

void Camera::mouse_callback(double xpos, double ypos) {
	if (m_firstMouse) {
		m_lastX = xpos;
		m_lastY = ypos;
		m_firstMouse = false;
	}

	float xOffset = xpos - m_lastX;
	float yOffset = m_lastY - ypos;
	m_lastX = xpos;
	m_lastY = ypos;
	float sensitivity = 0.1f;
	xOffset *= sensitivity;
	yOffset *= sensitivity;

	m_yaw += xOffset;
	m_pitch += yOffset;

	if (m_pitch > 89.0) {
		m_pitch = 89.0;
	}
	if (m_pitch > -89.0) {
		m_pitch = -89.0;
	}

	updateCameraVectors();

}

void Camera::processInput(GLFWwindow* window, float deltaTime) {
	const float cameraSpeed{ 2.5f * deltaTime };
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		m_position += cameraSpeed * m_front;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
		m_position -= cameraSpeed * m_front;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
		m_position -= glm::normalize(glm::cross(m_front, m_up)) * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
		m_position += glm::normalize(glm::cross(m_front, m_up)) * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		m_position += m_up * cameraSpeed;
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		m_position -= m_up * cameraSpeed;
	}
}

void Camera::scroll_callback(double xOffset, double yOffset) {
	m_fov -= (float)yOffset;
	if (m_fov < 1.0) {
		m_fov = 1.0;
	}
	if (m_fov > 45.0) {
		m_fov = 45.0;
	}

}

glm::vec3 Camera::getPosition() const {
	return m_position;
}
glm::vec3 Camera::getFront() const {
	return m_front;
}
glm::vec3 Camera::getUp() const {
	return m_up;
}
float Camera::getFov() const {
	return m_fov;
}

void Camera::updateCameraVectors() {
	m_front.x = glm::cos(m_yaw) * glm::cos(m_pitch);
	m_front.y = glm::sin(m_pitch);
	m_front.z = glm::sin(m_yaw) * glm::cos(m_pitch);
	m_front = glm::normalize(m_front);
	//m_right = glm::normalize(glm::cross(Front, WorldUp));  
	//m_up = glm::normalize(glm::cross(Right, Front));
}