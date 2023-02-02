using ll = long long;
const ll MAXN=(ll)1e5+5;
struct node
{
    ll seg,pref,suf,sum;
};
node t[4*MAXN];
ll n,m;
void build(vector<int> &a,ll v,ll tl,ll tr)
{
    if(tl==tr)
    {
     t[v].seg=a[tl];
     t[v].pref=a[tl];
     t[v].suf=a[tl];
     t[v].sum=a[tl];
    }
    else
    {
        ll tm=(tr+tl)/2;
        build(a,2*v,tl,tm);
        build(a,2*v+1,tm+1,tr);
        t[v].sum=t[2*v].sum+t[2*v+1].sum;
        t[v].pref=max(t[2*v].pref,t[2*v].sum+t[2*v+1].pref);
        t[v].suf=max(t[v*2+1].suf,t[2*v+1].sum+t[2*v].suf);
        t[v].seg=max(t[v*2].seg,max(t[2*v+1].seg,t[2*v].suf+t[2*v+1].pref));
    }
}
node query(ll v,ll tl,ll tr,ll l,ll r)
{
    node res;
    res.sum=res.seg=res.pref=res.suf=LLONG_MIN;
    if(r<tl || l>tr)
    return res;
    else if(tl>=l && tr<=r)
    return t[v];
    ll tm=(tl+tr)/2;
    if(l>tm)
    {
        return query(2*v+1,tm+1,tr,l,r);
    }
    else
    {
        return query(2*v,tl,tm,l,r);
    }
    node left=query(2*v,tl,tm,l,r);
    node right=query(2*v+1,tm+1,tr,l,r);
    res.sum=left.sum+right.sum;
    res.pref=max(left.pref,left.sum+right.pref);
    res.suf=max(right.suf,right.sum+left.suf);
    res.seg=max(left.seg,max(right.seg,left.suf+right.pref));
}
void update(ll v,ll tl,ll tr,ll pos,ll val)
{
    if(tl==tr)
    {
        t[v].seg=t[v].sum=t[v].pref=t[v].suf=val;
    }
    else
    {
        ll tm=(tl+tr)/2;
        if(pos<=tm)
        update(2*v,tl,tm,pos,val);
        else
        update(2*v+1,tm+1,tr,pos,val);
        t[v].sum=t[2*v].sum+t[2*v+1].sum;
        t[v].pref=max(t[2*v].pref,t[2*v].sum+t[2*v+1].pref);
        t[v].suf=max(t[v*2+1].suf,t[2*v+1].sum+t[2*v].suf);
        t[v].seg=max(t[v*2].seg,max(t[2*v+1].seg,t[2*v].suf+t[2*v+1].pref));
    }
}
class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<ll> ans;
        build(nums, 1, 0, n - 1);
        for(auto x: removeQueries) {
            ll q = max(0LL, query(1,0,n-1,0,n-1).seg) + 1e9;
            update(1, 0, n - 1, x, -q);
            ans.push_back(max(0LL, query(1,0,n-1,0,n-1).seg));
        }
        return ans;
    }
};