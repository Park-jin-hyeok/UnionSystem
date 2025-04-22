// BlockUtility.hpp
#pragma once
#include <vector>

using Block = std::vector<std::vector<int>>;
using Coord = std::pair<int, int>;

// �� ȸ�� �Լ� (90�� ������ ȸ��)
Block rotateBlock(const Block& block, int rotation);  // rotation: 0, 90, 180, 270

// �� flip �Լ�
Block flipBlock(const Block& block, bool flipX, bool flipY);

// ��ġ �������� Ȯ�� (���õ� ��ǥ ���� ���� ���� �� �ִ°�?)
bool canPlaceBlock(const Block& block, const std::vector<Coord>& selectedCells, Coord origin);

// ������ ���� ��ǥ ���� ��ġ
void placeBlockOnBoard(const Block& block, const Coord& origin, std::vector<std::vector<int>>& resultBoard);