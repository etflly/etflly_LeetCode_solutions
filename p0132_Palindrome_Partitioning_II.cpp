/* LeetCode 132. Palindrome Partitioning II
 *
 * 给定字符串s，将其划分为若干字串，使每个字串都是回文串。求最小划分次数
 *
 * DP
 * d[i]表示s[0..i-1]的最小划分次数。
 * 枚举中心点i扩展回文子串：
 * 1. 当i为中心点时，枚举半径k=[0, min(i, n-i-1)]，若扩展成功（s[i-k] == s[i+k]），用d[i-k]+1来更新d[i+k+1]（从i-k前切一刀）
 * 2. 当(i, i+1)为中心点时，枚举半径k=[0, min(i, n-i-2)]，若扩展成功（s[i-k] == s[i+1+k]），用d[i-k]+1来更新d[i+k+2]（从i-k前切一刀）
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> d(n+1, INT_MAX);
        d[0] = -1;
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k <= min(i, n-i-1); ++k)
                if (s[i-k] == s[i+k]) d[i+k+1] = min(d[i+k+1], d[i-k]+1);
                else break;
            for (int k = 0; k <= min(i, n-i-2); ++k)
                if (s[i-k] == s[i+1+k]) d[i+k+2] = min(d[i+k+2], d[i-k]+1);
                else break;
        }
        return d[n];
    }
};
