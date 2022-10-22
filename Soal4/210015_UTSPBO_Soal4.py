# Nama :Amir Salim
# NPM : 140810210015
# Kelas : A
# Tanggal : 19 Oktober 2022
# Nama Program : 210015_UTSPBO_Soal4.py
# Deskripsi :  UTS SOAL 4

from os import system

class Waktu:

    #Attribute
    __jam=0
    __menit=0
    __detik=0

    #Constructor
    def __init__(self, *args):
          if (len(args) == 3):
            self.__jam = int(args[0])
            self.__menit = int(args[1])
            self.__detik = int(args[2])
          
          elif(len(args)==0):
            self.__jam = int(0)
            self.__menit = int(0)
            self.__detik = int(0)

          else:
            print("False number of argument in constructor") 

    #Input Method
    def setJam(self,jam):
        self.__jam = int(jam)
    
    def setMenit(self,menit):
        self.__menit = int(menit)
    
    def setDetik(self,detik):
        self.__detik = int(detik)
    
    def inputWaktu(self):
       
        self.__jam = int(input("Masukkan jam : "))
        self.__menit = int(input("Masukkan menit : "))
        self.__detik = int(input("Masukkan detik : "))
    
    #Output Method
    def getJam(self):
        return self.__jam
    
    def getMenit(self):
        return self.__menit
    
    def getDetik(self):
        return self.__detik
    
    def getWaktu(self):
        nolJam =""
        nolMenit=""
        nolDetik=""

        if(self.__jam<10):
            nolJam="0"
            
        if(self.__menit<10):
            nolMenit="0"
            
        if(self.__detik<10):
            nolDetik="0"

        return nolJam + str(self.__jam) + ":" + str(nolMenit)+ str(self.__menit) + ":" +nolDetik+ str(self.__detik)
    
    #Proses

    def convertToSecond(self):
        hasil = self.__detik + (int(60) * self.__menit) + (int(3600) * self.__jam)
        return hasil 
    
    def secondToClock(self,second:int):
        self.__menit = int(second/60)
        self.__detik = int(second%60)
        self.__jam = int(self.__menit/60)
        self.__menit = int(self.__menit%60)
    
    def cariDurasi(self,akhir):
        temp = Waktu()

        detikAwal = self.convertToSecond()
        detikAkhir = akhir.convertToSecond()

        if(detikAkhir<detikAwal):
            detikAkhir+=86400
        
        detikHasil = detikAkhir - detikAwal
        temp.secondToClock(detikHasil)

        return temp

#-----------------------------------------------------------------------------------------------------------------------------------------

class Parkir:
    __no = " "
    __jenis=int(0)
    __datang = Waktu()
    __pulang = Waktu()

    #Constructor
    def __init__(self):
        self.__no = " "
        self.__jenis = 0
        self.__datang = Waktu(0,0,0)
        self.__pulang = Waktu(0,0,0)


    #Input
    def setNoKendaraan(self,no):
        self.__no = no
    
    def setJenis(self,jenis):
        self.__jenis=jenis
    
    def setWaktuDatang(self,datang):
        self.__datang = datang
    
    def setWaktuPulang(self,pulang):
        self.__pulang = pulang
    
    def inputKendaraan(self):
        print("\n--- INPUT KENDARAAN---")
        self.__no = input("No Kendaraan : ")
        self.__jenis = int(input("Jenis Kendaraan : "))

        print("\n--- Jam Masuk Kendaraan ---")
        self.__datang.inputWaktu()

        print("\n--- Jam Keluar Kendaraan ---")
        self.__pulang.inputWaktu()
    
    #Output
    def getNoKendaraan(self):
        return self.__no

    def getJenis(self):
        return self.__jenis
    
    def getWaktuDatang(self):
        return self.__datang
    
    def getWaktuPulang(self):
        return self.__pulang
    
    def getNamaJenis(self):
        hasil = " "

        if(self.__jenis == 1):
            hasil = "Motor"
        elif(self.__jenis==2):
            hasil="Mobil"
        
        return hasil
    
    def getLamaParkir(self):
        return self.__datang.cariDurasi(self.__pulang)
    
    def getLamaJam(self):
        hasil = int(0)
        if(self.getLamaParkir().getMenit()>=10 or self.getLamaParkir().getJam()>=1):
            hasil = self.getLamaParkir().getJam()

            if(self.getLamaParkir().getMenit()>0 or self.getLamaParkir().getDetik()>0):
                hasil = hasil + 1
        
        return hasil
    
    def getBiayaParkir(self):
        hasil = int(0)
        if(self.__jenis==1):
            hasil = self.getLamaJam()*2000
        
        elif(self.__jenis==2):
            hasil = self.getLamaJam()*3000
        
        return hasil

#-----------------------------------------------------------------------------------------------------------------------------------------
class LarikParkir:
    __ukuran=int(0)
    __p = []

    #Constructor
    def __init__(self,ukuran):
        self.__ukuran = ukuran
    
    #Input
    def inputLarikParkir(self):
        i = int(0)
        while(i<self.__ukuran):
            system("cls")
            print("Kendaraan ke - ",(i+1))
            obj = Parkir()
            obj.inputKendaraan()
            self.__p.append(obj)
            system("cls")
            i=i+1
    
    #Output
    def cetakTabelParkir(self):
        print("\t\t\t\tRekapitulasi Biaya parkir PT Parkir Jaya\n")
        if(self.__p[0].getNoKendaraan()==" "):
            print("Larik Kosong ! ")
        
        else:
            no = int(1)
            i = int(0)
            print("================================================================================================================================")
            print("No\tNo Kendaraan\t\tJenis\tJam Masuk\tJam Pulang\tLama Parkir\tLama jam\tBiaya");
            print("================================================================================================================================")
            while(i<self.__ukuran):
                if(self.__p[i].getNoKendaraan() == " "):
                    break

                else:
                    print(
                    no,"\t",
                    self.__p[i].getNoKendaraan(),"\t\t", 
                    self.__p[i].getNamaJenis(),"\t", 
                    self.__p[i].getWaktuDatang().getWaktu(),"\t", 
                    self.__p[i].getWaktuPulang().getWaktu(),"\t",   
                    self.__p[i].getLamaParkir().getWaktu(),"\t ", 
                    self.__p[i].getLamaJam(),"\t\t", 
                    self.__p[i].getBiayaParkir(),"\t  "  
                         )
                no = no+1;
                i = i+1
            print("================================================================================================================================")
    
    #Proses
    def totalBiaya(self):
        hasil = float(0)
        i = int(0)
        while(i<self.__ukuran):
            hasil = hasil + self.__p[i].getBiayaParkir()
            i = i + 1
        return hasil


#-----------------------------------------------------------------------------------------------------------------------------------------

uk = int(input("Masukkan ukuran matriks : "))

system("cls")

lp = LarikParkir(uk)

lp.inputLarikParkir()
system("cls")
lp.cetakTabelParkir()

print("Total Biaya Parkir adalah = ",lp.totalBiaya())