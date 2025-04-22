#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

const int CELL_SIZE = 32;
const int GRID_WIDTH = 22;
const int GRID_HEIGHT = 20;
const int WINDOW_WIDTH = CELL_SIZE * GRID_WIDTH;
const int WINDOW_HEIGHT = CELL_SIZE * GRID_HEIGHT;

// Zone 구조체 정의
struct Zone {
    int id;
    sf::Vector2i origin;                      // 기준 위치
    std::vector<sf::Vector2i> baseShape;      // 기본 셀 좌표 (상대 좌표)
    std::string effectType = "NONE";
    bool flipX = false;
    bool flipY = false;
    bool hasBlock = false;

    std::vector<sf::Vector2i> getTransformedCells() const {
        std::vector<sf::Vector2i> transformed;
        for (auto pt : baseShape) {
            int x = flipX ? -pt.x : pt.x;
            int y = flipY ? -pt.y : pt.y;
            transformed.push_back({ origin.x + x, origin.y + y });
        }
        return transformed;
    }
};

std::vector<Zone> zones;

// ZoneSpec 구조체 정의
struct ZoneSpec {
    int id;
    sf::Vector2i origin;
    std::string effectType;
    bool flipX;
    bool flipY;
    bool isTriangle; // true = triangle, false = trapezoid
};

// ZoneSpec을 사용하여 존을 정의하는 벡터
std::vector<ZoneSpec> innerZoneSpecs = {
    {0,  {11, 10},  "STR", false, false, true},
    //{1,  {10, 10},  "DEX", false,  true, true},
    //{2,  {10, 9},  "INT", true, true,  true},
    //{3,  {11, 9},  "LUK", true,  false,  true},
    //{4,  {14, 2}, "HP", false, false, true},
    //{5,  {14, 7}, "MP", true,  false, true},
    //{6,  {2, 12}, "ATK", false, true,  true},
    //{7,  {8, 12}, "MGC", true,  true,  true},
};

std::vector<ZoneSpec> outterZoneSpecs = {
    //{0,  {2, 2},  "Critical_Chance", false, false, true},
    //{1,  {8, 2},  "Critical_Damage", true,  false, true},
    //{2,  {2, 7},  "Experience_Gained", false, true,  true},
    //{3,  {8, 7},  "Normal_Damage", true,  true,  true},
    //{4,  {14, 2}, "Boss_Damage", false, false, true},
    //{5,  {14, 7}, "Ignore_Defense", true,  false, true},
    //{6,  {2, 12}, "Status_Abnormality_Resistance", false, true,  true},
    //{7,  {8, 12}, "Buff_Duration", true,  true,  true},
};

// 기본 삼각형 모양을 생성하는 함수
std::vector<sf::Vector2i> createBaseTriangleShape() {
    std::vector<sf::Vector2i> shape;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x <= y; x++) {
            shape.push_back({ y, x });
        }
    }
    return shape;
}

// 기본 사다리꼴 모양을 생성하는 함수
std::vector<sf::Vector2i> createBaseTrapezoidShape() {
    std::vector<sf::Vector2i> shape;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x <= y + 5; x++) {
            shape.push_back({ y, x });
        }
    }
    return shape;
}

void initZones() {
    std::vector<sf::Vector2i> triangle = createBaseTriangleShape();
    std::vector<sf::Vector2i> trapezoid = createBaseTrapezoidShape();

    for (const auto& spec : innerZoneSpecs) {
        zones.push_back(Zone{
            spec.id,
            spec.origin,
            spec.isTriangle ? triangle : trapezoid,
            spec.effectType,
            spec.flipX,
            spec.flipY
            });
    }
}

void drawGrid(sf::RenderWindow& window)
{
    for (int y = 0; y < GRID_HEIGHT; ++y)
    {
        for (int x = 0; x < GRID_WIDTH; ++x)
        {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
            cell.setFillColor(sf::Color(100, 100, 100));
            cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            window.draw(cell);
        }
    }
}

void drawZones(sf::RenderWindow& window)
{
    for (const auto& zone : zones)
    {
        sf::Color color = sf::Color::Blue;
        if (zone.effectType == "DEX") color = sf::Color::Green;
        else if (zone.effectType == "INT") color = sf::Color::Magenta;
        else if (zone.effectType == "LUK") color = sf::Color::Cyan;

        for (const auto& pos : zone.getTransformedCells())
        {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1));
            cell.setPosition(pos.x * CELL_SIZE, pos.y * CELL_SIZE);
            cell.setFillColor(color);
            window.draw(cell);
        }
    }
}


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Union Map", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    initZones();  // 존 초기화

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        drawGrid(window);
        drawZones(window);
        window.display();
    }

    return 0;
}