// BlockGenerator.hpp
#ifndef BLOCK_GENERATOR_HPP
#define BLOCK_GENERATOR_HPP

#include <vector>
#include <string>
using Block = std::vector<std::vector<int>>;

// 직업 이름 + 등급(B~SSS)에 따라 블럭 반환
Block generateBlock(const std::string& job, const std::string& grade);

#endif