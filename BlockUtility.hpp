// BlockUtility.hpp
#pragma once
#include <vector>

using Block = std::vector<std::vector<int>>;
using Coord = std::pair<int, int>;

// 블럭 회전 함수 (90도 단위로 회전)
Block rotateBlock(const Block& block, int rotation);  // rotation: 0, 90, 180, 270

// 블럭 flip 함수
Block flipBlock(const Block& block, bool flipX, bool flipY);

// 배치 가능한지 확인 (선택된 좌표 내에 블럭을 놓을 수 있는가?)
bool canPlaceBlock(const Block& block, const std::vector<Coord>& selectedCells, Coord origin);

// 실제로 블럭을 좌표 위에 배치
void placeBlockOnBoard(const Block& block, const Coord& origin, std::vector<std::vector<int>>& resultBoard);