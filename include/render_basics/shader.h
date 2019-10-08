#pragma once

#include "al2o3_platform/platform.h"
#include "al2o3_vfile/vfile.h"
#include "render_basics/api.h"

// not all types of shader will be supported on all languages etc.
typedef enum Render_ShaderType {
	Render_ST_VERTEXSHADER,
	Render_ST_FRAGMENTSHADER,
	Render_ST_COMPUTESHADER,

	Render_ST_GEOMETRYSHADER,
	Render_ST_TESSCONTROLSHADER,
	Render_ST_TESSEVALUATIONSHADER,

	//	Render_ST_TASKSHADER,
	//	Render_ST_MESHSHADER,
} Render_ShaderType;

typedef struct Render_ShaderObjectDesc {
	Render_ShaderType shaderType;
	VFile_Handle file;
	char const *entryPoint;
} Render_ShaderObjectDesc;

// helper for the standard vertex + fragment shader from VFiles
AL2O3_EXTERN_C  Render_ShaderHandle Render_CreateShaderFromVFile(Render_RendererHandle renderer,
																																 VFile_Handle vertexFile,
																																 char const * vertexEntryPoint,
																																 VFile_Handle fragmentFile,
																																 char const * fragmentEntryPoint );
