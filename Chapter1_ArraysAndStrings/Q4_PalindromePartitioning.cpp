#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        bool checkPalindromePartition(string input){
            
            unordered_map<char,int> charCount;
            int odds = 0;

            for(auto i : input)
                if(i!=' ')
                    charCount[tolower(i)]++;
        
            for(auto i : charCount)
                if(i.second%2!=0) 
                    odds++;

            if(odds == 0 || odds == 1)
                return true;
            return false;
                
        }

};

int main(){
    //Case 1
    string input = "Taco Cat";
    cout<<"String: "<<input<<endl;
    cout<<"Plaindrome Permutation exists? "<<solution().checkPalindromePartition(input)<<endl;

    input = "abc abc";
    cout<<"String: "<<input<<endl;
    cout<<"Plaindrome Permutation exists? "<<solution().checkPalindromePartition(input)<<endl;

    input = "abc def";
    cout<<"String: "<<input<<endl;
    cout<<"Plaindrome Permutation exists? "<<solution().checkPalindromePartition(input)<<endl;


    return 0;
}
