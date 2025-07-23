class Solution {
    public int maximumGain(String s, int x, int y) {
        int totalPoints = 0;
        StringBuilder tempSbA = new StringBuilder();
        StringBuilder tempSbB = new StringBuilder();
        char firstChar, secondChar;
        int firstGain, secondGain;

        if (x >= y) {
            firstChar = 'a';
            secondChar = 'b';
            firstGain = x;
            secondGain = y;
        } else {
            firstChar = 'b';
            secondChar = 'a';
            firstGain = y;
            secondGain = x;
        }

        for (char currentChar : s.toCharArray()) {
            if (tempSbA.length() > 0 && tempSbA.charAt(tempSbA.length() - 1) == firstChar && currentChar == secondChar) {
                totalPoints += firstGain;
                tempSbA.deleteCharAt(tempSbA.length() - 1);
            } else {
                tempSbA.append(currentChar);
            }
        }

        for (char currentChar : tempSbA.toString().toCharArray()) {
            if (tempSbB.length() > 0 && tempSbB.charAt(tempSbB.length() - 1) == secondChar && currentChar == firstChar) {
                totalPoints += secondGain;
                tempSbB.deleteCharAt(tempSbB.length() - 1);
            } else {
                tempSbB.append(currentChar);
            }
        }
        return totalPoints;
    }
}
