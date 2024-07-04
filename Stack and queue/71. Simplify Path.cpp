//already push(/) to path because we judge when / occurs and last element might be left
//when '/' comes check for stored temp string and do accordingly and clear the temp string
class Solution {
public:
    string simplifyPath(string path) {
        vector<string>v;
        string dir;
        path.push_back('/');

        for(int i =0;i<path.size();i++){
            if(path[i]=='/'){
                if(dir.size()==0)continue;
                if(dir==".."){
                    if(v.size()>0)v.pop_back();
                }
                else if(dir=="."){}
                else v.push_back(dir);

                dir.clear();
            }
            else dir.push_back(path[i]);
        }
        
        string res;
        if(v.empty())return "/";
        else{
            for(auto it:v){
                res.append("/"+it);
            }
        }
        return res;




    }


};
