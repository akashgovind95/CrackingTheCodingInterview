#include<iostream>
#include<vector>
using namespace std;

class square{
    public:
        vector<pair<float,float>> top;
        vector<pair<float,float>> bottom;
        pair<float,float> getMiddle(){
            float x = (top[1].first + top[0].first)/2;
            float y = (top[1].second + bottom[0].second)/2;
            return make_pair(x,y);
        }
};

bool isSame(pair<float,float> mid1,pair<float,float> mid2){
    if(mid1.first==mid2.first && mid1.second==mid2.second)
        return true;
    return false;
}

void getEquation(pair<float,float> mid1,pair<float,float> mid2){
    float a = mid2.second - mid1.second;
    float b = mid2.first - mid1.first;
    int c = a*mid1.first + b*mid1.second;
    cout<<"Line segment that bisects the two squares are:"<<endl;
    cout<<a<<"x+"<<b<<"y="<<c;
}

int main(){

    square s1;
    s1.top.push_back(make_pair(2,4));
    s1.top.push_back(make_pair(4,4));
    s1.bottom.push_back(make_pair(2,2));
    s1.bottom.push_back(make_pair(4,2));

    pair<float,float> mid1 = s1.getMiddle();

    cout<<"Mid point of square 1: "<<mid1.first<<","<<mid1.second<<endl;

    square s2;
    s2.top.push_back(make_pair(3,6));
    s2.top.push_back(make_pair(6,6));
    s2.bottom.push_back(make_pair(3,3));
    s2.bottom.push_back(make_pair(6,3));

    pair<float,float> mid2 = s2.getMiddle();

    cout<<"Mid point of square 2: "<<mid2.first<<","<<mid2.second<<endl;

    if(isSame(mid1,mid2)==false){
        cout<<"The mid points are not the same"<<endl;
        getEquation(mid1,mid2);
    }
    else{
        cout<<"The mid points are the same"<<endl;
        getEquation(s1.top[0],s1.bottom[1]);
    }


}
