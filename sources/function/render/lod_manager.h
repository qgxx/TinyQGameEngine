#ifndef __LOG_MANAGER_H__
#define __LOG_MANAGER_H__

#include "core/qgearray.h"

#include <vector>
#include <glm/glm.hpp>
#include <iostream>

#define Z_FAR 5000.0f

class LODManager {
public:
    LODManager() {};
    ~LODManager() = default;
    int InitLodManager(int PatchSize, int NumPatchesX, int NumPatchesZ, float WorldScale);

    void Update(const glm::vec3& CameraPos);

    struct PatchLod {
        int Core   = 0;
        int Left   = 0;
        int Right  = 0;
        int Top    = 0;
        int Bottom = 0;
    };

    const PatchLod& GetPatchLod(int PatchX, int PatchZ) const;

    void PrintLodMap();

private:
    void CalcLodRegions();
    void CalcMaxLOD();
    void UpdateLodMapPass1(const glm::vec3& CameraPos);
    void UpdateLodMapPass2(const glm::vec3& CameraPos);

    int DistanceToLod(float Distance);

    int m_maxLOD = 0;
    int m_patchSize = 0;
    int m_numPatchesX = 0;
    int m_numPatchesZ = 0;
    float m_worldScale = 0.0f;

    Array2d<PatchLod> m_map;
    std::vector<int> m_regions;
};

#endif // !__LOG_MANAGER_H__