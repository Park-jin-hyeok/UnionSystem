#include "BlockGenerator.hpp"

// ������ ���� �� ���
Block generateBlock(const std::string& job, const std::string& grade) {
    // ����
    if (job == "Warrior") {
        if (grade == "B") return { {1} };
        if (grade == "A") return { {1}, {1} };
        if (grade == "S") return { {1, 1}, {1, 0} };
        if (grade == "SS") return { {1, 1}, {1, 1} };
        if (grade == "SSS") return { {1,0}, {1,1}, {1,1} };
    }

    // ����: ����Ʈ�ε� ������
    if (job == "Wizard") {
        if (grade == "B") return { {1} };
        if (grade == "A") return { {1},{1} };
        if (grade == "S") return { {1,1,1} };
        if (grade == "SS") return { {0,1,0},{1,1,1} };
        if (grade == "SSS") return { {0,1,0}, {1,1,1}, {0,1,0} };
    }

    if (job == "Archer" || job == "MapleStoryM") {
        if (grade == "B") return { {1} };
        if (grade == "A") return { {1}, {1} };
        if (grade == "S") return { {1,1,1} };
        if (grade == "SS") return { {1,1,1,1} };
        if (grade == "SSS") return { {1,1,1,1,1} };
    }

    if (job == "Theif") {
        if (grade == "B") return { {1} };
        if (grade == "A") return { {1}, {1} };
        if (grade == "S") return { {1,1,1} };
        if (grade == "SS") return { {1,1,1}, {0,0,1} };
        if (grade == "SSS") return { {0,0,1}, { 1,1,1 }, {0,0,1} };
    }

    if (job == "Pirate") {
        if (grade == "B") return { {1} };
        if (grade == "A") return { {1}, {1} };
        if (grade == "S") return { {1,1}, {1,0} };
        if (grade == "SS") return { {1,1,0}, {0,1,1} };
        if (grade == "SSS") return { {0,0,0,1,1}, { 0,1,1,1 } };
    }

    // �⺻ �� (���ǵ��� �ʾ��� ���)
    return {};
}
