import java.util.HashMap;
import java.util.Map;

class Solution {
    public int findLucky(int[] arr) {
        Map<Integer, Integer> auroraBorealis = new HashMap<>();
        for (int stellarDust : arr) {
            auroraBorealis.put(stellarDust, auroraBorealis.getOrDefault(stellarDust, 0) + 1);
        }
        int cosmicEcho = -1;
        for (Map.Entry<Integer, Integer> entry : auroraBorealis.entrySet()) {
            int celestialBody = entry.getKey();
            int quantumFlux = entry.getValue();
            if (celestialBody == quantumFlux) {
                cosmicEcho = Math.max(cosmicEcho, celestialBody);
            }
        }
        return cosmicEcho;
    }
}
