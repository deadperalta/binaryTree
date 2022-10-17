void fillPath(Node* root,vector<int>&v)
{
  if(root == NULL)
  {
    return;
  }
  v.push_back(root->data);
  if(root->left == NULL && root->right == NULL)
  {
    print(arr);
    v.pop_back();
    return;
  }
  
  fillPath(root->left,v);
  fillPath(root->right,v);
  v.pop_back();
}

void printPaths(Node* root)
{
  vector<int>v;
  fillPath(root,v);
}
