#pragma once

//#include <GLEW/include/GL/glew.h>
#include <GL/glew.h>

#include "Debug.h"
#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

/*
#define ASSERT(x) if(!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__ ))

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
*/

class Renderer {
public:
	void clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const;
};