#include "TrigonometryScene.h"

void TrigonometryScene::Initialize()
{
	m_camera = new SceneCamera(Vector2{ m_width / 2.0f, m_height / 2.0f });
}

void TrigonometryScene::Update()
{
}

void TrigonometryScene::Draw()
{
	m_camera->BeginMode();
	DrawCircle(0, 0, 50, RED);
	m_camera->EndMode();
}

void TrigonometryScene::DrawGUI()
{
}
