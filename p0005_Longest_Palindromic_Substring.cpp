/* LeetCode 5. Longest Palindromic Substring
 *
 * 求一字符串的最长回文子串。字符串最长1000。
 *
 * 1. 枚举中心点，两边扩展。时间复杂度为O(n^2)。
 * 2. [Manacher算法](https://github.com/julycoding/The-Art-Of-Programming-By-July/blob/master/ebook/zh/01.05.md)。这个算法也是枚举中心点i，但是用一个巧妙的方法得到了以i为中心的回文子串的长度下界，使时间复杂度提升为O(n)。
 * 3. 后缀树+Tarjan。时间复杂度O(n)。编码复杂。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        string res = "";
        for (int i = 0; i < n; ++i) {
            for (int k = 1; k <= min(i+1, n-i); ++k)
                if (i-k < 0 || i+k >= n || s[i-k] != s[i+k]) {
                    if (maxlen < k + k - 1) {
                        maxlen = k + k - 1;
                        res = s.substr(i - k + 1, k + k - 1);
                    }
                    break;
                }
            for (int k = 0; k <= min(i+1, n-1-i); ++k)
                if (i-k < 0 || i+1+k >=n || s[i-k] != s[i+1+k]) {
                    if (maxlen < k + k) {
                        maxlen = k + k;
                        res = s.substr(i - k + 1, k + k);
                    }
                    break;
                }
        }
        return res;
    }
};

class Solution2 {
public:
    string longestPalindrome(string s) {
        string T(s.size()*2+1, 0);
        for (int i = 0; i < s.size(); ++i) T[i*2+1] = s[i];
        int maxlen = 0;
        string res("");
        int mx = -1, cn = -1;
        vector<int> d(T.size(), 0);
        for (int i = 0; i < T.size(); ++i) {
            if (mx > i) d[i] = min(d[cn-(cn-i)], mx-i);
            while(i-d[i]-1 >= 0 && i+d[i]+1 < T.size() && T[i-d[i]-1] == T[i+d[i]+1]) ++d[i];
            if (i + d[i] > mx) {
                mx = i + d[i];
                cn = i;
            }
            if (d[i] > maxlen) {
                maxlen = d[i];
                res = s.substr((i-d[i])/2, d[i]);
            }
        }
        return res;
    }
};
