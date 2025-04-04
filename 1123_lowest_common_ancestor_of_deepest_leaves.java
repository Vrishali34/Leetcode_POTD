class Solution {
    public TreeNode lcaDeepestLeaves(TreeNode r) {
        return f(r, d(r));
    }
    private int d(TreeNode n) {
        return n == null ? 0 : 1 + Math.max(d(n.left), d(n.right));
    }
    private TreeNode f(TreeNode n, int h) {
        if (n == null) return null;
        int l = d(n.left), r = d(n.right);
        return l == r ? n : f(l > r ? n.left : n.right, h - 1);
    }
}
