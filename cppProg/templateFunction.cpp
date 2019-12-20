#import <iostream>

using namespace std;

/*
 Function Templates
 */
template <typename T>
T maxx(T a, T b){
    if (a > b)
        return a;
    else
        return b;
}

int main(){
    int m = maxx(5, 6);
    cout<<"max of 5 and 6:: "<<m<<endl;

    float f = maxx(3.2, 2.9);
    cout<<"max of 3.2 and 2.9:: "<<f<<endl;

    char ch = maxx('A', 'a');
    cout<<"max of A and a:: "<<ch<<endl;

    return 0;
}
