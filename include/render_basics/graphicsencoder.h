#pragma once

#include "al2o3_platform/platform.h"
#include "render_basics/api.h"

typedef enum Render_DescriptorType {
	Render_DT_TEXTURE,
	Render_DT_SAMPLER,
	Render_DT_BUFFER,
	Render_DT_ROOT_CONSTANT
} Render_DescriptorType;

typedef struct Render_DescriptorDesc {
	char const *name;

	Render_DescriptorType type;
	uint64_t offset;
	uint64_t size; // for buffers

	union {
		Render_TextureHandle texture;
		Render_SamplerHandle sampler;
		Render_BufferHandle buffer;
		void const *rootConstant;
		//		TheForge_AcclerationStructureHandle const* pAccelerationStructures;
	};
} Render_DescriptorDesc;

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