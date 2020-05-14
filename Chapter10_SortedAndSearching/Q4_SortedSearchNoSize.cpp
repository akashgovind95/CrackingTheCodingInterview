#include<iostream>
#include<vector>
using namespace std;

class Listy{
    public:
        vector<int> arr;
        int elementAt(int x){
            if(x<0 || x>=arr.size())
                return -1;
            return arr[x];
        }
        void insert(int x){
            arr.push_back(x);
        }

        void print(){
            for(auto i : arr)
                cout<<i<<" ";
            cout<<endl;
        }

        pair<int,int> getIndexRange(int target){
            
            int index=1;
            while(elementAt(index)!=-1 && elementAt(index)<target)
                index*=2;
            return make_pair(index/2,index);

        }

        int findElement(int target){
            pair<int,int> index = getIndexRange(target);
            int start = index.first;
            int end  = index.second;

            while(start<=end){
                int mid = (start+end)/2;
                if(elementAt(mid)==target)
                    return mid;
                if(target<elementAt(mid) || elementAt(mid)==-1)
                    end=mid-1;
                else
                    start=mid+1;
            }
            if(elementAt(start)==target)
                return start;
            return -1;
        }
        
};



int main(){

    Listy obj;
    for(int i=0;i<10;i++)
        obj.insert(i+1);
    obj.print();

    for(int i=0;i<10;i++)
        cout<<obj.findElement(i+1)<<endl;


}