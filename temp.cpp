#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//    void generateStrings(vector<string>&result,string &s,int n,int ch){
//     if(s.size() == n){
//         result.push_back(s);
//         return;
//     }

//     s.push_back('1');
//     generateStrings(result,s,n,1);
//     s.pop_back();

//     if(ch!=0){
//        s.push_back('0');
//        generateStrings(result,s,n,0);
//        s.pop_back();
//     }
//    }

//     vector<string> validStrings(int n) {
//         vector<string>result;
//         string s;
//         generateStrings(result,s,n,-1);
//         return result;
//     }
// };

// class Solution {
// public:
//         vector<vector<int>> CalculatePreSum(vector<vector<char>>& grid,char ch){
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>>preSum(n,vector<int>(m,0));

//     preSum[0][0] = ( grid[0][0] == ch ? 1 : 0);

//    for(int j=1;j<m;j++){
//     preSum[0][j] = preSum[0][j-1] + ( grid[0][j] == ch ? 1 : 0);
//    }

//    for(int i=1;i<n;i++){
//     preSum[i][0] = preSum[i-1][0] + ( grid[i-1][0] == ch ? 1 : 0);
//    }

//     for(int i=1;i<n;i++){
//         for(int j=1;j<m;j++){
//             preSum[i][j] = preSum[i][j-1] + preSum[i-1][j] - preSum[i-1][j-1] + ( grid[0][j] == ch ? 1 : 0);
//         }
//     }
//     return preSum;
// }

//     int numberOfSubmatrices(vector<vector<char>>& grid) {
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>>countOfX = CalculatePreSum(grid,'x');
//     vector<vector<int>>countOfY = CalculatePreSum(grid,'y');

//     int count = 0;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//          if(countOfX[i][j] == countOfY[i][j] && countOfX[i][j]>0){
//             count++;
//          }
//         }
//     }
//     return count;
//     }
// };

class Solution
{
public:
    double myPow(double x, int n)
    {
        double power = 1;
        if (x == 0)
            return 0;
        if (n == 0)
            return power;
        while (n != 0)
        {
            if (n & 1)
            {
                n = n - 1;
                power *= x;
            }
            x *= x;
            n = n >> 1;
        }
    }
};

class Solution
{
public:
    string getSmallestString(string s)
    {
        int n = s.size();
        int index = -1;
        int prev = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if ((s[i] - s[i + 1]) > prev)
            {
                index = i;
                break;
            }
        }

        if (index)
        {
            swap(s[index], s[index + 1]);
        }

        return s;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        set<int> s(nums.begin(), nums.end());
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *current = dummy;

        while (current->next != NULL)
        {
            if (s.find(current->next->val) != s.end())
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
            else
            {
                current = current->next;
            }
        }

        ListNode *newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

class Solution
{
public:
    int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut)
    {

        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int i = 0, j = 0;
        int horizontalCuts = 0, verticalCuts = 0;
        int totalCost = 0;

        while (i < m - 1 && j < n - 1)
        {
            if (horizontalCut[i] > verticalCut[j])
            {
                totalCost += horizontalCut[i] * (verticalCuts + 1);
                i++;
                horizontalCuts++;
            }
            else
            {
                totalCost += verticalCut[j] * (horizontalCuts + 1);
                j++;
                verticalCuts++;
            }
        }

        while (i < m - 1)
        {
            totalCost += horizontalCut[i] * (verticalCuts + 1);
            i++;
        }

        while (j < n - 1)
        {
            totalCost += verticalCut[j] * (horizontalCuts + 1);
            j++;
        }

        return totalCost;
    }
};

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int ans = INT_MIN;
        int totalSum = 0;

        for (auto i : cardPoints)
            totalSum += cardPoints[i];

        int windowSize = n - k;
        if (windowSize == 0)
            return totalSum;

        int curr = 0;
        for (int i = 0; i < windowSize; i++)
            curr += cardPoints[i];

        ans = max(ans, totalSum - curr);

        for (int j = 1; j < j + windowSize; j++)
        {
            curr += cardPoints[j + windowSize - 1];
            curr -= cardPoints[j - 1];

            ans = max(ans, totalSum - curr);
        }

        return ans;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        vector<int> left(n), right(n);
        
        left[0] = height[0];
        for (int i = 1; i < n; ++i) {
            left[i] = max(left[i-1], height[i]);
        }

        right[n-1] = height[n-1];
        for (int i = n-2; i >= 0; --i) {
            right[i] = max(right[i+1], height[i]);
        }

        int water = 0;
        for (int i = 0; i < n; ++i) {
            water += min(left[i], right[i]) - height[i];
        }

        return water;
    }
};
