#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* constructBST(vector<int> preorder, vector<int> inorder)
{
    if(preorder.size()==1) 
    {
        TreeNode* node = new TreeNode();
        node->data = inorder[0];
        node->left = NULL;
        node->right = NULL;
        return node;
    }

    TreeNode* node = new TreeNode();
    node->data = preorder[0];

    auto it = find(inorder.begin(),inorder.end(),preorder[0]);
    int root_index = it - inorder.begin();

    auto first = inorder.begin();
    auto last = inorder.begin() + root_index;
    vector<int> inorder_left(first, last); //slicing inorder vector

    auto first1 = inorder.begin()+root_index+1;
    auto last1 = inorder.end();
    vector<int> inorder_right(first1, last1);

    vector<int> preorder_left;
    int i;
    for(i=1;i<preorder.size();i++)
    {
        if(binary_search(inorder_left.begin(),inorder_left.end(),preorder[i]))
        {
            preorder_left.push_back(preorder[i]);
        }
        else{break;}
    }

    vector<int> preorder_right;
    for(int j=i;j<preorder.size();j++)
    {
        preorder_right.push_back(preorder[j]);
    }
   
    node->left = constructBST(preorder_left,inorder_left);
    node->right = constructBST(preorder_right,inorder_right);
    return node;
}

int main()
{
    int n; cin>>n;
    vector<int> A,preorder,inorder; //A= preorder
    
    for(int i=0;i<n;i++)
    {
        int x; 
        cin>>x; 
        A.push_back(x);
        preorder.push_back(x);
        inorder.push_back(x);
    }
    sort(inorder.begin(),inorder.end()); //inorder

    struct TreeNode* root;
    root = constructBST(preorder,inorder);
    
    cout<<root->data;
}