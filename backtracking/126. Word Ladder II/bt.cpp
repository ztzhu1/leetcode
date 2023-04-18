/** Warning: This answer takes so long time! */

#include <algorithm>
#include <cmath>
#include <numeric>
#include <optional>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string>> ans;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return ans;
        }
        vector<string> oneAns{beginWord};
        vector<bool> used(wordList.size(), false);
        bt(ans, oneAns, endWord, wordList, used);
        return ans;
    }

private:
    bool valid(vector<string> &oneAns, const string &word) {
        string curr = *std::prev(oneAns.end());
        if (curr.size() != word.size()) {
            return false;
        }
        auto currIt = curr.begin();
        auto wordIt = word.begin();
        int diffCount = 0;
        while (currIt != curr.end() && wordIt != word.end()) {
            if (*currIt != *wordIt) {
                diffCount++;
            }
            if (diffCount >= 2) {
                break;
            }
            ++currIt;
            ++wordIt;
        }
        return diffCount == 1;
    }

    void bt(vector<vector<string>> &ans,
            vector<string> &oneAns,
            string &endWord,
            vector<string> &wordList,
            vector<bool> &used) {
        int len = static_cast<int>(oneAns.size());
        if (len > _minCount) {
            return;
        }
        if (*std::prev(oneAns.end()) == endWord) {
            if (len < _minCount) {
                ans.clear();
                ans.emplace_back(oneAns.begin(), oneAns.end());
                _minCount = len;
            } else {  // len == _minCount
                ans.emplace_back(oneAns.begin(), oneAns.end());
            }
            return;
        }

        if (valid(oneAns, endWord)) {
            oneAns.push_back(endWord);
            bt(ans, oneAns, endWord, wordList, used);
            oneAns.pop_back();
            return;
        }
        for (size_t i = 0; i < wordList.size(); ++i) {
            if (used[i]) {
                continue;
            }
            if (valid(oneAns, wordList[i])) {
                oneAns.push_back(wordList[i]);
                used[i] = true;
                bt(ans, oneAns, endWord, wordList, used);
                used[i] = false;
                oneAns.pop_back();
            }
        }
    }

    int _minCount = numeric_limits<int>::max();
};

int main() {
    vector<string> wordList{"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le",
                            "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn",
                            "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc",
                            "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co",
                            "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an",
                            "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io",
                            "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};
    Solution().findLadders("qa", "sq", wordList);
}