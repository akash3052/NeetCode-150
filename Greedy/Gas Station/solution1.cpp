class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIndex = 0, gasSum = 0, costSum = 0;
        for(auto g : gas){
            gasSum += g;
        }
        for(auto c : cost){
            costSum += c;
        }
        if(gasSum < costSum){
            return -1;
        }

        // unique solution always exist because we have checked above that totalgas >= totalcost 

        int currGas = 0;
        for(int i = 0; i < gas.size(); i++){
            currGas += (gas[i] - cost[i]);
            // Note : we need to find that amount where gas > cost 
            // because if that is not the case then we can't move to next station 
            // we need to find that station where surplus amount of gas exist to move to next station 
            // and we don't need to move back to check if we are able to complete the entire loop 
            // as we have already checked earlier that there exists enough amount of gas to complete the entire loop
            if(currGas < 0){
                currGas = 0;
                startIndex = i + 1;
            }
        }
        return startIndex;
    }
};


// TC = O(n) 
// SC = O(1)
  
