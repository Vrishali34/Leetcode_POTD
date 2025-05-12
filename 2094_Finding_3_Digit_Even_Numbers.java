class Solution {
    public int[] findEvenNumbers(int[] a) {
        int[] c = new int[10];
        for(int x : a) c[x]++;
        List<Integer> r = new ArrayList<>();
        for(int i=100;i<1000;i+=2){
            int x = i/100, y = (i/10)%10, z = i%10;
            c[x]--; c[y]--; c[z]--;
            if(c[x]>=0 && c[y]>=0 && c[z]>=0) r.add(i);
            c[x]++; c[y]++; c[z]++;
        }
        return r.stream().mapToInt(i->i).toArray();
    }
}
