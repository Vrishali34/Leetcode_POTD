class Solution {
    public boolean canMakeSubsequence(String strA, String strB) {
        int idxA = 0, idxB = 0;
        while (idxA < strA.length() && idxB < strB.length()) {
            if (strA.charAt(idxA) == strB.charAt(idxB) || strA.charAt(idxA) + 1 == strB.charAt(idxB) || (strA.charAt(idxA) == 'z' && strB.charAt(idxB) == 'a'))
                idxB++;
            idxA++;
        }
        return idxB == strB.length();
    }
}
