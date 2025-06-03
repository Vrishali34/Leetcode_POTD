import collections

class Solution(object):
    def maxCandies(self, chamber_seals, gem_deposits, mystic_keys, nested_realms, starting_portals):
        # Initialize total collected gems
        total_gems = 0
        
        # Use a deque for efficient BFS queue operations (append and popleft)
        exploration_queue = collections.deque()
        
        # encountered_sealed tracks boxes that have been discovered but are currently closed
        # and awaiting a key.
        encountered_sealed = [False] * len(chamber_seals)
        
        # current_seal_state is a mutable copy of the initial box status.
        # It will be updated when keys are found to open sealed boxes.
        current_seal_state = list(chamber_seals)

        # Process the initial set of portals (boxes)
        for portal in starting_portals:
            if current_seal_state[portal] == 1:
                # If the portal is initially open, add it to the queue for processing
                exploration_queue.append(portal)
            else:
                # If the portal is initially sealed, mark it as encountered but sealed
                encountered_sealed[portal] = True

        # Perform Breadth-First Search (BFS)
        while exploration_queue:
            # Get the current portal (box) to process
            current_realm = exploration_queue.popleft()

            # Collect gems from the current open portal
            total_gems += gem_deposits[current_realm]

            # Process keys found in the current portal
            for key_target in mystic_keys[current_realm]:
                # If the target box is currently sealed (status 0)
                if current_seal_state[key_target] == 0:
                    # Mark the target box as open (status 1) due to finding its key
                    current_seal_state[key_target] = 1
                    # If this box was previously encountered while sealed
                    if encountered_sealed[key_target]:
                        # It can now be opened, so add it to the queue
                        exploration_queue.append(key_target)

            # Process nested realms (contained boxes) found in the current portal
            for nested_realm in nested_realms[current_realm]:
                # If the nested realm is currently open
                if current_seal_state[nested_realm] == 1:
                    # Add it to the queue for processing
                    exploration_queue.append(nested_realm)
                # If the nested realm is sealed and has not been encountered before
                elif not encountered_sealed[nested_realm]:
                    # Mark it as encountered but sealed
                    encountered_sealed[nested_realm] = True
        
        # Return the total number of gems collected
        return total_gems
