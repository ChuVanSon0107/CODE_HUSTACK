#include <bits/stdc++.h>
using namespace std;

struct Tree {
    int id;
    struct Tree* sibling;
    struct Tree* child;
};

struct Tree* createNode(int id){
    struct Tree* node = new struct Tree();
    node -> id = id;
    node -> sibling = NULL;
    node -> child = NULL;
    return node;
}

struct Tree* makeRoot(int id){
    return createNode(id);
}

void addSibling(struct Tree** root, int id){
    struct Tree* temp = (*root);
    if(temp == NULL){
        (*root) = createNode(id);
        return;
    }
    
    //else
    while(temp -> sibling != NULL){
        temp = temp -> sibling;
    }
    
    temp -> sibling = createNode(id);
    return;
}

struct Tree* findNode(struct Tree* root, int id){
    if(root == NULL){
        return NULL;
    }

    if(root -> id == id){
        return root;
    }

    struct Tree* temp = NULL;
    struct Tree* node = root -> child;
    while(node != NULL){
        temp = findNode(node, id);
        if(temp != NULL) return temp;
        node = node -> sibling;
    }
    return NULL;
}

void insert(struct Tree** root, int parentID, int childID){
    struct Tree* parent = findNode((*root), parentID);
    struct Tree* child = findNode((*root), childID);
    if(parent != NULL && child == NULL){
        addSibling(&(parent -> child), childID);
    }
    return;
}

void preOrder(struct Tree* root){
    if(root == NULL) return;

    //root is not NULL
    cout << root -> id << " ";
    struct Tree* node = root -> child;
    while(node != NULL){
        preOrder(node);
        node = node -> sibling;
    } 
    return;
}

void inOrder(struct Tree* root) {
    if (root == NULL) return;

    // Duyệt các con trái
    struct Tree* node = root -> child;
    if (node != NULL) {
        inOrder(node); // Duyệt con trái nhất
    }

    // In giá trị nút hiện tại
    cout << root -> id << " ";

    // Duyệt các anh em của con đầu tiên
    if (node != NULL) {
        node = node -> sibling;
        while (node != NULL) {
            inOrder(node);
            node = node -> sibling;
        }
    }
}

void postOrder(struct Tree* root){
    if(root == NULL) return;

    //root is not NULL
    struct Tree* node = root -> child;
    while(node != NULL){
        postOrder(node);
        node = node -> sibling;
    }
    cout << root -> id << " ";
    return;
}


int main(){
    string s;
    string a[3];
    int cnt = 0;
    int u, v;
    struct Tree* root;
    while(true){
        getline(cin, s);
        if(s == "*"){
            break;
        }
        else{
            stringstream ss(s);
            string tmp;
            cnt = 0;
            while(ss >> tmp){
                a[cnt] = tmp;
                cnt ++;
            }
            if(a[0] == "MakeRoot"){
                u = stoi(a[1]);
                root = makeRoot(u);
            }
            else if(a[0] == "Insert"){
                u = stoi(a[1]);
                v = stoi(a[2]);
                insert(&root, v, u);
            }
            else if(a[0] == "InOrder"){
                inOrder(root);
                cout << endl;
            }
            else if(a[0] == "PreOrder"){
                preOrder(root);
                cout << endl;
            }
            else if(a[0] == "PostOrder"){
                postOrder(root);
                cout << endl;
            }
        }
    }
    return 0;
}