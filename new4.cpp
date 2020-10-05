#include<bits/stdc++.h>
#define crap ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
//#define int ll

using namespace std;

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*a = temp;
}

class MinHeap{
	int *harr;
	int capacity;
	int heap_size;

public:
	MinHeap(int capacity);

	void MinHeapify(int);
	int parent(int i){
		return (i-1)/2;
	}
	int left(int i){
		return (2*i+1);
	}
	int right(int i){
		return (2*i+2);
	}

	int extractMin();

	

	int getMin(){
		if(heap_size>0)
			return harr[0];
		return INT_MAX;

	};

	int sz1(){
		return heap_size;
	}

	

	void insertKey(int k);

};

MinHeap::MinHeap(int cap){
	heap_size =0;
	capacity = cap;
	harr = new int[cap];
}

int MinHeap:: extractMin(){
	if(heap_size <= 0) return INT_MAX;
	if(heap_size==1){
		heap_size--;
		return harr[0];
	}
	int root = harr[0];
	harr[0] = harr[heap_size-1];
	heap_size--;
	MinHeapify(0);
	return root;
}

void MinHeap::insertKey(int k){
	if(heap_size==capacity) return;
	heap_size++;
	harr[heap_size-1] = k;
	MinHeapify(parent(heap_size-1));
}

void MinHeap::MinHeapify(int i){
	int smallest = i;
	int l = left(i);
	int r = right(i);
	if(l<heap_size && harr[l] < harr[i])
		smallest = l;
	if(r< heap_size && harr[r] < harr[smallest])
		smallest = r;
	if(smallest != i){
		swap(&harr[i],&harr[smallest]);
		MinHeapify(smallest);
	}

}



int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
   
    crap;
    
    MinHeap pq =  MinHeap(11);
    pq.insertKey(1);
    pq.insertKey(19);
    pq.insertKey(3);
    cout<<pq.extractMin()<<endl;
    cout<<pq.getMin()<<endl; 
    cout<<pq.sz1()<<endl;
}


