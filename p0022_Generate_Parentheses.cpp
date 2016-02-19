/* LeetCode 22. Generate Parentheses
 *
 * 生成所有配对合法的n个括号的字符串。
 *
 * dfs或者bfs均可。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:

    vector<string> ret;
    string now;
    
    Solution() {
        ret.clear();
        now = "";
    }

    void dfs(int a, int b) {
        if (a == 0 && b == 0) {
            ret.push_back(now);
            return;
        }
        if (a) {
            now.push_back('(');
            dfs(a-1, b);
            now.pop_back();
        }
        if (a < b) {
            now.push_back(')');
            dfs(a, b-1);
            now.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return ret;
    }
};
