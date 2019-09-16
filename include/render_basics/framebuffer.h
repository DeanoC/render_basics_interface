#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

typedef struct Render_FrameBufferDesc {
	void *platformHandle;                ///< platform specific for the window/display (HWND etc.)
	Render_QueueHandle queue;            ///< queue present will be from
	Render_CmdPoolHandle commandPool;  ///< pool to use for new frame cmd
	uint32_t frameBufferWidth;          ///< size of the framebuffer horizontally in pixels
	uint32_t frameBufferHeight;          ///< size of the framebuffer vertically in pixels
	uint32_t frameBufferCount;          ///< how many frames can be buffered
	TinyImageFormat colourFormat;        ///< swap chain format, UNDEFINED == platform recommended
	TinyImageFormat depthFormat;        ///< swap chain depth format, UNDEFINED == none

	bool embeddedImgui; ///< Do you want an imgui binding created and handled ?
	bool visualDebugTarget; ///< do you want visual debug calls to appear here?

} Render_FrameBufferDesc;

AL2O3_EXTERN_C Render_CmdHandle Render_FrameBufferNewFrame(Render_FrameBufferHandle frameBuffer,
																													 Render_RenderTargetHandle *outRenderTarget,
																													 Render_RenderTargetHandle *outDepthTarget);

// if has an embeddedImgui this should be done before Imgui::NewFrame
AL2O3_EXTERN_C void Render_FrameBufferUpdate(Render_FrameBufferHandle frameBuffer,
																						 uint32_t width,
																						 uint32_t height,
																						 float backingScaleX, float backingScaleY,
																						 double deltaMS);

AL2O3_EXTERN_C void Render_FrameBufferPresent(Render_FrameBufferHandle frameBuffer);

AL2O3_EXTERN_C TinyImageFormat Render_FrameBufferColourFormat(Render_FrameBufferHandle frameBuffer);
AL2O3_EXTERN_C TinyImageFormat Render_FrameBufferDepthFormat(Render_FrameBufferHandle frameBuffer);
