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

// Kadane's algo

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int res = 0;
        int sum = 0;

        for(int i = 1; i < n; i++){
            if(sum < 0){
                sum = prices[i] - prices[i-1];
            }
            else sum += prices[i] - prices[i-1];
            res = max(res, sum);
        }
        return res;
    }
};
