#include <iostream>
using namespace std;

struct node{
    int val;
    node * next;
    node * prev;
    int cnt;
};
struct list{
    node * cur;
    node * front;
    long long val_size = 0;

    list(){
        cur = NULL;
        front = NULL;
    }


    long long size(){
        return val_size;
    }

    void add(int x){
        node * item = new node();
        item->val = x;
        item->cnt = 1;
        val_size++;
        if(front == NULL){
            front = cur = item;
        }else{
            cur->next = item;
            item->prev = cur;
            cur = item;   
        }
    }

    void show(){
        if(!is_empty()){
            node * temp = front;
            while(temp != NULL){
                cout << temp->val << " ";
                temp = temp->next;
            }
        }
    }

    node * find(int x){
        node * null = new node();
        null->val = -1;
        if (!is_empty()){
            node * temp = front;
            while (temp != NULL){
                if (temp->val == x){
                    return temp;
                } else {
                    temp = temp->next;
                }
            }
            return null;
        }
        return null;
    }

    void del(int x){
        node * item = find(x);
        if (item->val != -1){
            if (item->prev == NULL && item->next != NULL){
                node * temp = front;
                front = item->next;
                front->prev = NULL;
                delete(temp);
            } else if (item->prev != NULL && item->next == NULL){
                node * temp = cur;
                cur = cur->prev;
                cur->next = NULL;
                delete(temp);
            } else if (val_size == 1){
                delete(item);
                front = cur = NULL;
            } else {
                item->prev->next = item->next;
                item->next->prev = item->prev;
                delete(item);
            }
            val_size--;
        }
    }

    void sort_by_val(){
        node* current = front, * index = NULL;
        if(front == NULL){
            return;
        }else{
            while(current != NULL){
                index = current->next;
                while(index != NULL){
                    if (current->val > index->val){
                        int temp = current->val;
                        current->val = index->val;
                        index->val = temp;
                        int temp2 = current->cnt;
                        current->cnt = index->cnt;
                        index->cnt = temp2;
                    }
                    index = index->next;
                }
                current = current->next;
            }
        }
    }
    

    bool is_empty(){
        return val_size == 0;
    }

    bool in_list(int x){
        return find(x)->val != -1;
    }

};

int main(){
    list l;
    string s;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
    while(cin >> s){
        int mem = stoi(s.substr(1,s.size()));
        if(s[0] == '+'){
            l.add(mem);
        }
        else{
            if(l.in_list(mem)){
                l.del(mem);
            }else{
                cout << "ERROR";return 0;
            }
        }
    }
    if(l.is_empty() == true){cout << "EMPTY";}
    else{
        l.sort_by_val();
        l.show();
    }
    
}