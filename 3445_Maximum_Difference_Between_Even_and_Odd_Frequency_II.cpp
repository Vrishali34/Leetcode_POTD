class Solution {
public:
    int maxDifference(string f, int h) {
        int r = -1e9, s = f.size();

        // Try all pairs of different digits (0-4)
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j) 
                if (i != j) {
                    int x = 0, y = 0;     // Current frequency of i and j
                    int px = 0, py = 0;   // Frequency of i and j in window start
                    int l = -1;           // Window left bound
                    int T[4];             // State table for (px parity, py parity)
                    fill(T, T + 4, 1e9);  // Initialize all states to large number

                    for (int z = 0; z < s; ++z) {
                        // Extend window: update freq of i and j
                        x += f[z] == '0' + i;
                        y += f[z] == '0' + j;

                        // Shrink window from left if it satisfies size and j appears ≥ 2 times
                        while (z - l >= h && y - py >= 2) {
                            int key = (px & 1) << 1 | (py & 1); // encode parity state
                            T[key] = min(T[key], px - py);     // track min (px - py) for state
                            ++l;
                            px += f[l] == '0' + i;
                            py += f[l] == '0' + j;
                        }

                        // Check opposite parity of x & y to satisfy odd/even constraint
                        int pkey = ((x & 1) ^ 1) << 1 | (y & 1);
                        if (T[pkey] != 1e9)
                            r = max(r, x - y - T[pkey]);  // Update max difference
                    }
                }

        return r;
    }
};
