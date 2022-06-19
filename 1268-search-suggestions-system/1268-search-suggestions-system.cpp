class Solution {
public:
    static bool my_compare(string a,string b)
    {
        if((a.compare(0,b.size(),b) == 0 || b.compare(0,a.size(),a) == 0))
           return a.size() < b.size(); //greater length words first first
        return a < b;
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) 
    {
        vector<vector<string>> ans;
        string temp = "";
        vector<string> v;
        //To sort the lexico graphically;
        sort(products.begin(),products.end(),my_compare);
        int k = 1;
        for(int i = 0;i<searchWord.size();i++)
        {
            temp = temp + searchWord[i];
            for(int j = 0;j<products.size();j++)
            {
                if(products[j].substr(0,i+1) == temp)
                    v.push_back(products[j]);
                if(v.size() == 3 || j == products.size()-1)
                {
                    ans.push_back(v);
                    v.clear();
                    break;
                }
            }
        }
        return ans;
    }
};