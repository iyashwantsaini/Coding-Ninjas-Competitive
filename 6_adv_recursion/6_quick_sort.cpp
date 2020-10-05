// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.


// Input format :
// Line 1 : Integer n i.e. Array size
// Line 2 : Array elements (separated by space)
// Output format :
// Array elements in increasing order (separated by space)
// Constraints :
// 1 <= n <= 10^3
// Sample Input 1 :
// 6 
// 2 6 8 5 4 3
// Sample Output 1 :
// 2 3 4 5 6 8
// Sample Input 2 :
// 5
// 1 5 2 7 3
// Sample Output 2 :
// 1 2 3 5 7 

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

// int partition(int *input,int start,int end){
//     int num=input[end]; //pivot element
//     int countless=start-1;
//     for(int i=start;i<=end-1;i++){
//         if(input[i]<num){
//             countless++;
//             swap(&input[countless], &input[i]); 
//         }
//     }
//     swap(&input[countless+1],&input[end]);
//     return countless+1;
// }

int partition(int *a,int s,int e){
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(a[i]<=a[s]){
            count++;
        }
    }
    swap(&a[s],&a[s+count]);
    for(int i=s,j=e;i<count+s && j>count+s;){
        if(a[i]<=a[s+count]){
            i++;
        }else if(a[j]>a[s+count]){
            j--;
        }else{
            swap(&a[i++],&a[j--]);
        }
    }
    return count+s;
}

void quick_sort(int *input,int start,int end){
    if(start<end){
    	int c=partition(input,start,end);
    	quick_sort(input,start,c-1);
    	quick_sort(input,c+1,end);
    }
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
	quick_sort(input,0,size-1);    
}
