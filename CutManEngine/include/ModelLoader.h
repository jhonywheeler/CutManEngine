#include "Prerequisites.h"
#pragma once

class ModelLoader
{
public:
	ModelLoader() = default;
	~ModelLoader() = default;

	void
		init();

	void
		update();

	void
		render();

	void
		destroy();

	//Carga un Mod desde el archivo OBJ

	Mesh
		Load(std::string objFileName); //Obj Nombre

private:
};
