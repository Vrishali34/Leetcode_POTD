class Solution { 
    public int minOperations(int[] j, int q) { 
        PriorityQueue<Long> u = new PriorityQueue<>(); 
        for (int x : j) u.add((long) x);
        int c = 0; 
        while (u.peek() < q) { 
            u.add(u.poll() * 2 + u.poll()); 
            c++; 
        } 
        return c; 
    }
}
