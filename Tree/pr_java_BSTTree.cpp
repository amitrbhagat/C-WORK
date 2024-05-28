// #include <bits/stdc++.h>
// using namespace std;

// class node
// {
// public:
//   int data;
//   node *left, *right;
//   node(int val)
//   {
//     data = val;
//     left = NULL;
//     right = NULL;
//   }
// };

// node *insert(node *root, int val)
// {
//   if (root == NULL)
//   {
//     root = new node(val);
//     return root;
//   }

//   if (root->data > val)
//   {
//     root->left = insert(root->left, val);
//   }
//   else
//   {
//     root->right = insert(root->right, val);
//   }

//   return root;
// }

// void inorder(node *root)
// {

//   if (root != NULL)
//   {
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
//   }
// }
// // int search(node *root,int key){

// //     if(root==NULL){
// //         return false;
// //     }

// //     if(root->data==key){
// //         return true;
// //     }

// //     if(key<root->data){
// //       return search(root->left,key);
// //     }else{
// //       return search(root->right,key);
// //     }
// // }

// // void print(node *root,int k1,int k2){
// //     if(root==NULL){
// //         return;
// //     }

// //     print(root->left,k1,k2);

// //     if(k1<=root->data && k2>=root->data){
// //         cout<<root->data<<" ";
// //     }

// //     print(root->right,k1,k2);
// // }

// // void printpath(list<int>path1){
// //     for(auto i=path1.begin();i!=path1.end();i++){
// //         cout<<*i<<" ";
// //     }
// //     cout<<endl;
// // }

// // void root2leaf(node *root,list<int>path){

// //     if(root==NULL){
// //         return;
// //     }

// //     path.push_back(root->data);

// //     if(root->left==NULL && root->right==NULL){
// //         printpath(path);
// //     }

// //     root2leaf(root->left,path);
// //     root2leaf(root->right,path);

// //     path.pop_back();
// // }

// // int isvalid(node *root,node *min,node *max){

// //     if(root==NULL){
// //         return true;
// //     }

// //     if(min!=NULL && min->data>=root->data){
// //         return false;
// //     }

// //     else if(max!=NULL && max->data<=root->data){
// //         return false;
// //     }

// //     return isvalid(root->left,min,root) &&
// //     isvalid(root->right,root,max);
// // }

// // node *mirror(node *root){
// //     if(root==NULL){
// //         return NULL;
// //     }

// //     node *leftsubtree=mirror(root->left);
// //     node *rightsubtree=mirror(root->right);

// //     root->left=rightsubtree;
// //     root->right=leftsubtree;

// //     return root;
// // }

// int main()
// {
//   int values[] = {5, 1, 3, 4, 2, 7};
//   node *root = NULL;
//   int n = sizeof(values) / sizeof(values[0]);

//   for (int i = 0; i < n; i++)
//   {
//     root = insert(root, values[i]);
//   }

//   // inorder (root);

//   // int key=6;
//   // cout<<search(root,key)<<endl;

//   // if(search(root,key)){
//   //     cout<<"found";
//   // }else{
//   //      cout<<"not found";
//   // }

//   //  print(root,5,7);

//   //  list<int>path2;
//   //  root2leaf(root,path2);

//   // cout<<isvalid(root,NULL,NULL);

//   mirror(root);

//   return 0;
// }



#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node *left, *right;
  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

node *insert(node *root, int val)
{
  if (root == NULL)
  {
    root = new node(val);
    return root;
  }

  if (root->data > val)
  {
    root->left = insert(root->left, val);
  }
  else
  {
    root->right = insert(root->right, val);
  }

  return root;
}

void inorder(node *root)
{

  if (root != NULL)
  {
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
  }
}
  ////remaining
class Info{
    public:
    bool isBST;
    int max,min,size;
    Info(bool isBS,int sze,int mni,int mxe){
        isBST=isBS;
        size=sze;
        min=mni;
        max=mxe;
    }
};

static int maxBST=0;

Info largestBST(node *root){
    
    if(root==NULL){
        return{true,0,INT_MAX,INT_MIN};
    }
    
    Info leftInfo=largestBST(root->left);
    Info rightInfo=largestBST(root->right);
    int size=leftInfo.size+rightInfo.size+1;
    int mn=min(root->data,min(leftInfo.min,rightInfo.min));
    int mx=max(root->data,max(leftInfo.max,rightInfo.max));
    
    if(root->data<=leftInfo.min || root->data>=rightInfo.max){
        return {false,size,mn,mx};
    }
    
    if(leftInfo.isBST && rightInfo.isBST){
        maxBST=max(maxBST,mx);
        return {true,size,mn,mx};
    }
    
    return {false,size,mn,mx};
}

int main()
{
//   int values[] = {5, 1, 3, 4, 2, 7};
//   node *root = NULL;
//   int n = sizeof(values) / sizeof(values[0]);

//   for (int i = 0; i < n; i++)
//   {
//     root = insert(root, values[i]);
//   }

//   inorder (root);


  node *root=new node(50);
  root->left=new node(30);
  root->left->left=new node(5);
  root->left->right=new node(20);
  root->right=new node(60);
  root->right->left=new node(45);
  root->right->right=new node(70);
  root->right->right->left=new node(65);
  root->right->right->right=new node(80);

  Info info=largestBST(root);
  cout<<maxBST;
  return 0;
}
