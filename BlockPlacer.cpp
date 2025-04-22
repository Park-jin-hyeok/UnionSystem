// BlockPlacer.cpp
#include "UnionMapData.hpp"
#include "BlockGenerator.hpp"
#include <vector>
#include <utility>
#include <iostream>

// 블럭 배치 함수
void placeAllBlocks(
    const std::vector<std::tuple<std::string, std::string, int>>& blockSettings,
    const std::vector<std::pair<int, int>>& selectedCells
) {
    std::vector<Block> blocks;

    // 1. 블럭 생성
    for (const auto& [job, grade, count] : blockSettings) {
        Block blk = generateBlock(job, grade);
        for (int i = 0; i < count; ++i)
            blocks.push_back(blk);
    }

    // 2. 선택된 셀을 사용 가능한 맵으로 초기화
    std::set<std::pair<int, int>> availableCells(selectedCells.begin(), selectedCells.end());

    // 3. 여기서 블럭을 하나씩 배치 시도
    for (const Block& blk : blocks) {
        // TODO: 블럭을 availableCells 안에 배치할 수 있는 위치 찾기
        //       겹치지 않게 배치하면서 used 영역 업데이트
    }

    // 4. 배치 실패 시 오류 출력, 성공 시 board[][]에 .filled = true 설정
}
