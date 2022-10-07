#include<iostream>
#include<array>
#include<tuple> //for get function
using namespace std;

int main()
{
    array<int,7> arr1= {2,3,5,7,11,13,17};

    //at(),get(),[]
    cout<<arr1.at(4)<<" "<<arr1.at(5)<<endl;
    cout<<arr1[6]<<" "<<arr1[0]<<endl;
    cout<< get<1> (arr1) <<" "<< get<3> (arr1) <<endl;

    //front(),back(),size(),max_size()
    cout<<arr1.front()<<" "<<arr1.back()<<endl;
    cout<<"size= "<<arr1.size()<<endl;
    cout<<"max size= "<<arr1.max_size()<<endl;

    //swap()
    array<int,7> arr2= {1,2,3,4,5,6,7};
    cout<<"3rd elem of arr1 before swapping: "<<arr1[2]<<endl;
    cout<<"3rd elem of arr2 before swapping: "<<arr2[2]<<endl;
    
    arr1.swap(arr2);
    cout<<"3rd elem of arr1 after swapping: "<<arr1[2]<<endl;
    cout<<"3rd elem of arr2 after swapping: "<<arr2[2]<<endl;

    //empty()
    if( arr1.empty() ) {cout<<"array is empty"<<endl;}
    else{cout<<"array not empty\n";}

    //fill()
    array<int,4> arr3;
    arr3.fill(2);
    for(int i=0;i<4;i++) { cout<<arr3[i]<<" "; }
    

    return 0;
}