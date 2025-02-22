class Solution {
    public TreeNode recoverFromPreorder(String s) {
        List<TreeNode> stk = new ArrayList<>();
        int i = 0;
        
        while (i < s.length()) {
            int d = 0, v = 0;
            
            while (i < s.length() && s.charAt(i) == '-') {
                d++;
                i++;
            }
            
            while (i < s.length() && Character.isDigit(s.charAt(i))) {
                v = v * 10 + (s.charAt(i++) - '0');
            }
            
            TreeNode n = new TreeNode(v);
            
            if (d == stk.size()) {
                if (!stk.isEmpty()) stk.get(stk.size() - 1).left = n;
            } else {
                stk.get(d - 1).right = n;
                while (stk.size() > d) stk.remove(stk.size() - 1);
            }
            
            stk.add(n);
        }
        
        return stk.get(0);
    }
}
