class Solution {
    public TreeNode reverseOddLevels(TreeNode z) {
        Queue<TreeNode> y = new LinkedList<>();
        y.add(z);
        boolean x = false;
        while (!y.isEmpty()) {
            List<TreeNode> w = new ArrayList<>();
            for (int v = y.size(); v-- > 0;) {
                TreeNode u = y.poll();
                if (u == null) continue;
                w.add(u);
                y.add(u.left);
                y.add(u.right);
            }
            if (x) {
                for (int t = 0, s = w.size() - 1; t < s; t++, s--) {
                    int tmp = w.get(t).val;
                    w.get(t).val = w.get(s).val;
                    w.get(s).val = tmp;
                }
            }
            x = !x;
        }
        return z;
    }
}
