void addToAns(Node* root,vector<int>&path,vector<vector<int>>&ans,int i)
{
  vector<int>temp;
  for(int j=i;j<path.size();j++)
  {
    temp.push_back(path[j]);
  }
  ans.push_back(temp);
}

void solve(Node* root,int k,vector<vector<int>>&ans,vector<int>&path)
{
  if(root == NULL)
  {
    return;
  }
  
  path.push_back(root->data);
  
  solve(root->left,k,ans,path);
  solve(root->right,k,ans,path);
  
  int sum=0;
  
  for(int i=path.size()-1;i>=0;i--)
  {
    sum+=path[i];
    if(sum == k)
    {
      addToAns(root,path,ans,i);
    }
  }
  path.pop_back();
}
vector<vector<int>>printKPath(Node* root,int k)
{
  vector<vector<int>>ans;
  vector<int>path;
  solve(root,k,ans,path);
  return ans;
}
