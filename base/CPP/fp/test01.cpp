/**
 * @file test01.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-07-17
 *
 * @copyright Copyright (c) 2022
 *
 *
 * 读取文件行数
 */
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <ranges>
#include <numeric>

int count_lines(const std::string &filename)
{
    std::ifstream in(filename);

    return std::count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n');
}

int f(int previous_count, char c)
{
    return (c != '\n') ? previous_count : previous_count + 1;
}

// 使用std::accumulate统计换行符
int count_lines2(const std::string &s)
{
    return std::accumulate(s.cbegin(), s.cend(), 0, f);
}

std::vector<int> count_lines_in_files(const std::vector<std::string> &files)
{
    std::vector<int> results;
    for (const auto &file : files)
    {
        results.push_back(count_lines(file));
    }
    return results;
}

void test01()
{

    std::vector<std::string> files;
    files.push_back("../config/config.txt");
    std::vector<int> results = count_lines_in_files(files);

    std::cout << "counts: " << results[0] << std::endl;
}

std::vector<int> count_lines_in_files2(const std::vector<std::string> &files)
{
    std::vector<int> results(files.size());
    std::transform(files.cbegin(), files.cend(), results.begin(), count_lines);
    return results;
}

void test02()
{

    std::vector<std::string> files;
    files.push_back("../config/config.txt");
    std::vector<int> results = count_lines_in_files2(files);

    std::cout << "counts: " << results[0] << std::endl;
}

std::vector<int> count_lines_in_files3(const std::vector<std::string> &files)
{
    return files | transform(count_lines);
}

void test03()
{
    std::vector<std::string> files;
    files.push_back("../config/config.txt");
    std::vector<int> results = count_lines_in_files3(files);

    std::cout << "counts: " << results[0] << std::endl;
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    test03();
    return 0;
}
