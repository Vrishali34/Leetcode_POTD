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
    int pairSum(ListNode* head) {
        ListNode* lead_ptr = head;
        ListNode* mid_ptr = head;
        while (lead_ptr && lead_ptr->next) {
            mid_ptr = mid_ptr->next;
            lead_ptr = lead_ptr->next->next;
        }
        ListNode* rev_curr = mid_ptr;
        ListNode* rev_prev = nullptr;
        while (rev_curr) {
            ListNode* next_node = rev_curr->next;
            rev_curr->next = rev_prev;
            rev_prev = rev_curr;
            rev_curr = next_node;
        }
        int max_twin_sum = 0;
        ListNode* left_side = head;
        ListNode* right_side = rev_prev;
        while (right_side) {
            max_twin_sum = max(max_twin_sum, left_side->val + right_side->val);
            left_side = left_side->next;
            right_side = right_side->next;
        }
        return max_twin_sum;
    }
};
