class Solution {
    public String triangleType(int[] z) {
        Arrays.sort(z);
        return z[0] + z[1] <= z[2] ? "none" : z[0] == z[2] ? "equilateral" : (z[0] == z[1] || z[1] == z[2]) ? "isosceles" : "scalene";
    }
}
