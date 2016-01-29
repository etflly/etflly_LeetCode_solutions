/* LeetCode 29. Divide Two Integers
 *
 * 实现整数除法，不使用乘、除、模运算。溢出输出INT_MAX。
 *
 * 对除数和被除数取绝对值后，模拟二进制除法，再添加符号位。注意2点：
 * 1. 溢出有2种情况：除数为0；INT_MIN / (-1)。
 * 2. INT_MIN取绝对值超出32位整数范围，要用64位整数存储。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        if (b == 0 || a == INT_MIN && b == -1) return INT_MAX;
        bool minus = false;
        if (a < 0) { minus = !minus; a = - a; }
        if (b < 0) { minus = !minus; b = - b; }
        int ans = 0;
        long long rem = 0;
        for (int k = 31; k >= 0; --k) {
            rem = rem << 1 | (a >> k & 1);
            ans <<= 1;
            if (rem >= b) { rem -= b; ans++; }
        }
        return minus ? -ans : ans;
    }
};
