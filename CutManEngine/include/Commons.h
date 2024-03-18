#include "Prerequisites.h"
#pragma once

//Esta estructura esta encargada de almacenar la informacion que tendran nuestros objetos para despues dibujarse en pantalla

/*struct SimpleVertex {
	XMFLOAT3 Pos; //Posiciones
	XMFLOAT2 Tex; //Coordenadas de Textura
};*/

struct
	LoadData {
	std::string name;
	std::vector <SimpleVertex> vertex;
	std::vector<unsigned int> index;
	int numVertex;
	int numIndex;

};

/*struct Camera {
	XMMATRIX mView;
	XMMATRIX mProjection;
};*/
