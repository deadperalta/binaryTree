vector<vector<int>>rootToLeaf(Node* root)
{
  queue<pair<Node*,vector<int>>q;
  q.push({root,{root->data}});
  vector<vector<int>>ans;
  
  while(!q.empty())
  {
    Node* curr=q.front().first;
    vector<int>path=q.front().second;
    q.pop();
    
    if(curr->left == NULL && curr->right == NULL)
    {
      ans.push_back(path);
    }
    
    if(curr->left)
    {
      path.push_back(curr->left);
      q.push({curr->left,path});
      path.pop_back();
    }
    if(curr->right)
    {
      path.push_back(curr->right);
      q.push({curr->right,path});
      path.pop_back();
    }
  }
  return ans;
}
