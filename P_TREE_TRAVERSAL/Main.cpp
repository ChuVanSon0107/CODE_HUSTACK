#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;
};

Node* createNode(int id){
    Node* newNode = new Node();
    newNode -> id = id;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

Node* findNode(Node* root, int id){
    if(root == NULL){
        return NULL;
    }
    else if(root -> id == id){
        return root;
    }

    Node* temp = NULL;
    if(root -> left != NULL){
        temp = findNode(root -> left, id);
        if(temp != NULL){
            return temp;
        }
    }

    if(root -> right != NULL){
        temp = findNode(root -> right, id);
        if(temp != NULL){
            return temp;
        }
    }

    return NULL;
}

void addLeft(Node* root, int u, int v){
    Node* curr = findNode(root, v);
    Node* temp = findNode(root, u);

    if(temp != NULL || curr -> left != NULL){
        return;
    }

    curr -> left = createNode(u);
    return;

}

void addRight(Node* root, int u, int v){
    Node* curr = findNode(root, v);
    Node* temp = findNode(root, u);

    if(temp != NULL || curr -> right != NULL){
        return;
    }

    curr -> right = createNode(u);
    return;

}

void preOrder(Node* root){
    if(root == NULL) return;

    cout << root -> id << " ";
    preOrder(root -> left);
    preOrder(root -> right);
    return;
}

void inOrder(Node* root){
    if(root == NULL) return;

    inOrder(root -> left);
    cout << root -> id << " ";
    inOrder(root -> right);
    return;
}

void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root -> left);
    postOrder(root  -> right);
    cout << root -> id << " ";
    return;
}

int main(){
    string s;
    string a[3];
    int i = 0;
    int u, v;
    struct Node* root;
    while(true){
        getline(cin, s);
        if(s == "*"){
            break;
        }
        else{
            stringstream ss(s);
            string tmp;
            i = 0;
            while(ss >> tmp){
                a[i] = tmp;
                i ++;
            }
            if(a[0] == "MakeRoot"){
                u = stoi(a[1]);
                root = createNode(u);
            }
            else if(a[0] == "AddLeft"){
                u = stoi(a[1]);
                v = stoi(a[2]);
                addLeft(root, u, v);
            }
            else if(a[0] == "AddRight"){
                u = stoi(a[1]);
                v = stoi(a[2]);
                addRight(root, u, v);
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