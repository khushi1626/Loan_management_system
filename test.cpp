/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include<bits/stdc++.h>
#define ll long long
#define ull signed long long int
#define int64 int64_t
#define mod 1000000007
#define repi(x,y,z) for(ll i=x;i<=y;i+=z)
#define repj(x,y,z) for(ll j=x;j<=y;j+=z)
#define repk(x,y,z) for(ll k=x;k<=y;k+=z)
#define pb push_back
#define con continue;
#define eb emplace_back;
#define ub upper_bound
#define lb lower_bound
#define mod1  998244353
#define nl '\n'
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define accending(a,n) sort(a,a+n)
#define decending(a,n) sort(a,a+n,greater<ll>())
#define sortacc(v) sort(v.begin(),v.end())
#define sortde(v) sort(v.rbegin(),v.rend())
#define rev(v) reverse(v.begin(),v.end())
#define mapll map<ll,ll> 
#define vecll vector<ll>
#define revrepi(x,y,z) for(ll i=x;i>=y;i-=z)
#define revrepj(x,y,z) for(ll j=x;j>=y;j-=z)
#define INF 1e9
using namespace std;
const ll MAX_CHAR = 256;


bool isprime(ll n);
bool ispallindrome(string s);
void primeFactors(ll n,vector<ll> &v);
void yes();
void no();
ll count_set_bit(ll n);
bool isPerfectSquare(ll x);
bool is_power2(ll n);
ll add(ll x,ll y);
ll multiply(ll x,ll y);
ll power(ll x,ll y,ll p);
bool is_sorted(ll a[],ll n);
void get_factors(ll n,set<ll> &st);
ll SieveOfEratosthenes(ll n);
bool is_prime(ll x);
ll lsb_setbit_no(ll x1)
{
    ll set_bit_no = x1 & ~(x1 - 1);
    return set_bit_no;
}



int main()
{
   
     char a[4][4];
    repi(1,3,1)
    {
        repj(1,3,1)
        {
            a[i][j]='*';
        }
    }
    ll n=9;
    ll cnt=0;
    
    //cout<<"kh8shi"<<nl;
    bool flag=false;
    
    while(n--)
    {
           ll r,c;
        
        if(cnt==0)
        {
            cout<<"Enter row and coloumn for O"<<nl;
         
            cin>>r>>c;
            a[r][c]='O';
            cnt=1;
        }
        
        else if(cnt==1)
        {
            cout<<"Enter row and coloumn for X"<<nl;
            //ll r,c;
            cin>>r>>c;
            a[r][c]='X';
            cnt=0;
        }
        
        
        
        repi(1,3,1)
        {
            repj(1,3,1)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<nl;
        }
        
       // for row
    
        repi(1,3,1)
        {
            ll c0=0,cx=0;
            repj(1,3,1)
            {
               if(a[i][j]=='O') c0++; 
               else if(a[i][j]=='X') cx++;
            }
            
            if(c0==3)
            {
                cout<<"O Wins";
                flag=true;
                break;
            }
            else if(cx==3) 
            {
                cout<<"X Wins";
                flag=true;
                break;
            }
        } 
        
        repi(1,3,1)
        {
            ll c0=0,cx=0;
            repj(1,3,1)
            {
               if(a[j][i]=='O') c0++; 
               else if(a[j][i]=='X') cx++;
            }
            
            if(c0==3) 
            {
                cout<<"O Wins";
                flag=true;
                break;
            }
            else if(cx==3)
            {
                cout<<"X Wins";
                flag=true;
                break;
            }
        } 
        
         ll c0=0,cx=0;
         repi(1,3,1)
        {
           
            repj(1,3,1)
            {
                if(i==j)
                {
                     if(a[j][i]=='O') c0++; 
                    else if(a[j][i]=='X') cx++;
                }
              
            }
        }
            
            if(c0==3)
            {
                cout<<"O Wins";
                flag=true;
                break;
            }
             else if(cx==3) 
             {
                 cout<<"X Wins";
                 flag=true;
                 break;
            }
        
        
        if(a[3][1]=='O' && a[2][2]=='O' && a[1][3]=='O')
        {
            cout<<"O Wins";
            flag=true;
            break;
        }
        else if(a[3][1]=='X' && a[2][2]=='X' && a[1][3]=='X')
        {
            cout<<"X Wins";
            flag=true;
            break;
        }  
        
    }

    if(!flag)
    {
         cout<<"Match is draw"<<nl;
    }
    
        
   return 0;
        
}






bool isprime(ll n)
{
    bool flag=true;
    for (ll i = 2; i*i<=n; i++)
    {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
    }
    if (n <= 1)
    {
        flag = false;
    }
    return flag;
}
bool ispallindrome(string s)
{
    string t(s.rbegin(),s.rend());
    return (t==s);
}
ll nCrModp(ll n, ll r, ll p)
{
        
    if (r > n - r)
        r = n - r;
    ll C[r + 1];
    memset(C, 0, sizeof(C));
    C[0] = 1; 
    for (ll i = 1; i <= n; i++) 
    {               
        for (ll j = min(i, r); j > 0; j--)  
        {
            C[j] = (C[j] + C[j - 1]) % p;
        }           
    }
    return C[r];
}
void primeFactors(ll n,vector<ll> &v)
{ 
    while (n % 2 == 0)
    {
        v.pb(2);
        n = n/2;
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            v.pb(i);
            n = n/i;
        }
    }
    if(n > 2)
        v.pb(n);
}
void yes()
{
    cout<<"YES"<<nl;
}
void no()
{
    cout<<"NO"<<nl;
}
ll count_set_bit(ll n) 
{
    ll count = 0;
    while(n != 0) 
    {
        if(n & 1 == 1) 
        {
            count++;
        }
        n = n >> 1; //right shift 1 bit`
     }
     return count;
}
bool isPerfectSquare(ll x)
{
    if (x >= 0)
    {
        ll sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
bool is_power2(ll n)
{
    if(n&(n-1))
    {
        return false;
    }
    else
    {
        return true;
    }
}
ll add(ll x,ll y)
{
    ull ans=(((x%mod)+(y%mod))%mod);
    if(ans<0)
    {
        ans+=mod;
    }
    return ans;
}
ll multiply(ll x,ll y)
{
        ll ans=(((x%mod)*(y%mod))%mod);
        return ans;
}
ll power(ll x,ll y,ll p)
{
    ll res=1;
    x=x%p;
    if(x==0)
    {
        return 0;
    }
    while(y>0)
    {
        if(y&1)
        {
            res=multiply(res,x);
        }
        x=multiply(x,x);
        y=(y/2);
    }
    return res;
}
bool is_sorted(ll a[],ll n)
{
    repi(1,n-1,1)
    {
        if(a[i]<a[i-1])
        {
            return false;
        }
    }
    return true;
}
bool is_sortedstring(string s,ll n)
{
    repi(1,n-1,1)
    {
        if(s[i]<s[i-1])
        {
            return false;
        }
    }
    return true;
}
void get_factors(ll n,set<ll> &st)
{
    vecll v;
    for(ll i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            st.insert(i);
            st.insert((n/i));
        }       
    }
}

ll SieveOfEratosthenes(ll n)
{
    ll c=0;
    bool prime[n+1];
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=n; i += p)
                prime[i] = false;
        }
    }
    for (int p=2; p<=n; p++)
       if (prime[p])
          c++;
      return c;
}


bool is_prime(ll x)
{
    for(ll i=2;i<=sqrt(x);i++)
     if(x%i==0)
     {
        return false;
     } 
    return true;
}






  