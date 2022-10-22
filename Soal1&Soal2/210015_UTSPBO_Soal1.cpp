/*
* Nama :Amir Salim
* NPM : 140810210015
* Kelas : A
* Tanggal : 19 Oktober 2022
* Nama Program : Soal1.cpp
* Deskripsi :  UTS SOAL 1
*/
#include<iostream>

class Bilangan{
    private:
        int bilangan;
    
    public:
        Bilangan(){
            this->bilangan = 0 ;
        }
        Bilangan(int bilangan){
            this->bilangan = bilangan;
        }

        void setNum(int bilangan){
            this->bilangan = bilangan;

        }

        void inputNum(){
            std::cout<<"Bilangan : ";
            std::cin>>this->bilangan;
        }

        int getNum(){
            return this->bilangan;
        }

        void outputBilangan(){
            std::cout<<"Bilangan = "<<this->bilangan;
        }

};

class Perpangkatan{
    private:
        Bilangan angka;
        Bilangan pangkat;
    
    public:
        Perpangkatan(){
            this->angka.setNum(0);
            this->pangkat.setNum(0);
        }

        Perpangkatan(int angka,int pangkat){
            this->angka.setNum(angka);
            this->pangkat.setNum(pangkat);
        }

      

        void inputPerpangkatan(){
            int n1,n2;
            std::cout<<"Masukkan angka = ";
            std::cin>>n1;
            this->angka.setNum(n1);

            std::cout<<"Masukkan pangkat = ";
            std::cin>>n2;
            this->pangkat.setNum(n2);
        }

        int hitungPangkat(){
            int hasil=1;

       
            for(int i=1;i<=this->pangkat.getNum();i++){
                hasil*=this->angka.getNum();
            }
        
        return hasil;
        }

        void outPutPerpangkatan(){
            std::cout<<"Pangkat 3 -> (" << this->angka.getNum()<< " , " << this->pangkat.getNum()<<")" << " = " << this->hitungPangkat();
        }

};

int main(){
    Perpangkatan p1;
    p1.inputPerpangkatan();
    p1.outPutPerpangkatan();
}