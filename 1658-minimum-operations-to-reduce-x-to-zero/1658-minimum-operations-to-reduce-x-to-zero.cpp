class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int total = 0;
        int n = nums.size();

       
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
 
        int target = total - x;
 
        if (target < 0) {
            return -1;
        }

        int low = 0;
        int sum = 0;
        int maxLen = -1;

        // Sliding window
        for (int high = 0; high < n; high++) {

            sum += nums[high];

            while (sum > target) {
                sum -= nums[low];
                low++;
            }

            if (sum == target) {
                maxLen = max(maxLen, high - low + 1);
            }
        }
 
        if (maxLen == -1) {
            return -1;
        }
 
        return n - maxLen;
    }
};