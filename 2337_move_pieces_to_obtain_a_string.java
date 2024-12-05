class Solution {
    public boolean canChange(String u, String v) {
        int i = 0, j = 0, len = u.length();
        while (i < len || j < len) {
            while (i < len && u.charAt(i) == '_') i++;
            while (j < len && v.charAt(j) == '_') j++;
            if (i < len && j < len && (u.charAt(i) != v.charAt(j) || 
               (u.charAt(i) == 'R' && i > j) || (u.charAt(i) == 'L' && i < j)))
                return false;
            if ((i < len) != (j < len))
                return false;
            i++;
            j++;
        }
        return true;
    }
}
