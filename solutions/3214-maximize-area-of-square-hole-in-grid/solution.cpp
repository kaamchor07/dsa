class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        if(hBars.size()==0 || vBars.size()==0){
            return 1;
        }
        if(hBars.size()==1 || vBars.size()==1){
            return 4;
        }
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int sidelength=1;
        int hcons=1;
        int hconsmax=1;
        int vcons=1;
        int vconsmax=1;
        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i]==hBars[i+1]-1){
                hcons++;
                hconsmax=max(hcons,hconsmax);
            }else{
                hcons=1;
            }
        }  
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i]==vBars[i+1]-1){
                vcons++;
                vconsmax=max(vcons,vconsmax);
            }else{
                vcons=1;
            }
        }
        sidelength=min(vconsmax,hconsmax)+1; 
        return sidelength*sidelength;              
    }
};
