#pragma once

#include "al2o3_cmath/vector.h"
#include "al2o3_cmath/matrix.h"

typedef struct Render_View {
	Math_Vec3F position;  // world space position
	Math_Vec3F lookAt;    // world space position
	Math_Vec3F upVector;  // world space up vector

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

static const int UNIFORM_BUFFER_MIN_SIZE = 256; // minimum size allowed
