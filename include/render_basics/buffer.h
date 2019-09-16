#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

typedef struct Render_BufferVertexDesc {
	uint32_t vertexCount; ///< total vertex count this buffer can have
	uint32_t vertexSize;    ///< size of each vertex
	bool frequentlyUpdated; ///< if set 3 vertexCount 'frames' space to allow efficient updates

} Render_BufferVertexDesc;

typedef struct Render_BufferIndexDesc {
	uint32_t indexCount; ///< total index count this buffer can have
	uint32_t indexSize;    ///< size of each index 2 or 4 bytes
	bool frequentlyUpdated; ///< if set 3 indexCount 'frames' space to allow efficient updates
} Render_BufferIndexDesc;

typedef struct Render_BufferUniformDesc {
	uint32_t size; ///< total size in bytes this buffer can have
	bool frequentlyUpdated; ///< if set 3 size 'frames' space to allow efficient updates
} Render_BufferUniformDesc;
