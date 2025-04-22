// BlockPlacer.cpp
#include "UnionMapData.hpp"
#include "BlockGenerator.hpp"
#include <vector>
#include <utility>
#include <iostream>

// �� ��ġ �Լ�
void placeAllBlocks(
    const std::vector<std::tuple<std::string, std::string, int>>& blockSettings,
    const std::vector<std::pair<int, int>>& selectedCells
) {
    std::vector<Block> blocks;

    // 1. �� ����
    for (const auto& [job, grade, count] : blockSettings) {
        Block blk = generateBlock(job, grade);
        for (int i = 0; i < count; ++i)
            blocks.push_back(blk);
    }

    // 2. ���õ� ���� ��� ������ ������ �ʱ�ȭ
    std::set<std::pair<int, int>> availableCells(selectedCells.begin(), selectedCells.end());

    // 3. ���⼭ ���� �ϳ��� ��ġ �õ�
    for (const Block& blk : blocks) {
        // TODO: ���� availableCells �ȿ� ��ġ�� �� �ִ� ��ġ ã��
        //       ��ġ�� �ʰ� ��ġ�ϸ鼭 used ���� ������Ʈ
    }

    // 4. ��ġ ���� �� ���� ���, ���� �� board[][]�� .filled = true ����
}
