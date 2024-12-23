public class Solution {
    public int minimumOperations(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int result = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            List<Integer> level = new ArrayList<>();
            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                level.add(node.val);
                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }
            result += countSwaps(level);
        }
        return result;
    }

    private int countSwaps(List<Integer> nums) {
        int n = nums.size(), swaps = 0;
        Integer[] indices = new Integer[n];
        for (int i = 0; i < n; i++) indices[i] = i;

        Arrays.sort(indices, Comparator.comparingInt(nums::get));
        boolean[] visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            if (visited[i] || indices[i] == i) continue;
            int j = i, cycle = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = indices[j];
                cycle++;
            }
            swaps += cycle - 1;
        }
        return swaps;
    }
}
