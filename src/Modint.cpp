template<ll mod> struct modint{
    public:
    ll x;
    modint(ll x=0) : x((x%mod+mod)%mod) {}
    modint operator-() const { return modint(-x); }
    modint& operator+=(const modint& a){
        if(mod<=(x += a.x)) x-=mod;
        return *this;
    }
    modint& operator-=(const modint& a){
        if(mod<=(x+=mod-a.x)) x-=mod;
        return *this;
    }
    modint& operator*=(const modint& a){
        (x*=a.x)%=mod;
        return *this;
    }
    modint& operator++(){
        ++x;
        return *this;
    }
    modint operator++(int){
        modint temp = *this;
        x++;
        return temp;
    }
    modint& operator--(){
        --x;
        return *this;
    }
    modint operator--(int){
        modint temp = *this;
        x--;
        return temp;
    }
    modint pow(ll t) const{
        modint a=1,b=x;
        while(t){
            if(t&1) a*=b;
            b*=b;
            t/=2;
        }
        return a;
    }
    modint inv() const { return pow(mod-2); }
    modint& operator/=(const modint& a){ return (*this)*=a.inv(); }
    friend modint operator+(const modint& a, const modint& b) { return modint(a)+=b; }
    friend modint operator-(const modint& a, const modint& b) { return modint(a)-=b; }
    friend modint operator*(const modint& a, const modint& b) { return modint(a)*=b; }
    friend modint operator/(const modint& a, const modint& b) { return modint(a)/=b; }
    friend bool operator==(const modint& a, const modint& b) { return (modint(a).x==b.x); }
    friend bool operator!=(const modint& a, const modint& b) { return (modint(a).x!=b.x); }
    friend ostream& operator<<(ostream& os, const modint& m){ os << m.x; return os; }
    friend istream& operator>>(istream& is, modint& m){ is >> m.x; return is; }
};

using fp998=modint<998244353>;
using fp107=modint<1000000007>;