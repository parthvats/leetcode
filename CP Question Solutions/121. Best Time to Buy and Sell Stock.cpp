class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mn = INT_MAX;
        int res = 0;
        for(int i = 0; i < n; i++){
            mn = min(mn, prices[i]);
            res = max(res, prices[i]-mn);
        }
        return res;
    }
};
