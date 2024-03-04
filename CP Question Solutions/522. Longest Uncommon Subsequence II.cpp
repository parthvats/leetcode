class Solution {
public:
    bool static sortcol(vector<string>& v1, vector<string>& v2)
    {
        int num1 = stoi(v1[1]);  
        int num2 = stoi(v2[1]);
        if(num1!=num2){
            return num1 > num2;
        }
        return v1[0] > v2[0];
    }

    bool compare(string& s1, string& s2){
        int m = s1.size();
        int n = s2.size();
        int i = 0;
        int j = 0;

        while(i<m){
            if(s1[i]==s2[j]){
                j++;
                if(j==n) {
                    return true;
                }
            }
            i++;
        }
        return false;
    }

    bool search(vector<string>& strs, string& s){
        int n = strs.size();
        int m = s.size();
        int i = 0;
        
        while(i<n && ((strs[i].size())>m)){
            if(compare(strs[i],s)){
                return true;
            }
            i++;
        }
        return false;
    }

    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end(),greater<string>());

        vector<vector<string>> vect(n, vector<string>(2));
        
        for(int i=0; i<n; i++){
            vect[i][0] = strs[i];
            vect[i][1] = to_string(strs[i].size());
        }

        sort(vect.begin(), vect.end(), sortcol);

        for(int i=0; i<n; i++){
            strs[i] = vect[i][0];
        }

        int i = 0;
        int lc_len;
        while(i<n){
            if(i<n-1 && strs[i]==strs[i+1]){
                while(i<n-1 && strs[i]==strs[i+1]){
                    i++;
                }
                i++;
            }
            else{
                bool BOOL = search(strs, strs[i]);
                if(!BOOL) return strs[i].size();
                else i++;
            }
        }
        return -1;
        
    }
};
