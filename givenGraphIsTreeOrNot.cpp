bool isCycle(int i,int par,vector<vector<int>>&adj,int n)
{
  vis[i] = true;
  
  for(int j:adj[i])
  {
    if(i == par)
    {
      continue;
    }
    if(vis[i] == false)
    {
      isCycle(j,i,adj);
    }
    else
    {
      return true;
    }
  }
  return false;
}

bool isTree(vector<pair<int,int>>&edges,int n)
 {
   vector<vector<int>>adj(n);
   
   for(auto edge:edges)
   {
     adj[edge.first].push_back(edge.second);
     adj[edge.second].push_back(edge.first);
   }
   
   vector<int>vis(n,false);
   
   for(int i=0;i<n;i++)
   {
     if(vis[i] == 0)
     {
       if(isCycle(i,-1,adj,n))
       {
         return true;
       }
     }
   }
   return false;
 }
