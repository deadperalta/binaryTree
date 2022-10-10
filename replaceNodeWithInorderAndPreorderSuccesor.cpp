void inorderStore(Node* root,vector<int>&arr)
{
  if(root == NULL)
  {
    return;
  }
  
  inorderStore(root->left,arr);
  arr.push_back(root->data);
  inorderStore(root->right,arr);
}

void replaceNodeWithSum(Node* root,int arr[],int &i)
{
  if(root == NULL)
  {
    return;
  }
 
  replaceNodeWithSum(root->left,arr,i);
  root->data=arr[i-1]+arr[i+1];
  ++i;
  replaceNodeWithSum(root->right,arr,i);
}

void replaceNodeWithSumUtil(Node* root)
{
  if(root == NULL)
  {
    return;
  }
  
  vector<int>arr;
  arr.push_back(0);
  inorderStore(root,arr);
  arr.push_back(0);
  
  int i=1;
  replaceNodeWithSum(root,arr,i);
}

void preorderTraversal(Node* root)
{
  if(root == NULL)
  {
    return;
  }
  
  cout<<root->data<<" ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

int main()
{
  struct Node* root = getNode(1); /*         1        */
    root->left = getNode(2);        /*       /   \      */
    root->right = getNode(3);       /*     2      3     */
    root->left->left = getNode(4);  /*    /  \  /   \   */
    root->left->right = getNode(5); /*   4   5  6   7   */
    root->right->left = getNode(6);
    root->right->right = getNode(7);
 
    cout << "Preorder Traversal before tree modification:n";
    preorderTraversal(root);
 
    replaceNodeWithSumUtil(root);
 
    cout << "\nPreorder Traversal after tree modification:n";
    preorderTraversal(root);
 
    return 0;
}
