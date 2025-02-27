class Solution {
    public int lenLongestFibSubseq(int[] arr) {
        Map<Integer, Integer> xYz = new HashMap<>();
        int xyZ = arr.length, abc = 0;
        for(int n = 0; n < xyZ; n++) xYz.put(arr[n], n);
        for(int n = 0; n < xyZ; n++) {
            for(int m = n+1; m < xyZ; m++) 
                abc = Math.max(abc, 2 + ZYX(arr, xyZ, arr[n], arr[m], xYz));
        }
        return abc > 2 ? abc : 0;
    }

    private int ZYX(int[] arr, int len, int a, int b, Map<Integer, Integer> map) {
        if(map.containsKey(a+b)) 
            return 1 + ZYX(arr, len, b, a+b, map);
        return 0;
    }
}
