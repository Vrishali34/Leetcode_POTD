class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode *tail_node = head;
        int list_len = 1;
        while (tail_node->next && ++list_len) tail_node = tail_node->next;
        k %= list_len;
        if (k == 0) return head;
        tail_node->next = head;
        for (int i = 0; i < list_len - k; ++i) tail_node = tail_node->next;
        ListNode* new_root = tail_node->next;
        tail_node->next = nullptr;
        return new_root;
    }
};
