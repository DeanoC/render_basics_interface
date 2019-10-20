#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

typedef enum Render_TextureUsageFlags {
	Render_TUF_SHADER_READ = 0x1, // shader can sample (normal read only texture)
	Render_TUF_SHADER_WRITE = 0x2, // AKA UAV

	Render_TUF_ROP_READ = 0x4, // AKA can blend with if render target
	Render_TUF_ROP_WRITE = 0x8, // AKA render target

	Render_TUF_UPDATEABLE = 0x16,  // can be update by not every frame
	Render_TUF_UPDATEABLE_FREQUENTLY = 0x32, // is update very often (every frame)
} Render_TextureUsageFlags;

typedef struct Render_ClearValue {
	union {
		float r;
		float depth;
	};
	union {
		float g;
		uint32_t stencil;
	};
	float b;
	float a;
} Render_ClearValue;

typedef struct Render_TextureCreateDesc {
	TinyImageFormat format;
	Render_TextureUsageFlags usageflags;
	uint32_t width;
	uint32_t height;
	uint32_t depth;
	uint32_t slices;
	uint32_t mipLevels;
	uint32_t sampleCount; // 0 same as 1 (no extra samples)
	uint32_t sampleQuality;
	void const *initialData;
	char const *debugName;
	Render_ClearValue renderTargetClearValue;
} Render_TextureCreateDesc;

typedef struct Render_TextureUpdateDesc {
	TinyImageFormat format; // TODO this shouldn't be needed retrieve from the texture
	uint32_t width;
	uint32_t height;
	uint32_t depth;
	uint32_t slices;
	uint32_t mipLevels;
	void const *data;
} Render_TextureUpdateDesc;

AL2O3_EXTERN_C void Render_TextureSyncUpdate(Render_TextureHandle handle, Render_TextureUpdateDesc const *desc);

AL2O3_EXTERN_C uint32_t Render_TextureGetWidth(Render_TextureHandle handle);
AL2O3_EXTERN_C uint32_t Render_TextureGetHeight(Render_TextureHandle handle);
AL2O3_EXTERN_C uint32_t Render_TextureGetDepth(Render_TextureHandle handle);
AL2O3_EXTERN_C uint32_t Render_TextureGetSliceCount(Render_TextureHandle handle);
AL2O3_EXTERN_C uint32_t Render_TextureGetMipLevelCount(Render_TextureHandle handle);
AL2O3_EXTERN_C TinyImageFormat Render_TextureGetFormat(Render_TextureHandle handle);
