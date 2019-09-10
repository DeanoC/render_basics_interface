#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

AL2O3_EXTERN_C Render_CmdHandle Render_FrameBufferNewFrame(Render_FrameBufferHandle handle,
																												 Render_RenderTargetHandle *outRenderTarget,
																												 Render_RenderTargetHandle *outDepthTarget);
AL2O3_EXTERN_C void Render_FrameBufferPresent(Render_FrameBufferHandle handle);

AL2O3_EXTERN_C TinyImageFormat Render_FrameBufferColourFormat(Render_FrameBufferHandle handle);
AL2O3_EXTERN_C TinyImageFormat Render_FrameBufferDepthFormat(Render_FrameBufferHandle handle);
