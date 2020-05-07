#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        string compressedString(string s1){
            if(s1.size()==0)
                return s1;
            int i = 0;
            int j = 0;
            string res="";
            while(i<s1.size()){
                j = i;
                while(s1[j]==s1[i])
                    j++;
                res+=s1[i];
                res+=(j-i)+'0';
                i=j;
            }
            if(res.size()/2==s1.size())
                return s1;
            return res;
 
        }
        
};

int main()
{
    cout<<"Case 1:"<<endl;
    string s1 = "aabbcddd";
    cout<<"String: "<<s1<<endl;
    cout<<"Compressed String: "<<solution().compressedString(s1)<<endl;

    cout<<"Case 2:"<<endl;
    s1 = "aabbcccd";
    cout<<"String: "<<s1<<endl;
    cout<<"Compressed String: "<<solution().compressedString(s1)<<endl;

    cout<<"Case 3:"<<endl;
    s1 = "abcd";
    cout<<"String: "<<s1<<endl;
    cout<<"Compressed String: "<<solution().compressedString(s1)<<endl;
    

    cout<<"Case 4:"<<endl;
    s1 = "";
    cout<<"String: "<<s1<<endl;
    cout<<"Compressed String: "<<solution().compressedString(s1)<<endl;


}
