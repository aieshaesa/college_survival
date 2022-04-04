//Patrick Cruz
//
//My Contributions to the project
//

//This calls the credits page.
#include <stdio.h>
#include <std>


void pcruz() 
{
    string temp;
    cout<<"enter yes for odin username: ";
    cin >> temp;
    
    while(temp != "yes") {
        cout << "enter yes for odin username: ";
        cin >> temp;
    }
    cout << "pcruz";
    
}
int main()
{
    pcruz();
    return 0;
}


