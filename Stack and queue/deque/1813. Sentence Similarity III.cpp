https://leetcode.com/problems/sentence-similarity-iii/submissions/1414156637/
class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.size()<sentence2.size()){
            swap(sentence1,sentence2);
        }
        sentence2.push_back(' ');
        sentence1.push_back(' ');
        deque<string>d1;
        deque<string>d2;        
        string temp = "";

        for(int i = 0;i<sentence1.size();i++){
            if(sentence1[i]==' '){
                d1.push_back(temp);
                // cout<<temp<<" ";
                temp.clear();
            }
            else{
                temp.push_back(sentence1[i]);
            }
        }

        for(int i = 0;i<sentence2.size();i++){
            if(sentence2[i]==' '){
                d2.push_back(temp);
                // cout<<temp<<" ";
                temp.clear();
            }
            else{
                temp.push_back(sentence2[i]);
            }
        }
        while(!d2.empty()&&d1.front()==d2.front()){
            d2.pop_front();
            d1.pop_front();
        }
        while(!d2.empty()&&d1.back()==d2.back()){
            d2.pop_back();
            d1.pop_back();
        }
        return d2.empty();


    }
};
