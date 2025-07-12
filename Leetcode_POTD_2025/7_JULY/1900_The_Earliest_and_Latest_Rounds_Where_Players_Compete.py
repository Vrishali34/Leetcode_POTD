class Solution(object):
    def earliestAndLatest(self, n, firstPlayer, secondPlayer):
        """
        :type n: int
        :type firstPlayer: int
        :type secondPlayer: int
        :rtype: List[int]
        """
        # Adjust to 0-indexed for easier bit manipulation
        firstPlayer -= 1
        secondPlayer -= 1

        memo = {} # Stores (min_round, max_round) for each mask

        def solve(current_mask, current_round):
            if current_mask in memo:
                return memo[current_mask]

            current_players = []
            for i in range(n):
                if (current_mask >> i) & 1:
                    current_players.append(i)

            size = len(current_players)
            p1_idx = -1
            p2_idx = -1
            for i in range(size):
                if current_players[i] == firstPlayer:
                    p1_idx = i
                if current_players[i] == secondPlayer:
                    p2_idx = i

            # If the two players are at opposing ends of the current row, they meet
            if p1_idx + p2_idx == size - 1:
                memo[current_mask] = [current_round, current_round]
                return [current_round, current_round]

            # Use a list to hold min_rounds and max_rounds,
            # as lists are mutable and changes to them from inside
            # nested functions will be reflected in the outer scope.
            result_container = [float('inf'), float('-inf')] # [min_rounds, max_rounds]

            num_matches = (size + 1) // 2

            # Use a helper function for backtracking to generate next_mask combinations
            def generate_next_masks(k, new_mask):
                if k == num_matches:
                    res_next_round = solve(new_mask, current_round + 1)
                    result_container[0] = min(result_container[0], res_next_round[0])
                    result_container[1] = max(result_container[1], res_next_round[1])
                    return

                p_front = current_players[k]
                p_back = current_players[size - 1 - k]

                if k == size - 1 - k: # Middle player, automatically advances
                    generate_next_masks(k + 1, new_mask | (1 << p_front))
                else:
                    fp_involved = (p_front == firstPlayer or p_front == secondPlayer)
                    sp_involved = (p_back == firstPlayer or p_back == secondPlayer)

                    if fp_involved and sp_involved:
                        # This case means firstPlayer and secondPlayer are matched against each other
                        # This should be caught by the earlier p1_idx + p2_idx == size - 1 check
                        return
                    elif fp_involved: # p_front is one of the special players, they win
                        generate_next_masks(k + 1, new_mask | (1 << p_front))
                    elif sp_involved: # p_back is one of the special players, they win
                        generate_next_masks(k + 1, new_mask | (1 << p_back))
                    else: # Neither is a special player, choose either to win
                        generate_next_masks(k + 1, new_mask | (1 << p_front))
                        generate_next_masks(k + 1, new_mask | (1 << p_back))
            
            generate_next_masks(0, 0)
            memo[current_mask] = result_container
            return result_container

        initial_mask = (1 << n) - 1
        return solve(initial_mask, 1)
