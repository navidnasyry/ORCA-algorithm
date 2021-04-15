#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstddef>
#include <iostream>

#include "Geom.h"

#ifndef ORCASTAR_UPDATABLE_MAP_H
#define ORCASTAR_UPDATABLE_MAP_H


class UpdatableMap
{
    public:
        UpdatableMap();
        UpdatableMap(const UpdatableMap &obj) = default;
        ~UpdatableMap() = default;
        UpdatableMap & operator = (const UpdatableMap &obj);
        
        bool Update(std::vector<std::vector<bool>> grid, int64_t origin_i, int64_t origin_j, float c_size);
        bool CellIsObstacle(int64_t i, int64_t j) const;
        bool CellOnGrid(int64_t i, int64_t j) const;
        bool CellIsTraversable(int64_t i, int64_t j) const;
        int64_t GridHeight() const;
        int64_t GridWidth() const;
        float CellSize() const;
        Node CreateNodeForPoint(const Point &point) const;
        Point CenterPosition(int64_t i, int64_t j) const;
        std::unordered_map<size_t, ObstacleSegment>& GetCloseObstacles(const Point &point, float spacing);
        
    private:
        std::pair<int64_t, int64_t> origin;
        float cell_size;
        int64_t height;
        int64_t width;
        std::vector<std::vector<bool>> grid;
        std::unordered_map<size_t, ObstacleSegment> obstacle_segments;
};


#endif //ORCASTAR_UPDATABLE_MAP_H
