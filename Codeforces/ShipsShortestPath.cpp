#include <bits/stdc++.h>
using namespace std;

typedef complex<double> point;
#define cross(a,b) ((conj(a)*(b)).imag())
#define X real()
#define Y imag()

constexpr double eps = 1e-9;

int comp(double a, double b){
    if(fabs(a-b)<eps)return 0;
    return a>b?1:-1;
}
double len(point x, point y){
    return hypot(x.X-y.X,y.Y-x.Y);
}
bool on(point x, point y, point a){
    return comp(len(x,y),len(x,a)+len(a,y))==0;
}
bool intersect(point x, point y, point c, point d, point& r){
    double d1 = cross(c-x,y-x);
    double d2 = cross(d-x, y-x);
    if(comp(d1,d2)==0)return false;
    r = (d1*d-d2*c)/(d1-d2);
    if(!on(x,y,r)||!on(c,d,r))return false;
    return true;
}
struct pComp{
    bool operator()(const point x, const point y) const{
        if(comp(x.X,y.X))return x.X<y.X;
        if(comp(x.Y,y.Y))return x.Y<y.Y;
        return 0;
    }
};
int main(){
    point s,t;
    int lol,xd;cin>>lol>>xd;s = point(lol,xd);
    cin>>lol>>xd;t = point(lol,xd);
    int n;cin>>n;
    vector<point> x;
    for(int i=0; i<n; i++){
        cin>>xd>>lol;
        x.emplace_back(xd,lol);
    }
    double ans = len(s,t);
    set<point, pComp> li;
    for(int i=0; i<n; i++){
        point r;
        if(intersect(s,t,x[i],x[(i+1)%n],r)){
            li.insert(r);
        }
    }
    double c1=-1,c2 = 0;
    if(li.size()==2){
        point p1 = *li.begin();
        point p2 = *li.rbegin();
        int j;
        for(int i=0; i<n; i++){
            j = (i+1)%n;
            c2+=len(x[i],x[j]);
            if(on(x[i],x[j],p2)&&c1==-1)swap(p1,p2);
            if(on(x[i],x[j],p1)&&c1==-1){
                if(on(x[i],x[j],p2))goto END;
                c1=len(p1,x[j]);
                while(true){
                    int j1 = (j+1)%n;
                    if(on(x[j],x[j1],p2)){
                        c1+=len(x[j],p2);
                        break;
                    }
                    else c1+=len(x[j],x[j1]);
                    j = j1;
                }
            }
        }
        c2-=c1;
        ans-=len(p1,p2);
        double c3 = 2*len(p1,p2);
        ans+=min({c2,c1,c3});
    }
    END:; 
    cout<<setprecision(7)<<ans<<"\n";
}