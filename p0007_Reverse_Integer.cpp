/* LeetCode 7. Reverse Integer
 *
 * 将一个十进制数翻转，符号不变。如123=>321，-123=>-321。另原题中没说的：若结果溢出输出0。
 *
 * 1. 除/模运算。除了对溢出的处理，还需要注意不同语言对含负数的除法和模运算实现的不同：C/Java是向零取整（余数与被除数相同），对此题来说负数和正数可一样处理；而Python是向下取整，对负数的处理就会麻烦一些。
 * 2. 将数转换为字符串然后倒序输出。需要额外判断一下溢出。对Python来说相对比较方便。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution1 {
public:
    int reverse(int x) {
        long long ans = 0;
        while (x) { ans = ans * 10 + x % 10; x /=10; }
        if (ans < INT_MIN || ans > INT_MAX) return 0;
        return ans;
    }
};
