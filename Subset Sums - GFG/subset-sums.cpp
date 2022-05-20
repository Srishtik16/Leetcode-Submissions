// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void recurse(vector<int> &ans, int sum, int index, vector<int> &a) {
        if(index == (int)a.size()) {
            ans.push_back(sum);
            return;
        }
        sum += a[index];
        recurse(ans, sum, index + 1, a);
        sum -= a[index];
        recurse(ans, sum, index + 1, a);
    }
    vector<int> subsetSums(vector<int> a, int n)
    {
        // Write Your Code here
        vector<int> ans;
        recurse(ans, 0, 0, a);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends