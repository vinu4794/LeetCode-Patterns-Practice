int tribUtil(int n, vector<int> &trib)
{
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 1;
    }
    
    if (trib[n] != -1) {
        return trib[n];
    }

    trib[n] = tribUtil(n-1, trib) + tribUtil(n-2, trib) + tribUtil(n-3, trib);
    return trib[n];

}

int FindTribonacci(int n)
{
    vector<int> trib(n+1,-1);
    trib[0] = 0;
    trib[1] = 1;
    trib[2] = 1;

    
    return tribUtil(n, trib);
    
    
    
}

