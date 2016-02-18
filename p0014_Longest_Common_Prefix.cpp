/* LeetCode 14. Longest Common Prefix
 *
 * 给定一组字符串，求最长公共前缀。
 *
 * 暴力枚举前缀位数。注意处理特殊情况（空集、空串、长度越界等）。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        int n = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) n = min(n, (int)strs[i].size());
        for (int k = 0; k < n; ++k)
            for (int i = 1; i < strs.size(); ++i)
                if (strs[0][k] != strs[i][k])
                    return strs[0].substr(0, k);
        return strs[0].substr(0, n);
    }
};
