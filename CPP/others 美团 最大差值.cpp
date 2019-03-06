class LongestDistance {
public:
    int getDis(vector<int> A, int n) {
        /*
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                res=max(res,A[j]-A[i]);
            }
        }
        return res;
        */
        int min = A[0];
        int max = INT_MIN;
        for(int i = 0; i<n;i++){
            if(A[i]<min)min=A[i];
            if(A[i]-min>max)max=A[i]-min;
        }
       return max;
    }
};

