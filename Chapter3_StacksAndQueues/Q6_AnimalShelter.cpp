#include<iostream>
#include<ctime>
using namespace std;

enum AnimalType{
    DOG,CAT
};

class Animal{ 
    public:
        AnimalType type;
        time_t TimeOfArr;
        void setDetails(AnimalType type, time_t TimeOfArr){
            this->type = type;
            this->TimeOfArr = TimeOfArr;
        }
};
class Cat : public Animal{
    public:
        Cat(time_t TimeOfArr){
            setDetails(CAT,TimeOfArr);
            next=NULL;
        }
       Cat * next;
};

class Dog : public Animal{
    public:
        Dog(time_t TimeOfArr){
            setDetails(DOG,TimeOfArr);
            next=NULL;
        }
      Dog * next;
};

template <typename T> 
void insert(T &head, T &tail, T &temp){
    if(head==NULL && tail==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next = temp;
        tail=temp;
    }
}

template <typename T> 
void remove(T &head, T &tail){
    if(!head && !tail)
        cout<<"List Empty"<<endl;
    else{
        head=head->next;
    }
    if(head == NULL)
        tail=NULL;
}

template <typename T> 
time_t getOldest(T head){
    if(head==NULL)
        return -1;
    return head->TimeOfArr;
}

template <typename T> 
void printList(T head){
    if(head==NULL)
        cout<<"List Empty"<<endl;
    else{
        T temp = head;
        while(temp!=NULL){
            cout<<temp->TimeOfArr<<" ";
            temp=temp->next;
        }
    }
    cout<<endl;
}


int main(){
    
    // Let time of arrival of each animal be an unique identifier 
    int counter = 1;
    Dog * DogListHead = NULL;
    Dog * DogListTail = NULL;
    Cat * CatListHead = NULL;
    Cat * CatListTail = NULL;

    for(int i = counter;i<counter+5;i++){
        Cat * temp = new Cat(time(NULL)+i); //appending couter just for the sake allowing every animal to have a unique ID
        insert(CatListHead,CatListTail,temp);
    }
    counter+=6;

    for(int i = counter;i<counter+5;i++){
        Dog * temp = new Dog(time(NULL)+i);
        insert(DogListHead,DogListTail,temp);
    }

    cout<<"List of Cats:"<<endl;
    printList(CatListHead);
    
    cout<<"List of Dogs:"<<endl;
    printList(DogListHead);

    cout<<"Oldest Cat:"<<endl;
    cout<<getOldest(CatListHead)<<endl;
    
    cout<<"Oldest Dog:"<<endl;
    cout<<getOldest(DogListHead)<<endl;


    if(getOldest(DogListHead)<getOldest(CatListHead))
        cout<<"Oldest Animal is a dog"<<endl;
    else
        cout<<"Oldest Animal is a cat"<<endl;
    
    cout<<"Adopting cat (removing the oldest cat): "<<endl;
    remove(DogListHead,DogListTail);

    cout<<"Adopting dog (removing the oldest dog):"<<endl;
    remove(CatListHead,CatListTail);

    if(getOldest(DogListHead)<getOldest(CatListHead))
        cout<<"Oldest Animal is a dog"<<endl;
    else
        cout<<"Oldest Animal is a cat"<<endl;

    cout<<"List of Cats:"<<endl;
    printList(CatListHead);
    
    cout<<"List of Dogs:"<<endl;
    printList(DogListHead);

    return 0;
}





