#include <iostream>
#include <string.h>
using namespace std;
// ALDI 144
class kasus{
  private:
    int i, j, k, l, j_jenis, j_buku, cur, cur2, temp;
    string jenis[100], judul[100][100], temp2;
    int kode[100][100];
  public:  
    void input();
    void proses();
    void output();
};

//AGUNG 145
void kasus::input(){
  cout<<" Masukkan Jumlah Jenis Buku : "; cin>>j_jenis;
  for(i=0; i<j_jenis; i++){
    cout<<" Masukkan Nama Jenis Buku : "; cin>>jenis[i];
    cout<<" Masukkan Jumlah Buku     : "; cin>>j_buku;
    for(j=0; j<j_buku; j++){
      cout<<" Kode Buku  : "; cin>>kode[i][j];
      cout<<" Judul Buku : "; cin>>judul[i][j];
    }
    cout<<endl;
  } 
}
//FARIDHAL 151
void kasus::proses(){
  for(i=0;i<j_jenis;i++){
    for(j=0;j<j_buku;j++){
      cur=i;
      cur2=j;
      for(int k=0;k<j_buku;k++)
      for(int l=0;l<j_buku;l++){
       if(kode[cur][cur2]<kode[k][l]){ 
        cur=k;
        cur2=l;
        }
        temp=kode[i][j];     
        kode[i][j]=kode[cur][cur2];
        kode[cur][cur2]=temp;
        
        temp2=judul[i][j];     
        judul[i][j]=judul[cur][cur2];
        judul[cur][cur2]=temp2;
      }   
    }
  }
}

// ALDI 144
void kasus::output(){
  cout<<"=== Hasil Sorting === : "<<endl;
  for(i=0; i<j_jenis; i++){
    cout<<" Jenis Buku   : "<<jenis[i]<<endl;
    for(j=0; j<j_buku; j++){
      cout<<" Kode Buku  : " <<kode[i][j]<<endl;
      cout<<" Judul Buku : " <<judul[i][j];
      cout<<endl;
    }
    cout<<endl;
  }  
}

int main(){
  kasus jln;
  jln.input();
  jln.proses();
  jln.output();
}