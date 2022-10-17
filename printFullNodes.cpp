vector<int>fullNodes(Node* root)
{
  queue<Node*>q;
  vector<int>ans;
  
  q.push(root);
  
  while(!q.empty())
  {
    Node* curr=q.front();
    q.pop();
    
    if(curr->left && curr->right)
    {
      ans.push_back(curr->data);
    }
    
    if(curr->left)
    {
      q.push(curr->left);
    }
    if(curr->right)
    {
      q.push(curr->right);
    }
  }
  return ans;
}
