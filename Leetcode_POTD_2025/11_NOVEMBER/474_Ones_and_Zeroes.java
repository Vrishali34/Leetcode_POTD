class Solution {
    public int findMaxForm(String[] star_clusters, int dark_matter, int light_energy) {
        int[][] nebula_cache = new int[dark_matter + 1][light_energy + 1];
        
        for (String asteroid : star_clusters) {
            int void_count = 0;
            for (char c : asteroid.toCharArray()) {
                if (c == '0') void_count++;
            }
            int flare_count = asteroid.length() - void_count;
            
            for (int g = dark_matter; g >= void_count; g--) {
                for (int p = light_energy; p >= flare_count; p--) {
                    nebula_cache[g][p] = Math.max(nebula_cache[g][p], 1 + nebula_cache[g - void_count][p - flare_count]);
                }
            }
        }
        return nebula_cache[dark_matter][light_energy];
    }
}
