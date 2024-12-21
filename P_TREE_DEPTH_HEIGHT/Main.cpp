#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id;
    Node* firstChild;
    Node* sibling;
};

Node* createNode(int id){
    Node* newNode = new Node();
    newNode -> id = id;
    newNode -> firstChild = NULL;
    newNode -> sibling = NULL;
    return newNode;
}

Node* makeRoot(int id){
    return createNode(id);
}

Node* findNode(Node* root, int id){
    if(root == NULL){
        return NULL;
    }

    else if(root -> id == id){
        return root;
    }

    root = root -> firstChild;
    while(root != NULL){
        Node* temp = findNode(root, id);
        if(temp != NULL){
            return temp;
        }   
        root = root -> sibling;
    }

    return NULL;
}

void insert(Node* root, int u, int v){
    Node* curr = findNode(root, v);
    Node* node = findNode(root, u);

    //not insert
    if(curr == NULL || node != NULL){
        return;
    }

    //curr don't have any child
    if(curr -> firstChild == NULL){
        curr -> firstChild = createNode(u);
        return;
    }

    //else
    curr =  curr -> firstChild;
    while(curr -> sibling != NULL){
        curr = curr -> sibling;
    }

    curr -> sibling = createNode(u);
    return;

}

int depth(Node* root, int u){
    if(root == NULL){
        return 0;
    }

    if(root -> id == u){
        return 1;
    }

    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    int n = 0;
    while(q.empty() == 0){
        n = q.size();
        cnt ++;
        while(n > 0){
            n --;
            Node* temp = q.front();
            q.pop();
            
            if(temp -> id == u){
                return cnt;
            }

            temp = temp -> firstChild;
            while(temp != NULL){
                q.push(temp);
                temp = temp -> sibling;
            }
        }
    }
    return cnt;
}

int heightTree(Node* root){
    if(root == NULL){
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int cnt = 0;
    int n = 0;
    while(q.empty() == 0){
        n = q.size();
        cnt ++;
        while(n > 0){
            n --;
            Node* temp = q.front();
            q.pop();

            temp = temp -> firstChild;
            while(temp != NULL){
                q.push(temp);
                temp = temp -> sibling;
            }
        }
    }
    return cnt; 
}

int height(Node* root, int u){
    return heightTree(root) - depth(root, u) + 1;
}

int main(){
    Node* root = NULL;
    string s;
    string tmp;
    string a[3];
    int i = 0;
    while(true){
        getline(cin, s);

        if(s == "*") break;

        else{
            stringstream ss(s);
            i = 0;
            while(ss >> tmp){
                a[i] = tmp;
                i ++;
            }

            if(a[0] == "MakeRoot"){
                root = makeRoot(stoi(a[1]));
            }
            else if(a[0] == "Insert"){
                insert(root, stoi(a[1]), stoi(a[2]));
            }
            else if(a[0] == "Height"){
                cout << height(root, stoi(a[1])) << endl;
            }
            else if(a[0] == "Depth"){
                cout << depth(root, stoi(a[1])) << endl;
            }
        }

    };

    return 0;
}