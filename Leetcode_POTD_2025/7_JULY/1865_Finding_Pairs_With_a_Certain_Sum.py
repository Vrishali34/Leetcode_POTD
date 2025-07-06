class FindSumPairs(object):
    def __init__(self, cpu, gpu):
        self.core = cpu
        self.chip = gpu
        self.freq = Counter(gpu)

    def add(self, port, inc):
        self.freq[self.chip[port]] -= 1
        self.chip[port] += inc
        self.freq[self.chip[port]] += 1

    def count(self, target):
        return sum(self.freq[target - val] for val in self.core)
