#pragma once

/// Render basics provides higher level render function than the direct gfx
/// libraries. Its also begins to abstract the actual gfx backend (currently
/// always TheForge). Its not designed to provide every function the gfx backend
/// does for that simply drop to its level. However it provides much of the glue
/// for most common cases.
/// Also provide 'stocks' objects for many of the common uses of samplers etc.

#include "al2o3_platform/platform.h"
#include "tiny_imageformat/tinyimageformat_base.h"
#include "input_basic/input.h"
#include "al2o3_handle/handle.h"

typedef struct Render_Renderer *Render_RendererHandle;
typedef struct Render_VertexLayout const * Render_VertexLayoutHandle;

typedef struct { Handle_Handle32 handle; } Render_FrameBufferHandle;
typedef struct { Handle_Handle32 handle; } Render_BlendStateHandle;
typedef struct { Handle_Handle32 handle; } Render_BlitEncoderHandle;
typedef struct { Handle_Handle32 handle; } Render_BufferHandle;
typedef struct { Handle_Handle32 handle; } Render_ComputeEncoderHandle;
typedef struct { Handle_Handle32 handle; } Render_DepthStateHandle;
typedef struct { Handle_Handle32 handle; } Render_DescriptorSetHandle;
typedef struct { Handle_Handle32 handle; } Render_GraphicsEncoderHandle;
typedef struct { Handle_Handle32 handle; } Render_QueueHandle;
typedef struct { Handle_Handle32 handle; } Render_RasteriserStateHandle;
typedef struct { Handle_Handle32 handle; } Render_RootSignatureHandle;
typedef struct { Handle_Handle32 handle; } Render_SamplerHandle;
typedef struct { Handle_Handle32 handle; } Render_ShaderObjectHandle;
typedef struct { Handle_Handle32 handle; } Render_ShaderHandle;
typedef struct { Handle_Handle32 handle; } Render_TextureHandle;

typedef struct { Handle_Handle32 handle; } Render_PipelineHandle;

AL2O3_EXTERN_C bool Render_FrameBufferHandleIsValid(Render_FrameBufferHandle handle);
AL2O3_EXTERN_C bool Render_BlendStateHandleIsValid(Render_BlendStateHandle handle);
AL2O3_EXTERN_C bool Render_BlitEncoderHandleIsValid(Render_BlitEncoderHandle handle);
AL2O3_EXTERN_C bool Render_BufferHandleIsValid(Render_BufferHandle handle);
AL2O3_EXTERN_C bool Render_ComputeEncoderHandleIsValid(Render_ComputeEncoderHandle handle);
AL2O3_EXTERN_C bool Render_DepthStateHandleIsValid(Render_DepthStateHandle handle);
AL2O3_EXTERN_C bool Render_DescriptorSetHandleIsValid(Render_DescriptorSetHandle handle);
AL2O3_EXTERN_C bool Render_GraphicsEncoderHandleIsValid(Render_GraphicsEncoderHandle handle);
AL2O3_EXTERN_C bool Render_QueueHandleIsValid(Render_QueueHandle handle);
AL2O3_EXTERN_C bool Render_RasteriserStateHandleIsValid(Render_RasteriserStateHandle handle);
AL2O3_EXTERN_C bool Render_RootSignatureHandleIsValid(Render_RootSignatureHandle handle);
AL2O3_EXTERN_C bool Render_SamplerHandleIsValid(Render_SamplerHandle handle);
AL2O3_EXTERN_C bool Render_ShaderObjectHandleIsValid(Render_ShaderObjectHandle handle);
AL2O3_EXTERN_C bool Render_ShaderHandleIsValid(Render_ShaderHandle handle);
AL2O3_EXTERN_C bool Render_TextureHandleIsValid(Render_TextureHandle handle);
AL2O3_EXTERN_C bool Render_PipelineHandleIsValid(Render_PipelineHandle handle);

typedef enum Render_QueueType {
	Render_QT_GRAPHICS,
	Render_QT_COMPUTE,
	Render_QT_BLITTER
} Render_QueueType;

typedef enum Render_BufferTransitionType {
	Render_BTT_UNDEFINED = 0,
	Render_BTT_VERTEX_OR_CONSTANT_BUFFER = 0x1,
	Render_BTT_INDEX_BUFFER = 0x2,
	Render_BTT_UNORDERED_ACCESS = 0x4,
	Render_BTT_INDIRECT_ARGUMENT = 0x8,
	Render_BTT_COPY_DEST = 0x10,
	Render_BTT_COPY_SOURCE = 0x20,

	Render_BTT_MAX = Render_BTT_COPY_SOURCE
} Render_BufferTransitionType;

typedef enum Render_TextureTransitionType {
	Render_TTT_UNDEFINED = 0,
	Render_TTT_RENDER_TARGET = 0x1,
	Render_TTT_UNORDERED_ACCESS = 0x2,
	Render_TTT_DEPTH_WRITE = 0x4,
	Render_TTT_DEPTH_READ = 0x8,
	Render_TTT_COPY_DEST = 0x10,
	Render_TTT_COPY_SOURCE = 0x20,
	Render_TTT_PRESENT = 0x40,
	RENDER_TTT_SHADER_ACCESS = 0x80,
	Render_TTT_MAX = RENDER_TTT_SHADER_ACCESS
} Render_TextureTransitionType;

typedef struct Render_FrameBufferDesc Render_FrameBufferDesc; // forward decl. Definition in framebuffer.h
typedef struct Render_BufferVertexDesc Render_BufferVertexDesc; // forward decl. Definition in buffer.h
typedef struct Render_BufferIndexDesc Render_BufferIndexDesc; // forward decl. Definition in buffer.h
typedef struct Render_BufferUniformDesc Render_BufferUniformDesc; // forward decl. Definition in buffer.h
typedef struct Render_ShaderObjectDesc Render_ShaderObjectDesc; // forward decl. Definition in shader.h
typedef struct Render_RootSignatureDesc Render_RootSignatureDesc; // forward decl. Definition in rootsignature.h
typedef struct Render_GraphicsPipelineDesc Render_GraphicsPipelineDesc; // forward decl. Definition in pipeline.h
typedef struct Render_ComputePipelineDesc Render_ComputePipelineDesc; // forward decl. Definition in pipeline.h
typedef struct Render_TextureCreateDesc Render_TextureCreateDesc; // forward decl. Definition in texture.h
typedef struct Render_DescriptorSetDesc Render_DescriptorSetDesc; // forward decl. Defination in descriptorset.h

// for debugging input context is required. if null renderer input will be disabled
AL2O3_EXTERN_C Render_RendererHandle Render_RendererCreate(InputBasic_ContextHandle input);

// renderer functions

// this is usually set via framebuffer NewFrame if no framebuffer handle it with fences etc.
AL2O3_EXTERN_C void Render_RendererSetFrameIndex(Render_RendererHandle renderer, uint32_t newFrameIndex);
AL2O3_EXTERN_C uint32_t Render_RendererGetFrameIndex(Render_RendererHandle renderer);

AL2O3_EXTERN_C char const *Render_RendererGetBackendName(Render_RendererHandle renderer);
AL2O3_EXTERN_C char const *Render_RendererGetGPUName(Render_RendererHandle renderer);
AL2O3_EXTERN_C Render_QueueHandle Render_RendererGetPrimaryQueue(Render_RendererHandle renderer,
																																 Render_QueueType queueType);
AL2O3_EXTERN_C bool Render_RendererCanShaderReadFrom(Render_RendererHandle renderer, TinyImageFormat format);
AL2O3_EXTERN_C bool Render_RendererCanColourWriteTo(Render_RendererHandle renderer, TinyImageFormat format);
AL2O3_EXTERN_C bool Render_RendererCanShaWriteTo(Render_RendererHandle renderer, TinyImageFormat format);

AL2O3_EXTERN_C void Render_RendererStartGpuCapture(Render_RendererHandle renderer, char const* filename);
AL2O3_EXTERN_C void Render_RendererEndGpuCapture(Render_RendererHandle renderer);

AL2O3_EXTERN_C void Render_QueueWaitIdle(Render_QueueHandle queue);


// creation functions
AL2O3_EXTERN_C Render_FrameBufferHandle Render_FrameBufferCreate(Render_RendererHandle renderer,
																																 Render_FrameBufferDesc const *desc);

AL2O3_EXTERN_C Render_BufferHandle Render_BufferCreateVertex(Render_RendererHandle renderer,
																														 Render_BufferVertexDesc const *desc);
AL2O3_EXTERN_C Render_BufferHandle Render_BufferCreateIndex(Render_RendererHandle renderer,
																														Render_BufferIndexDesc const *desc);
AL2O3_EXTERN_C Render_BufferHandle Render_BufferCreateUniform(Render_RendererHandle renderer,
																															Render_BufferUniformDesc const *desc);

AL2O3_EXTERN_C Render_GraphicsEncoderHandle Render_GraphicsEncoderCreate(Render_RendererHandle renderer);
AL2O3_EXTERN_C Render_ComputeEncoderHandle Render_ComputeEncoderCreate(Render_RendererHandle renderer);
AL2O3_EXTERN_C Render_BlitEncoderHandle Render_BlitEncoderCreate(Render_RendererHandle renderer);

AL2O3_EXTERN_C Render_ShaderObjectHandle Render_ShaderObjectCreate(Render_RendererHandle renderer,
																																	 Render_ShaderObjectDesc const *desc);
AL2O3_EXTERN_C Render_ShaderHandle Render_ShaderCreate(Render_RendererHandle renderer,
																											 uint32_t count,
																											 Render_ShaderObjectHandle *shaderObjects);
AL2O3_EXTERN_C Render_RootSignatureHandle Render_RootSignatureCreate(Render_RendererHandle renderer,
																																		 Render_RootSignatureDesc const *desc);
AL2O3_EXTERN_C Render_PipelineHandle Render_GraphicsPipelineCreate(Render_RendererHandle renderer,
																																					 Render_GraphicsPipelineDesc const *desc);
AL2O3_EXTERN_C Render_PipelineHandle Render_ComputePipelineCreate(Render_RendererHandle renderer,
																																				 Render_ComputePipelineDesc const *desc);

AL2O3_EXTERN_C Render_TextureHandle Render_TextureSyncCreate(Render_RendererHandle renderer,
																														 Render_TextureCreateDesc const *desc);

AL2O3_EXTERN_C Render_DescriptorSetHandle Render_DescriptorSetCreate(Render_RendererHandle renderer,
																																		 Render_DescriptorSetDesc const *desc);


// destruction functions
AL2O3_EXTERN_C void Render_RendererDestroy(Render_RendererHandle renderer);
AL2O3_EXTERN_C void Render_FrameBufferDestroy(Render_RendererHandle renderer, Render_FrameBufferHandle handle);
AL2O3_EXTERN_C void Render_BufferDestroy(Render_RendererHandle renderer, Render_BufferHandle handle);
AL2O3_EXTERN_C void Render_GraphicsEncoderDestroy(Render_RendererHandle renderer, Render_GraphicsEncoderHandle handle);
AL2O3_EXTERN_C void Render_ComputeEncoderDestroy(Render_RendererHandle renderer, Render_ComputeEncoderHandle handle);
AL2O3_EXTERN_C void Render_BlitEncoderDestroy(Render_RendererHandle renderer, Render_BlitEncoderHandle handle);
AL2O3_EXTERN_C void Render_ShaderObjectDestroy(Render_RendererHandle renderer, Render_ShaderObjectHandle handle);
AL2O3_EXTERN_C void Render_ShaderDestroy(Render_RendererHandle renderer, Render_ShaderHandle handle);
AL2O3_EXTERN_C void Render_RootSignatureDestroy(Render_RendererHandle renderer,
																								Render_RootSignatureHandle handle);
AL2O3_EXTERN_C void Render_PipelineDestroy(Render_RendererHandle renderer, Render_PipelineHandle handle);
AL2O3_EXTERN_C void Render_TextureDestroy(Render_RendererHandle renderer, Render_TextureHandle handle);
AL2O3_EXTERN_C void Render_DescriptorSetDestroy(Render_RendererHandle renderer, Render_DescriptorSetHandle handle);

// stock interface
typedef enum Render_StockBlendStateType {
	Render_SBS_OPAQUE, // opaque destination is replaced, single render targets
	Render_SBS_PORTER_DUFF, // classic alpha blend, single render target
	Render_SBS_ADDITIVE, // src + dest all channels, single render target
	Render_SBS_PM_PORTER_DUFF, // pre multiple porter duff. useful for particles

	Render_SBS_COUNT
} Render_StockBlendStateType;

typedef enum Render_StockDepthStateType {
	Render_SDS_IGNORE, // complete ignore (no read or write) on depth buffer
	Render_SDS_READONLY_LESS, // test the depth buffer, less comparision
	Render_SDS_READWRITE_LESS, // test as less and also write the depth buffer
	Render_SDS_READONLY_GREATER, // test the depth buffer, greater comparision
	Render_SDS_READWRITE_GREATER, // test as greater and also write the depth buffer
	Render_SDS_WRITEONLY, // write the depth buffer unconditionally
	Render_SDS_COUNT
} Render_StockDepthStateType;

typedef enum Render_StockRasterState {

	Render_SRS_NOCULL, // filled no culling
	Render_SRS_BACKCULL, // filled back face culling
	Render_SRS_FRONTCULL, // filled front face culling

	Render_SRS_COUNT
} Render_StockRasterState;

typedef enum Render_StockSamplerType {
	Render_SST_POINT,  // point for all filters. clamp to edge all axis
	Render_SST_LINEAR, // linear for all filter. clamp to edge all axis

	Render_SST_COUNT
} Render_StockSamplerType;

typedef enum Render_StockVertexLayouts {
	Render_SVL_2D_COLOUR, // 2D + packed colour
	Render_SVL_2D_FLOATCOLOUR, // 2D + float colour
	Render_SVL_2D_COLOUR_UV, // 2D + packed colour + 2D float UV
	Render_SVL_2D_FLOATCOLOUR_UV, // 2D + float colour + 2D float UV

	Render_SVL_3D_COLOUR, // 3D + packed colour
	Render_SVL_3D_FLOATCOLOUR, // 3D + float colour
	Render_SVL_3D_COLOUR_UV, // 3D + packed colour + 2D float UV
	Render_SVL_3D_FLOATCOLOUR_UV, // 3D + float colour + 2D float UV

	Render_SVL_3D_NORMAL_COLOUR, // 3D + 3D normal + packed colour

	Render_SVL_COUNT
} Render_StockVertexLayouts;

AL2O3_EXTERN_C Render_BlendStateHandle Render_GetStockBlendState(Render_RendererHandle renderer,
																																 Render_StockBlendStateType stock);
AL2O3_EXTERN_C Render_DepthStateHandle Render_GetStockDepthState(Render_RendererHandle renderer,
																																 Render_StockDepthStateType stock);
AL2O3_EXTERN_C Render_RasteriserStateHandle Render_GetStockRasterisationState(Render_RendererHandle renderer,
																																							Render_StockRasterState stock);
AL2O3_EXTERN_C Render_SamplerHandle Render_GetStockSampler(Render_RendererHandle renderer,
																													 Render_StockSamplerType stock);
AL2O3_EXTERN_C Render_VertexLayoutHandle Render_GetStockVertexLayout(Render_RendererHandle renderer,
																																		 Render_StockVertexLayouts stock);
