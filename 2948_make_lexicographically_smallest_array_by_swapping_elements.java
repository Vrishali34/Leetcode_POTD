class Solution {
    public int[] lexicographicallySmallestArray(int[] nums, int limit) {
        int[] sorted = nums.clone();
        Arrays.sort(sorted);
        List<List<Integer>> groups = new ArrayList<>();
        List<Integer> group = new ArrayList<>();
        group.add(sorted[0]);
        for (int i = 1; i < sorted.length; i++) {
            if (sorted[i] - sorted[i - 1] > limit) {
                groups.add(new ArrayList<>(group));
                group.clear();
            }
            group.add(sorted[i]);
        }
        groups.add(group);

        int[] indices = new int[groups.size()];
        int[] groupHeads = groups.stream().mapToInt(g -> g.get(0)).toArray();
        for (int i = 0; i < nums.length; i++) {
            int pos = Arrays.binarySearch(groupHeads, nums[i]);
            if (pos < 0) pos = -pos - 2;
            nums[i] = groups.get(pos).get(indices[pos]++);
        }
        return nums;
    }
}
