class Solution(object):
    def minTime(self, vertex, conduit):
        v_size = len(vertex)
        v_track = [0] * v_size
        
        for c_val in conduit:
            # 1. Base
            v_track[0] = v_track[0] + vertex[0] * c_val
            
            # 2. Forward Propagate
            for k in range(1, v_size):
                proc_time = vertex[k] * c_val
                v_track[k] = max(v_track[k], v_track[k - 1]) + proc_time
                
            # 3. Backward Adjust
            for k in range(v_size - 2, -1, -1):
                proc_time_next = vertex[k + 1] * c_val
                v_track[k] = v_track[k + 1] - proc_time_next
                
        return v_track[-1]
