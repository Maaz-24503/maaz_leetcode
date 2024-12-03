public class Solution {

    List<List<int>> adjList;
    bool[] isVisited;

    public double dist(int x1, int y1, int x2, int y2){
        return Math.Sqrt((((x1*1.0) - (x2*1.0)) * ((x1*1.0) - (x2*1.0))) + (((y1*1.0) - (y2*1.0)) * ((y1*1.0) - (y2*1.0))));
    }

    public int dfs(int u){
        int count = 0;
        foreach(int v in adjList[u]){
            if(!isVisited[v]){
                isVisited[v] = true;
                count += dfs(v);
            }
        }
        return 1+count;
    }

    public int MaximumDetonation(int[][] bombs) {
        int n = bombs.Length;
        adjList = new List<List<int>>();
        isVisited = new bool[n];
        for(int i = 0; i<n; i++){
            adjList.Add(new List<int>());    
        }
        
        for(int i = 0; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                if(dist(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]) <= bombs[i][2]){         
                    adjList[i].Add(j);
                }
                if(dist(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1]) <= bombs[j][2]){         
                    adjList[j].Add(i);
                }
            }
        }
        
        int maxi = 1;
        for(int i = 0; i<n; i++){
            isVisited = new bool[n];
            isVisited[i] = true;
            maxi = Math.Max(maxi, dfs(i));
        }
        return maxi;
    }
}