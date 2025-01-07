class Solution {
    public List<String> stringMatching(String[] x) {
        List<String> y = new ArrayList<>();
        int z = x.length;
        for (int a = 0; a < z; a++) 
            for (int b = 0; b < z; b++) 
                if (a != b && x[b].contains(x[a])) {
                    y.add(x[a]);
                    break;
                }
        return y;
    }
}
