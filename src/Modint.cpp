template<ll mod> struct Modint{
    public:
    ll x;
    Modint(ll x=0) : x((x%mod+mod)%mod) {}
    Modint operator-() const { return Modint(-x); }
    Modint& operator+=(const Modint& a){
        if(mod<=(x += a.x)) x-=mod;
        return *this;
    }
    Modint& operator-=(const Modint& a){
        if(mod<=(x+=mod-a.x)) x-=mod;
        return *this;
    }
    Modint& operator*=(const Modint& a){
        (x*=a.x)%=mod;
        return *this;
    }
    Modint& operator++(){
        ++x;
        return *this;
    }
    Modint operator++(int){
        Modint temp = *this;
        x++;
        return temp;
    }
    Modint& operator--(){
        --x;
        return *this;
    }
    Modint operator--(int){
        Modint temp = *this;
        x--;
        return temp;
    }
    Modint pow(ll t) const{
        Modint a=1,b=x;
        while(t){
            if(t&1) a*=b;
            b*=b;
            t/=2;
        }
        return a;
    }
    Modint inv() const { return pow(mod-2); }
    Modint& operator/=(const Modint& a){ return (*this)*=a.inv(); }
    friend Modint operator+(const Modint& a, const Modint& b) { return Modint(a)+=b; }
    friend Modint operator-(const Modint& a, const Modint& b) { return Modint(a)-=b; }
    friend Modint operator*(const Modint& a, const Modint& b) { return Modint(a)*=b; }
    friend Modint operator/(const Modint& a, const Modint& b) { return Modint(a)/=b; }
    friend bool operator==(const Modint& a, const Modint& b) { return (Modint(a).x==b.x); }
    friend bool operator!=(const Modint& a, const Modint& b) { return (Modint(a).x!=b.x); }
    friend ostream& operator<<(ostream& os, const Modint& m){ os << m.x; return os; }
    friend istream& operator>>(istream& is, Modint& m){ is >> m.x; return is; }
};

using fp998 = Modint<998244353>;
using fp107 = Modint<1000000007>;

fp998 modpow(int n, int k){
    fp998 p = n;
    return p.pow(k);
}