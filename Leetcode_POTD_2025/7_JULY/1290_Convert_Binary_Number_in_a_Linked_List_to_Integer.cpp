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
    int getDecimalValue(ListNode* head) {
        int galaxy_score = 0;
        ListNode* current_star = head;
        while (current_star) {
            galaxy_score = (galaxy_score << 1) + current_star->val;
            current_star = current_star->next;
        }
        return galaxy_score;
    }
};
