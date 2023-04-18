#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<Position> result;
        bt(count, result, n);
        return count;
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

    void bt(int &count, vector<Position> &result, int n) {
        int used = static_cast<int>(result.size());
        if (used == n) {
            count++;
            return;
        }
        int x = used;
        for (int y = 0; y < n; ++y) {
            if (valid(x, y, result)) {
                result.push_back(Position{x, y});
                bt(count, result, n);
                result.pop_back();
            }
        }
    }
};