int sum(Node* root)
{
  if(root == NULL)
  {
    return 0;
  }
  
  int left=sum(root->left);
  int right=sum(root->right);
  
  return left+right+root->data;
}

int uncoveredSumRight(Node* right)
{
  if(right == NULL)
  {
    return 0;
  }
  if(right->left == NULL && right->right == NULL)
  {
    return right->data;
  }
  
  int sum=0;
  
  if(right->left)
  {
    sum=uncoveredSumLeft(right->left);
  }
  else
  {
    sum=uncoveredSumRight(right->right);
  }
  
  return sum+right->data;
}
int uncoveredSumLeft(Node* left)
{
  if(left == NULL)
  {
    return 0;
  }
  if(left->left == NULL && left->right == NULL)
  {
    return left->data;
  }
  
  int sum=0;
  
  if(left->left)
  {
    sum=uncoveredSumLeft(left->left);
  }
  else
  {
    sum=uncoveredSumRight(left->right);
  }
  
  return sum+left->data;
}

int uncoveredSum(Node* root)
{
  int lb=0,rb=0;
  
  if(root->left)
  {
    lb=uncoveredSumLeft(root->left);
  }
  if(root->right)
  {
    rb=uncoveredSumRight(root->right);
  }
  
  return root->data+lb+rb;
}
bool isSumSame(Node* root)
{
  int sumUC=uncoveredSum(root);
  int totSum=sum(root);
  
  return ((totSum-sumUC) == sumUC);
}
