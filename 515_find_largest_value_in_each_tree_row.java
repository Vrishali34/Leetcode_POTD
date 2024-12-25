class Solution {
    public List<Integer> largestValues(TreeNode r) {
        List<Integer> a = new ArrayList<>();
        if (r == null) return a;
        Queue<TreeNode> q = new LinkedList<>();
        q.add(r);
        while (!q.isEmpty()) {
            int b = q.size(), c = Integer.MIN_VALUE;
            while (b-- > 0) {
                TreeNode d = q.poll();
                c = Math.max(c, d.val);
                if (d.left != null) q.add(d.left);
                if (d.right != null) q.add(d.right);
            }
            a.add(c);
        }
        return a;
    }
}
