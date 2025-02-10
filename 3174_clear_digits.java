class Solution {
    public String clearDigits(String q) {
        Stack<Character> r = new Stack<>();
        for (char t : q.toCharArray()) if (Character.isDigit(t)) { if (!r.isEmpty()) r.pop(); } else r.push(t);
        StringBuilder p = new StringBuilder();
        while (!r.isEmpty()) p.insert(0, r.pop());
        return p.toString();
    }
}
