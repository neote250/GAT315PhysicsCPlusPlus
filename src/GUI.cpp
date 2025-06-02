
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "GUI.h"

#define GUI_DATA(data) TextFormat("%0.2f", data), &data


void GUI::Update()
{
	mouseOverGUI = physicsWindowBoxActive && CheckCollisionPointRec(GetMousePosition(), { anchor01.x + 0, anchor01.y + 0, 240, 600 });
	if (IsKeyPressed(KEY_TAB)) physicsWindowBoxActive = !physicsWindowBoxActive;
}

void GUI::Draw()
{
	if (bodyTypeEditMode) GuiLock();

	if (physicsWindowBoxActive)
	{
		physicsWindowBoxActive = !GuiWindowBox(Rectangle { anchor01.x + 0, anchor01.y + 0, 312, 472 }, "Physics");
		GuiToggle(Rectangle { anchor01.x + 24, anchor01.y + 432, 120, 24 }, "Simulate", & simulateActive);
		resetPressed = GuiButton(Rectangle { anchor01.x + 168, anchor01.y + 432, 120, 24 }, "Reset");

	}
	GuiGroupBox(Rectangle { anchor02.x + 0, anchor02.y + 0, 264, 176 }, "Body");
	GuiSliderBar(Rectangle { anchor02.x + 104, anchor02.y + 16, 120, 16 }, "Mass", GUI_DATA(massValue), 0, 10);
	GuiSliderBar(Rectangle { anchor02.x + 104, anchor02.y + 40, 120, 16 }, "Size", GUI_DATA(sizeValue), 0.1f, 5.0f);

	GuiSliderBar(Rectangle { anchor02.x + 104, anchor02.y + 64, 120, 16 }, "Gravity Scale", GUI_DATA(gravityScaleValue), 0, 10);
	GuiSliderBar(Rectangle { anchor02.x + 104, anchor02.y + 88, 120, 16 }, "Damping", GUI_DATA(dampingValue), 0, 1);
	GuiSliderBar(Rectangle{ anchor02.x + 104, anchor02.y + 112, 120, 16 }, "Restitution", GUI_DATA(restitutionValue), 0, 1);

	if (GuiDropdownBox(Rectangle { anchor02.x + 104, anchor02.y + 136, 120, 24 }, "Dynamic;Static;Kinematic", & bodyTypeActive, bodyTypeEditMode)) bodyTypeEditMode = !bodyTypeEditMode;


	GuiLabel(Rectangle { anchor02.x + 32, anchor02.y + 136, 120, 24 }, "Body Type");
	GuiGroupBox(Rectangle { anchor03.x + 0, anchor03.y + 0, 264, 72 }, "Spring");
	GuiSliderBar(Rectangle { anchor03.x + 104, anchor03.y + 16, 120, 16 }, "Damping", GUI_DATA(springDampingValue), 0, 1);
	GuiSliderBar(Rectangle { anchor03.x + 104, anchor03.y + 40, 120, 16 }, "Stiffness", GUI_DATA(stiffnessValue), 0, 1);

	GuiGroupBox(Rectangle { anchor04.x + 0, anchor04.y + -8, 264, 96 }, "World");
	GuiSliderBar(Rectangle { anchor03.x + 104, anchor03.y + 104, 120, 16 }, "Gravitation", GUI_DATA(gravitationValue), 0, 5);
	GuiSlider(Rectangle{ anchor04.x + 104, anchor04.y + 56, 120, 16 }, "Gravity", GUI_DATA(World::gravity.y), -20, 20);
	GuiSliderBar(Rectangle { anchor03.x + 104, anchor03.y + 128, 120, 16 }, "Spring Multiplier", NULL, & springSiffnessMultiplierValue, 0, 100);


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
