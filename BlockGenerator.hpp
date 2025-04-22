// BlockGenerator.hpp
#ifndef BLOCK_GENERATOR_HPP
#define BLOCK_GENERATOR_HPP

#include <vector>
#include <string>
using Block = std::vector<std::vector<int>>;

// ���� �̸� + ���(B~SSS)�� ���� �� ��ȯ
Block generateBlock(const std::string& job, const std::string& grade);

#endif