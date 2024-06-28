// four sum  :  
// 1. sort the array 
// 2. fix the two pointers i,j and move the k & l two get the target sum 
//  k-----> greater      lesser <-----l
// same approach for the three sum

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}

// 1 1 1 2 2 3 3 4 4 4

/*int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}*/

// : N = 6, array[] = {9, -3, 3, -1, 6, -5}
                    // 9   6  9   8   14  9

// Length of the longest subarray with zero Sum ----
//presum approach


int solve(vector<int>& a) {
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for (int i = 0; i < a.size(); i++) {
        sum += a[i];

        if (sum == 0) {
            maxLen = i + 1;
        } else if (sumIndexMap.find(sum) != sumIndexMap.end()) {
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        } else {
            sumIndexMap[sum] = i;
        }
    }

    return maxLen;
}

// int main() {
//     vector<int> a = {9, -3, 3, -1, 6, -5};
//     cout << solve(a) << endl;

//     return 0;
// }


// Count the number of subarrays with given xor K  same approach as pre sum but using the xor property 



int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int xr = 0;
    map<int, int> mpp; //declaring the map.
    mpp[xr]++; //setting the value of 0.
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        // prefix XOR till index i:
        xr = xr ^ a[i];

        //By formula: x = xr^k:
        int x = xr ^ k;

        // add the occurrence of xr^k
        // to the count:
        cnt += mpp[x];

        // Insert the prefix xor till index i
        // into the map:
        mpp[xr]++;
    }
    return cnt;
}

// int main()
// {
//     vector<int> a = {4, 2, 2, 6, 4};
//     int k = 6;
//     int ans = subarraysWithXorK(a, k);
//     cout << "The number of subarrays with XOR k is: "
//          << ans << "\n";
//     return 0;
// }


// Merge Overlapping Sub-intervals 

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
    int n = arr.size(); // size of the array

    //sort the given intervals:
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        // if the current interval does not
        // lie in the last interval:
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        }
        // if the current interval
        // lies in the last interval:
        else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

// int main()
// {
//     vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
//     vector<vector<int>> ans = mergeOverlappingIntervals(arr);
//     cout << "The merged intervals are: " << "\n";
//     for (auto it : ans) {
//         cout << "[" << it[0] << ", " << it[1] << "] ";
//     }
//     cout << endl;
//     return 0;
// }



// Maximum Product Subarray in an Array

int maxProductSubArray(vector<int> &arr) {
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

// int maxProductSubArray(vector<int>& nums) {
//     int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
//     for(int i=1;i<nums.size();i++) {
//         int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
//         prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
//         prod1 = temp;
        
//         result = max(result,prod1);
//     }
    
//     return result;
// }

// int main()
// {
//     vector<int> arr = {1, 2, -3, 0, -4, -5};
//     cout << "The maximum product subarray is: "
//          << maxProductSubArray(arr) << "\n";
//     return 0;
// }











