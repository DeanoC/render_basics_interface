#pragma once

typedef struct Render_View {
	float position[3]; 	// world space position
	float lookAt[3]; 		// world space position
	float barrelRoll; 	// rotation around axial look vector

	float sensorOffset; // offset from position along look vector
	float sensorWidth; 	// world space distance
	float sensorHeight;	// world space distance

	float nearOffset; // near clipping plane
	float farOffset; // far culling plane

} Render_View;

