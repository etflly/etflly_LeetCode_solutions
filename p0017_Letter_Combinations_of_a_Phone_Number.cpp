/* LeetCode 17. Letter Combinations of a Phone Number
 *
 * 给一个数字序列（不含01）a[n]，求用这个数字序列在手机键盘上敲可以产生哪些字母序列。
 *
 * 1. 每个数字可以表示3-4位字母，可以枚举一个n位的不定进制数，来表示每个数字遍历到了哪一个字母。
 * 2. 按位扩展字符串。每扩展一位，将所有已有字符串后面分别跟上这位数字能表示的所有字母，若已有k个字符串，这位数字能表示t个数，扩展后共有k*t个字符串。
 * 3. 递归。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return vector<string>(0);
        vector<string> cp {
            " ",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> ret(0);
        vector<int> d(n);
        for (int i = 0; i < n; ++i) d[i] = digits[i] - '0';
        vector<int> mx(n);
        for (int i = 0; i < n; ++i) mx[i] = cp[d[i]].size();
        vector<int> t(n, 0);
        while (t[0] < mx[0]) {
            string now = "";
            for (int i = 0; i < n; ++i) now += cp[d[i]][t[i]];
            ret.push_back(now);
            for (int k = n - 1; k >= 0; --k)
                if (++t[k] < mx[k]) break;
                else if (k > 0) t[k] = 0;
        }
        return ret;
    }
};

class Solution2 {
public:
    const vector<string> cp{
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) return vector<string>(0);
        vector<int> d(n);
        for (int i = 0; i < n; ++i) d[i] = digits[i] - '0';
        vector<string> ret(1, ""), tmp(0);
        for (int i = 0; i < n; ++i) {
            tmp.clear();
            tmp.swap(ret);
            for (int k = 0; k < tmp.size(); ++k)
                for (int j = 0; j < cp[d[i]].size(); ++j)
                    ret.push_back(tmp[k] + cp[d[i]][j]);
        }
        return ret;
    }
};

class Solution3 {
public:
    const vector<string> cp {
        " ",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    
    int n;
    vector<int> d;
    
    vector<string> ret;
    
    string now;
    
    void dfs(int i) {
        if (i == n) {
            ret.push_back(now);
            return;
        }
        for (int k = 0; k < cp[d[i]].size(); ++k) {
            now.push_back(cp[d[i]][k]);
            dfs(i+1);
            now.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if (n == 0) return vector<string>(0);
        for (int i = 0; i < n; ++i) d.push_back(digits[i] - '0');
        
        dfs(0);
        
        return ret;
    }
};
