int total(Node* root)
{
  if(root == NULL)
  {
    return 0;
  }
  
  int left=total(root->left,x);
  int right=total(root->right,x);
  
  return left+right+1;
}
pair<int,int>leftAndRight(Node* root,int totalNodes)
{
  if(root == NULL)
  {
    return {0,0};
  }
  
  pair<int,int>left=leftAndRight(root->left,totalNodes);
  pair<int,int>right=leftAndRight(root->right,totalNodes);
  
  int lc=left.first+left.second;
  int rc=right.first+right.second;
  
  if(totalNodes-lc == lc)
  {
    ans=true;
  }
  if(totalNodes-rc == rc)
  {
    ans=true;
  }
  
  return lc+rc+1;
}

bool ans=false;

bool canBreak(Node* root)
{
  int totalNodes=total(root);
  leftAndRight(root,totalNodes);
  
  return ans;
}
