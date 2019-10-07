#pragma once

typedef enum Render_DescriptorType {
	Render_DT_TEXTURE,
	Render_DT_SAMPLER,
	Render_DT_BUFFER,
	Render_DT_ROOT_CONSTANT
} Render_DescriptorType;

typedef enum Render_DescriptorUpdateFrequency {
	Render_DUF_NEVER = 0,
	Render_DUF_PER_FRAME,
	Render_DUF_PER_BATCH,
	Render_DUF_PER_DRAW,
} Render_DescriptorUpdateFrequency;

typedef struct Render_DescriptorSetDesc {
	Render_RootSignatureHandle rootSignature;
	Render_DescriptorUpdateFrequency updateFrequency;
	uint32_t maxSets;
} Render_DescriptorSetDesc;

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

AL2O3_EXTERN_C void Render_DescriptorUpdate(Render_DescriptorSetHandle set,
																						uint32_t setIndex,
																						uint32_t numDescriptors,
																						Render_DescriptorDesc *desc);

// if you have frequently updates buffers/etc. and only the data changes *NOT* the binding do this once as an optimization.
AL2O3_EXTERN_C void Render_DescriptorPresetFrequencyUpdated(Render_DescriptorSetHandle set,
																														 uint32_t setIndex,
																														 uint32_t numDescriptors,
																														 Render_DescriptorDesc *desc);