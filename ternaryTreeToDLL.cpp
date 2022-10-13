Node* prev=NULL;
Node* next;

void convert(TreeNode* root)
{
  if(root == NULL)
  {
    return;
  }
  
  if(prev == NULL)
  {
    head=new Node(root->data);
  }
  else
  {
    prev->next=new Node(root->data);
  }
  prev=root;
  
  convert(root->left);
  convert(root->middle);
  convert(root->right);
}

Node* ternaryTreeToDLL(TreeNode* root)
{
  convert(root);
  return head;
}
