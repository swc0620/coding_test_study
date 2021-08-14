vector<string> ans;
     map<int,string> m  { {2,"abc"},{3,"def"},{4,"ghi"},{5,"jkl"},{6,"mno"},{7,"pqrs"},{8,"tuv"},};
    
    void dfs(string d,string current){
        
        if(d.length()==0){
           ans.push_back(current);
            return;
        }
        
        auto id = m.find(d[0]-'0');
        
        for(int i=0;i<id->second.length();i++){
            dfs(d.substr(1),current+(id->second)[i]);
        }
        return;
    }
    
    vector<string> letterCombinations(string d) {
        int n = d.length();
        if(n==0) return ans;
        dfs(d,"");
        return ans;
    }