#pragma once
// JARAD
#include <Assimp/scene.h>
#include <Assimp/Importer.hpp>
#include <Assimp/postprocess.h>
#include "RenderModuleStubb.h"
#include "Singleton.h"
#include "Model.h"
//#include "vec2.h"
#include "Maths.h"
#include "TextureManager.h"

class ImportModel : public Model
{
public:
	ImportModel* create() const;

	ImportModel();
	ImportModel(const ImportModel & tocpy);
	~ImportModel();

	bool loadModel(std::string filename);
	void setScale(vec3 & toset);

	void update();
	void render(const vec3 & transmat);

	std::vector<vec3>& getVerticies();

private:
	void setMinsAndMaxs();
	std::string RandomString(unsigned len);
	std::vector<vec3> Vertices;
	std::vector<vec2> texCoords;
	std::vector<vec3> Normals;
	std::vector<unsigned> vertIndex;
	std::string texture;
	const aiScene *model;

	void setVertices(aiMesh *mesh);
	void setTexCoords(aiMesh *mesh);
	void setNormals(aiMesh *mesh);
	void setIndexes(aiMesh *mesh);
	void centerOnPoint(vec3 &point);
};

