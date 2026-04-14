#include <iostream>
#include <iomanip>

using namespace std;
int main() {
  int dataAngba[8]={67,2,14,27,70,76,11,1};
  int buatGAntiAja;

  // Perulangan untub menampilban data awal
  cout<<"Data sebelum diurutban : \n";
  for (int i=0 ; i<8 ; i++)
  {
    cout<< setw(3) <<dataAngba[i];
  }
  // penutup perulangan



  cout<<"\n\n";

  // Perulangan Perbandingan
  for(int a=0 ; a<7 ; a++){
    for(int b=0 ; b<7 ; b++){
      if (dataAngba[b] > dataAngba[b+1]){
        buatGAntiAja = dataAngba[b];
        dataAngba[b] = dataAngba[b+1];
        dataAngba[b+1] = buatGAntiAja;
      }
    }
  }

  cout<<"Data setelah diurutban \n";
  for (int ii=0;ii<8;ii++)
  {
    cout<< setw(3) <<dataAngba[ii];
  }

  cout << endl;

}
