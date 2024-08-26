class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        

        map<int,int>mp;//pos,health


        for(int i =0;i<positions.size();i++){
            int pos = positions[i];
            int health = healths[i];

            if(directions[i]=='L'){
                mp[pos]= -health;
            }
            else mp[pos]= health;
            

        }
        stack<pair<int,int>>st;
        for(auto it:mp){

            int pos = it.first;
            int x = it.second;


            if(x>0){
                st.push({pos,x});
            }
            else {

                while(x<0&&!st.empty()&&st.top().second>0&&abs(x)>st.top().second){
                    int y = st.top().first;

                    mp.erase(y);

                    x++;
                    mp[pos]++;


                }

                if(st.empty()||st.top().second<0){
                    if(x<0)st.push({pos,x});
                }
                else if(st.top().second>0&&st.top().second==abs(x)){
                    mp.erase(st.top().first);
                    mp.erase(pos);
                    st.pop();
                }
                else{
                    mp.erase(pos);
                    mp[st.top().first]--;
                    if(mp[st.top().first]==0){
                        mp.erase(st.top().first);
                        st.pop();
                    }
                }
            }

        }
        vector<int>res;
        for(auto pos:positions){
            if(mp.find(pos)!=mp.end()){
                res.push_back(abs(mp[pos]));
            }
        }
        return res;


    }
};
