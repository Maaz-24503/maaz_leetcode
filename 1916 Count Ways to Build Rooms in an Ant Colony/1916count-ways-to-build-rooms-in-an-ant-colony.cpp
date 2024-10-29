class Solution {
public:
    int mod = 1000000007;
    vector<long long> fact;
    vector<long long> factInv;
    vector<vector<int>> adjList;
    
    long long power(long long x, unsigned int y = 1000000005) 
    { 
        long long res = 1;     
    
        x = x % mod; 
    
        if (x == 0) return 0; 
    
        while (y > 0) 
        { 
            if (y & 1) 
                res = (res*x) % mod;  
            y = y>>1; 
            x = (x*x) % mod; 
        } 
        return res; 
    }

    pair<int, long long> DFS(int u){
        if(adjList[u].size() == 0) return {1,1};
        int currRooms = 0;
        long long currWays = 1;
        for(int i = 0; i<adjList[u].size(); i++){
            pair<int, long long> res = DFS(adjList[u][i]);
            currRooms += res.first;
            long long temp = ((((long long)fact[currRooms] * (long long)factInv[currRooms - res.first])%mod) * (long long)factInv[res.first]) % mod;
            currWays = (res.second*((temp*currWays)%mod)%mod); 
        }
        // cout<<u<<": "<<currWays<<" "<<currRooms+1<<endl;
        return {currRooms+1, currWays};
    }

    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        fact.resize(n+1);
        factInv.resize(n+1);
        fact[0] = 1;
        factInv[0] = 1;
        for(int i = 1; i<n+1; i++){
            fact[i] = (i*fact[i-1])%mod;
            factInv[i] = power(fact[i])%mod;
        }
        adjList.resize(n);
        for(int i = 1; i<n; i++) adjList[prevRoom[i]].push_back(i);
        // printGraph();
        return DFS(0).second;
    }
};