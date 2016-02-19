/* LeetCode 24. Swap Nodes in Pairs
 *
 * 将一个链表每两个数字一交换。只允许使用常数级别空间。
 *
 * 基础的链表操作。
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *h1 = head, *h2 = head->next;
        ListNode *h3 = h1;
        head = h2;
        while (h1 && h2) {
            h3->next = h2; h1->next = h2->next; h2->next = h1;
            h3 = h1; h1 = h1->next; if (h1) h2 = h1->next;
        }
        return head;
    }
};
