class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>n;
        for(int i: nums){
            n.push_back(abs(i));
        }
        sort(n.begin(), n.end());

        for(int i = 0; i<n.size();i++){
            nums[i] = pow(n[i], 2);
        }
        return nums;
    }
};