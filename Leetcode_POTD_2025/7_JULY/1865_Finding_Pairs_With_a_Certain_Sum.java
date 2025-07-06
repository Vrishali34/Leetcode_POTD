class FindSumPairs {
    int[] blade, arrow;
    Map<Integer, Integer> quiver = new HashMap<>();

    public FindSumPairs(int[] b, int[] a) {
        blade = b;
        arrow = a;
        for (int x : a) quiver.put(x, quiver.getOrDefault(x, 0) + 1);
    }

    public void add(int i, int v) {
        quiver.put(arrow[i], quiver.get(arrow[i]) - 1);
        arrow[i] += v;
        quiver.put(arrow[i], quiver.getOrDefault(arrow[i], 0) + 1);
    }

    public int count(int val) {
        int sum = 0;
        for (int b : blade) sum += quiver.getOrDefault(val - b, 0);
        return sum;
    }
}
