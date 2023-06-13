/*Approach 1: Brute Force
  i. Initialise an ans 2D array to store our result.
 ii. Check for each element if arr[i]+arr[j] == Sum then store both the 
     element int the increasing order in the ans vector .
iii. In the end return the ans vector.
   
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    Where 'N' is the size of the array.
*/
#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   vector<vector<int>> ans;
   int n = arr.size();
   for(int i=0; i<n; i++){
      int num = s-arr[i];
      vector<int> a;
      for(int j=i+1; j<n; j++){
         if(num==arr[j]){
           a.push_back(min(arr[j],arr[i]));
           a.push_back(max(arr[j],arr[i]));
           ans.push_back(a);
         }
      }
   }

   sort(ans.begin(), ans.end());
   return ans;
}

/* Approach 2: Using Hashmap
   i. Initialize a list to store our results.
  ii. For each element in the array ‘ARR[i]’, we will check whether there 
      exists an element equals to ('S' - ‘ARR[i]’) already in the map.
     
    Time Complexity: O(N^2)
    Space COmplexity: O(N)
*/

vector<vector<int>> pairSum(vector<int> &arr, int s){
    map<int, int> hash;

    // This will store the result.
    vector<vector<int>> ans;

    for (int ele : arr)
    {
        int count = hash[s - ele];

        vector<int> pair(2);
        pair[0] = ele;
        pair[1] = s - ele;

        while (count--)
        {
            ans.push_back(pair);
        }

        hash[ele] += 1;
    }

    // This will store the final result.
    vector<vector<int>> res(ans.size(), vector<int>(2, 0));

    // Sorting the 'ans' arrays element.
    for (int i = 0; i < ans.size(); i++)
    {
        int a = ans[i][0], b = ans[i][1];
        res[i][0] = min(a, b);
        res[i][1] = max(a, b);
    }

    // Finally sorting each pair in 'res'.
    sort(res.begin(), res.end());
    return res;
}