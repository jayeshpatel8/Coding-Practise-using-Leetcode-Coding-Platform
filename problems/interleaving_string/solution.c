

bool isInterleave(char * s1, char * s2, char * s3){
    int l1 = strlen(s1),l3 = strlen(s3),l2 = strlen(s2);  
    if (l1+l2 != l3)  return false;
    
    int dp[l1+1][l2+1];
    dp[0][0]=true;
    for (int i=1; i <=l1; i++)
        dp[i][0] = dp[i-1][0] && s1[i-1]==s3[i-1];
    for (int i=1; i <=l2; i++)
        dp[0][i] = dp[0][i-1] && s2[i-1]==s3[i-1];
    for (int i=1; i <=l1; i++)
        for (int j=1; j <=l2; j++){
            dp[i][j]  = ((dp[i-1][j] && s1[i-1]==s3[i+j-1]) || 
                (dp[i][j-1] && s2[j-1]==s3[i+j-1]));
                
        }
    
    return dp[l1][l2];
}