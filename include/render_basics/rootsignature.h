#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

typedef struct Render_RootSignatureDesc {
	uint32_t shaderCount;
	Render_ShaderHandle *shaders;
	uint32_t staticSamplerCount;
	const char **staticSamplerNames;
	Render_SamplerHandle *staticSamplers;
} Render_RootSignatureDesc;