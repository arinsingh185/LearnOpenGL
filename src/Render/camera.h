#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include "window.h"
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include <glm/geometric.hpp>

class Camera {
public:
	Camera();
	void mouse_callback(double xpos, double ypos);
	void scroll_callback(double xOffset, double yOffset);
	void processInput(GLFWwindow* window, float deltaTime);
	glm::vec3 getPosition() const;
	glm::vec3 getFront() const;
	glm::vec3 getUp() const;
	float getFov() const;
	void updateCameraVectors();
	//void update();
private:
	glm::vec3 m_position = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);

	float m_deltaTime = 0.0f;
	float m_lastFrame = 0.0f;


	bool m_firstMouse = true;
	float m_yaw = -90.0f;
	float m_pitch = 0.0f;
	float m_lastX = 1920.0f/2.0f;
	float m_lastY = 1080.0f/2.0f;
	float m_fov = 120.0f;


	const float velocity{ 0.05f };
};


#endif