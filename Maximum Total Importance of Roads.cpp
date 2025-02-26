/*
You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.

You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.

You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.

Return the maximum total importance of all roads possible after assigning the values optimally.

*/


//SOLUTION

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> indeg(n,0);
        
        for(auto it : roads)
        {
            indeg[it[0]]++;
            indeg[it[1]]++;
        }
        
        sort(indeg.begin(),indeg.end());
        
        long long res = 0;
        
        for(int i = 0; i < n ; i++)
        {
            res += (i+1) * indeg[i];
        }
        
        return res;
    }
};
