#include "PolarScene.h"

void PolarScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
	m_polar = new Polar{PI/8,0.1f};
}

void PolarScene::Update()
{
}

void PolarScene::Draw()
{
	m_camera->BeginMode();

	DrawGrid(10, 5, WHITE);

	float rate = 0.5f;
	float time = (float)GetTime();
	int steps = 500;
	float size = 3.0f;
	int petals = 7;


	//Archimedean
	//for (int i = 0; i < steps; i++)
	//{
	//	float theta = i * m_polar->radius;
	//	float radius = 0 + rate * theta;
	//	float x = cosf(theta) * radius;
	//	float y = sinf(theta) * radius;

	//	DrawCircle(Vector2{ x,y }, 0.25f, RED);
	//}





	//Cardioid
	//for (int i = 0; i < steps; i++)
	//{
	//	float theta = i * m_polar->radius;
	//	float radius = size + cosf(theta);
	//	float x = cosf(theta) * radius;
	//	float y = sinf(theta) * radius;

	//	DrawCircle(Vector2{ x,y }, 0.25f, RED);
	//}



	//Limaçon
	//for (int i = 0; i < steps; i++)
	//{
	//	float theta = i * m_polar->radius;
	//	float radius = 0.5f + 0.75f * cosf(theta);
	//	float x = cosf(theta) * radius;
	//	float y = sinf(theta) * radius;
	//	DrawCircle(Vector2{ x,y }, 0.07f, RED);
	//}



	//RoseCurve
	//for (int i = 0; i < steps; i++)
	//{
	//	float theta = i * m_polar->radius;
	//	float radius = size * cosf(theta * petals);
	//	float x = cosf(theta) * radius;
	//	float y = sinf(theta) * radius;
	//	DrawCircle(Vector2{ x,y }, 0.07f, RED);
	//}




	//lemniscates
	for (int i = 0; i < steps; i++)
	{
		float theta = i * m_polar->radius;
		float radius = sqrtf(size * size * cosf(2* theta));
		float x = cosf(theta) * radius;
		float y = sinf(theta) * radius;
		DrawCircle(Vector2{ x,y }, 0.25f, RED);
	}


	m_camera->EndMode();
}

void PolarScene::DrawGUI()
{
}

void PolarScene::ArchimedeanSpiral(float startRadius, float radius)
{
}

void PolarScene::Cardioid(float size)
{
}

void PolarScene::Limaçon()
{
}

void PolarScene::RoseCurve(float size, int petals)
{
}
