#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    Node(int k,int v):key(k), val(v), prev(NULL), 
    next(NULL){}
};
class LRU{
private:
    int capacity;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;
    void addNode(Node* node){
       Node* temp = head->next;
       node->next = temp;
       node->prev = head;
       head->next = node;
       temp->prev = node;
    }
    void removeNode(Node* node){
        Node* prevNode=node->prev;
        Node* nextNode=node->next;
        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    void moveToFront(Node* node){
        removeNode(node);
        addNode(node);
    }
    Node* removeTail(){
        Node* lr=tail->prev;
        removeNode(lr);
        return lr;
    }
public:
    LRU(int cap):capacity(cap){
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
    }
    int get(int key){
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* node=mp[key];
        moveToFront(node);
        return node->val;
    }
    void put(int key,int val){
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            node->val=val;
            moveToFront(node);
        }
        else{
            if(mp.size()==capacity){
                Node* lr=removeTail();
                mp.erase(lr->key);
                delete lr;
            }
            Node* newNode=new Node(key,val);
            mp[key]=newNode;
            addNode(newNode);
        }
    }
    void display(){
        Node* curr=head->next;
        while(curr!=tail){
            cout<<curr->val;
            curr=curr->next;
        }
        cout<<endl;
    }
    
};

int main()
{
    LRU cache(2);
    cache.put(1,1);
    cache.put(2,2);
    cache.display();
    cout<<cache.get(1)<<endl;
    cache.display();
    cache.put(3,3);
    cache.display();
    cout<<cache.get(2)<<endl;
    cache.put(4,4);
    cache.display();
    cout<<cache.get(1)<<endl;
    cout<<cache.get(3)<<endl;
    cout<<cache.get(4)<<endl;

    return 0;
}