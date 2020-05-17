#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class LRUCache {
public:
    class ll{
        public:
        int key;
        ll* next;
        ll(int data){key = data; next=NULL;}
    };
    
    int cap;
    unordered_map<int,int> cache;
    unordered_map<int,ll*> ll_add;
    ll* head=NULL;
    ll* tail=NULL;
    int sizeSoFar=0;
    
    void push_back_ll(int key){
        ll* temp = new ll(key);
        if(tail && tail->key == key){
            ll_add[key]=tail;
            sizeSoFar++;
            return;
        }
        else if(head==NULL && tail ==NULL){
            head=temp;
            tail=temp;
        }
        else if(!head)
            head=tail;
        else{
            tail->next = temp;
            tail=temp;
        }
        ll_add[key]=temp;
        sizeSoFar++;
    }
    void pop_front_ll(){
        
        head=head->next;
        sizeSoFar--;
    }
    
    void remove_ll(int key){
        
        ll * temp = ll_add[key];
        if(temp->next == tail)
            tail=temp;
        if(temp->next!=NULL){
            temp->key = temp->next->key;
            ll_add[temp->next->key] = temp;
            temp->next = temp->next->next;
        }
        
        ll_add[key]=NULL;
        sizeSoFar--;
    }
    
    LRUCache(int capacity) {
        
        cap=capacity;
    }
    
    int get(int key) {
        
        if(cache[key]==0)
            return -1;
        remove_ll(key);
        push_back_ll(key);
        return cache[key];
    }
    
    void put(int key, int value) {

        if(cache[key]==0){
            if(sizeSoFar==cap){
                int temp = head->key;
                pop_front_ll();
                cache[temp]=0;
            }    
        }   
        else
            remove_ll(key);
        
        push_back_ll(key);
        cache[key]=value;
    }
};


int main(){
    LRUCache *obj;
    vector<string> funcToCall = {"LRUCache","put","put","get","put","get","put","get","get","get"};
    vector<vector<int>>  valueToPass = {{2},{1,1},{2,2},{1},{3,3},{2},{4,4},{1},{3},{4}};
    for(int i =0;i<funcToCall.size();i++){

        if(funcToCall[i]=="LRUCache")
            obj = new LRUCache(valueToPass[i][0]);
        else if(funcToCall[i]=="put")
            obj->put(valueToPass[i][0],valueToPass[i][1]);
        else if(funcToCall[i]=="get")
            cout<<obj->get(valueToPass[i][0])<<endl;

    }

}

