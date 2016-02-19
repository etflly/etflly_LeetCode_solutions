/* LeetCode 20. Valid Parentheses
 *
 * 判断"()[]{}"三种括号匹配。
 *
 * 单纯栈的应用。注意取栈顶元素前判断栈是否为空。
 *
 * Author: etflly
 * Website: etflly.me
 */

class Solution {
public:
    bool isValid(string s) {
        stack<char> h;
        for (int i = 0; i < s.size(); ++i)
            switch (s[i]) {
                case '(': case '{': case '[':
                    h.push(s[i]);
                    break;
                case ')':
                    if (h.empty() || h.top() != '(') return false;
                    else h.pop();
                    break;
                case '}':
                    if (h.empty() || h.top() != '{') return false;
                    else h.pop();
                    break;
                case ']':
                    if (h.empty() || h.top() != '[') return false;
                    else h.pop();
                    break;
                default:
                    return false;
            }
        return h.empty();
    }
};
