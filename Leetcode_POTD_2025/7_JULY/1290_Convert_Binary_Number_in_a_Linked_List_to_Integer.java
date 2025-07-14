/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int getDecimalValue(ListNode head) {
        int stellar_val = 0;
        while (head != null) {
            stellar_val = (stellar_val << 1) | head.val;
            head = head.next;
        }
        return stellar_val;
    }
}
