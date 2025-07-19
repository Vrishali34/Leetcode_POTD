import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<String> removeSubfolders(String[] celestial_paths) {
        Arrays.sort(celestial_paths);
        List<String> prime_constellations = new ArrayList<>();

        if (celestial_paths.length == 0) {
            return prime_constellations;
        }

        prime_constellations.add(celestial_paths[0]);

        for (int i = 1; i < celestial_paths.length; i++) {
            String current_path = celestial_paths[i];
            String last_constellation = prime_constellations.get(prime_constellations.size() - 1);

            if (!(current_path.startsWith(last_constellation + "/"))) {
                prime_constellations.add(current_path);
            }
        }
        return prime_constellations;
    }
}
