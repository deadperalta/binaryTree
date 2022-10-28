int solve(Node* root,int &sum)
{
  if(root == NULL)
  {
    return 0;
  }
  
  int left=solve(root->left,sum);
  int right=solve(root->right,sum);
  
  int height=1+max(left,right);
  sum+=height;
  return height;
}

int sumOHeight(Node* root)
{
  int sum=0;
  solve(root,sum);
  return sum;
}
