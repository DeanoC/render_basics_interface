#pragma once

#include "al2o3_cmath/vector.h"

typedef struct Render_View {
	Math_Vec3F_t position;  // world space position
	Math_Vec3F_t lookAt;    // world space position
	float barrelRoll; 	// rotation around axial look vector

	bool orthographic;
	float orthoLeft;
	float orthoRight;
	float orthoTop;
	float orthoBottom;
	float perspectiveFOV;
	float perspectiveAspectWoverH;

	float nearOffset; // near clipping plane
	float farOffset; // far culling plane

} Render_View;
