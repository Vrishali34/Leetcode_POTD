class Solution {
    bool validate_galaxy(long long min_luminosity, int n, int r, long long nova_budget, vector<long long>& base_glow) {
        vector<long long> flux_deltas(n + 1, 0);
        long long budget_spent = 0;
        long long transient_brightness = 0;
        for (int i = 0; i < n; ++i) {
            transient_brightness += flux_deltas[i];
            long long current_glow = base_glow[i] + transient_brightness;
            if (current_glow < min_luminosity) {
                long long needed_flux = min_luminosity - current_glow;
                budget_spent += needed_flux;
                if (budget_spent > nova_budget) return false;
                transient_brightness += needed_flux;
                int end_aura = i + 2 * r;
                if (end_aura + 1 <= n) flux_deltas[end_aura + 1] -= needed_flux;
            }
        }
        return true;
    }
public:
    long long maxPower(vector<int>& star_clusters, int aura_radius, int k) {
        int n = star_clusters.size();
        long long nova_budget = k;
        vector<long long> base_glow(n);
        long long current_window_sum = 0;
        for (int i = 0; i <= aura_radius && i < n; ++i) current_window_sum += star_clusters[i];
        base_glow[0] = current_window_sum;
        for (int i = 1; i < n; ++i) {
            current_window_sum += (i + aura_radius < n ? star_clusters[i + aura_radius] : 0);
            current_window_sum -= (i - aura_radius - 1 >= 0 ? star_clusters[i - aura_radius - 1] : 0);
            base_glow[i] = current_window_sum;
        }
        
        long long min_flux = 0, max_flux = 0;
        for (int s : star_clusters) max_flux += s;
        max_flux += nova_budget;
        long long peak_flux = 0;
        
        while (min_flux <= max_flux) {
            long long mid_flux = min_flux + (max_flux - min_flux) / 2;
            if (validate_galaxy(mid_flux, n, aura_radius, nova_budget, base_glow)) {
                peak_flux = mid_flux;
                min_flux = mid_flux + 1;
            } else {
                max_flux = mid_flux - 1;
            }
        }
        return peak_flux;
    }
};
