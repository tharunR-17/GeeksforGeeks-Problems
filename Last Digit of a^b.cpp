class Solution {
  private:
    string div2String(string a){
            string p="";
            int n=a.size();
            int hasil=0;
            int t=0;
            if(a[t]=='1'){
                t++;
                hasil=1;
                if(n==1) return "0";
            }
            for(int i=t;i<n;i++){
                 char c=a[i];
                 hasil=hasil*10+(c-'0');
                 int d=hasil/2;
                 p+=('0'+d);
                 hasil=hasil%2;
            }
            return p;
    }
  public:
    int getLastDigit(string& a, string& b) {
        int digit=1;
        int val=a[a.size()-1]-'0';
        while(b!="0"){
            int n=b.size();
            if((b[n-1]-'0')&1){
                digit=digit*val;
                digit=digit%10;
            }
            val=val*val;
            val=val%10;
            b=div2String(b);
        }
        return digit;
    }
}; 
