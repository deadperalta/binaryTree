int solve(Node* root,int &sum)
{
  if(root == NULL)
  {
    return 0;
  }
  if(root->left == NULL && root->right == NULL)
  {
    return root->data;
  }
  
  int left=solve(root->left,sum);
  int right=solve(root->right,sum);
  
  root->data+=left+right; 
  sum=max(sum,root->data);
  
  return root->data;
}

int largestSubtree(Node* root)
{
  int sum=INT_MIN;
  solve(root,sum);
  return sum;
}
