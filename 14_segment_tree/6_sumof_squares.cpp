/*
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
Input
There will be T (T <= 25) test cases in the input file. First line of the input contains two positive integers, N (N <= 100,000) and Q (Q <= 100,000). 
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:

2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and -1,000 <= x <= 1,000).
Output
For each test case output the “Case <caseno>:” in the first line and from the second line output the sum of squares for each operation of type 2. Intermediate overflow will not occur with proper use of 64-bit signed integer.
Input:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Output:
Case 1:
30
7
13
Case 2:
1
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class node{
    public:
        // for tree - a = sum of squares
        // for tree - b = sum of elements
        // for lazy - a = value for increment 
        // for lazy - b = value for setting
        ll a=0;
        ll b=0;
};

void build(ll *arr,node *tree,ll s,ll e,ll i){
    // base case
    if(s==e){
        tree[i].a=arr[s]*arr[s];
        tree[i].b=arr[s];
        return;
    }
    // building children
    ll mid=(s+e)/2;
    build(arr,tree,s,mid,i*2);
    build(arr,tree,mid+1,e,i*2+1);
    // setting current
    tree[i].a=tree[i*2].a+tree[i*2+1].a;
    tree[i].b=tree[i*2].b+tree[i*2+1].b;
}

void update_inc(ll *arr,node *tree,node *lazy,ll s,ll e,ll i,ll l,ll r,ll val){
    // outside bounds
    if(s>e){
        return;
    }
    // if lazy updation left
    if(lazy[i].a!=0){
        // update current index of the tree
        tree[i].a+=(r-l+1)*lazy[i].a*lazy[i].a+2*lazy[i].a*tree[i].b;
        tree[i].b+=(r-l+1)*lazy[i].a;
        if(s!=e){
            lazy[i*2].a+=lazy[i].a;
            lazy[i*2+1].a+=lazy[i].a;
        }
        lazy[i].a=0;
    }
    if(lazy[i].b!=0){
        // update current index of the tree
        tree[i].a=(r-l+1)*lazy[i].b*lazy[i].b;
        tree[i].b=(r-l+1)*lazy[i].b;
        if(s!=e){
            lazy[i*2].b=lazy[i].b;
            lazy[i*2+1].b=lazy[i].b;
        }
        lazy[i].b=0;
    }
    // 3 cases
    // completely outside -return 
    if(l>e||r<s){
        return;
    }
    // completely inside -update
    if(s>=l&&e<=r){
        tree[i].a+=(r-l+1)*val*val+2*val*tree[i].b;
        tree[i].b+=(r-l+1)*val;
        // if its not the root node - then tell lazy to update children later
        if(s!=e){
            lazy[i*2].a+=val;
            lazy[i*2+1].a+=val;
        }
        // lazy[i].a=0;
        return;
    }
    // partial - build both left and right then update current
    ll mid=(s+e)/2;
    update_inc(arr,tree,lazy,s,mid,i*2,l,r,val);
    update_inc(arr,tree,lazy,mid+1,e,i*2+1,l,r,val);
    tree[i].a=tree[i*2].a+tree[i*2+1].a;
    tree[i].b=tree[i*2].b+tree[i*2+1].b;
}

// this is the lazy setter function
void lazy_update_b(node* tree, node* lazy, int start, int end, int current_position,int left, int right,  int x)
{
	if (start > end)
	{
		return;
	}
	if (lazy[current_position].b != 0)
	{
		tree[current_position].b = (right-left + 1) * (lazy[current_position].b);
		tree[current_position].a = (right-left + 1) * (lazy[current_position].b * lazy[current_position].b);
		if (start != end)
		{
			lazy[2 * current_position].b = lazy[current_position].b;
			lazy[2 * current_position+1].b = lazy[current_position].b;
		}
		lazy[current_position].b = 0;
	}

	//completely outside
	if (start > right || end < left)
	{
		return;
	}
	//complete overlap
	if (start >= left && end <= right)
	{
		tree[current_position].a = (right-left + 1) * (x * x);
		tree[current_position].b = (right-left + 1) * x;
		if (start != end)
		{
			lazy[2 * current_position].b = x;
			lazy[2 * current_position + 1].b = x;
		}
		return;
	}
	//partial overlap
	int mid = (start + end) / 2;
	lazy_update_b(tree, lazy, start, mid,2 * current_position, left, right,  x);
	lazy_update_b(tree, lazy, mid+1, end,2 * current_position+1, left, right,  x);
	tree[current_position].b = tree[2 * current_position].b + tree[2 * current_position + 1].b;
	tree[current_position].a = tree[2 * current_position].a + tree[2 * current_position + 1].a;
	return;
}

// this function shows error in 1 test case
void update_set(ll *arr,node *tree,node *lazy,ll s,ll e,ll i,ll l,ll r,ll val){
    // outside bounds
    if(s>e){
        return;
    }
    // if lazy updation left
    // if(lazy[i].a!=0){
    //     // update current index of the tree
    //     tree[i].a+=(r-l+1)*lazy[i].a*lazy[i].a+2*lazy[i].a*tree[i].b;
    //     tree[i].b+=(r-l+1)*lazy[i].a;
    //     if(s!=e){
    //         lazy[i*2].a+=lazy[i].a;
    //         lazy[i*2+1].a+=lazy[i].b;
    //     }
    //     lazy[i].a=0;
    // }
    if(lazy[i].b!=0){
        // update current index of the tree
        tree[i].a=(r-l+1)*lazy[i].b*lazy[i].b;
        tree[i].b=(r-l+1)*lazy[i].b;
        if(s!=e){
            lazy[i*2].b=lazy[i].b;
            lazy[i*2+1].b=lazy[i].b;
        }
        lazy[i].b=0;
    }
    // 3 cases
    // completely outside -return 
    if(l>e||r<s){
        return;
    }
    // completely inside -update
    if(s>=l&&e<=r){
        tree[i].a=(r-l+1)*val*val;
        tree[i].b=(r-l+1)*val;
        // if its not the root node - then tell lazy to update children later
        if(s!=e){
            lazy[i*2].b=val;
            lazy[i*2+1].b=val;
        }
        // lazy[i].b=0;
        return;
    }
    // partial - build both left and right then update current
    ll mid=(s+e)/2;
    update_inc(arr,tree,lazy,s,mid,i*2,l,r,val);
    update_inc(arr,tree,lazy,mid+1,e,i*2+1,l,r,val);
    tree[i].a=tree[i*2].a+tree[i*2+1].a;
    tree[i].b=tree[i*2].b+tree[i*2+1].b;
}

int query(node *tree,node *lazy,ll s,ll e,ll i,ll l,ll r){
    if(s>e){
        return 0;
    }
    // if lazy updation left
    if(lazy[i].a!=0){
        // update current index of the tree
        tree[i].a+=(r-l+1)*lazy[i].a*lazy[i].a+2*lazy[i].a*tree[i].b;
        tree[i].b+=(r-l+1)*lazy[i].a;
        if(s!=e){
            lazy[i*2].a+=lazy[i].a;
            lazy[i*2+1].a+=lazy[i].a;
        }
        lazy[i].a=0;
    }
    if(lazy[i].b!=0){
        // update current index of the tree
        tree[i].a=(r-l+1)*lazy[i].b*lazy[i].b;
        tree[i].b=(r-l+1)*lazy[i].b;
        if(s!=e){
            lazy[i*2].b=lazy[i].b;
            lazy[i*2+1].b=lazy[i].b;
        }
        lazy[i].b=0;
    }
    // 3 cases
    // out
    if(l>e||r<s){
        return 0;
    }
    // inside
    if(s>=l&&e<=r){
        return tree[i].a;
    }
    // partial
    ll mid=(s+e)/2;
    ll lans=query(tree,lazy,s,mid,i*2,l,r);
    ll rans=query(tree,lazy,mid+1,e,i*2+1,l,r);
    return lans+rans;
}

void view_tree(ll n,node *tree){
    for(int i=1;i<2*n;i++){
        cout<<tree[i].a<<" "<<tree[i].b<<endl;
    }
}

void view_lazy(ll n,node *lazy){
    for(int i=1;i<2*n;i++){
        cout<<lazy[i].a<<" "<<lazy[i].b<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
    ll t;
    cin>>t;
    for(int i=0;i<t;i++){
        cout<<"Case "<<i+1<<":"<<endl;
        ll n,q;
        cin>>n>>q;
        ll *arr=new ll[n+1];
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }

        node *tree=new node[4*n];
        node *lazy=new node[4*n];

        build(arr,tree,1,n,1);
        // view_tree(n,tree);
        // view_lazy(n,lazy);

        while(q--){
            int typeop;
            cin>>typeop;
            if(typeop==2){
                // query - return sum of squares
                ll a,b;
                cin>>a>>b;
                ll ans=query(tree,lazy,1,n,1,a,b);
                cout<<ans<<endl;
            }else if(typeop==1){
                // update - increment a-b with x
                ll a,b,x;
                cin>>a>>b>>x;
                update_inc(arr,tree,lazy,1,n,1,a,b,x);
                // view_lazy(n,lazy);
                // view_tree(n,tree);
            }else if(typeop==0){
                // update - set a-b to x
                ll a,b,x;
                cin>>a>>b>>x;
                // update_set(arr,tree,lazy,1,n,1,a,b,x);
                lazy_update_b(tree,lazy,1,n,1,a,b,x);
                // view_lazy(n,lazy);
                // view_tree(n,tree);
            }
        }
    }
}