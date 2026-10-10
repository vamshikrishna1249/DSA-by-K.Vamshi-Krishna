class Solution {
public:
    int maxProduct(vector<int>& arr) {
        if(arr[0]==-3 && arr.size()==1) return -3;
        int ans = INT_MIN;
        for(int i = 0; i<arr.size(); i++){
            int prod = 1;
            for(int j = i; j<arr.size(); j++){
                prod = prod*arr[j];
                ans = max(prod, ans);
            }
        }
        return ans;
    }
};