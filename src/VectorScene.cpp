#include "VectorScene.h"
#include "Body.h"
#include "raymath.h"
#include "MathUtils.h"


void VectorScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
	m_world = new World();
	m_world->Initialize();

}

void VectorScene::Update()
{
	float dt = GetFrameTime();
	float theta = randomf(0, 360);
	

	if (IsMouseButtonPressed(0))
	{
		Vector2 position = m_camera->ScreenToWorld(GetMousePosition());
		Body* temp = m_world->CreateBody(position, 0.3f, RED);

		int total = 50;
		for (int i = 0; i < total; i++)
		{
			float angle = ((float)i / total) * 2 * PI;
			float starAngle = (PI / 2.5f) * i;

			Body* body = m_world->CreateBody(position, 0.05f, ColorFromHSV(randomf(360), 1,1));
			//use offset to create spread?
			//float offset = randomf(0, 360);
			float x = cosf(starAngle);
			float y = sinf(starAngle);
			body->velocity = Vector2{ x * randomf(3, 10), y * randomf(3,10)};
		}


	}
	m_world->Step(dt);
}

void VectorScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, DARKGRAY);
	m_world->Draw(*this);

	m_camera->EndMode();
}

void VectorScene::DrawGUI()
{
}
