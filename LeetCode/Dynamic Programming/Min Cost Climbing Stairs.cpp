// problem source: https://leetcode.com/problems/min-cost-climbing-stairs/
// discussion reference: https://leetcode.com/problems/min-cost-climbing-stairs/discuss/1577147/C++-oror-Dynamic-Programming-oror-Bottom-up
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cost_size = cost.size();
        vector<int> result(cost_size + 1); // for last value

        for(int i = 2; i < cost_size + 1; i++) {
            result[i] = min(result[i - 1] + cost[i - 1], result[i - 2] + cost[i - 2]);
        }

        return result[cost_size];

        // All PASS Presented Test Case, Wrong With [0,1,2,2]
        // int index_0_result = cost[0];
        // int index_1_result = cost[1];
        // int result;
        // int cost_size = cost.size();
        //
        // // Starting At Index 0
        // int i = 0;
        // while (i + 1 < cost_size && i + 2 < cost_size) {
        //     if (cost [i + 1] < cost [i + 2]) {
        //         index_0_result += cost[i + 1];
        //         i++;
        //     } else {
        //         index_0_result += cost[i + 2];
        //         i += 2;
        //     }
        // }
        //
        // // Starting At Index 1
        // i = 1;
        // while (i + 1 < cost_size && i + 2 < cost_size) {
        //     if (cost [i + 1] < cost [i + 2]) {
        //         index_1_result += cost[i + 1];
        //         i++;
        //     } else {
        //         index_1_result += cost[i + 2];
        //         i += 2;
        //     }
        // }
        //
        // // Get Minimal Cost
        // cout << index_0_result << " " << index_1_result << endl;
        // result = min(index_0_result, index_1_result);
        // return result;
    }
};
