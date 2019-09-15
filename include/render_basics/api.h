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

typedef struct Render_Renderer * Render_RendererHandle;
typedef struct Render_FrameBuffer * Render_FrameBufferHandle;

typedef struct Render_BlendState *Render_BlendStateHandle;
typedef struct Render_CmdPool * Render_CmdPoolHandle;
typedef struct Render_Cmd * Render_CmdHandle;
typedef struct Render_DepthState *Render_DepthStateHandle;
typedef struct Render_Queue * Render_QueueHandle;
typedef struct Render_RasteriserState *Render_RasteriserStateHandle;
typedef struct Render_RenderTarget *Render_RenderTargetHandle;
typedef struct Render_Sampler *Render_SamplerHandle;
typedef struct Render_VertexLayout *Render_VertexLayoutHandle;

typedef enum Render_GraphicsQueueType {
	Render_GQT_GRAPHICS,
	Render_GQT_COMPUTE,
	Render_GQT_BLITTER
} Render_GraphicsQueueType;

struct Render_FrameBufferDesc; // forward decl. Definition in framebuffer.h

// for debugging input context is required. if null renderer input will be disabled
AL2O3_EXTERN_C Render_RendererHandle Render_RendererCreate(InputBasic_ContextHandle input);

// renderer functions
AL2O3_EXTERN_C char const *Render_RendererGetBackendName(Render_RendererHandle renderer);
AL2O3_EXTERN_C char const *Render_RendererGetGPUName(Render_RendererHandle renderer);
AL2O3_EXTERN_C Render_QueueHandle Render_RendererGetPrimaryQueue(Render_RendererHandle renderer,
																																 Render_GraphicsQueueType queueType);
AL2O3_EXTERN_C Render_CmdPoolHandle Render_RendererGetPrimaryCommandPool(Render_RendererHandle renderer,
																																				 Render_GraphicsQueueType queueType);

// creation functions
AL2O3_EXTERN_C Render_FrameBufferHandle Render_FrameBufferCreate(Render_RendererHandle renderer,
																																 Render_FrameBufferDesc const *desc);

// destruction functions
AL2O3_EXTERN_C void Render_RendererDestroy(Render_RendererHandle renderer);
AL2O3_EXTERN_C void Render_FrameBufferDestroy(Render_RendererHandle renderer, Render_FrameBufferHandle framebuffer);

// stock interface

typedef enum Render_StockBlendType {
	Render_SBT_Opaque, // opaque destination is replaced, single render targets
	Render_SBT_PorterDuff, // classic alpha blend, single render target
	Render_SBT_Additive, // src + dest all channels, single render target
	Render_SBT_PorterDuffPM, // combined blend + add. useful for particles

	Render_SSB_COUNT
} Render_StockBlendType;

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
																																 Render_StockBlendType stock);
AL2O3_EXTERN_C Render_DepthStateHandle Render_GetStockDepthState(Render_RendererHandle renderer,
																																 Render_StockDepthStateType stock);
AL2O3_EXTERN_C Render_RasteriserStateHandle Render_GetStockRasterState(Render_RendererHandle renderer,
																																			 Render_StockRasterState stock);
AL2O3_EXTERN_C Render_SamplerHandle Render_GetStockSampler(Render_RendererHandle renderer,
																													 Render_StockSamplerType stock);
AL2O3_EXTERN_C Render_VertexLayoutHandle Render_GetStockVertexLayout(Render_RendererHandle renderer,
																																		 Render_StockVertexLayouts stock);
