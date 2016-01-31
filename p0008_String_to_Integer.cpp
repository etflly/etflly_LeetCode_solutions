/* LeetCode 8. String to Integer
 *
 * 实现atoi函数，即字符串转换为整数。
 *
 * 几种特殊情况：
 * 1. 忽略首部空白字符，其余视为非法字符。
 * 2. 只接受第一个出现的正负号，其余视为非法字符。
 * 3. 转换过程碰到任何非数字字符（非法字符）就视为转换完成，输出现有答案。
 * 4. 若结果溢出，视正负输出INT_MIN或INT_MAX。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (isspace(s[i])) ++i;
        bool minus = false;
        long long ans = 0;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-') minus = true;
            ++i;
        }
        s = s.substr(i);
        for (i = 0; i < s.size(); ++i) {
            if (s[i] < '0' || s[i] > '9') return minus ? -ans : ans;
            ans = ans * 10 + s[i] - '0';
            if (minus) {
                if (-ans < INT_MIN) return INT_MIN;
            }
            else {
                if (ans > INT_MAX) return INT_MAX;
            }
        }
        return minus ? -ans : ans;
    }
};
