#include "TrigonometryScene.h"

void TrigonometryScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
}

void TrigonometryScene::Update()
{
}

float DegToRad(float degrees)
{
	return degrees * PI / 180;
}

float RadToDeg(float radians)
{
	return radians * 180 / PI;
}

float Vector2Length(const Vector2& v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y));
}

Vector2 Vector2Normalize(const Vector2& v)
{
	float l = Vector2Length(v);
	if (l == 0) return Vector2{ 0 };
	return Vector2{ v.x / l, v.y / l };
}


void TrigonometryScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, WHITE);
	//DrawCircle(0, 0, 50, RED);
	//DrawCircle(Vector2{ 0, 0 }, 1, RED);
	
	float radius = 3;
	int steps = 50;
	float rate = 2;
	float time = (float)GetTime();

	float radians = 180 * DEG2RAD;

	for (int i = 0; i < steps; i++)
	{
		float theta = (i / (float)steps) * 2 * PI; //  0 - 1 percentage
		float x = cosf(theta) * radius;
		float y = sinf(theta) * radius;

		DrawCircle(Vector2{ x,y }, 0.25f, RED);
	}

	// sin / cos

	for (float x = -9.0f; x < 9.0f; x += 0.2)
	{
		float theta = time + (x / (float)18) * 2 * PI; //  0 - 1 percentage
		float cosine = cosf(theta) * radius;
		float sine = sinf(theta) * radius;

		DrawCircle(Vector2{ x, cosine }, 0.25f, GREEN);
		DrawCircle(Vector2{ x, sine }, 0.25f, BLUE);

	}

	float theta = time;
	float x = cosf(theta) * radius;
	float y = sinf(theta) * radius;
	DrawCircle(Vector2{ x,y }, 0.25f, YELLOW);
	
	//
	//sinTheta = o/h
	//arctan ( y,x ) = angle
	float angle = atan2(y, x);

	m_camera->EndMode();
}

void TrigonometryScene::DrawGUI()
{
}
