class Solution(object):
    def matchPlayersAndTrainers(self, players, trainers):
        """
        :type players: List[int]
        :type trainers: List[int]
        :rtype: int
        """
        players.sort()
        trainers.sort()

        match_count = 0
        p_idx = 0
        t_idx = 0

        while p_idx < len(players) and t_idx < len(trainers):
            if players[p_idx] <= trainers[t_idx]:
                match_count += 1
                p_idx += 1
                t_idx += 1
            else:
                t_idx += 1
        
        return match_count
