#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

static inline void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

static inline void trim(std::string& s) {
    rtrim(s);
    ltrim(s);
}

void calculateScore(const std::string &answers, const std::string &studentAnswers, std::vector<int> &stScores) {
    int score{0};
    for (size_t i = 0; i < answers.size(); i++)
        if (answers.at(i) == studentAnswers.at(i))
            score++;
    stScores.push_back(score);
}

double calcAverageScore(const std::vector<int> &studScores) {
    return std::accumulate(studScores.begin(), studScores.end(), 0.0)/studScores.size();
}

int main()
{
    std::string answers{}, studentName{}, studentAnswer{};
    std::vector<int> studentScores;
    std::vector<std::string> studentNames, studentAnswers;

    std::ifstream testScores;
    testScores.open("responses.txt");
    if (!testScores.is_open())
    {
        std::cout << "Error: coulnd't open file.\nTerminating..........." << std::endl;
        return -1;
    }

    std::getline(testScores, answers);
    trim(answers);
    while (std::getline(testScores, studentName))
    {
        std::getline(testScores, studentAnswer);
        trim(studentName);
        trim(studentAnswer);
        studentNames.push_back(studentName);
        studentAnswers.push_back(studentAnswer);
    }
    for (size_t i = 0; i < studentAnswers.size(); i++)
        calculateScore(answers, studentAnswers.at(i), studentScores);
    std::cout << std::setw(15) << std::left << "Student" << std::setw(8) << "Score" << std::endl;
    std::cout << "---------------------" << std::endl;
    for (size_t i = 0; i < studentNames.size(); i++)
        std::cout << std::setw(15) << std::left << studentNames.at(i) << std::setw(8) << studentScores.at(i) << std::endl;
    std::cout << "---------------------" << std::endl;

    std::cout << std::setw(15) << std::left << "Average Score" << std::setw(8) << calcAverageScore(studentScores) << std::endl;
    testScores.close();
    return 0;
}
