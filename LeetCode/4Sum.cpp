// problem source: https://leetcode.com/problems/4sum/
// discussion reference: https://leetcode.com/problems/4sum/discuss/1341213/C%2B%2BPython-2-solutions-Clean-and-Concise-Follow-up%3A-K-Sum
// discussion reference 2: https://leetcode.com/problems/4sum/discuss/1524084/C++-APPROACH-oror-WITH-EASY-AND-SIMPLE-EXPLANATION
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int nums_size = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums_size; i++) {
            for (int j = i + 1; j < nums_size; j++) {
                int remain_target = target - nums[i] - nums[j];
                int forward = j + 1;
                int backward = nums_size - 1;
                while (forward < backward) {
                    int two_sum = nums[forward] + nums[backward];
                    if (two_sum < remain_target) // two_sum is increasing, because of sorting
                        forward++;
                    else if (two_sum > remain_target) // two_sum is decreasing, because of sorting
                        backward--;
                    else { // two_sum == remain_target
                        vector<int> individual_element = {nums[i], nums[j], nums[forward], nums[backward]};
                        result.push_back(individual_element);
                        while (forward < backward && nums[forward] == individual_element[2])
                            forward++;
                        while (forward < backward && nums[backward] == individual_element[3])
                            backward--;
                    }
                }
                while (j + 1 < nums_size && nums[j + 1] == nums[j])
                    j++;
            }
            while (i + 1 < nums_size && nums[i + 1] == nums[i])
                i++;
        }
        return result;

        // Time Limit Exceeded	with [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2], 8
        // int nums_size = nums.size();
        //
        // unordered_set<int> seen_element;
        // set<multiset<int>> result_set; // multiset is allowing key redundancy, set is not allow key redundancy and sorted
        //
        // for (int i = 0; i < nums_size; i++) {
        //     for (int j = i + 1; j < nums_size; j++) {
        //         for (int k = j + 1; k < nums_size; k++) { // O(N^3) complexity
        //             int last_element = target - (long(nums[i]) + long(nums[j]) + long(nums[k])); // signed integer overflow with 2000000000 + 1000000000
        //             if (seen_element.count(last_element)) {
        //                 multiset<int> individual_element = {nums[i], nums[j], nums[k], last_element};
        //                 result_set.emplace(individual_element); // emplace is faster than insert
        //             }
        //         }
        //     }
        //     seen_element.insert(nums[i]);
        // }
        //
        // vector<vector<int>> result(result_set.size());
        // for_each(result_set.begin(), result_set.end(), [&, i(0)](multiset<int> element) mutable { // & is captured all external variable, mutable change const to variable
        //     result[i++] = vector<int>(element.begin(), element.end()); // make result
        // });
        // return result;

        // Time Limit Exceeded	with [91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245], -236727523
        // int nums_size = nums.size();
        // vector<vector<int>> result;
        // for (int i = 0; i < nums_size - 3; i++) {
        //     for (int j = i + 1; j < nums_size - 2; j++) {
        //         for (int k = j + 1; k < nums_size - 1; k++) {
        //             for (int l = k + 1; l < nums_size; l++) {
        //                 if (nums[i] + nums[j] + nums[k] + nums[l] == target) {
        //                     cout << i << " " << j << " " << k << " " << l << endl;
        //                     vector<int> individual_element = {nums[i], nums[j], nums[k], nums[l]};
        //                     // vector<int> individual_element;
        //                     // individual_element.push_back(nums[i]);
        //                     // individual_element.push_back(nums[j]);
        //                     // individual_element.push_back(nums[k]);
        //                     // individual_element.push_back(nums[l]);
        //                     sort(individual_element.begin(), individual_element.end());
        //                     if (find(result.begin(), result.end(), individual_element) == result.end())
        //                         result.push_back(individual_element);
        //                 }
        //             }
        //         }
        //     }
        // }
        // return result;
    }
};
