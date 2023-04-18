#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        if (n == 0) {
            return results;
        }
        generateParenthesis(results, "", 0, 0, n);
        return results;
    }

private:
    void generateParenthesis(vector<string> &results, string curr, int leftCount, int rightCount, int n) {
        if (leftCount < rightCount) {
            return;
        }
        if (leftCount > rightCount) {
            if (leftCount < n) {
                generateParenthesis(results, curr + "(", leftCount + 1, rightCount, n);
            }
            generateParenthesis(results, curr + ")", leftCount, rightCount + 1, n);
            return;
        }
        // left == right
        if (leftCount == n) {
            results.push_back(curr);
        } else {
            generateParenthesis(results, curr + "(", leftCount + 1, rightCount, n);
            generateParenthesis(results, curr + ")", leftCount, rightCount + 1, n);
        }
    }
};