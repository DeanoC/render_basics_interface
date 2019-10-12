#pragma once

#include "al2o3_platform/platform.h"
#include "al2o3_cmath/vector.h"
#include "render_basics/api.h"



AL2O3_EXTERN_C void Render_GraphicsEncoderBindRenderTargets(Render_GraphicsEncoderHandle encoder,
																														uint32_t count,
																														Render_TextureHandle *targets,
																														bool clear,
																														bool setViewports,
																														bool setScissors);

//AL2O3_EXTERN_C void Render_GraphicsEncoderClearTexture(Render_TextureHandle texture, Math_Vec3F_t clearColor);
//AL2O3_EXTERN_C void Render_GraphicsEncoderBeginRenderPass();
//AL2O3_EXTERN_C void Render_GraphicsEncoderEndRenderPass();
//AL2O3_EXTERN_C Render_GraphicsEncoderBlit(Render::TextureConstPtr const& src_, Render::TextureConstPtr const& dst_) -> void final;

AL2O3_EXTERN_C void Render_GraphicsEncoderBindVertexBuffer(Render_GraphicsEncoderHandle encoder,
																													 Render_BufferHandle vertexBuffer,
																													 uint64_t offset);
AL2O3_EXTERN_C void Render_GraphicsEncoderBindVertexBuffers(Render_GraphicsEncoderHandle encoder,
																														uint32_t vertexBufferCount,
																														Render_BufferHandle *vertexBuffers,
																														uint64_t *offsets);
AL2O3_EXTERN_C void Render_GraphicsEncoderBindIndexBuffer(Render_GraphicsEncoderHandle encoder,
																													Render_BufferHandle indexBuffer,
																													uint64_t offset);

AL2O3_EXTERN_C void Render_GraphicsEncoderSetScissor(Render_GraphicsEncoderHandle encoder, Math_Vec4U32 rect);
AL2O3_EXTERN_C void Render_GraphicsEncoderSetViewport(Render_GraphicsEncoderHandle encoder,
																											Math_Vec4F rect,
																											Math_Vec2F depth);
AL2O3_EXTERN_C void Render_GraphicsEncoderBindDescriptorSet(Render_GraphicsEncoderHandle encoder,
																														Render_DescriptorSetHandle descriptorBinder,
																														uint32_t setIndex);

AL2O3_EXTERN_C void Render_GraphicsEncoderBindPipeline(Render_GraphicsEncoderHandle encoder,
																											 Render_GraphicsPipelineHandle pipeline);

AL2O3_EXTERN_C void Render_GraphicsEncoderDraw(Render_GraphicsEncoderHandle encoder,
																							 uint32_t vertexCount,
																							 uint32_t firstVertex);
AL2O3_EXTERN_C void Render_GraphicsEncoderDrawInstanced(Render_GraphicsEncoderHandle encoder,
																												uint32_t vertexCount,
																												uint32_t firstVertex,
																												uint32_t instanceCount,
																												uint32_t firstInstance);
AL2O3_EXTERN_C void Render_GraphicsEncoderDrawIndexed(Render_GraphicsEncoderHandle encoder,
																											uint32_t indexCount,
																											uint32_t firstIndex,
																											uint32_t firstVertex);
AL2O3_EXTERN_C void Render_GraphicsEncoderDrawIndexedInstanced(Render_GraphicsEncoderHandle encoder,
																															 uint32_t indexCount,
																															 uint32_t firstIndex,
																															 uint32_t instanceCount,
																															 uint32_t firstVertex,
																															 uint32_t firstInstance);

AL2O3_EXTERN_C void Render_GraphicsEncoderTransition(Render_GraphicsEncoderHandle encoder,
																										 uint32_t numBuffers,
																										 Render_BufferHandle const *buffers,
																										 Render_BufferTransitionType const *bufferTransitions,
																										 uint32_t numTextures,
																										 Render_TextureHandle const *textures,
																										 Render_TextureTransitionType const *textureTransitions);