import java.util.Arrays;
import java.util.function.IntUnaryOperator;

class Solution {
    private int[] parent; // This array will store the parent of each character's group

    // The find method with path compression
    // It finds the representative (root) of the set that 'i' belongs to.
    private int find(int i) {
        if (parent[i] == i) {
            return i; // 'i' is the root of its own set
        }
        // Path compression: set the parent of 'i' directly to the root
        return parent[i] = find(parent[i]);
    }

    // The union method
    // It merges the sets containing 'x' and 'y'.
    private void union(int x, int y) {
        int rootX = find(x); // Find the root of 'x'
        int rootY = find(y); // Find the root of 'y'

        if (rootX != rootY) { // If they are in different sets
            // To ensure lexicographically smallest equivalent character,
            // the smaller character's root becomes the parent of the larger character's root.
            if (rootX < rootY) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
            }
        }
    }

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        // Initialize the parent array. Each character (0-25 for 'a'-'z')
        // is initially its own parent, meaning each is in its own set.
        parent = new int[26];
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }

        // Iterate through s1 and s2 to establish equivalences
        // For each pair of characters at the same index, union their sets.
        for (int i = 0; i < s1.length(); i++) {
            char char1 = s1.charAt(i);
            char char2 = s2.charAt(i);
            union(char1 - 'a', char2 - 'a'); // Convert char to 0-25 integer index
        }

        // Build the result string
        StringBuilder result = new StringBuilder();
        for (char c : baseStr.toCharArray()) {
            // For each character in baseStr, find its equivalent smallest character
            // (which is the root of its set) and append it to the result.
            result.append((char) (find(c - 'a') + 'a')); // Convert integer index back to char
        }

        return result.toString();
    }
}
