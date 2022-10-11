void print(Node* root)
{
  cout<<root->data<<" ";
  
  if(root->left)
  {
    cout<<root->left<<" "<<root->right<<" ";
  }
  else
  {
    return;
  }
  
  if(root->left->left == NULL)
  {
    return;
  }
  
  queue<Node*>q;
  q.push(root->left);
  q.push(root->right);
  
  while(!q.empty())
  {
    Node* first=q.front();
    q.pop();
    
    Node* second=q.front();
    q.pop();
    
    cout<<first->left<<" "<<second->right<<" "<<first->right<<" "<<second->left<<" ";
    
    if(first->left->left)
    {
      q.push(first->left);
      q.push(second->right);
      q.push(first->right);
      q.push(second->left);
    }
  }
  return ;
}
