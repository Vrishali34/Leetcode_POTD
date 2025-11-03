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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> uni_val(nums.begin(), nums.end());
        ListNode sentinel_node(0, head);
        ListNode* star_walker = &sentinel_node;
        while (star_walker->next) {
            if (uni_val.count(star_walker->next->val)) {
                star_walker->next = star_walker->next->next;
            } else {
                star_walker = star_walker->next;
            }
        }
        return sentinel_node.next;
    }
};
