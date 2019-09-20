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

typedef struct Render_Renderer *Render_RendererHandle;
typedef struct Render_FrameBuffer *Render_FrameBufferHandle;

typedef struct Render_BlendState *Render_BlendStateHandle;
typedef struct Render_BlitEncoder *Render_BlitEncoderHandle;
typedef struct Render_Buffer *Render_BufferHandle;
typedef struct Render_CmdPool *Render_CmdPoolHandle;
typedef struct Render_Cmd *Render_CmdHandle;
typedef struct Render_ComputeEncoder *Render_ComputeEncoderHandle;
typedef struct Render_ComputePipeline *Render_ComputePipelineHandle;
typedef struct Render_DepthState *Render_DepthStateHandle;
typedef struct Render_DescriptorBinder *Render_DescriptorBinderHandle;
typedef struct Render_GraphicsEncoder *Render_GraphicsEncoderHandle;
typedef struct Render_GraphicsPipeline *Render_GraphicsPipelineHandle;
typedef struct Render_Queue *Render_QueueHandle;
typedef struct Render_RasteriserState *Render_RasteriserStateHandle;
typedef struct Render_RenderTarget *Render_RenderTargetHandle;
typedef struct Render_RootSignature *Render_RootSignatureHandle;
typedef struct Render_Sampler *Render_SamplerHandle;
typedef struct Render_ShaderObject *Render_ShaderObjectHandle;
typedef struct Render_Shader *Render_ShaderHandle;
typedef struct Render_Texture *Render_TextureHandle;
typedef struct Render_VertexLayout *Render_VertexLayoutHandle;

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

	Render_TTT_MAX = Render_TTT_PRESENT
} Render_TextureTransitionType;

struct Render_FrameBufferDesc; // forward decl. Definition in framebuffer.h
struct Render_BufferVertexDesc; // forward decl. Definition in buffer.h
struct Render_BufferIndexDesc; // forward decl. Definition in buffer.h
struct Render_BufferUniformDesc; // forward decl. Definition in buffer.h
struct Render_ShaderObjectDesc; // forward decl. Definition in shader.h
struct Render_RootSignatureDesc; // forward decl. Definition in rootsignature.h
struct Render_GraphicsPipelineDesc; // forward decl. Definition in pipeline.h
struct Render_ComputePipelineDesc; // forward decl. Definition in pipeline.h
struct Render_TextureCreateDesc; // forward decl. Definition in texture.h


// TODO I don't really like this API its unclear to me but for now
typedef struct Render_DescriptorBinderDesc {
	Render_RootSignatureHandle rootSignature;
	uint32_t maxDynamicUpdatesPerBatch;
	uint32_t maxDynamicUpdatesPerDraw;
} Render_DescriptorBinderDesc;

// for debugging input context is required. if null renderer input will be disabled
AL2O3_EXTERN_C Render_RendererHandle Render_RendererCreate(InputBasic_ContextHandle input);

// renderer functions
AL2O3_EXTERN_C char const *Render_RendererGetBackendName(Render_RendererHandle renderer);
AL2O3_EXTERN_C char const *Render_RendererGetGPUName(Render_RendererHandle renderer);
AL2O3_EXTERN_C Render_QueueHandle Render_RendererGetPrimaryQueue(Render_RendererHandle renderer,
																																 Render_QueueType queueType);
AL2O3_EXTERN_C Render_CmdPoolHandle Render_RendererGetPrimaryCommandPool(Render_RendererHandle renderer,
																																				 Render_QueueType queueType);

// creation functions
AL2O3_EXTERN_C Render_FrameBufferHandle Render_FrameBufferCreate(Render_RendererHandle renderer,
																																 Render_FrameBufferDesc const *desc);

AL2O3_EXTERN_C Render_BufferHandle Render_BufferCreateVertex(Render_RendererHandle renderer,
																														 Render_BufferVertexDesc const *desc);
AL2O3_EXTERN_C Render_BufferHandle Render_BufferCreateIndex(Render_RendererHandle renderer,
																														Render_BufferIndexDesc const *desc);
AL2O3_EXTERN_C Render_BufferHandle Render_BufferCreateUniform(Render_RendererHandle renderer,
																															Render_BufferUniformDesc const *desc);

AL2O3_EXTERN_C Render_GraphicsEncoderHandle Render_GraphicsEncoderCreate(Render_RendererHandle renderer,
																																				 Render_CmdPoolHandle cmdPoolHandle);
AL2O3_EXTERN_C Render_ComputeEncoderHandle Render_ComputeEncoderCreate(Render_RendererHandle renderer,
																																			 Render_CmdPoolHandle cmdPoolHandle);
AL2O3_EXTERN_C Render_BlitEncoderHandle Render_BlitEncoderCreate(Render_RendererHandle renderer,
																																 Render_CmdPoolHandle cmdPoolHandle);
AL2O3_EXTERN_C Render_ShaderObjectHandle Render_ShaderObjectCreate(Render_RendererHandle renderer,
																																	 Render_ShaderObjectDesc const *desc);
AL2O3_EXTERN_C Render_ShaderHandle Render_ShaderCreate(Render_RendererHandle renderer,
																											 uint32_t count,
																											 Render_ShaderObjectHandle *shaderObjects);
AL2O3_EXTERN_C Render_RootSignatureHandle Render_RootSignatureCreate(Render_RendererHandle renderer,
																																		 Render_RootSignatureDesc const *desc);
AL2O3_EXTERN_C Render_GraphicsPipelineHandle Render_GraphicsPipelineCreate(Render_RendererHandle renderer,
																																					 Render_GraphicsPipelineDesc const *desc);
AL2O3_EXTERN_C Render_ComputePipelineHandle Render_ComputePipelineCreate(Render_RendererHandle renderer,
																																				 Render_ComputePipelineDesc const *desc);

AL2O3_EXTERN_C Render_TextureHandle Render_TextureSyncCreate(Render_RendererHandle renderer,
																														 Render_TextureCreateDesc const *desc);

AL2O3_EXTERN_C Render_DescriptorBinderHandle Render_DescriptorBinderCreate(Render_RendererHandle renderer,
																																					 uint32_t descCount,
																																					 Render_DescriptorBinderDesc const *descs);


// destruction functions
AL2O3_EXTERN_C void Render_RendererDestroy(Render_RendererHandle renderer);
AL2O3_EXTERN_C void Render_FrameBufferDestroy(Render_RendererHandle renderer, Render_FrameBufferHandle framebuffer);
AL2O3_EXTERN_C void Render_BufferDestroy(Render_RendererHandle renderer, Render_BufferHandle buffer);
AL2O3_EXTERN_C void Render_GraphicsEncoderDestroy(Render_RendererHandle renderer, Render_GraphicsEncoderHandle buffer);
AL2O3_EXTERN_C void Render_ComputeEncoderDestroy(Render_RendererHandle renderer, Render_ComputeEncoderHandle buffer);
AL2O3_EXTERN_C void Render_BlitEncoderDestroy(Render_RendererHandle renderer, Render_BlitEncoderHandle buffer);
AL2O3_EXTERN_C void Render_ShaderObjectDestroy(Render_RendererHandle renderer, Render_ShaderObjectHandle shaderObject);
AL2O3_EXTERN_C void Render_ShaderDestroy(Render_RendererHandle renderer, Render_ShaderHandle shader);
AL2O3_EXTERN_C void Render_RootSignatureDestroy(Render_RendererHandle renderer,
																								Render_RootSignatureHandle rootSignature);
AL2O3_EXTERN_C void Render_GraphicsPipelineDestroy(Render_RendererHandle renderer,
																									 Render_GraphicsPipelineHandle pipeline);
AL2O3_EXTERN_C void Render_ComputePipelineDestroy(Render_RendererHandle renderer,
																									Render_ComputePipelineHandle pipeline);
AL2O3_EXTERN_C void Render_TextureDestroy(Render_RendererHandle renderer, Render_TextureHandle texture);
AL2O3_EXTERN_C void Render_DescriptorBinderDestroy(Render_RendererHandle renderer,
																									 Render_DescriptorBinderHandle descBinder);

// stock interface

typedef enum Render_StockBlendStateType {
	Render_SBS_OPAQUE, // opaque destination is replaced, single render targets
	Render_SBS_PORTER_DUFF, // classic alpha blend, single render target
	Render_SBS_ADDITIVE, // src + dest all channels, single render target
	Render_SBS_PM_PORTER_DUFF, // pre multiple porter duff. useful for particles

	Render_SBS_COUNT
} Render_StockBlendStateType;

typedef enum Render_StockDepthStateType {
	Render_SDS_IGNORE, // complete ignore (no read or write) any depth buffer
	Render_SDS_READONLY_LESS, // test the depth buffer, less comparision
	Render_SDS_READWRITE_LESS, // test as read only less and also write the depth buffer
	Render_SDS_READONLY_GREATER, // test the depth buffer, greater comparision
	Render_SDS_READWRITE_GREATER, // test as read only greater and also write the depth buffer
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
