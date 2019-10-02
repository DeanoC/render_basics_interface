#pragma once

#include "al2o3_cmath/vector.h"

typedef struct Render_View {
	Math_Vec3F position;  // world space position
	Math_Vec3F lookAt;    // world space position
	float barrelRoll;  // rotation around axial look vector

	float perspectiveFOV; // in radians
	float perspectiveAspectWoverH;

	float nearOffset; // near clipping plane
	float farOffset; // far culling plane

} Render_View;


typedef struct Render_GpuView {
	Math_Mat4F worldToViewMatrix;
	Math_Mat4F viewToNDCMatrix;
	Math_Mat4F worldToNDCMatrix;
} Render_GpuView;