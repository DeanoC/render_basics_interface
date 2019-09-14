#pragma once

#include "al2o3_platform/platform.h"
#include "tiny_imageformat/tinyimageformat_base.h"

typedef struct Render_Renderer * Render_RendererHandle;
typedef struct Render_FrameBuffer * Render_FrameBufferHandle;
typedef struct Render_RenderTarget * Render_RenderTargetHandle;
typedef struct Render_CmdPool * Render_CmdPoolHandle;
typedef struct Render_Cmd * Render_CmdHandle;
typedef struct Render_Queue * Render_QueueHandle;

typedef struct Render_Globals {
	float time;
} Render_Globals;

typedef enum Render_GraphicsQueueType {
	RENDER_GQT_GRAPHICS,
	RENDER_GQT_COMPUTE,
	RENDER_GQT_BLITTER
} Render_GraphicsQueueType;

typedef struct Render_FrameBufferDesc {
	void * platformHandle;						///< platform specific for the window/display (HWND etc.)
	Render_QueueHandle queue;					///< queue present will be from
	Render_CmdPoolHandle commandPool; ///< pool to use for new frame cmd
	uint32_t frameBufferWidth;				///< size of the framebuffer horizontally in pixels
	uint32_t frameBufferHeight;				///< size of the framebuffer vertically in pixels
	uint32_t frameBufferCount;				///< how many frames can be buffered
	TinyImageFormat colourFormat;			///< swap chain format, UNDEFINED == platform recommended
	TinyImageFormat depthFormat;			///< swap chain depth format, UNDEFINED == none
} Render_FrameBufferDesc;

AL2O3_EXTERN_C Render_RendererHandle Render_RendererCreate();

AL2O3_EXTERN_C char const * const Render_RendererGetBackendName(Render_RendererHandle handle);
AL2O3_EXTERN_C char const * const Render_RendererGetGPUName(Render_RendererHandle handle);
AL2O3_EXTERN_C Render_QueueHandle Render_RendererGetPrimaryQueue(Render_RendererHandle ctx, Render_GraphicsQueueType queueType);
AL2O3_EXTERN_C Render_CmdPoolHandle Render_RendererGetPrimaryCommandPool(Render_RendererHandle handle, Render_GraphicsQueueType queueType);

AL2O3_EXTERN_C void Render_RendererDestroy(Render_RendererHandle handle);
AL2O3_EXTERN_C Render_FrameBufferHandle Render_FrameBufferCreate(Render_RendererHandle handle,Render_FrameBufferDesc const* desc);
AL2O3_EXTERN_C void Render_FrameBufferDestroy(Render_FrameBufferHandle handle);


AL2O3_EXTERN_C void Render_CmdBindRenderTargets(Render_CmdHandle cmd, uint32_t count, Render_RenderTargetHandle* targets, bool clear, bool setViewports, bool setScissors);