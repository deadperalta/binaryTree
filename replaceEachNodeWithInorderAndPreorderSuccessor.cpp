void inorder(Node* root,vector<int>&arr)
{
  if(root == NULL)
  {
    return;
  }
  
  inorder(root->left,arr);
  arr.push_back(root->data);
  inorder(root->right,arr);
}

void replaceSum(Node* root,vector<int>&arr,int &i)
{
  if(root == NULL)
  {
    return;
  }
  
  replaceSum(root->left,arr,i);
  root->data=arr[i-1]+arr[i+1];
  i++;
  replaceSum(root->right,arr,i);
}

void replace(Node* root)
{
  vector<int>arr;
  arr.push_back(0);
  inorder(root,arr);
  arr.push_back(0);
  
  replaceSum(root,arr,1);
}
