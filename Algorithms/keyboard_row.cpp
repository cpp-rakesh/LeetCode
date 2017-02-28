
/*
  Solution for Keyboard row  
  Author: cpp.rakesh@gmail.com
  Date: Feb 28th 18th, 2017
*/

#include <cstdio>
#include <string>
#include <vector>
#include <map>

const std::vector<std::string> keyboard = {"EIOPQRTUWYeiopqrtuwy",
                                           "ADFGHJKLSadfghjkls",
                                           "BCMNVXZbcmnvxz"};

class Solution {
public:
    std::vector<std::string> findWords(const std::vector<std::string>& words) {
        std::vector<std::string> result;
        for (std::size_t i = 0; i < words.size(); ++i)
            if (words[i].size() == 1)
                result.push_back(words[i]);
            else if (m_find_in_keyboard(words[i]))
                result.push_back(words[i]);

        return result;
    }

private:
    bool m_find_in_keyboard(const std::string& word) {
        std::map<char, int> dictionary;
        for (std::size_t i = 0; i < keyboard.size(); ++i) {
            if (m_search(i, word[0])) {
                dictionary[word[0]] = 1;
                int j = 1;
                while (j < word.size() - 1) {
                    if (dictionary[word[j]] != 1) {
                        if (m_search(i, word[j]))
                            dictionary[word[j]] = 1;
                        else
                            return false;

                    }
                    ++j;
                }

                if (dictionary[word[j]]) {
                    return true;
                } else {
                    if (m_search(i, word[j]))
                        return true;
                    else
                        return false;
                }
            }
        }

        return true;
    }

    bool m_search(std::size_t pos, char c) {
        int start = 0;
        int end = keyboard[pos].size() - 1;

        while (start <= end) {
            if (c == keyboard[pos][start])
                return true;
            if (c == keyboard[pos][end])
                return true;

            const int mid = (start + end) >> 1;

            if (c == keyboard[pos][mid]) {
                return true;
            } else if (c < keyboard[pos][mid]){
                ++start;
                end = mid - 1;
            } else {
                start = mid + 1;
                --end;
            }
        }

        return false;
    }
};

int main() {
    Solution solution;
    std::vector<std::string> words = {"Qwee", "Alaska", "Dad", "a", "Hello"};

    const std::vector<std::string> result = solution.findWords(words);

    for (std::size_t i = 0; i < result.size(); ++i)
        printf("%s\n", result[i].c_str());
    
    return 0;
}
