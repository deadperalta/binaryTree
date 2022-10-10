void preorder(Node* tree)
{
  if(tree == NULL)
  {
    return;
  }
  
  cout<<tree->data<<" ";
  preorder(tree->left);
  preorder(tree->right);
}
vector<Node*>getTrees(int in[],int st,int en)
{
  if(st > en)
  {
    return {NULL};
  }
  
  vector<Node*>trees;
  
  for(int i=st;i<=en;i++)
  {
    vector<Node*>ltree=getTrees(in,st,i-1);
    vector<Node*>rtree=getTrees(in,i+1,en);
    
    for(auto l:ltree)
    {
      for(auto r:rtree)
      {
        Node* root=new Node(in[i]);
        root->left=l;
        root->right=r;
        
        trees.push_back(root);
      }
    }
  }
  return trees;
}

int main()
{
    int in[] = {4, 5, 7};
    int n = sizeof(in) / sizeof(in[0]);
 
    vector<Node *> trees = getTrees(in, 0, n-1);
 
    cout << "Preorder traversals of different "
         << "possible Binary Trees are \n";
    for (int i = 0; i < trees.size(); i++)
    {
        preorder(trees[i]);
        printf("\n");
    }
    return 0;
}
