class Solution {
    public String removeOccurrences(String a, String b) {
        StringBuilder q = new StringBuilder();
        int n = b.length();
        for (char c : a.toCharArray()) {
            q.append(c);
            if (q.length() >= n && q.substring(q.length() - n).equals(b)) 
                q.setLength(q.length() - n);
        }
        return q.toString();
    }
}
