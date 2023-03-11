#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

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

int main()
{
    std::ifstream in{ "romeoandjuliet.txt" };
    std::ofstream out{ "romeoandjuliet_out.txt" };
    std::string line;

    if (!in) {
        std::cout << "" << std::endl;
        return -1;
    }
    int lineNum{ 0 };
    while (std::getline(in, line)) {
        trim(line);
        if (line.size() == 0)
            out << line << std::endl;
        else out << std::left << std::setw(7) << lineNum++ << line << std::endl;
    }
    std::cout << "File copied successfully!" << std::endl;
    in.close();
    out.close();
    return 0;
}