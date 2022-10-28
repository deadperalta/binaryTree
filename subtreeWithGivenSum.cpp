int solve(Node* root,int x,bool &found)
{
  if(root == NULL)
  {
    return 0;
  }
  
  if(root->left == NULL && root->right == NULL)
  {
    return root->data;
  }
  
  int left=solve(root->left,x,found);
  int right=solve(root->right,x,found);
  
  root->data+=left+right;
  
  if(root->data == x)
  {
    found=true;
  }
  
  return root->data;
}
bool subtreeWithGivenSum(Node* root,int x)
{
  bool found=false;
  solve(root,x,found);
  return found;
}
