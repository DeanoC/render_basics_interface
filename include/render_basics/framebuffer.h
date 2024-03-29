#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"
#include "al2o3_cmath/vector.h"
struct Render_View;

typedef struct Render_FrameBufferDesc {
	void *platformHandle;                ///< platform specific for the window/display (HWND etc.)
	Render_QueueHandle queue;            ///< queue present will be from
	uint32_t frameBufferWidth;          ///< size of the framebuffer horizontally in pixels
	uint32_t frameBufferHeight;          ///< size of the framebuffer vertically in pixels
	TinyImageFormat colourFormat;        ///< swap chain format, UNDEFINED == platform recommended

	bool embeddedImgui; ///< Do you want an imgui binding created and handled ?
	bool visualDebugTarget; ///< do you want visual debug calls to appear here?

} Render_FrameBufferDesc;

// if has an embeddedImgui this should be done before Imgui::NewFrame
AL2O3_EXTERN_C void Render_FrameBufferUpdate(Render_FrameBufferHandle frameBuffer,
																						 uint32_t width,
																						 uint32_t height,
																						 double deltaMS);

// must be called at the begining of a frame
AL2O3_EXTERN_C void Render_FrameBufferNewFrame(Render_FrameBufferHandle frameBuffer);

// these need to be called after new frame is started as the targets will change!
AL2O3_EXTERN_C Render_TextureHandle Render_FrameBufferColourTarget(Render_FrameBufferHandle frameBuffer);
AL2O3_EXTERN_C void Render_SetFrameBufferDebugView(Render_FrameBufferHandle frameBuffer, Render_View const *view);

AL2O3_EXTERN_C void Render_FrameBufferResize(Render_FrameBufferHandle frameBuffer, uint32_t width, uint32_t height);

AL2O3_EXTERN_C Render_GraphicsEncoderHandle Render_FrameBufferGraphicsEncoder(Render_FrameBufferHandle frameBuffer);

AL2O3_EXTERN_C void Render_FrameBufferPresent(Render_FrameBufferHandle frameBuffer);

AL2O3_EXTERN_C TinyImageFormat Render_FrameBufferColourFormat(Render_FrameBufferHandle frameBuffer);
AL2O3_EXTERN_C Math_Vec4F Render_FrameBufferEntireViewport(Render_FrameBufferHandle frameBuffer);
AL2O3_EXTERN_C Math_Vec4U32 Render_FrameBufferEntireScissor(Render_FrameBufferHandle frameBuffer);

AL2O3_EXTERN_C float const* Render_FrameBufferImguiScaleOffsetMatrix(Render_FrameBufferHandle frameBuffer);

AL2O3_EXTERN_C void Render_FrameBufferDescribeROPLayout(Render_FrameBufferHandle frameBuffer, Render_ROPLayout* out);