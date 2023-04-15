#include <vector>

class Solution {
public:
    int numTrees(int n) {
        _cache.reserve(n);
        _cache.push_back(1);
        _cache.push_back(1);
        return catalan(n);
    }

    int catalan(int n) {
        if (n < (int)_cache.size()) {
            return _cache[n];
        }
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += catalan(i) * catalan(n - i - 1);
        }
        if (n >= (int)_cache.size()) {
            _cache.push_back(s);
        }
        return s;
    }

private:
    std::vector<int> _cache;
};