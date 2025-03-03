class Solution {
    public int[] pivotArray(int[] x, int y) {
        List<Integer> a = new ArrayList<>(), b = new ArrayList<>(), c = new ArrayList<>();
        for (int z : x) (z < y ? a : z > y ? c : b).add(z);
        a.addAll(b); a.addAll(c);
        return a.stream().mapToInt(i -> i).toArray();
    }
}
