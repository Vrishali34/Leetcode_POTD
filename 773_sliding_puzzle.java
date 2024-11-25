class Solution {
    public int slidingPuzzle(int[][] b) {
        StringBuilder s = new StringBuilder();
        String target = "123450";
        for (int[] row : b) for (int val : row) s.append(val);
        Queue<Pair<String, Integer>> q = new LinkedList<>();
        q.add(new Pair<>(s.toString(), 0));
        Set<String> v = new HashSet<>();
        v.add(s.toString());
        while (!q.isEmpty()) {
            Pair<String, Integer> p = q.poll();
            String curr = p.getKey();
            int steps = p.getValue();
            if (curr.equals(target)) return steps;
            int zeroIndex = curr.indexOf('0');
            for (int move : new int[]{-3, 3, -1, 1}) {
                int ni = zeroIndex + move;
                if (ni < 0 || ni >= 6 || (zeroIndex % 3 == 2 && move == 1) || (zeroIndex % 3 == 0 && move == -1)) continue;
                char[] arr = curr.toCharArray();
                char temp = arr[zeroIndex];
                arr[zeroIndex] = arr[ni];
                arr[ni] = temp;
                String newStr = new String(arr);
                if (v.add(newStr)) q.add(new Pair<>(newStr, steps + 1));
            }
        }
        return -1;
    }
}
