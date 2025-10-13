import java.util.*;

class Solution {
    private String transform_star_dust(String particle) {
        char[] atoms = particle.toCharArray();
        Arrays.sort(atoms);
        return new String(atoms);
    }

    public List<String> removeAnagrams(String[] words) {
        List<String> nova_array = new ArrayList<>();
        String previous_cosmic_signature = "";

        for (String current_star : words) {
            String current_signature = transform_star_dust(current_star);
            if (!current_signature.equals(previous_cosmic_signature)) {
                nova_array.add(current_star);
                previous_cosmic_signature = current_signature;
            }
        }
        return nova_array;
    }
}
