class Solution {
public:
    bool canChange(string S, string T) {
        int i=0,r1=0, N= S.size();
        //cout<<endl <<S << " : ";
        for (; i<N; i++){
           // cout << i << " ";
            if (S[i] == T[i]) continue;
            else if (S[i]=='_' && T[i]=='L'){
                // to do
                bool found=false;
                for (int j=max(i+1,r1); j<N; j++){
                    if (S[j]=='R') return false;
                    else if (S[j]=='L') {
                        S[j]='_';
                        found=true; r1 = j; break;                            
                    }
                }
                if (!found)
                return false;
            }
            else if (S[i]=='_' && T[i]=='R'){
                return false;
            }
            else if (S[i]=='L' && T[i]=='_')return false;
            else if (S[i]=='R' && T[i]=='_'){
                if (i+1<N && S[i+1] ==  '_'){
                    S[i+1]='R';
                }
                else if (i+1<N && S[i+1]=='R'){
                    bool found=false;
                    for (int j=max(i+1,r1); j<N; j++){
                        if (S[j]=='L') return false;
                        else if (S[j] == '_'){
                            S[j] = 'R'; r1=  j; found=true; break;
                        }
                    }
                    if (!found)
                        return false;
                }
                else
                    return false;                
            }
            else if (S[i]=='L' && T[i]=='R'){ 
                return false;
            }
            else if (S[i]=='R' && T[i]=='L'){ 
                return false;
            }
            
        }


        
        return  true;;
    }
};