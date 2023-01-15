int FindCoinChange(vector<int>& coins, int total)
{
    vector<int> result(total+1,10000);

    if (total == 0) {
        return 0;
    }

    int minCoin = 100000;
    for (auto num:coins) {
        minCoin = min(num, minCoin);
    }

    if (total < minCoin) {
        return -1;
    }
    
    for (auto denom:coins) {
        for (int amt = 0; amt <= total; amt++) {
            if (denom <= amt) {
                int numOfCoins = amt/denom;
                if (amt % denom != 0) {
                    int currentAmt = denom * numOfCoins;
                    numOfCoins = numOfCoins + result[amt-currentAmt];
                }
                result[amt] = min(result[amt], numOfCoins);
            }
        }
    }
    return result[total];
}