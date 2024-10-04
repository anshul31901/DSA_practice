#define ll long long int
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(),skill.end());

        long long product = skill[0]*skill[n-1];

        int sum = skill[0]+skill[n-1];
        

        for(int i = 1 ; i<n/2;i++){
            if(skill[i]+skill[n-1-i]==sum){
                product +=  1ll*skill[i]*skill[n-1-i];
            }
            else return -1;
        }
        return product;

        
    }
};
