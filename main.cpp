#include "UnionMapData.hpp"
#include <SFML/Graphics.hpp>
#include "BlockGenerator.hpp"
#include <iostream>
#include <tuple>
#include <vector>

using BlockInfo = std::tuple<std::string, std::string, int>;

std::vector<BlockInfo> blockSettings = {
    {"Warrior", "SSS", 2}, {"Warrior", "SS", 5}, {"Warrior", "S", 1}, {"Warrior", "A", 2}, {"Warrior", "B", 3},
    {"Wizard",  "SSS", 2}, {"Wizard",  "SS", 4}, {"Wizard",  "S", 1}, {"Wizard",  "A", 2}, {"Wizard",  "B", 2},
    {"Archer",  "SSS", 4}, {"Archer",  "SS", 2}, {"Archer",  "S", 8}, {"Archer",  "A", 2}, {"Archer",  "B", 0},
    {"Theif",   "SSS", 0}, {"Theif",   "SS", 1}, {"Theif",   "S", 2}, {"Theif",   "A", 1}, {"Theif",   "B", 0},
    {"Pirate",  "SSS", 5}, {"Pirate",  "SS", 2}, {"Pirate",  "S", 1}, {"Pirate",  "A", 0}, {"Pirate",  "B", 2}
};

extern void generateMap();
extern void handleClick(sf::Vector2i, bool);
extern void highlightSelected(sf::RenderWindow&);

void drawGrid(sf::RenderWindow& window) {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
            cell.setFillColor(sf::Color(100, 100, 100));
            cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            window.draw(cell);
        }
    }
}

void drawZones(sf::RenderWindow& window) {
    for (int y = 0; y < GRID_HEIGHT; ++y) {
        for (int x = 0; x < GRID_WIDTH; ++x) {
            int id = board[y][x].zoneId;
            if (id != -1) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
                sf::Color color(
                    50 + (id * 12) % 200,
                    50 + (id * 12) % 200,
                    50 + (id * 12) % 200
                );
                cell.setFillColor(color);
                cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
                window.draw(cell);
            }
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Union Map Editor");
    generateMap();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                bool shift = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);
                handleClick({ event.mouseButton.x, event.mouseButton.y }, shift);
            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                std::cout << "Selected Cells: ";
                for (const auto& cell : selectedCells)
                    std::cout << "(" << cell.first << "," << cell.second << ") ";
                std::cout << "\n";

                // 블럭 총 필요한 칸 계산
                int totalBlockCells = 0;
                for (const auto& [job, grade, count] : blockSettings) {
                    Block blk = generateBlock(job, grade);
                    int blockArea = 0;
                    for (const auto& row : blk)
                        for (int val : row)
                            if (val) ++blockArea;
                    totalBlockCells += blockArea * count;
                }

                if (selectedCells.size() < totalBlockCells) {
                    std::cout << "선택한 칸이 너무 적습니다. (필요: " << totalBlockCells << ", 선택: " << selectedCells.size() << ")\n";
                }
                else {
                    std::cout << "충분한 칸이 선택되었습니다. 블럭 배치를 위한 보드를 생성합니다...\n";

                    // 복사 보드 초기화
                    placementBoard.assign(GRID_HEIGHT, std::vector<int>(GRID_WIDTH, -1));

                    // 선택된 칸만 0으로 초기화
                    for (const auto& [x, y] : selectedCells)
                        placementBoard[y][x] = 0;

                    std::cout << "복사된 보드 준비 완료. 알고리즘 배치 가능 상태입니다.\n";
                }
            }
        }

        window.clear();
        drawGrid(window);
        drawZones(window);
        highlightSelected(window);
        window.display();
    }

    return 0;
}
