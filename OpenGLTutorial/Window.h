#pragma once

#include <stdio.h>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

class Window
{
public:
	Window();

	Window(GLint windowWidth, GLint windowHeight);

	int Initialize();

	GLint getBufferWidth() { return bufferWidth; };
	GLint getBufferHeight() { return bufferHeight; };

	bool getShouldClose() { return glfwWindowShouldClose(mainWindow); };
	
	// Returning the entire key array is not the best practice. We should use getter/setters. But doing
	// it for simplicity
	bool* getKeys() { return keys; };
	GLfloat getXChange();
	GLfloat getYChange();

	void swapBuffers() { glfwSwapBuffers(mainWindow); };

	~Window();

private:
	GLFWwindow* mainWindow;
	GLint width, height, bufferWidth, bufferHeight;

	// We're storing the status of all keys in an array
	bool keys[1024];

	GLfloat lastX, lastY, xChange, yChange;
	bool mouseFirstMoved;
	
	void createCallbacks();
	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	static void handleMouse(GLFWwindow* window, double xPos, double yPos);
	static void handleGlfwError(int error, const char* msg);
};

