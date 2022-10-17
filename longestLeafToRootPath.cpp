void findLongest(Node* root,vector<int>&v,vector<int>&ans)
{
  if(root == NULL)
  {
    return;
  }
  
  if(root->left == NULL && root->right == NULL)
  {
    v.push_back(root->data);
    if(v.size() > ans.size())
    {
      ans=v;
    }
    v.pop_back();
  }
  
  v.push_back(root->data);
  findLongest(root->left,v,ans);
  findLongest(root->right,v,ans);
  v.pop_back();
}
  
void printLongestPath(Node* root)
{
  vector<int>ans;
  vector<int>v;
  
  findLongest(root,v,ans);
  
  for(int i:ans)
  {
    cout<<i<<" ";
  }
}
