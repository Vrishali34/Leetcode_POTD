import java.util.*;

class NumberContainers {
    Map<Integer, Integer> idxMap = new HashMap<>();
    Map<Integer, TreeSet<Integer>> numMap = new HashMap<>();

    public void change(int index, int number) {
        if (idxMap.containsKey(index)) {
            int prev = idxMap.get(index);
            if (prev == number) return; // Avoid redundant removal
            numMap.get(prev).remove(index);
            if (numMap.get(prev).isEmpty()) numMap.remove(prev);
        }
        idxMap.put(index, number);
        numMap.computeIfAbsent(number, k -> new TreeSet<>()).add(index);
    }

    public int find(int number) {
        return numMap.containsKey(number) ? numMap.get(number).first() : -1;
    }
}
