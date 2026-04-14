class Solution {
// private:
//     bool validpair(string a,string b){
//         int n=a.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             if((a[i]^b[i])!=0){
//                 count++;
//                 if(count>1) return false;
//             }
//         }
//         return true;
//     }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n=wordList.size();
        int len=beginWord.size();
        unordered_map<string,int>m;
        vector<pair<int,int>>visited(n,{-1,-1});
        int end=-1;
        int beg=-1;
        unordered_set<string> hash;
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord){
                end=i;
            }
            if(wordList[i]==beginWord){
                beg=i;
            }
            m.insert({wordList[i],i});
            hash.insert(wordList[i]);
        }
        if(end==-1) return 0;
        // vector<vector<int>>adj(wordList.size(),vector<int>(0));
        // for(int i=0;i<wordList.size();i++){
        //     for(int j=i;j<wordList.size();j++){
        //         if(i==j){
        //             continue;
        //         }else{
        //             if(validpair(wordList[i],wordList[j])){
        //                 adj[i].push_back(j);
        //                 adj[j].push_back(i);
        //             }
        //         }
        //     }
        // }
        queue<pair<pair<int,int>,int>>q; 
        q.push({{beg,1},0});
        visited[beg]={1,0};
        q.push({{end,1},1});
        visited[end]={1,1};
        while(!q.empty()){
            int node=q.front().first.first;
            int dist=q.front().first.second;
            int parent=q.front().second;
            q.pop();
            for(int i=0;i<len;i++){
                string word=wordList[node];
                for(int j=0;j<26;j++){
                    word[i]='a'+j;
                    if(hash.find(word)!=hash.end()){
                        if(visited[m[*hash.find(word)]].first==-1){
                            q.push({{m[*hash.find(word)],dist+1},parent});
                            visited[m[*hash.find(word)]]={dist+1,parent};
                        }else if(visited[m[*hash.find(word)]].first!=-1 && parent!=visited[m[*hash.find(word)]].second){
                            return visited[m[*hash.find(word)]].first+dist;
                        }
                    }
                }
                
            }
        }
        return 0;
    }
};
