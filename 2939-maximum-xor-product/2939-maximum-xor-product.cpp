class Solution {
public:

/*
solve bit by bit 
(num>>i)&1

2^x  is this form mean  3rd place bit  will be  set(1) and other all zero 

num^x but x is not known 

0101
---- bit by bit
solve again it 

011001 = 25
kisi bhi one bit ko zero mein covert karo value will decrease significantly 

*/
int M=1e9+7;
typedef long long ll;

    int maximumXorProduct(long long a, long long b, int n) {
        ll xora=0;
        ll xorb=0;
        //49th bit to nth bit

for( ll i=49;i>=n;i--)      {
   bool a_th=((a>>i)&1) >0;
   bool b_th=((b>>i)&1) >0;
   if(a_th==true){
    xora=(xora^(1ll<<i));
   }
   if(b_th==true){
    xorb=(xorb^(1ll<<i));
   }


}  
for( ll i=n-1;i>=0;i--){
          bool a_th = (a & (1ll << i)) > 0; 
     bool b_th = (b & (1ll << i)) > 0; 
   if( a_th==b_th){
    xora=(xora^(1ll<<i));
     xorb=(xorb^(1ll<<i));
   continue;
   }
   if(xora>xorb){
    xorb^=(1ll<<i);
   }
   else{
    xora=(xora^(1ll<<i));
   }
}
xora=(xora%M);
xorb=(xorb%M);
return (xora*xorb)%M;

    }
};