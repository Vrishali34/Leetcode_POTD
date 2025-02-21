import java.util.*;

class FindElements {
    Set<Integer> vals = new HashSet<>();

    public FindElements(TreeNode root) {
        fix(root, 0);
    }

    private void fix(TreeNode node, int v) {
        if (node == null) return;
        node.val = v; vals.add(v);
        fix(node.left, 2 * v + 1);
        fix(node.right, 2 * v + 2);
    }

    public boolean find(int target) {
        return vals.contains(target);
    }
}
