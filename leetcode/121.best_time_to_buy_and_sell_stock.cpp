class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price = INT_MAX; //int 형식 변수의 최대값(2147483647)
        int profit = 0;
        for (int p : prices) {
            price = min(price, p);
            profit = max(profit, p - price);
        }
        return profit;
    }
};