void solve(Node* root,unordered_map<int,int>&map,bool &flag,int x)
{
  if(root == NULL)
  {
    return;
  }
  
  if(map[x-root->data] > 0)
  {
    ans=true;
    return;
  }
  map[root->data]++;
  solve(root->left,map,ans);
  solve(root->right,map,ans);
  map[root->data]--;
}
  
bool isThere(Node* root)
{
  unordered_map<int,int>map;
  bool ans=false;
  
  solve(root,map,ans,root->data);
  return ans;
}
