/* LeetCode 23. Merge k Sorted Lists
 *
 * 合并n个有序链表。
 *
 * 用优先队列取最小元素。c++的priority_queue和make_heap的堆都是大根堆，priority_queue自定义比较器需要传入重载了()的struct，而make_heap传入比较函数即可。
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
    struct cmp {
        bool operator() (ListNode* a, ListNode* b) {
            if (a==NULL) return false;
            if (b==NULL) return true;
            return a->val > b->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<ListNode*, vector<ListNode*>, cmp> a;
        for (int i = 0; i < n; ++i) if (lists[i]) a.push(lists[i]);
        ListNode *head = new ListNode(0);
        ListNode *now = head;
        while (!a.empty()) {
            now = now->next = a.top();
            a.pop();
            if (now->next) a.push(now->next);
        }
        now = head;
        head = head->next;
        delete now;
        return head;
    }
};
