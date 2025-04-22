#include "UnionMapData.hpp"

std::vector<std::vector<int>> placementBoard;
std::vector<std::vector<CellState>> board(GRID_HEIGHT, std::vector<CellState>(GRID_WIDTH));

sf::Vector2i transform(sf::Vector2i pt, bool flipX, bool flipY, bool transpose) {
    int x = pt.x, y = pt.y;
    if (transpose) std::swap(x, y);
    if (flipX) y = -y;
    if (flipY) x = -x;
    return { x, y };
}

std::vector<sf::Vector2i> createBaseTriangleShape() {
    std::vector<sf::Vector2i> shape;
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x <= y; ++x) {
            shape.push_back({ x, y });
        }
    }
    return shape;
}

std::vector<sf::Vector2i> createBaseTrapezoidShape() {
    std::vector<sf::Vector2i> shape;
    for (int y = 0; y < 5; ++y) {
        for (int x = 0; x <= y + 5; ++x) {
            shape.push_back({ x, y });
        }
    }
    return shape;
}

void placeShape(const std::vector<sf::Vector2i>& shape, sf::Vector2i origin, int zoneId, bool flipX = false, bool flipY = false, bool transpose = false) {
    for (auto pt : shape) {
        sf::Vector2i t = transform(pt, flipX, flipY, transpose);
        int fx = origin.x + t.x;
        int fy = origin.y + t.y;
        if (fx >= 0 && fx < GRID_WIDTH && fy >= 0 && fy < GRID_HEIGHT) {
            board[fy][fx].zoneId = zoneId;
        }
    }
}

void generateMap() {
    auto triangle = createBaseTriangleShape();
    auto trapezoid = createBaseTrapezoidShape();

    placeShape(triangle, { 11, 10 }, 0);
    placeShape(triangle, { 11, 9 }, 1, true);
    placeShape(triangle, { 10, 10 }, 2, false, true);
    placeShape(triangle, { 10, 9 }, 3, true, true);
    placeShape(triangle, { 12, 10 }, 4, false, false, true);
    placeShape(triangle, { 12, 9 }, 5, true, false, true);
    placeShape(triangle, { 9, 10 }, 6, false, true, true);
    placeShape(triangle, { 9, 9 }, 7, true, true, true);
    placeShape(trapezoid, { 11, 15 }, 8);
    placeShape(trapezoid, { 11, 4 }, 9, true);
    placeShape(trapezoid, { 10, 15 }, 10, false, true);
    placeShape(trapezoid, { 10, 4 }, 11, true, true);
    placeShape(trapezoid, { 17, 10 }, 12, false, false, true);
    placeShape(trapezoid, { 17, 9 }, 13, true, false, true);
    placeShape(trapezoid, { 4, 10 }, 14, false, true, true);
    placeShape(trapezoid, { 4, 9 }, 15, true, true, true);
}