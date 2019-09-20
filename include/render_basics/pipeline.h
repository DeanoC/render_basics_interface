#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

typedef enum Render_PrimitiveTopology {
	Render_PT_POINT_LIST = 0,
	Render_PT_LINE_LIST,
	Render_PT_LINE_STRIP,
	Render_PT_TRI_LIST,
	Render_PT_TRI_STRIP,
	Render_PT_PATCH_LIST,
} Render_PrimitiveTopology;

typedef struct Render_GraphicsPipelineDesc {
	// required by all rendering
	Render_ShaderHandle shader;
	Render_RootSignatureHandle rootSignature;

	// required for all rasterisation
	Render_RasteriserStateHandle rasteriserState;
	Render_BlendStateHandle blendState;
	Render_DepthStateHandle depthState;
	TinyImageFormat depthStencilFormat; // UNKNOWN to be ignored

	// required for rendering to a colour buffer
	uint32_t colourRenderTargetCount; // can be 0
	uint32_t sampleCount;
	uint32_t sampleQuality;
	TinyImageFormat const *colourFormats;

	// reqiured for any normal fixed rasterisation
	Render_PrimitiveTopology primitiveTopo;
	Render_VertexLayoutHandle vertexLayout;

} Render_GraphicsPipelineDesc;

typedef struct Render_ComputePipelineDesc {
	Render_ShaderHandle shader;
	Render_RootSignatureHandle rootSignature;

} Render_ComputePipelineDesc;
