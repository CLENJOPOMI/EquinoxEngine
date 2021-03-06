﻿#ifndef __MODULELIGHTING_H__
#define __MODULELIGHTING_H__

#include "Module.h"
#include "GL/glew.h"
#include <gl/GL.h>
#include <string>

enum LightType
{
	L_POINT,
	L_DIRECTIONAL,
	L_SPOTLIGHT,
	L_DEFAULT
};

struct Light
{

	GLfloat* Ambient = new GLfloat[4]{ 0.f, 0.f, 0.f, 1.f };
	GLfloat* Diffuse = new GLfloat[4]{ 1.f, 1.f, 1.f, 1.f };
	GLfloat* Specular = new GLfloat[4]{ 1.f, 1.f, 1.f, 1.f };

	bool IsEnabled = false;

	int Number;
	LightType Type = L_DEFAULT;

	// w=1 => position || w=0 => direction (Direct light = 0.f, 0.f, 1.f, 0.f | position light = 0.f, 0.f, 0.f, 1.f)
	GLfloat* Position = new GLfloat[4]{ 0.f, 0.f, 0.f, 1.f };

	//Required for Spotlight
	GLfloat CutOff = 180.f;
	GLfloat* Direction = new GLfloat[3]{ 0.f, 0.f, 0.f };

};

class ModuleLighting : public Module
{
public:
	ModuleLighting();
	~ModuleLighting();

	bool Init();
	bool Start();
	update_status PreUpdate(float DeltaTime);
	update_status Update(float DeltaTime);
	update_status PostUpdate(float DeltaTime);
	bool CleanUp();

public:
	Light* Lights[8];
	bool EnableAmbientLight = false;
	GLfloat* AmbientLight;

	void SetLightType(Light* light, LightType new_type);

	LightType GetTypeByLabel(int label);
	int GetLabelByType(LightType type);

	void DrawGizmo(Light* light);
};

#endif
