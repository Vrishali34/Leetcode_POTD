class Solution {
    public int[] resultsArray(int[] arr, int len) {
        int n = arr.length, cnt = 1;
        int[] out = new int[n - len + 1];
        Arrays.fill(out, -1);
        for (int i = 1; i < len; i++) 
            cnt = (arr[i] == arr[i - 1] + 1) ? cnt + 1 : 1;
        if (cnt == len) out[0] = arr[len - 1];
        for (int left = 1, right = len; right < n; left++, right++) {
            cnt = (arr[right] == arr[right - 1] + 1) ? cnt + 1 : 1;
            if (cnt >= len) out[left] = arr[right];
        }
        return out;
    }
}
