#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	bool isPossible(int n, vector<pair<int, int> >& courses) {
	   
	    vector<vector<int>> graph(n);
        vector<int> indegree(n,0);
        for(auto c : courses)
        {
            graph[c.second].push_back(c.first);
            indegree[c.first]++;
        }
        
        vector<int> toposort;
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) 
                q.push(i);
        }
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            toposort.push_back(curr);
            
            for(auto nbr: graph[curr])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0) 
                    q.push(nbr);
            }
        }
        if(toposort.size()!=n) 
        	return false;
        	
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends