#include<iostream>
#include<vector>
using namespace std;

int getMajorElement(vector<int> &nums){
   
    /*
    ===WORKS ONLY IF THERE IS A MAJORITY ELEMENT. ELSE GIVES WRONG RESULT===
    Algo:
    1. take two variables majEle and counter
    2. initialise majEle = nums[0] and counter=1
    3. Loop from 1->n-1 and for each element check if that element is equal to majEle or not. If yes, increment the counter by 1. If not, check if the counter-1==0 (i.e counter==1). If yes, make the current element as majEle. If not, decrement the counter by 1.
    4. return majEle
    */

    int majEle = nums[0];     
    int counter=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==majEle)
            counter++;
        else{
            if(counter==1)
                majEle=nums[i];
            else
                counter--;
        }
    }
    return majEle;
}
int main(){
    vector<int> nums = {8,8,7,7,7};
    cout<<"Array: ";
    for(auto i : nums)
        cout<<i<<" ";
    cout<<endl<<"Majority element: "<<getMajorElement(nums);
}

