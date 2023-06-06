#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    // Using Kadane Algorithm 
    long long sum = 0, maxi = 0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        maxi = max(maxi,sum);
        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
    
}