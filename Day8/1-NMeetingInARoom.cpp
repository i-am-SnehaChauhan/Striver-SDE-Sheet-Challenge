/*Approach 1: 
    Sort the meetings acc to finish time.
    check if end time of meeting i is less then start time of meeting i+1 then 
    meeting can be held
    Time Complexity: O(nlogn)
    Space Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int, int>> b)
{
    return a.second.first < b.second.first;
}

vector<int> maxMeeting(vector<int> &start, vector<int> &end, int n)
{
    vector<pair<int, <pair<int, int>>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i], {end[i], i + 1}});
    }

    sort(v.begin(), v.end(), cmp);

    vector<int> ans;
    ans.push_back(v[0].second.second);
    int limit = v[0].second.first;

    for (int i = 1; i < n; i++)
    {
        if (v[i].first > limit)
        {
            ans.push_back(v[i].second.second);
            limit = v[i].second.first;
        }
    }

    return ans;
}


    

