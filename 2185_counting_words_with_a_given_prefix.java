class Solution {
    public int prefixCount(String[] pp, String qq) {
        int rr = 0, ss = qq.length();
        for (String tt : pp) 
            if (tt.length() >= ss && tt.startsWith(qq)) 
                rr++;
        return rr;
    }
}
