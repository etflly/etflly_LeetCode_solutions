/* LeetCode 25. Reverse Nodes in k-Group
 *
 * 将一个链表每k个数字一翻转。只允许使用常数级别空间。
 *
 * 此题为p24的扩展，并不困难。每k个元素一处理，让一个指针先走到第k个元素，然后从头开始改变next值即可。
 *
 * Author: etflly
 * Website: etflly.me
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pre = new ListNode(0);
        pre->next = head;
        head = pre;
        ListNode *pend, *pbegin, *ptmp0, *ptmp1;
        while(pre) {
            pbegin = pend = pre->next;
            for (int i = 1; i < k; ++i)
                if (pend) pend = pend->next;
                else break;
            if (!pend) break;
            ptmp1 = pend->next;
            pre->next = pend;
            pre = pbegin;
            while (pbegin != pend) {
                ptmp0 = pbegin->next;
                pbegin->next = ptmp1;
                ptmp1 = pbegin;
                pbegin = ptmp0;
            }
            pbegin->next = ptmp1;
        }
        pre = head; head = pre->next; delete pre;
        return head;
    }
};
