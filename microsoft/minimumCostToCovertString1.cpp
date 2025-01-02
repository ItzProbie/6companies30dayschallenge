class Solution {

    typedef long long ll;

public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<ll>>dist(26 , vector<ll>(26 , LLONG_MAX));

        for(int i = 0 ; i < 26 ; i++)
            dist[i][i] = 0;

        for(int idx = 0 ; idx < original.size() ; idx++){
            
            int from = static_cast<int>(original[idx] - 'a');
            int to = static_cast<int>(changed[idx] - 'a');

            // dist[from][to] = min(dist[from][to] , cost[idx]);
            if(dist[from][to] > cost[idx])
                dist[from][to] = cost[idx];

        }

        for(int via = 0 ; via < 26 ; via++){

            for(int from = 0 ; from < 26 ; from++){

                for(int to = 0 ; to < 26 ; to++){

                    if(via == from || via == to)
                        continue;

                    // dist[from][to] = min(dist[from][to] , dist[from][via] + dist[via][end]);
                    if(dist[from][via] != LLONG_MAX && dist[via][to] != LLONG_MAX)
                    if(dist[from][to] > dist[from][via] + dist[via][to])
                        dist[from][to] = dist[from][via] + dist[via][to];

                }

            }

        }

        ll ans = 0;
        for(int idx = 0 ; idx < source.size() ; idx++){
            int from = static_cast<int>(source[idx] - 'a');
            int to = static_cast<int>(target[idx] - 'a');
            if(dist[from][to] == LLONG_MAX)
                return -1;
            ans += dist[from][to];
        }

        return ans;

    }
};