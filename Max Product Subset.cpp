class Solution {
  public:
    int findMaxProduct(vector<int>& arr) {
        // code here
        const int md = 1e9 +7;
        int ans =1;
        bool pos = false, z = false;
        int ng = 0 , ng1 = 0;
        for(auto i: arr){
            if(i>0){
                pos = true;
                ans = (1LL * ans* i)%md;
            }else if(i< 0){
                if(ng){
                    if(ng1){
                        pos = true;
                        int j = i;
                        if(j > ng)swap(j , ng);
                        if(ng < ng1)swap(ng , ng1);
                        ans = (1LL * ans * ((1LL * ng1 *j)%md))%md;
                        ng1 = 0;
                    }else{
                        ng1 = i;
                    }
                }else ng = i;
            }else z = true;
            // cout<<ans<<endl;
        }
        if(ng <0 && ng1 <0){pos  =true; ans = (1LL * ans * ((1LL * ng1* ng)%md))%md;
        }    
        if(pos)return ans;
        else{
            if(z)return 0;
            else return arr[0]; 
        }
    }
};
