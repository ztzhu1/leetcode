#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<Position> result;
        bt(results, result, n);
        return results;
    }

private:
    struct Position {
        int x;
        int y;
    };

    static bool valid(int x0, int y0, int x1, int y1) {
        if (x0 == x1 || y0 == y1 || x0 + y0 == x1 + y1 || x0 - y0 == x1 - y1) {
            return false;
        }
        return true;
    }

    static bool valid(int x0, int y0, vector<Position> &result) {
        for (const auto &p : result) {
            if (!valid(x0, y0, p.x, p.y)) {
                return false;
            }
        }
        return true;
    }

    static vector<string> toString(vector<Position> &result, int n) {
        vector<string> ret(n, string(n, '.'));
        for (const auto &p : result) {
            ret[p.y].replace(p.x, 1, "Q");
        }
        return ret;
    }

    void bt(vector<vector<string>> &results, vector<Position> &result, int n) {
        int used = static_cast<int>(result.size());
        if (used == n) {
            results.emplace_back(toString(result, n));
            return;
        }
        int x = used;
        for (int y = 0; y < n; ++y) {
            if (valid(x, y, result)) {
                result.push_back(Position{x, y});
                bt(results, result, n);
                result.pop_back();
            }
        }
    }
};