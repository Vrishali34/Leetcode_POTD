/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;
        ListNode* lead_node = head;
        ListNode* lag_node = head;
        ListNode* pre_lag = nullptr;
        while (lead_node && lead_node->next) {
            pre_lag = lag_node;
            lag_node = lag_node->next;
            lead_node = lead_node->next->next;
        }
        pre_lag->next = lag_node->next;
        delete lag_node;
        return head;
    }
};
