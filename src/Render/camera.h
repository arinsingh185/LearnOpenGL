#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

class Camera {
public:
	Camera();
	void setVelocity();

	void update();


private:
	glm::vec3 m_postion = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 m_front = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);

	const float velocity{ 0.05f };
};


#endif