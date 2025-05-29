
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "GUI.h"

#define GUI_DATA(data) TextFormat("%0.2f", data), &data


void GUI::Update()
{
	mouseOverGUI = PhysicsWindowBoxActive && CheckCollisionPointRec(GetMousePosition(), { anchor01.x + 0, anchor01.y + 0, 240, 600 });
	if (IsKeyPressed(KEY_TAB)) PhysicsWindowBoxActive = !PhysicsWindowBoxActive;
}

void GUI::Draw()
{
	if (BodyTypeSelectionDropdownEditMode) GuiLock();

	if (PhysicsWindowBoxActive)
	{
		PhysicsWindowBoxActive = !GuiWindowBox(Rectangle{ anchor01.x + 0, anchor01.y + 0, 240, 600 }, "Physics Controls");
		GuiSlider(Rectangle{ anchor01.x + 80, anchor01.y + 48, 120, 16 }, "BodyMass", GUI_DATA(BodyMassSliderValue), 0, 10);
		GuiSlider(Rectangle{ anchor01.x + 80, anchor01.y + 80, 120, 16 }, "BodySize", GUI_DATA(BodySizeSliderValue), 0.1f, 5.0f);
		if (GuiDropdownBox(Rectangle{ anchor01.x + 80, anchor01.y + 112, 120, 24 }, "Dynamic;Static;Kinematic", &BodyTypeSelectionDropdownActive, BodyTypeSelectionDropdownEditMode)) BodyTypeSelectionDropdownEditMode = !BodyTypeSelectionDropdownEditMode;
		GuiSlider(Rectangle{ anchor01.x + 80, anchor01.y + 152, 120, 16 }, "GravityScale", GUI_DATA(WGravForceSliderValue), 0, 5);
		GuiSlider(Rectangle{ anchor01.x + 80, anchor01.y + 184, 120, 16 }, "BodyDamping", GUI_DATA(BodyDampingSliderValue), 0, 1);
		GuiSlider(Rectangle{ anchor01.x + 80, anchor01.y + 216, 120, 16 }, "Restitution", GUI_DATA(RestitutionSliderValue), 0, 1);
		GuiSlider(Rectangle{ anchor01.x + 80, anchor01.y + 248, 120, 16 }, "WGravForce", TextFormat("%0.2f", World::gravity.y), &World::gravity.y, -20, 20);



		//GuiSlider(Rectangle{ anchor01.x + 80, anchor01.y + 260, 120, 16 }, "Stiffness X", GUI_DATA(springStiffnessMultiplier), 0, 5);
	}

	GuiUnlock();
}

Body* GUI::GetBodyIntersect(const Vector2& position, bodies_t& bodies, const SceneCamera& camera)
{
	for (auto body : bodies)
	{
		if (CheckCollisionPointCircle(position, body->position, body->size))
		{
			return body;
		}
	}
	return nullptr;
}
