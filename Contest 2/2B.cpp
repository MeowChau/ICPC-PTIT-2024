#include <bits/stdc++.h>
using namespace std;
#define FOR9=(a,b,i) for(int i = a; i < b; i++)
typedef long long ll; 
	
	vector<ll> check(){
		vector <ll> kq;
		FOR(1,9,i){
			kq.push_back(i);
		}
		FOR(0,10,d1){
			FOR(0,10,d2){
				if(d1 != d2){
					FOR(2,11,len){
						for(int mask = 1; mask < (1 << len); mask++){
							ll num = 0;
							FOR(0, len,i){
								num = num * 10 + ((mask & (1 << i)) ? d1 : d2);
							}
							if(num > 0){
								kq.push_back(num);
							}
						}
					}
				}
			}
		}
		sort(kq.begin(), kq.end());
		kq.erase(unique(kq.begin(), kq.end()), kq.end());
		return kq;
	}
int main(){
	int n; cin >> n;
	vector <ll> nums = check();
	int count = upper_bound(nums.begin(),nums.end(), n) - nums.begin();
	cout << cout << endl;
	return 0;
}