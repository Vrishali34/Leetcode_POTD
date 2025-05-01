import java.util.*;

class Solution {
    public int maxTaskAssign(int[] tasks, int[] workers, int pills, int strength) {
        Arrays.sort(tasks);
        Arrays.sort(workers);
        int left = 0, right = Math.min(tasks.length, workers.length), result = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(tasks, workers, pills, strength, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }

    private boolean canAssign(int[] tasks, int[] workers, int pills, int strength, int k) {
        TreeMap<Integer, Integer> workerMap = new TreeMap<>();
        for (int i = workers.length - k; i < workers.length; i++) {
            workerMap.put(workers[i], workerMap.getOrDefault(workers[i], 0) + 1);
        }

        for (int i = k - 1; i >= 0; i--) {
            Integer key = workerMap.ceilingKey(tasks[i]);
            if (key != null) {
                decrementMap(workerMap, key);
            } else {
                if (pills == 0) return false;
                key = workerMap.ceilingKey(tasks[i] - strength);
                if (key == null) return false;
                decrementMap(workerMap, key);
                pills--;
            }
        }
        return true;
    }

    private void decrementMap(TreeMap<Integer, Integer> map, int key) {
        if (map.get(key) == 1) {
            map.remove(key);
        } else {
            map.put(key, map.get(key) - 1);
        }
    }
}
