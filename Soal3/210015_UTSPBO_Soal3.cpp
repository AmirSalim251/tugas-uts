/*
* Nama :Amir Salim
* NPM : 140810210015
* Kelas : A
* Tanggal : 22 Oktober 2022
* Nama Program : 210015_UTSPBO_Soal3
* Deskripsi :  UTS SOAL 3
*/

#include<iostream>

class Matriks{
    private:
        int baris,kolom;
        int data[100][100];
    
    public:
        Matriks(int baris,int kolom){
            this->baris = baris;
            this->kolom = kolom;
        }

        Matriks(){
            this->baris = 2; 
            this->kolom =2;
            std::cout<<"Objek Matriks telah dibuat....\n";
        }

        //Input

        void setBaris(int baris){
            this->baris = baris;
        }

        void setKolom(int kolom){
            this->kolom = kolom;
        }

        void setElemByIndex(int i,int j,int x){
            this->data[i][j]=x;
        }

        void inputBaris(){
            std::cout<<"Masukkan Baris = ";
            std::cin>>this->baris;
        }

        void inputKolom(){
            std::cout<<"Masukkan Kolom = ";
            std::cin>>this->kolom;
        }

        void isiMatriks(){
            for(int i=0;i<this->baris;i++){
                std::cout<<"Input baris ke - "<<(i+1)<<"\n";

                for(int j=0;j<this->kolom;j++){
                    std::cout<<"\tInput kolom ke - "<<(j+1)<<" = ";
                    std::cin>>this->data[i][j];
                }
            }
        }


        //Proses
        Matriks prosesFungsi(Matriks b){
            Matriks temp(this->baris,this->kolom);

            for(int i=0;i<this->baris;i++){
            for(int j=0;j<this->kolom;j++){
                if(this->getElemenByIndex(i, j) >= b.getElemenByIndex(i, j)){
                    temp.setElemByIndex(i, j, 1);
                }

                else{
                    temp.setElemByIndex(i, j, 0);
                }
            }
           
        }
            return temp;
        }

        //Output

        int getBaris(){
            return this->baris;
        }

        int getKolom(){
            return this->kolom;
        }

        int getElemenByIndex(int i,int j){
            return this->data[i][j];
        }

        void cetakMatriks(){
                for(int i=0;i<this->baris;i++){
                    for(int j=0;j<this->kolom;j++){
                        std::cout<<this->data[i][j] <<" ";
                    }
            std::cout<<"\n";
            }
        }
        

        
  
};
int main()
{
    Matriks m1(3,4);
    Matriks m2(3,4);
    Matriks hasil(3,4);

    std::cout<<"\n--- Input Matriks 1---\n";
    m1.isiMatriks();

    std::cout<<"\n--- Input Matriks 2---\n";
    m2.isiMatriks();

    hasil = m1.prosesFungsi(m2);

    std::cout<<"\n--- Matriks Hasil---\n";
    hasil.cetakMatriks();


    return 0;
}
