#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }
        unordered_map<int, vector<string>> table;
        table.emplace(2, vector<string>{"a", "b", "c"});
        table.emplace(3, vector<string>{"d", "e", "f"});
        table.emplace(4, vector<string>{"g", "h", "i"});
        table.emplace(5, vector<string>{"j", "k", "l"});
        table.emplace(6, vector<string>{"m", "n", "o"});
        table.emplace(7, vector<string>{"p", "q", "r", "s"});
        table.emplace(8, vector<string>{"t", "u", "v"});
        table.emplace(9, vector<string>{"w", "x", "y", "z"});
        bt(table, "", digits, result);
        return result;
    }
    void bt(unordered_map<int, vector<string>> &table, string one_result, string &digits, vector<string> &result) {
        int depth = static_cast<int>(one_result.size());
        int len = static_cast<int>(digits.size());
        if (depth == len) {
            result.push_back(one_result);
            return;
        }
        for (const auto &s : table[stoi(digits.substr(depth, 1))]) {
            bt(table, one_result + s, digits, result);
        }
    }
};