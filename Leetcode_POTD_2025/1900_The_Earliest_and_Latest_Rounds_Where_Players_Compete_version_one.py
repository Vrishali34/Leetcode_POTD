class Solution(object):
    def earliestAndLatest(self, n, firstPlayer, secondPlayer):
        """
        :type n: int
        :type firstPlayer: int
        :type secondPlayer: int
        :rtype: List[int]
        """
        # Adjust players to be 0-indexed for bit manipulation convenience
        p1 = firstPlayer - 1
        p2 = secondPlayer - 1

        # Memoization dictionary to store results for (mask, current_round)
        # Using a single memo for both min and max results for a given mask
        memo_results = {} # Maps mask -> [min_round, max_round]

        def calculate_tournament_rounds(current_player_mask, current_round_num):
            # If we've already computed for this mask, return the cached result
            if current_player_mask in memo_results:
                return memo_results[current_player_mask]

            # Get the list of actual player indices from the current mask
            active_players_list = []
            for i in range(n):
                if (current_player_mask >> i) & 1:
                    active_players_list.append(i)

            num_active = len(active_players_list)
            
            # Find the positions of the two special players in the current list
            pos_p1 = -1
            pos_p2 = -1
            for i in range(num_active):
                if active_players_list[i] == p1:
                    pos_p1 = i
                if active_players_list[i] == p2:
                    pos_p2 = i

            # Check if the two special players are competing against each other in this round
            # They compete if their positions sum up to (number of active players - 1)
            if pos_p1 + pos_p2 == num_active - 1:
                # This is the round they meet, so min and max are both this current round
                memo_results[current_player_mask] = [current_round_num, current_round_num]
                return [current_round_num, current_round_num]

            # Initialize min and max rounds for this state
            min_possible_round = float('inf')
            max_possible_round = float('-inf')
            
            # Determine the number of matches in this round
            matches_in_round = (num_active + 1) // 2

            # Use a helper list to store the min/max values as we explore possibilities.
            # This is a common Python 2 workaround for `nonlocal`
            min_max_tracker = [min_possible_round, max_possible_round]

            # Recursive helper to generate all possible next round masks
            def generate_next_masks_recursive(k, new_mask_accumulator):
                # Base case: All matches for the current round have been decided
                if k == matches_in_round:
                    # Recursively call `calculate_tournament_rounds` for the next state
                    next_round_outcome = calculate_tournament_rounds(new_mask_accumulator, current_round_num + 1)
                    
                    # Update the min and max found so far
                    min_max_tracker[0] = min(min_max_tracker[0], next_round_outcome[0])
                    min_max_tracker[1] = max(min_max_tracker[1], next_round_outcome[1])
                    return

                # Get the players in the current match (front vs. back)
                front_player_in_match = active_players_list[k]
                back_player_in_match = active_players_list[num_active - 1 - k]

                # If it's the middle player in an odd-numbered group, they advance automatically
                if k == num_active - 1 - k:
                    generate_next_masks_recursive(k + 1, new_mask_accumulator | (1 << front_player_in_match))
                else:
                    # Check if either special player is involved in this match
                    p1_involved = (front_player_in_match == p1 or front_player_in_match == p2)
                    p2_involved = (back_player_in_match == p1 or back_player_in_match == p2)

                    if p1_involved and p2_involved:
                        # This scenario means p1 and p2 are facing each other in this match.
                        # This specific case should already be handled by the direct check at the start.
                        return
                    elif p1_involved:
                        # If the front player is special, they must win to continue the path
                        generate_next_masks_recursive(k + 1, new_mask_accumulator | (1 << front_player_in_match))
                    elif p2_involved:
                        # If the back player is special, they must win to continue the path
                        generate_next_masks_recursive(k + 1, new_mask_accumulator | (1 << back_player_in_match))
                    else:
                        # If neither special player is involved, we can choose either outcome
                        # to explore both min and max paths
                        generate_next_masks_recursive(k + 1, new_mask_accumulator | (1 << front_player_in_match))
                        generate_next_masks_recursive(k + 1, new_mask_accumulator | (1 << back_player_in_match))
            
            # Start the generation of next round masks
            generate_next_masks_recursive(0, 0)
            
            # Store the computed min and max for the current mask before returning
            memo_results[current_player_mask] = min_max_tracker
            return min_max_tracker

        # Start the recursive calculation from the initial state
        initial_mask = (1 << n) - 1
        return calculate_tournament_rounds(initial_mask, 1)
