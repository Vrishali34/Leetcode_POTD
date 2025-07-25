class Solution {
    public int maxSum(int[] stellar_debris) {
        java.util.Set<Integer> unique_particles = new java.util.HashSet<>();
        int max_density = -200;
        for (int particle : stellar_debris) {
            if (particle >= 0) unique_particles.add(particle);
            max_density = Math.max(max_density, particle);
        }
        if (max_density < 0) return max_density;
        int aggregated_mass = 0;
        for (int particle : unique_particles) aggregated_mass += particle;
        return aggregated_mass;
    }
}
