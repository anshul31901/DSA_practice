https://leetcode.com/discuss/interview-question/5171196/OA-problem-Find-the-number-of-illumination-sources-for-each-point/

#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>

struct compare{
	bool operator()(pii&a,pii&b){
		return (a.second>b.second||(a.second==b.second&&a.first>b.first));
	}

};


int main(){
	int n;
	cin>>n;

	int m ;
	cin>>m;

	vector<pii>lamps;
	for(int i =0;i<n;i++){
		int a ,b;
		cin>>a>>b;
		lamps.push_back({a,b});
	}
	vector<int>points;
	for(int i =0;i<m;i++){
		int a ;
		cin>>a;
		points.push_back(a);
	}

	vector<int>pts = points;

  //sort intervals on basis of start
	sort(pts.begin(),pts.end());
	unordered_map<int,int>mp;

	sort(lamps.begin(),lamps.end());
	priority_queue<pii,vector<pii>,compare>pq;
	int j =0;
//for an ele keep pushing valid intervals on basis of start time and after you cant push no more 
  //remove invalid ones on basis of ending time (for step 1 sort on start time and for removing use pq sorted on end time)

  // as we sort the points start time of a next point will also take into consideration start of all nprev pts
  // as those will aslo be less than start if this pt 

  //2nd step

  //we remove all intervals where end time <pt. as pq is sorted on end time if top element is valid all the other present elements are valid too
  // as they end after top element
  //if start time 
	for(int i = 0;i<m;i++){
		while(j<n&&pts[i]>=lamps[j].first){
			pq.push(lamps[j]);
			j++;
		}
		while(!pq.empty()&&pts[i]>pq.top().second){
			pq.pop();
		}
		mp[pts[i]]= pq.size();
	}
	for(int i =0;i<m;i++){
		cout<<mp[points[i]]<<" ";
	}






}
