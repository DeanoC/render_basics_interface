#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

AL2O3_EXTERN_C void Render_CmdBindRenderTargets(Render_CmdHandle cmd,
																								uint32_t count,
																								Render_RenderTargetHandle *targets,
																								bool clear,
																								bool setViewports,
																								bool setScissors);
