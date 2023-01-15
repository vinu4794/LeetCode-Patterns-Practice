#include<iostream>
#include<vector>

using namespace std;

class GasStationsCircularRoute 
{
    public:
        int computeStartingIndex(vector<int> &gas, vector<int> &cost)
        {
            int numberOfStations = gas.size();

            for (int i = 0; i < numberOfStations; i++) { // start/restart
                int startingGasStation = i;
                int currentGasStation = i;
                int carGas = 0;

                int cycleLength = numberOfStations;

                while(cycleLength >= 0) {
                    if (currentGasStation == numberOfStations) {
                        currentGasStation = 0;
                    }
                    carGas += gas[currentGasStation];

                    if (carGas < cost[currentGasStation]) {
                        break;
                    }
                    cycleLength--;
                    carGas -= cost[currentGasStation];  
                    currentGasStation++;                 
                }
                if (cycleLength == -1) {
                    return startingGasStation;
                }
            }
            return -1;
        }
};

int main(int argc, char **argv)
{
    GasStationsCircularRoute gsObj;
    vector<int> gas = {5, 1, 2, 3, 4};
    vector<int> cost = {4, 4, 1, 5, 1};
    cout << gsObj.computeStartingIndex(gas, cost);
}