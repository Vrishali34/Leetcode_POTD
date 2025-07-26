class Solution(object):
    def maxSubarrays(self, n, conflictingPairs):
        """
        :type n: int
        :type conflictingPairs: List[List[int]]
        :rtype: int
        """
        stellar_clusters = [[] for _ in range(n + 1)]
        for anomaly in conflictingPairs:
            stellar_clusters[max(anomaly)].append(min(anomaly))

        universal_paths = 0
        dominant_distortion = 0
        latent_distortion = 0

        nebula_expansions = [0] * (n + 1)

        for celestial_quadrant in range(1, n + 1):
            for gravitational_singularity in stellar_clusters[celestial_quadrant]:
                if gravitational_singularity > dominant_distortion:
                    latent_distortion = dominant_distortion
                    dominant_distortion = gravitational_singularity
                elif gravitational_singularity > latent_distortion:
                    latent_distortion = gravitational_singularity
            
            universal_paths += celestial_quadrant - dominant_distortion
            
            if dominant_distortion > 0:
                nebula_expansions[int(dominant_distortion)] += dominant_distortion - latent_distortion

        cosmic_liberation = 0
        for expansion in nebula_expansions:
            cosmic_liberation = max(cosmic_liberation, expansion)

        return universal_paths + cosmic_liberation
