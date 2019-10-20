#include<bits/stdc++.h>
using namespace std;

typedef long long let;

class job{
	public:
		let id, deadline, profit;
		void get_data(let x, let y, let z){
			id = x;
			deadline = y;
			profit = z;
		}
};

bool comparison(job a, job b){
	return (a.profit > b.profit);
}

void print_job_schedule(job arr[], let n){
	sort(arr, arr+n, comparison);
	let i, j, ans[n];
	let slot[n] = {0};
	for(i=0;i<n;++i){
		for(j=min(n, arr[i].deadline)-1; j>=0; --j){
			if(!slot[j]){
				ans[j] = i;
				slot[j] = 1;
				break;
			}
		}
	}
	for(i=0;i<n;++i){
		if(slot[i]){
			cout<<arr[ans[i]].id<<" ";
		}
	}
}

int main(){
	freopen("input.txt", "r", stdin);

	job arr[100];
	let n; cin>>n;
	let i; for(i=0;i<n;++i){
		let id, deadline, profit;
		cin>>id>>deadline>>profit;
		arr[i].get_data(id, deadline, profit);
	}

	print_job_schedule(arr, n);
	return 0;
}