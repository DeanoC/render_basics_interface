#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

AL2O3_EXTERN_C void Render_GraphicsEncoderBindRenderTargets(Render_GraphicsEncoderHandle encoder,
																														uint32_t count,
																														Render_RenderTargetHandle *targets,
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

AL2O3_EXTERN_C void Render_GraphicsEncoderSetScissor(Render_GraphicsEncoderHandle encoder, Math_Vec4U32_t rect);
AL2O3_EXTERN_C void Render_GraphicsEncoderSetViewport(Render_GraphicsEncoderHandle encoder,
																											Math_Vec4F_t rect,
																											Math_Vec2F_t depth);
AL2O3_EXTERN_C void Render_GraphicsEncoderBindDescriptors(Render_GraphicsEncoderHandle encoder,
																								Render_DescriptorBinderHandle descriptorBinder,
																								Render_RootSignatureHandle rootSignature,
																								uint32_t numDescriptors,
																								Render_DescriptorDesc *desc);
