int findMaxInd(vector<int>&pre,int st,int en)
{
  int ind;
  int maxInd=st;
  
  for(ind=st;ind<=en;ind++)
  {
    if(pre[ind] > pre[maxInd])
    {
      maxInd=ind;
    }
  }
  return maxInd;
}
Node* create(vector<int>&pre,int st,int en)
{
  if(st > en)
  {
    return NULL;
  }
  
  int ind=findMaxInd(pre,st,en);
  
  Node* root=new Node(pre[ind]);
  
  root->left=create(pre,st,ind-1);
  root->right=create(pre,ind+1,en);
  
  return root;
}
Node* createTree(vector<int>&pre)
{
  return create(pre,0,pre.size()-1);
}
