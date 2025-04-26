#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node {

    public:
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }

};

void insertAtHead(Node* &head, int d) {

    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {

    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

void deleteNode(int position, Node* & head) { 

    if(position == 1) {
        Node* temp = head;
        head = head -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        curr -> next  = NULL;
        delete curr;

    }
}

bool isCircularList(Node* head) {
    //empty list
    if(head == NULL) {
        return true;
    }

    Node* temp = head -> next;
    while(temp != NULL && temp != head ) {
        temp = temp -> next;
    }

    if(temp == head ) {
        return true;
    }

    return false;
}
// bool solve(vector<int> arr) {
//     int s = 0;
//     int e = arr.size() - 1;
//     while (s < e) {
//         if (arr[s] != arr[e]) {
//             return false;
//         }
//         s++;
//         e--;
//     }
//     return true;
// }

// bool ispalindrome(Node* head) {
//     vector<int> arr;
//     Node* temp = head;

//     while (temp != NULL) {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }

//     bool ans = solve(arr);
//     return ans;
// }
Node* getmid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* reverse(Node* head) {
    Node* curr = head;
    Node* prev = NULL;
    Node* nextnode = NULL;

    while (curr != NULL) {
        nextnode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextnode;
    }
    return prev;
}

bool ispalindrome(Node* head) {
   
    Node* mid = getmid(head);

    Node* temp = mid->next;
    mid->next = reverse(temp);

    Node* head1 = head;
    Node* head2 = mid->next;

    while (head2 != NULL) {
        if (head1->data != head2->data) {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return true;
}

int main() {
    
    Node* node1 = new Node(1);
    cout << node1 -> data << endl;
    cout << node1 -> next << endl;
    
    Node* head = node1; 
    Node* tail = node1;
    print(head);

    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    print(head);

    if(ispalindrome(head)){
        cout<<"it is palindrome."<<endl;
    }
    else{
        cout<<"not a palindrome."<<endl;
    }

    return 0;
}