//SOL - 1
class Solution {

public:
    string getHint(string secret, string guess) {
        
        int bull = 0 , cow = 0;

        unordered_map<int,int>m;
        for(auto i : secret){
            m[i]++;
        }

        for(int idx = 0 ; idx < secret.size() ; idx++){

            if(secret[idx] == guess[idx]){
                bull++;
                m[secret[idx]]--;
            }
                
        }
        for(int idx = 0 ; idx < secret.size() ; idx++){

            if(secret[idx] == guess[idx]){
                continue;
            }

            if(m[guess[idx]] != 0){
                m[guess[idx]]--;
                cow++;
            }
                
        }


        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;

    }
};

//SOL - 2
class Solution {

public:
    string getHint(string secret, string guess) {
        
        int bull = 0 , cow = 0 , n = secret.size();
        vector<int>cntS(10 , 0);
        vector<int>cntG(10 , 0);

        for(int idx = 0 ; idx < n ; idx++){

            if(secret[idx] == guess[idx]){
                bull++;
            }
            else{
                cntS[static_cast<int>(secret[idx]) - '0']++;
                cntG[static_cast<int>(guess[idx]) - '0']++;
            }

        }

        for(int i = 0 ; i < 10 ; i++){
            cow += min(cntS[i] , cntG[i]);
        }

        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;

    }
};