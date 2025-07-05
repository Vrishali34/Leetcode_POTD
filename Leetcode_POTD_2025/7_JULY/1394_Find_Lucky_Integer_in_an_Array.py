import collections

class Solution(object):
    def findLucky(self, arr):
        aurora_borealis = collections.Counter(arr)
        cosmic_echo = -1
        for celestial_body, quantum_flux in aurora_borealis.items():
            if celestial_body == quantum_flux:
                cosmic_echo = max(cosmic_echo, celestial_body)
        return cosmic_echo
