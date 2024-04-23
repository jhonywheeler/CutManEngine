#include "ModelLoader.h"
#include "OBJ_Loader.h"

void ModelLoader::init()
{
}

void ModelLoader::update()
{
}

void ModelLoader::render()
{
}

void ModelLoader::destroy()
{
}

Mesh
ModelLoader::Load(std::string objFileName)
{
	//Temporal Load Data
	Mesh mesh;
	objl::Loader Loader;
	Loader.LoadFile(objFileName);

	mesh.name = objFileName;

	WARNING("ModelLoader::Load() [Load of file: " << objFileName.c_str() << "] \n");

	//Cargar y configurar datos en una estructura personalizada (SimpleVertex)
	mesh.vertex.resize(Loader.LoadedVertices.size());

	for (int i = 0; i < mesh.vertex.size(); i++)
	{
		// Load Positions
		mesh.vertex[i].Pos.x = Loader.LoadedVertices[i].Position.X;
		mesh.vertex[i].Pos.y = Loader.LoadedVertices[i].Position.Y;
		mesh.vertex[i].Pos.z = Loader.LoadedVertices[i].Position.Z;

		// Load Text
		mesh.vertex[i].Tex.x = Loader.LoadedVertices[i].TextureCoordinate.X;
		mesh.vertex[i].Tex.y = 1.0f - Loader.LoadedVertices[i].TextureCoordinate.Y;

		//Normal
		mesh.vertex[i].Nor.x = Loader.LoadedVertices[i].Normal.X;
		mesh.vertex[i].Nor.y = Loader.LoadedVertices[i].Normal.Y;
		mesh.vertex[i].Nor.z = Loader.LoadedVertices[i].Normal.Z;
	}

	// Cargar y configurar datos en una estructura personalizada
	mesh.index.resize(Loader.LoadedIndices.size());
	for (int i = 0; i < mesh.index.size(); i++)
	{
		mesh.index[i] = Loader.LoadedIndices[i];
	}

	mesh.numVertex = mesh.vertex.size();
	mesh.numIndex = mesh.index.size();

	return mesh;
}