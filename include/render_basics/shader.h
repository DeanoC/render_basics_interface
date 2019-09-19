#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

// not all types of shader will be supported on all languages etc.
typedef enum Render_ShaderType {
	Render_ST_VERTEXSHADER,
	Render_ST_FRAGMENTSHADER,
	Render_ST_COMPUTESHADER,

	Render_ST_GEOMETRYSHADER,
	Render_ST_TESSCONTROLSHADER,
	Render_ST_TESSEVALUATIONSHADER,

	Render_ST_TASKSHADER,
	Render_ST_MESHSHADER,
} Render_ShaderType;

typedef struct Render_ShaderObjectDesc {
	Render_ShaderType shaderType;
	VFile_Handle file;
	char const *entryPoint;
} Render_ShaderObjectDesc;

typedef struct Render_ShaderDesc {
	uint32_t count;
	Render_ShaderObjectHandle *shaders;
} Render_ShaderDesc;

