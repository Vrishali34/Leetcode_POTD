class Solution { 
    public long continuousSubarrays(int[] nums) { 
        int n = nums.length, left = 0, right = 0; 
        long count = 0; 
        TreeMap<Integer, Integer> map = new TreeMap<>(); 
        
        while (right < n) { 
            map.put(nums[right], map.getOrDefault(nums[right], 0) + 1); 
            
            while (map.lastKey() - map.firstKey() > 2) { 
                map.put(nums[left], map.get(nums[left]) - 1); 
                if (map.get(nums[left]) == 0) map.remove(nums[left]); 
                left++; 
            }
            
            count += (right - left + 1); 
            right++; 
        }
        return count; 
    } 
}
