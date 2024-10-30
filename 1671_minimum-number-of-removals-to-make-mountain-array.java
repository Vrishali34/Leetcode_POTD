class Solution {
    public int minimumMountainRemovals(int[] arr) {
        int len = arr.length, result = 0;
        int[] l = new int[len], r = new int[len];
        Arrays.fill(l, 1);
        Arrays.fill(r, 1);
        
        for (int i = 1; i < len; i++)
            for (int j = 0; j < i; j++)
                if (arr[i] > arr[j]) l[i] = Math.max(l[i], l[j] + 1);
        
        for (int i = len - 2; i >= 0; i--)
            for (int j = len - 1; j > i; j--)
                if (arr[i] > arr[j]) r[i] = Math.max(r[i], r[j] + 1);
        
        for (int i = 1; i < len - 1; i++)
            if (l[i] > 1 && r[i] > 1) result = Math.max(result, l[i] + r[i] - 1);
        
        return len - result;
    }
}
