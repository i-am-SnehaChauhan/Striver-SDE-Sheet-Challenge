/* Approach 1: Using Hashmap
/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the size of array/list.
*/
#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int,int> mp;
    vector<int> ans;
    int l = n/3+1;
    for(int i=0; i<n; i++){
       mp[arr[i]]++;
       
       if(mp[arr[i]]==l){
           ans.push_back(arr[i]);
       }
    }
   return ans;
}

/*Approach 2: Using Moore Voting Algorithm
   Time Complexity: O(N)
    Space Complexity: O(1)

    Where 'N' is the size of array/list.
*/

