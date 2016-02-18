/* LeetCode 10. Regular Expression Matching
 *
 * 实现简单的正则匹配，仅2条特殊规则：
 * 1. '.'匹配一个任何字符
 * 2. '*'表示匹配零个或多个其之前的字符（如"a*"匹配零个或多个a）
 *
 * DP。  
 * d[i][j] = true表示母串s的前i位（s[0..i-1]）和模式串p的前j位（p[0..j-1]）匹配成功。
 * 初始d[0][0] = true，若d[i][j] == true，可以推出：
 * 1. 若p[j+1] == '*'，则d[i][j+2] = true；
 * 2. 若p[j+1] != '*'，且s[i] == p[j] || p[j] == '.'，则d[i+1][j+1] = true；
 * 3. 若p[j-1] == '*'，且s[i] == p[j-2] || p[j-2] == '.'，则d[i+1][j] = true。
 * 另外要注意i,j的枚举范围（[0, 串长]），以及递推时越界判断。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> d(n+1, vector<bool>(m+1, false));
        d[0][0] = true;
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= m; ++j)
                if (d[i][j]) {
                    if (j + 1 < m && p[j+1] == '*')
                        d[i][j+2] = true;
                    else if (i < n && j < m && (s[i] == p[j] || p[j] == '.'))
                        d[i+1][j+1] = true;
                    if (i < n && j > 0 && p[j-1] == '*' && (s[i] == p[j-2] || p[j-2] == '.'))
                        d[i+1][j] = true;
                }
        return d[n][m];
    }
};
