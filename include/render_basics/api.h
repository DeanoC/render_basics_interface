#pragma once

typedef struct Render_Renderer* Render_RendererHandle;

typedef struct Render_Globals {
	float time;
} Render_Globals;

AL2O3_EXTERN_C Render_RendererHandle Render_RendererCreate();
AL2O3_EXTERN_C void Render_RendererDestroy(Render_RendererHandle handle);

AL2O3_EXTERN_C char const * const Render_RendererGetBackendName(Render_RendererHandle handle);
AL2O3_EXTERN_C char const * const Render_RendererGetGPUName(Render_RendererHandle handle);

