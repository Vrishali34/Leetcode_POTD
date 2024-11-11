class Solution {
    private int[] getPrimeArray() {
        int[] primes = new int[1002];
        int idx = 0;
        boolean[] flag = new boolean[1002];
        Arrays.fill(flag, true);
        flag[1] = false;
        for (int i = 2; i < 1002; i++) {
            if (flag[i]) {
                primes[idx++] = i;
                for (int j = i * i; j < 1002; j += i)
                    flag[j] = false;
            }
        }
        return Arrays.copyOf(primes, idx);
    }

    public boolean primeSubOperation(int[] nums) {
        int[] primes = getPrimeArray();
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) continue;
            int diff = nums[i] - nums[i + 1];
            int pos = Arrays.binarySearch(primes, diff + 1);
            if (pos < 0) pos = -pos - 1;
            if (pos >= primes.length || primes[pos] >= nums[i]) return false;
            nums[i] -= primes[pos];
        }
        return true;
    }
}
