

#include <iostream>
#include<fstream>
using namespace std;


int modInverse_1(int M, int m) {
    int y;
    for (int i = 1; i <= m - 1; i++) {
        if ((M * i)%m == 1 ) y = i;
        if ((i * M) % m == 0) cout << "There No Inverse" << endl; 
    }

    return y;
}






int M=1;
int num;
int x=0;
int main()
{
    ifstream infile("data.txt");
    if (!infile.is_open()) {
       cout<< "Error Unable to open file." << endl;
        return 1;
    }

   
    int* a;
    int* m;
    int* y;
    int* M1;
    cout << "Enter the number of equation:";
    cin >> num;
 
    a = new int[num];
    m = new int[num];
    y = new int[num];
    M1= new int[num];

    for (int i = 0; i < num; i++) {
       

        infile >> a[i];
        infile >> m[i];
        M *= m[i];
    }

    for (int i = 0; i < num; i++) {
        M1[i] = M / m[i];
       
    }


    for (int i = 0; i < num; i++) {
     
        y[i] = modInverse_1(M1[i], m[i]);
    }



    for (int i = 0; i < num; i++) {
      
        x += a[i] * M1[i] * y[i];
    }
    x = x % M;
    cout << "********************************************" << endl;
    cout << "Constant for the equation of the Chines Remainder is:" << endl;
    for (int i = 0; i < num; i++) {
        cout << "a"<<i<<":"<< a[i];
        cout << "\tm"<<i<<":"<< m[i];
        cout << "\tM"<<i<<":"<< M1[i];
        cout << "\tY"<<i<<":"<<y[i] << endl;
    }
    cout << "********************************************" << endl;
    cout <<"Solution for the equation of the Chines Remainder is:" << x<<endl;
    cout << "********************************************" << endl;

    
    

}

