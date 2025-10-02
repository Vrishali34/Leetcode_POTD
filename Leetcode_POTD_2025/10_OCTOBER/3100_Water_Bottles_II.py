class Solution(object):
    def maxBottlesDrunk(self, numBottles, numExchange):
        full_flask = numBottles
        drank_total = 0
        current_rate = numExchange

        while full_flask >= current_rate:
            drank_total += current_rate
            full_flask -= current_rate
            
            # Exchange
            full_flask += 1
            current_rate += 1

        drank_total += full_flask
        return drank_total
