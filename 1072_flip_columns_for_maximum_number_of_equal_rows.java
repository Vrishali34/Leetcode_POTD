class Solution {
    public int maxEqualRowsAfterFlips(int[][] n) {
        var l = new HashMap<String, Integer>();
        for (var e : n) {
            var j = new StringBuilder();
            for (var q : e) j.append(q ^ e[0]);
            l.merge(j.toString(), 1, Integer::sum);
        }
        return l.values().stream().reduce(0, Math::max);
    }
}
