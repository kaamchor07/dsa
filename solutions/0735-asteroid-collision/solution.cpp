class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        for(int asteroid : asteroids){
            bool alive=true;
            while(!s.empty() && asteroid<0 && s.top()>0){
                if(s.top() < -asteroid){
                    s.pop();
                    continue;
                }else if(s.top()== -asteroid){
                    s.pop();
                }
                alive=false;
                break;
            }
            if(alive){
                s.push(asteroid);
            }
        }
        vector<int>res(s.size());
        for(int i=s.size()-1;i>=0;--i){
            res[i]=s.top();
            s.pop();
        }
        return res;
    }
};
