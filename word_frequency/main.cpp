#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>

struct Statistics
{
    size_t count;
    std::string word;

    bool operator<(const Statistics& obj)
    {
        return count < obj.count;
    }

    bool operator>(const Statistics& obj)
    {
        return count > obj.count;
    }
};

std::string prepare(const std::string& str)
{
    std::string res;
    for (const auto& c: str)
    {
        res.push_back(tolower(c));
    }

    if (!isalpha(res.back()))
    {
        res.pop_back();
    }
    return res;
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "File name required\n";
        exit(-1);
    }

    std::ifstream file(argv[1]);
    if (file.is_open())
    {
        std::string word;
        std::map<std::string, size_t> words;
        while (!file.eof())
        {
            file >> word;
            words[prepare(word)]++;
        }

        std::vector<Statistics> stat_words;
        for (const auto& [word, num]: words)
        {
            stat_words.push_back({num, word});
        }

        std::sort(stat_words.begin(), stat_words.end());
        for (const auto& sw: stat_words)
        {
            std::cout << sw.word << " " << sw.count << "\n";
        }
    }
    return 0;
}