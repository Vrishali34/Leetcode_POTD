class ProductOfNumbers:
    def __init__(self):
        self.lst = [1]

    def add(self, num):
        if num == 0:
            self.lst = [1]
        else:
            self.lst.append(self.lst[-1] * num)

    def getProduct(self, k):
        return 0 if len(self.lst) <= k else self.lst[-1] // self.lst[-k-1]
