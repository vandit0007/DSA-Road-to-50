class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;

        // Sum of first window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
        }

        double maxAvg = (double)sum / k;

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - nums[i - k];
            maxAvg = max(maxAvg, (double)sum / k);
        }

        return maxAvg;
    }
};