# Nama :Amir Salim
# NPM : 140810210015
# Kelas : A
# Tanggal : 19 Oktober 2022
# Nama Program : Soal1.py
# Deskripsi :  UTS SOAL 1

class Bilangan:
    __bil = int(0)

    #constructor
    def __init__(self):
        self.__bil = 0
    #Method
    def setNum(self,bil):
        self.__bil = bil
    
    def inputNum(self):
        self.__bil = input("Bilangan =  ")
    
    def getNum(self):
        return int(self.__bil);
    
    def outputBil(self):
        print("Bilangan = " , self.__bil)

#-----------------------------------------------------------------------------------------------------------------------------------------

class Perpangkatan:
    __angka=Bilangan()
    __pangkat=Bilangan()

    #constructor
    def __init__(self):
        self.__angka = Bilangan()
        self.__pangkat =Bilangan()
    
    def inputPerpangkatan(self):
        n1 = int(input("Masukkan angka : "))
        n2 = int(input("Masukkan pangkat : "))

        self.__angka.setNum(n1)
        self.__pangkat.setNum(n2)
    
    def hitung(self):
        i = int(1)
        hasil = int(1)

        while(i<=self.__pangkat.getNum()):
            hasil = hasil * self.__angka.getNum()
            i = int(i) + int(1)
        
        return hasil;
    
    def hasil(self):
        print("Pangkat 3 -> (" , self.__angka.getNum() , " , " , self.__pangkat.getNum() , ")" , " = " , self.hitung())
#-----------------------------------------------------------------------------------------------------------------------------------------
p = Perpangkatan()
p.inputPerpangkatan()
p.hasil()


