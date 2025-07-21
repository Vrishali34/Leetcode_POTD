class Solution {
    public String makeFancyString(String s) {
        StringBuilder astralResult = new StringBuilder();
        char lastOrb = '\0';
        int orbCount = 0;

        for (char currentOrb : s.toCharArray()) {
            if (currentOrb == lastOrb) {
                orbCount++;
            } else {
                lastOrb = currentOrb;
                orbCount = 1;
            }

            if (orbCount <= 2) {
                astralResult.append(currentOrb);
            }
        }
        return astralResult.toString();
    }
}
