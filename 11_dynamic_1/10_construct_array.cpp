// https://www.hackerrank.com/challenges/construct-the-array/problem

// method1 - ninjas method
// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    long m=1000000007;
    long one_count=1;
    long non_one_count=0;

    for(int i=1;i<n;i++){
        long prev_one_count=one_count;
        one_count=(non_one_count*(k-1))%m;
        non_one_count=(prev_one_count+(non_one_count*(k-2))%m)%m;
    }

    if(x==1){
        return one_count;
    }else{
        return non_one_count;
    }
}

// method2 -using some storage
// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    
    long m=1000000007;

    long a[n]; //to store no of possibilities of length i ending at x
    long b[n]; //to store no of possibilities of length i not ending at x

    if(x!=1){
        a[0]=0;
        b[0]=1;
    }else{
        a[0]=1;
        b[0]=0;
    }

    for(int i=1;i<n;i++){
        a[i]=b[i-1]%m;
        b[i]=((a[i-1]*(k-1))%m+(b[i-1]*(k-2))%m)%m;
    }

    return a[n-1];

}

// method3 -using prev vars instead of storage, similar to last but just using 3 vars
// Complete the countArray function below.
long countArray(int n, int k, int x) {
    // Return the number of ways to fill in the array.
    
    long a,a_prev,b,b_prev;

    long m=1000000007;

    a_prev=x==1?1:0;
    b_prev=x==1?0:1;

    for(int i=1;i<n;i++){
        a=b_prev%m;
        b=((a_prev*(k-1))%m+(b_prev*(k-2))%m)%m;
        a_prev=a%m;
        b_prev=b%m;
    }
    return a;
}