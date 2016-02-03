/* LeetCode 9. Palindrome Number
 *
 * 判断一个整数转换成字符串后是否回文。
 *
 * 有2种思路：直接翻转整数，或者将整数转换成字符串。后者需要使用额外空间，故第一种较好。但需要注意一些问题：
 * 1. 负数不回文
 * 2. 翻转数可能溢出
 * 为避免溢出有几个可行的处理方案：
 * 1. 用64位整数存储
 * 2. 转换时少处理一位，最后一位单独判断。
 * 3. 转换一半的位数。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long xx = x, y = 0;
        for (; xx; xx /= 10) y = y * 10 + xx % 10;
        return x == y;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int xx = x, y = 0;
        for (; xx >= 10; xx /= 10) y = y * 10 + xx % 10;
        return y == x / 10 && xx == x % 10;
    }
};

class Solution3 {
public:
    bool isPalindrome(int x) {
        if (x < 0 || x != 0 && x % 10 == 0) return false;
        int y = 0;
        for (; x > y; x /= 10) y = y * 10 + x % 10;
        return y == x || y / 10 == x;
    }
};
