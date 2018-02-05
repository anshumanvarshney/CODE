
void printLeafNodes(node *root)
{
      if(root == NULL)       
        return;
       if(root->left == NULL && root->right==NULL)      
          cout<<root->data<<" "; 
       printLeafNodes(root->left); 
       printLeafNodes(root->right);      
}