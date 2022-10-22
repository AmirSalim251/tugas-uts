/*
* Nama :Amir Salim
* NPM : 140810210015
* Kelas : A
* Tanggal : 19 Oktober 2022
* Nama Program : 210015_UTSPBO_Soal4.cpp
* Deskripsi :  UTS SOAL 4
*/

#include<iostream>
#include<string>


class Waktu{
    private:
        int jam,menit,detik;
    
    public:
        Waktu(int jam,int menit,int detik){
            this->jam = jam;
            this->menit = menit;
            this->detik = detik;
        }
        Waktu(){
            this->jam = 0;
            this->menit =0;
            this->detik=0;
        }
        void setJam(int jam){
            this->jam = jam;
        }
        void setMenit(int menit){
            this->menit = menit;
        }
        void setDetik(int detik){
            this->detik = detik;
        }
        void inputWaktu(){
            std::cout<<"Masukkan jam : ";
            std::cin>>this->jam;

            std::cout<<"Masukkan menit : ";
            std::cin>>this->menit;

            std::cout<<"Masukkan detik : ";
            std::cin>>this->detik;
        }
        int getJam(){
            return this->jam;
        }
        int getMenit(){
            return this->menit;
        }
        int getDetik(){
            return this->detik;
        }
        std::string getWaktu(){
            std::string nolJam ="";
            std::string nolMenit="";
            std::string nolDetik="";

            if(this->jam<10){
                nolJam="0";
            }
            if(this->menit<10){
                nolMenit="0";
            }
            if(this->detik<10){
                nolDetik="0";
            }
            
            
            return nolJam + std::to_string(this->jam) + ":" + nolMenit+ std::to_string(this->menit) + ":" +nolDetik+ std::to_string(this->detik);
        }
        int convertToSecond(){
            int hasil = this->detik + this->menit*60 + this->jam*3600;
            return hasil;
        }
        void secondToClock(int second){
            this->menit=second/60;
            this->detik=second%60;
            this->jam=this->menit/60;
            this->menit=this->menit%60;
        }
        Waktu cariDurasi(Waktu akhir){
             Waktu temp;

            int detikAwal = this->convertToSecond();
            int detikAkhir = akhir.convertToSecond();
            if(detikAkhir<detikAwal){
                detikAkhir+=86400;
            }
            int detikHasil = detikAkhir - detikAwal;

            

            temp.secondToClock(detikHasil);
            return temp;
        }
};

class Parkir{
    private:
        std::string no;
        int jenis;
        Waktu datang;
        Waktu pulang;
    
    public:
        Parkir(){
            this->no = " ";
            this->jenis=0;
        }

        //Input
        void setNoKendaraan(std::string no){
            this->no = no;
        }

        void setJenis(int jenis){
            this->jenis = jenis;
        }

        void setWaktuDatang(Waktu datang){
            this->datang = datang;

        }

        void setWaktuPulang(Waktu pulang){
            this->pulang=pulang;
        }

        void inputKendaraan(){
            std::cout<<"\n--- INPUT KENDARAAN ---\n";
            std::cout<<"No Kendaraan : ";
            std::cin.ignore();
            std::getline(std::cin,this->no);

            std::cout<<"Jenis Kendaraan : ";
            std::cin>>jenis;

            std::cout<<"\n-- Jam Masuk Kendaraan --\n";
            this->datang.inputWaktu();

            std::cout<<"\n-- Jam Keluar Kendaraan --\n";
            this->pulang.inputWaktu();
        }

        //Output  
        std::string getNoKendaraan(){
            return this->no;
        }

        int getJenis(){
            return this->jenis;
        }

        Waktu getWaktudatang(){
            return this->datang;
        }

        Waktu getWaktuPulang(){
            return this->pulang;
        }

        //Proses 
        std::string getNamaJenis(){
             std::string hasil = " ";

            if(this->jenis == 1){
            hasil = "Motor";
            }
            else if(this->jenis==2){
            hasil = "Mobil";
            }

            return hasil;
        }

        Waktu getLamaParkir(){
            return this->datang.cariDurasi(this->pulang);
        }

        int getLamaJam(){
        int hasil = 0;
            if(this->getLamaParkir().getMenit()>=10 || this->getLamaParkir().getJam()>=1){
                hasil = this->getLamaParkir().getJam();

                if( this->getLamaParkir().getMenit()>0 || this->getLamaParkir().getDetik()>0 ){
                    hasil +=1;
                }
           
            }
            return hasil;
        }

        int getBiayaParkir(){
            int hasil = 0;
            if(this->jenis==1){
                hasil = this->getLamaJam() * 2000;
            }

            else if(this->jenis==2){
                hasil = this->getLamaJam() * 3000;
            }

        return hasil;
    }    

};

class LarikParkir{
    private:
        int ukuran;
        Parkir p[100];
    
    public:
        LarikParkir(int ukuran){
            this->ukuran = ukuran;
        }

        void inputLarikParkir(){
                for(int i=0;i<this->ukuran;i++){
                    system("cls");
                    std::cout<<"Kendaraan ke - " <<(i+1);
                    this->p[i].inputKendaraan();
                    system("cls");
            }
        }

        void cetakTabelParkir(){
            std::cout<<"\t\t\t\tRekapitulasi Biaya parkir PT Parkir Jaya\n";

            if(this->p[0].getNoKendaraan()=="s"){
                std::cout<<"Larik Kosong !\n";

            }

            else{
                int no = 1;
                std::cout<<"================================================================================================================================\n";
                std::cout<<"No\tNo Kendaraan\t\tJenis\tJam Masuk\tJam Pulang\tLama Parkir\tLama jam\tBiaya\n";
                std::cout<<"================================================================================================================================\n";

                for(int i=0;i<this->ukuran;i++){
                    if(this->p[i].getNoKendaraan() == " "){
                        break;
                    }

                    else{
                        std::cout<<no<<"\t"<<
                        this->p[i].getNoKendaraan() << "\t\t" << 
                        this->p[i].getNamaJenis()<< "\t" << 
                        this->p[i].getWaktudatang().getWaktu() << "\t" << 
                        this->p[i].getWaktuPulang().getWaktu() << "\t" <<   
                        this->p[i].getLamaParkir().getWaktu() << "\t " << 
                        this->p[i].getLamaJam() << "\t\t" << 
                        this->p[i].getBiayaParkir() << "\t  \n";  
                    }
                    no++;
                }
                std::cout<<"================================================================================================================================\n";
            }
        }

        float totalBiaya(){
            float hasil = 0;
            for(int i=0;i<this->ukuran;i++){
                hasil+=this->p[i].getBiayaParkir();
            }

            return hasil;
        }

};

int main()
{
    int ukuran;
    std::cout<<"Masukkan ukuran matriks = ";
    std::cin>>ukuran;

    LarikParkir lp(ukuran);

    system("cls");

    lp.inputLarikParkir();
    system("cls");
    lp.cetakTabelParkir();

    std::cout<<"Total Biaya adalah = "<<lp.totalBiaya();

    return 0;
}
