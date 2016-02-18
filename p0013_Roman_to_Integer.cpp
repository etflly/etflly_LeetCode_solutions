/* LeetCode 13. Roman to Integer
 *
 * 将给定的罗马数字转换成整数n（1 <= n <= 3999）。
 *
 * 根据[罗马数字](https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97)的定义进行模拟。
 * 1. 严格按照定义进行解码，好处是如果需要可以判断输入是否合法（虽然本题每要求）。
 * 2. 由于本题保证输入合法，可以仅按照读数的方法来进行转换，即当前位比后一位小则减这个数，否则加这个数
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    int romanToInt(string s) {
        vector<char> H {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        vector<char> M {'C', 'C', 'X', 'X', 'I', 'I', '\0'};
        vector<int> V {1000, 500, 100, 50, 10, 5, 1};
        vector<int> U {900, 400, 90, 40, 9, 4, 0};
        int ret = 0;
        int i = 0, k = 0;
        while (i < s.size()) {
            if (s[i] == H[k]) { ret += V[k]; ++i; }
            else if (i + 1 < s.size() && s[i] == M[k] && s[i+1] == H[k]) { ret += U[k]; ++++i; }
            else ++k;
        }
        return ret;
    }
};

class Solution2 {
public:
    int romanToInt(string s) {
        map<char, int> m {
            {'M', 1000},
            {'D', 500},
            {'C', 100},
            {'L', 50},
            {'X', 10},
            {'V', 5},
            {'I', 1}
        };
        int ret = m[s[s.size()-1]];
        for (int i = 0; i < s.size()-1; ++i) {
            if (m[s[i]] < m[s[i+1]]) ret -= m[s[i]];
            else ret += m[s[i]];
        }
        return ret;
    }
};
