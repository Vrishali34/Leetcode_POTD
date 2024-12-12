class Solution {
public:
    long long pickGifts(vector<int>& gifts, int rounds) {
        priority_queue<int> maxHeap;
        long long totalSum = 0;
        for (int gift : gifts) {
            maxHeap.push(gift);
            totalSum += gift;
        }
        while (rounds--) {
            int largest = maxHeap.top();
            totalSum -= (largest - sqrt(largest));
            maxHeap.pop();
            maxHeap.push(sqrt(largest));
        }
        return totalSum;
    }
};
