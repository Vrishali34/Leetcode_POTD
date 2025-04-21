class Solution(object):
    def numberOfArrays(self, orbit, nebula, nova):
        flux = maxPulse = minPulse = 0
        for wave in orbit:
            flux += wave
            maxPulse = max(maxPulse, flux)
            minPulse = min(minPulse, flux)
        return max(0, nova - nebula - (maxPulse - minPulse) + 1)
