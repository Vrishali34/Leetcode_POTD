class Solution {
    public int colorTheGrid(int m, int n) {
        final int MOD = 1_000_000_007;
        List<int[]> patterns = new ArrayList<>();
        generatePatterns(m, 0, new int[m], patterns);

        Map<String, Integer> patternToIndex = new HashMap<>();
        for (int i = 0; i < patterns.size(); i++) {
            patternToIndex.put(Arrays.toString(patterns.get(i)), i);
        }

        int size = patterns.size();
        int[][] transitions = new int[size][];
        for (int i = 0; i < size; i++) {
            List<Integer> compatible = new ArrayList<>();
            for (int j = 0; j < size; j++) {
                if (isCompatible(patterns.get(i), patterns.get(j))) {
                    compatible.add(j);
                }
            }
            transitions[i] = compatible.stream().mapToInt(k -> k).toArray();
        }

        int[] dp = new int[size];
        Arrays.fill(dp, 1);
        for (int col = 1; col < n; col++) {
            int[] next = new int[size];
            for (int i = 0; i < size; i++) {
                for (int j : transitions[i]) {
                    next[j] = (next[j] + dp[i]) % MOD;
                }
            }
            dp = next;
        }

        int result = 0;
        for (int count : dp) {
            result = (result + count) % MOD;
        }
        return result;
    }

    private void generatePatterns(int m, int row, int[] current, List<int[]> patterns) {
        if (row == m) {
            patterns.add(Arrays.copyOf(current, m));
            return;
        }
        for (int color = 0; color < 3; color++) {
            if (row == 0 || current[row - 1] != color) {
                current[row] = color;
                generatePatterns(m, row + 1, current, patterns);
            }
        }
    }

    private boolean isCompatible(int[] a, int[] b) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }
}
