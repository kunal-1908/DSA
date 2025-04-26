#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100]; 
    int size;

    heap(){
        this->size = 0; 
    }

    void insert(int data){
        if(size >= 100) { 
            cout << "Heap overflow" << endl;
            return;
        }

        int index = size;
        arr[index] = data;
        size++; 

        while(index > 0){  
            int parent = (index - 1) / 2; 

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deletefromheap(){
        if(size <= 0){  // Changed size < 0 to size <= 0
            cout << "Nothing to delete." << endl;
            return;
        }

        arr[0] = arr[size - 1]; // Replace root with last element
        size--; // Reduce heap size

        int i = 0;
        while(true){  
            int leftindex = 2 * i + 1;
            int rightindex = 2 * i + 2;
            int largest = i;  

            if(leftindex < size && arr[leftindex] > arr[largest]){
                largest = leftindex;
            }
            if(rightindex < size && arr[rightindex] > arr[largest]){
                largest = rightindex;
            }

            if(largest != i){
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
};

int main(){
    heap h;
    h.insert(90);
    h.insert(70);
    h.insert(60);
    h.insert(80);
    h.insert(10);
    h.insert(20);
    h.insert(40);
    h.insert(50);

    h.print();
    
    h.deletefromheap();
    h.print();  // Print after deletion

    return 0;
}
