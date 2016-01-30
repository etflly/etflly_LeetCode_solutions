/* LeetCode 3. Longest Substring Without Repeating Characters
 *
 * 给定一个字符串，求它的不含重复字符的最长字串的长度。
 *
 * 维护一个“滑动窗口”。并用vis[c]数组表示上一次看到字符c是在什么位置。
 * 遍历字符串，窗口右端始终是当前字符。如果vis[s[i]]在当前窗口之内，说明遇到了重复字符，那么将窗口左端移动到vis[s[i]]+1。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> vis(256, -1);
        int ans = 0, now = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (vis[s[i]] < i - now) ans = max(ans, ++now);
            else now = i - vis[s[i]];
            vis[s[i]] = i;
        }
        return ans;
    }
};
