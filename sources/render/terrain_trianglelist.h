#ifndef __TERRAIN_TRIANGLE_LIST_H__
#define __TERRAIN_TRIANGLE_LIST_H__

#include <vector>
#include <glm/glm.hpp>
#include <glad/gl.h>

#include "shader.h"

class Terrain;

class TriangleList {
public:
    TriangleList() {};
    ~TriangleList() = default;
    void CreateTriangleList(int width, int depth, const Terrain* pTerrain);
    void Draw(Shader& shader);

private:
    typedef struct Vertex {
        glm::vec3 Pos;
        void InitVertex(const Terrain* pTerrain, int x, int z);
    } Vertex;

    int mWidth, mDepth;
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
    unsigned int VAO, VBO, EBO;

    void setupTriangleList(const Terrain* pTerrain);
};

#endif // !__TERRAIN_TRIANGLE_LIST_H__