import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.List;

class TaskManager {

    private Map<Integer, int[]> taskDetails;
    private PriorityQueue<int[]> taskQueue;
    
    public TaskManager(List<List<Integer>> tasks) {
        taskDetails = new HashMap<>();
        
        taskQueue = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                if (a[0] != b[0]) {
                    return b[0] - a[0];
                }
                return b[1] - a[1];
            }
        });
        
        for (List<Integer> task : tasks) {
            add(task.get(0), task.get(1), task.get(2));
        }
    }
    
    public void add(int userId, int taskId, int priority) {
        int[] taskInfo = new int[]{userId, taskId, priority};
        taskDetails.put(taskId, taskInfo);
        // Add {priority, taskId} to the priority queue
        taskQueue.add(new int[]{priority, taskId});
    }
    
    public void edit(int taskId, int newPriority) {
        int[] taskInfo = taskDetails.get(taskId);
        taskInfo[2] = newPriority;
        // The old entry is now "stale". We add a new, valid entry to the queue.
        // The execTop method will handle skipping the stale entry.
        taskQueue.add(new int[]{newPriority, taskId});
    }
    
    public void rmv(int taskId) {
        // Mark the task as removed by deleting it from the map.
        // The stale entry in the queue will be ignored later by execTop.
        taskDetails.remove(taskId);
    }
    
    public int execTop() {
        while (!taskQueue.isEmpty()) {
            int[] topTask = taskQueue.poll();
            int priority = topTask[0];
            int taskId = topTask[1];
            
            // Check if the task is still valid and has the correct priority.
            // This handles both 'rmv' and 'edit' operations.
            if (taskDetails.containsKey(taskId) && taskDetails.get(taskId)[2] == priority) {
                int[] taskInfo = taskDetails.get(taskId);
                taskDetails.remove(taskId);
                return taskInfo[0];
            }
        }
        return -1;
    }
}
