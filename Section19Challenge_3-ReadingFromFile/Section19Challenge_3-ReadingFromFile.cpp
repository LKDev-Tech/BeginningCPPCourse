#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

static inline void ltrim(std::string& s) {
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


void increaseWordCount(int& numw) {
    numw++;
}

void increaseWordFindCount(int& fwc) {
    fwc++;
}

void readWord(const std::string wordToFind, const std::string &sentence, int &numw ,int &findWordCount) {

    std::istringstream iss(sentence);
    std::string word;

    while (iss >> word)
    {
        trim(word);
        increaseWordCount(numw);
        std::size_t found = word.find(wordToFind);
        if (found != std::string::npos)
            increaseWordFindCount(findWordCount);
    }
}

int main()
{
    std::ifstream read;
    std::string findWord, line;
    int numWords{ 0 }, findWordCount{ 0 };
    read.open("romeoandjuliet.txt");
    if (!read) {
        std::cout << "" << std::endl;
        return -1;
    }
    std::cout << "Enter the string to search for: ";
    std::cin >> findWord;
    std::cout << std::endl;

    while (std::getline(read, line)) {
        if (line.size() == 0)
            continue;
        trim(line);
        readWord(findWord, line, numWords, findWordCount);
    }
    std::cout << numWords << " words were searched..." << std::endl << "The string " << findWord << " was found " << findWordCount << std::endl;
    read.close();
    return 0;
}