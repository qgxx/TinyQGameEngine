#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>

#include "model.h"
#include "shader.h"

enum Camera_Movement {
	FORWARD,
	BACKWARD,
	cLEFT,
	cRIGHT,
	UP,
	DOWN
};

// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SENSITIVITY = 0.1f;
const float FOV = 45.0f;

class Camera {
public:
	glm::vec3 Position;
	glm::vec3 WorldUp;

	float Yaw;
	float Pitch;

	// Local/Model Space
	glm::vec3 Front;
	glm::vec3 Up;
	glm::vec3 Right;
	// Taget = Positoin + Front

	float MovementSpeed;
	float MouseSensitivity;
	float fov;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f),
		float yaw = YAW, float pitch = PITCH);
	Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

	glm::mat4 GetViewMatrix();
	void ProcessKeyboard(Camera_Movement direction, float deltaTime);
	void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
	void ProcessMouseScroll(float yoffset);
	void increaseMovementSpeed() { MovementSpeed = SPEED * 40.0; }
	void resetMovementSpeed() { MovementSpeed = SPEED; }
	void setModel(const Model& m) { model = m; }
	void Draw(Shader &shader) { model.Draw(shader); }
	glm::vec3 getPos() { return Position; }

private:
	void updateCameraVectors();
	Model model;
};
#endif // !__CAMERA_H__