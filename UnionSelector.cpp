#include "UnionMapData.hpp"
#include <set>

std::set<std::pair<int, int>> selectedCells;

void handleClick(sf::Vector2i mousePos, bool shift) {
    int x = mousePos.x / CELL_SIZE;
    int y = mousePos.y / CELL_SIZE;
    if (x < 0 || x >= GRID_WIDTH || y < 0 || y >= GRID_HEIGHT) return;

    int zoneId = board[y][x].zoneId;
    std::pair<int, int> cell = { x, y };

    if (!shift) {
        if (selectedCells.count(cell)) selectedCells.erase(cell);
        else selectedCells.insert(cell);
    }
    else {
        // SHIFT 눌렀을 경우: 해당 zone 전체 toggle
        bool anySelected = false;
        for (int yy = 0; yy < GRID_HEIGHT; ++yy) {
            for (int xx = 0; xx < GRID_WIDTH; ++xx) {
                if (board[yy][xx].zoneId == zoneId && selectedCells.count({ xx, yy })) {
                    anySelected = true;
                    break;
                }
            }
            if (anySelected) break;
        }
        for (int yy = 0; yy < GRID_HEIGHT; ++yy) {
            for (int xx = 0; xx < GRID_WIDTH; ++xx) {
                if (board[yy][xx].zoneId == zoneId) {
                    if (anySelected) selectedCells.erase({ xx, yy });
                    else selectedCells.insert({ xx, yy });
                }
            }
        }
    }
}

void highlightSelected(sf::RenderWindow& window) {
    for (const auto& cell : selectedCells) {
        sf::RectangleShape rect(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
        rect.setFillColor(sf::Color::Yellow);
        rect.setPosition(cell.first * CELL_SIZE, cell.second * CELL_SIZE);
        window.draw(rect);
    }
}