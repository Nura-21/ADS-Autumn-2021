#include <iostream>
#include <vector>
using namespace std;

struct node{
    int val;
    node * left;
    node * right;
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct bst{
    int h = 0;
    int cnt = 0;
    vector<int> v; 
    node * _root;
    
    node * add(node * current, int x){
        if(current == NULL) return new node(x);

        if(current->val < x){
            current->right = add(current->right, x);
        }

        if(current->val > x){
            current->left = add(current->left, x);
        }

        return current;
    }

    bool find(node * current, int x){
        if(current == NULL) return false;
        if(current->val == x) return true;
        if(current->val > x) return find(current->left, x);
        return find(current->right, x);
    }

    void in_vector(node * current){
        if(current == NULL) return;
        in_vector(current->left);
        v.push_back(current->val);
        in_vector(current->right);
    }
    void print(node * current, int level){
        if(current != NULL){
            if(h < level){h = level;}
            print(current->left, level + 1);
            cout << current->val << " " << level << endl;
            print(current->right, level + 1);
        }
    }

    int height2(node * current){
        if(current == NULL){
            return 0;
        }
        int right_h = height2(current->right);
        int left_h = height2(current->left);
        return max(left_h,right_h) + 1;
    }

    int count_nodes(node * current){
        if (current != NULL){
            count_nodes(current->left);
            cnt++;
            count_nodes(current->right);
        }   
        return cnt;
    }

    int rightmost(node * current){
        if(current == NULL) return -1;
        if(current->right == NULL) return current->val;
        return rightmost(current->right);
    }

    int second_max(node * current){
        del(_root,rightmost(_root)); 
        return rightmost(_root);
    }

    node * del(node * current, int x){
        if(current == NULL) return NULL;
        if(current->val == x){
            if(current->right == NULL && current->left == NULL){
                delete current;
                return NULL;
            }else if(current->left != NULL && current->right == NULL){
                node * temp = current->left;
                delete current;
                return temp;
            }else if(current->right != NULL && current->left == NULL){
                node * temp = current->right;
                delete current;
                return temp;
            }else if(current->right != NULL && current->left != NULL){
               current->val = rightmost(current->left);
               current->left = del(current->left, current->val);
            }
        }else if(current->val < x){
            current->right = del(current->right, x);
            return current;
        }else if(current->val > x){
            current->left = del(current->left, x);
            return current;
        }
        return current;
    }

    bst(){
        _root = NULL;
    }

    void add(int x){
        if(find(x) == false){
            node * res = add(_root, x);
            if(_root == NULL){
                _root = res;
            }
        }
    }

    void in_vector(){
        in_vector(_root);
    }

    void del(int x){
        del(_root, x);
    }

    bool find(int x){
        return find(_root, x);
    }

    void print(){
        print(_root, 0);
        cout << endl;
    }
    void count_height(){
        cout << height2(_root);
    }
    void count_nodes(){
        cout << count_nodes(_root);
    }

    void second_max(){
        cout << second_max(_root);
    }
};

int main(){

    bst * tree = new bst();
    int n;
    while(cin >> n){
        if(n == 0) break;
        else tree->add(n);
    }
    tree->in_vector();
    cout << tree->v[tree->v.size() - 2];
}