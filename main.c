#include "Includes.h"

int main(void)
{
	const int screenWidth = 800;
	const int screenHeight = 450;

	InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera free");

	// Define the camera to look into our 3d world
	Camera3D camera = { 0 };
	camera.position = (Vector3){ 10.0f, 10.0f, 10.0f }; // Camera position
	camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };	// Camera looking at point
	camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };	// Camera up vector (rotation towards target)
	camera.fovy = 45.0f;	// Camera field-of-view Y
	camera.type = CAMERA_PERSPECTIVE;	 // Camera mode type

	Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

	SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode
	SetCameraMoveControls(KEY_W, KEY_S, KEY_D, KEY_A, KEY_SPACE, KEY_LEFT_SHIFT);
	SetTargetFPS(60);	 // Set our game to run at 60 frames-per-second
	//--------------------------------------------------------------------------------------

	// Main game loop
	while (!WindowShouldClose())	// Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		UpdateCamera(&camera);	// Update camera

		if (IsKeyDown('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(RAYWHITE);

		BeginMode3D(camera);

		DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
		DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

		DrawGrid(10, 1.0f);

		EndMode3D();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------
	CloseWindow();	// Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}
