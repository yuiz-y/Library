template<ll base, ll mod1, ll mod2>
struct Hash{
    ll x1, x2, len;
    inline static vll pow1 = {1}, pow2 = {1};
    static Hash op_(Hash l, Hash r){
        while(pow1.size()<=r.len){
            pow1.push_back(pow1.back()*base%mod1);
            pow2.push_back(pow2.back()*base%mod2);
        }
        Hash ans;
        ans.x1 = (l.x1*pow1[r.len]+r.x1)%mod1;
        ans.x2 = (l.x2*pow2[r.len]+r.x2)%mod2;
        ans.len = l.len+r.len;
        return ans;
    }
    constexpr Hash(ll x){
        x1 = x2 = x;
        len = 1;
    }
    constexpr Hash(){
        x1 = x2 = len = 0;
    }
    friend bool operator==(const Hash& a, const Hash& b) { return (a.x1==b.x1 && a.x2==b.x2); }
};

constexpr ll bs = 26, mod1 = 998244353, mod2 = 1000000007;
using H = Hash<bs, mod1, mod2>;
ll get_x(char c){ return c-'a'; }
constexpr H id;