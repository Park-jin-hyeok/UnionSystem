#ifndef UNION_MAP_DATA_HPP
#define UNION_MAP_DATA_HPP

#include <vector>
#include <set>
#include <SFML/Graphics.hpp>

const int CELL_SIZE = 32;
const int GRID_WIDTH = 22;
const int GRID_HEIGHT = 20;
const int WINDOW_WIDTH = CELL_SIZE * GRID_WIDTH;
const int WINDOW_HEIGHT = CELL_SIZE * GRID_HEIGHT;

struct CellState {
    int zoneId = -1;
    bool filled = false;
};

extern std::vector<std::vector<CellState>> board;
extern std::set<std::pair<int, int>> selectedCells;
extern std::vector<std::vector<int>> placementBoard; 

#endif