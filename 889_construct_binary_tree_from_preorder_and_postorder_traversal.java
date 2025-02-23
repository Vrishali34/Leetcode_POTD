class Solution {
    public TreeNode v(int[] p, int[] q) {
        if (p.length == 0) return null;
        TreeNode n = new TreeNode(p[0]);
        if (p.length == 1) return n;
        int d = 0; while (q[d] != p[1]) d++;
        int[] a = java.util.Arrays.copyOfRange(p, 1, d + 2), b = java.util.Arrays.copyOfRange(q, 0, d + 1);
        int[] c = java.util.Arrays.copyOfRange(p, d + 2, p.length), e = java.util.Arrays.copyOfRange(q, d + 1, q.length - 1);
        n.left = v(a, b); n.right = v(c, e);
        return n;
    }
    public TreeNode constructFromPrePost(int[] p, int[] q) { return v(p, q); }
}
