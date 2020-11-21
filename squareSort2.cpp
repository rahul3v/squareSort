#include <iostream>
#include <string>

using namespace std;

void sort(int arr[],int x,int pos,int size){
	int rsize=size/(x*2);
	
	//cout<<"\nup:"<<pos<<"@"<<rsize<<size<<endl;
	if(pos==rsize*x*2){
		rsize=(size%(x*2))-x;
		if(rsize<=0)return;
		cout<<"\n\nlast R :"<<rsize<<" on "<<pos<<" at "<<x<<endl<<endl;
	}else{
		rsize=x;
	}
	
	
	int L[x];//={6,10};
	int R[rsize];//={1,7};
	for (int i = 0;i < x; i++){
    	L[i] = arr[pos+i];
    	if(i>=rsize){continue;cout<<"skip:"<<i;continue;}
    	R[i] = arr[pos+i+x];

	}

    /*
	cout<<"\nOur Left::Right array"<<endl;
	for(int i=0;i<x;i++){
		cout<<L[i]<<" :: ";
		if(i<rsize)cout<<R[i];
		cout<<endl;
	}
	*/
	//concept from merge sort to short 2 sorted array
	int i=0,j=0,k=0;
	int n1=sizeof(L)/sizeof(L[0]),
		n2=sizeof(R)/sizeof(R[0]);
	
	while (i<n1 && j<n2) {
		arr[pos+k++]=(L[i] <= R[j])?L[i++]:R[j++];
    }
    
    while(i<n1){
    	arr[pos+k++]=L[i++];
    }
    while(j<n2){
    	arr[pos+k++] = R[j++];
    }

}

int main() {
	
	int arr[]={5,2,12,1,18,9,7,3,1,3,14,12,33,78,21,0,0,34,56,232,343,1,223,112,3,6,44,2,3324,4,322,32,1,2321,121,2,1,21,2,1223,2,5435,6557,6};
	
	int asize=sizeof(arr)/sizeof(arr[0]);

	cout<<"\nYour current all array:"<<asize<<endl;
	for(int k=0;k<asize;k++)
	cout<<arr[k]<<" ";

	int maxblock=(asize/2)*2+1;
	for(int i=1;i<maxblock;i*=2){

		for(int j=0;j<asize;j=j+(2*i)){
			sort(arr,i,j,asize);
		}

		cout<<"\nYour new all array :"<<i<<" with block "<<i*2<<endl;
		for(int k=0;k<asize;k++){
			if(k%i*2==0&&k!=0)cout<<",";
			cout<<arr[k]<<" ";
		}
	}

	return 0;
}
