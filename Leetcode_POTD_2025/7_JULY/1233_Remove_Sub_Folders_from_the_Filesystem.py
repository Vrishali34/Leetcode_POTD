class Solution(object):
    def removeSubfolders(self, temporal_streams):
        """
        :type folder: List[str]
        :rtype: List[str]
        """
        temporal_streams.sort()
        
        anchor_points = []
        if not temporal_streams:
            return anchor_points

        anchor_points.append(temporal_streams[0])

        for i in range(1, len(temporal_streams)):
            current_stream = temporal_streams[i]
            last_anchor = anchor_points[-1]

            if not (current_stream.startswith(last_anchor + "/")):
                anchor_points.append(current_stream)
                
        return anchor_points
