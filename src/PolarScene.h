#pragma once
#include "scene.h"
#include "Polar.h"

class PolarScene : public Scene
{
public:
	PolarScene(const std::string& title, int width, int height, const Color& background = BLACK) :
		Scene(title, width, height, background)
	{

	}

	// Inherited via Scene
	void Initialize() override;

	void Update() override;

	void Draw() override;

	void DrawGUI() override;


	//Curve Drawing Logic
	void ArchimedeanSpiral(float startRadius, float radius);

	void Cardioid(float size);

	void Limaçon();

	void RoseCurve(float size, int petals);



private:
	Polar* m_polar{nullptr};


};