#include <iostream>
using namespace std;

main(int a){cin>>a;for(int i=32;i-->0;)a&(1<<i)?cout<<1:cout<<0;}