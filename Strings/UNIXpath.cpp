#include <bits/stdc++.h>
using namespace std;

//PTBN
/*
1. ..asdjf can be dir
2. afsds... can be dir
3. String manipulation
*/

    string simplifyPath(string path) {
        vector<string> s;
       
        
        for(int i=0;i<path.size(); i++){
            
            if(path[i]=='/')
                continue;
            
            else if(path[i]=='.'){
                
                int start=i;
                int flag=0;
                
                while( (i<path.size()) && (path[i]!='/'))
                {
                    if(path[i]!='.')
                        //if path name starts with .
                        flag=1;
                    i++;
                }
                std::string p(path.begin()+start, path.begin()+i);
                
                //if .. pop the last dir 
                if(flag==0 && p.size()==2)
                {
                    if(!s.empty())
                        s.pop_back();
                }
                
                //if ... or ..dir push it stack
                if(p.size()>=3)
                    s.push_back(p); 
            }
            
            else{
                //copy alphabets 
                int start=i;
                while( (i<path.size()) && (path[i]!='/'))
                    i++;

                std::string p( path.begin()+start, path.begin()+i);
                s.push_back(p);
            }
            
        }
        
        
        vector<char> ans;
        
        int k=0;
        
        if(s.size()==0)
            return "/";
        
        for(int i=0;i<s.size();i++){
            ans.push_back('/');
            for(int j=0;j<s[i].size();j++){
                ans.push_back(s[i][j]);
            }
        }
        
        std::string p( ans.begin(), ans.end() );
        return p;    
    }



int main()
{
    return 0;
}


