/* LeetCode 12. Integer to Roman
 *
 * 将给定的整数n（1 <= n <= 3999）转换成罗马数字。
 *
 * 1. 根据[罗马数字](https://zh.wikipedia.org/wiki/%E7%BD%97%E9%A9%AC%E6%95%B0%E5%AD%97)的定义进行模拟。
 * 2. 罗马数字也是十进制计数，十进制的每一位的每个数字有唯一的罗马数字记法来表示，据此可以简化逻辑。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    string intToRoman(int num) {
        string ret = "";
        while (num >= 1000) { ret += "M"; num -= 1000; }
        if (num >= 900) { ret += "CM"; num -= 900; }
        if (num >= 500) { ret += "D"; num -= 500; }
        if (num >= 400) { ret += "CD"; num -= 400; }
        while (num >= 100) { ret += "C"; num -= 100; }
        if (num >= 90) { ret += "XC"; num -= 90; }
        if (num >= 50) { ret += "L"; num -= 50; }
        if (num >= 40) { ret += "XL"; num -= 40; }
        while (num >= 10) { ret += "X"; num -= 10; }
        if (num >= 9) { ret += "IX"; num -= 9; }
        if (num >= 5) { ret += "V"; num -= 5; }
        if (num >= 4) { ret += "IV"; num -= 4; }
        while (num >= 1) {ret += "I"; num -= 1; }
        return ret;
    }
};

class Solution2 {
public:
    string intToRoman(int num) {
        vector<string> M {"", "M", "MM", "MMM"};
        vector<string> C {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num / 1000] + C[num / 100 % 10] + X[num / 10 % 10] + I[num % 10];
    }
};
