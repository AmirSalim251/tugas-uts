# Nama :Amir Salim
# NPM : 140810210015
# Kelas : A
# Tanggal : 22 Oktober 2022
# Nama Program : 210015_UTSPBO_Soal3
# Deskripsi :  UTS SOAL 3

class Matriks:
    __baris = int(0)
    __kolom = int(0)
    __data=[]

    #Constructor
    def __init__(self,baris,kolom):
        self.__baris = baris
        self.__kolom = kolom
        self.__data = []
      
        
    
    #Input
    def setBaris(self,baris):
        self.__baris = baris
    
    def setKolom(self,kolom):
        self.__kolom = kolom
    
    def setElemByIndex(self,i,j,x):
        self.__data[i][j]=x
    
    def inputBaris(self):
        self.__baris = int(input("Masukkan baris : "))
    
    def inputKolom(self):
        self.__kolom = int(input("Masukkan kolom : "))
    
    def isiMatriks(self):
        i = int(0)
        j = int(0)
        num = int(0)

        while(i<self.__baris):
            a=[]
            print("Input baris ke - ",(i+1))

            while(j<self.__kolom):
                print("\tInput kolom ke - ",(j+1),end=" = ") 
                num = int(input())
                a.append(num)
                j = j + 1
                
            
            j = int(0)
            self.__data.append(a)
            i = i +1
    
    def isiMatriksNol(self):
        i = int(0)
        j = int(0)
        while(i<self.__baris):
            a=[]
            while(j<self.__kolom):
               
                a.append(0)
                j = j + 1  
            j = int(0)
            self.__data.append(a)
            i = i +1

    
    #Proses
    def prosesFungsi(self,b):
        temp = Matriks(self.__baris,self.__kolom)
        temp.isiMatriksNol()
        i = int(0)
        j = int(0)

        while(i<self.__baris):
            while(j<self.__kolom):
                if(self.getElemenByIndex(i,j)>=b.getElemenByIndex(i,j)):
                    temp.setElemByIndex(i,j,1)    
                j=j+1    
            j = int(0)
            i = i +1
        
        return temp
    
    #Output
    def getBaris(self):
        return self.__baris
    
    def getKolom(self):
        return self.__kolom

    def getElemenByIndex(self,i,j):
        return self.__data[i][j]
    
    def cetakMatriks(self):
        i = int(0)
        j = int(0)
        while(i<self.__baris):
            while(j<self.__kolom): 
                print(self.__data[i][j]," ",end="")
                j = j + 1
               
            print(" ")
            j = int(0)
            i = i +1
#-----------------------------------------------------------------------------------------------------------------------------------------

m1 = Matriks(3,4)
m2 = Matriks(3,4)
hasil = Matriks(3,4)


print("\n---Input Matriks 1---")
m1.isiMatriks()

print("\n---Input Matriks 2---")
m2.isiMatriks()

hasil = m1.prosesFungsi(m2)

print("\n---Matriks Hasil---")
hasil.cetakMatriks()



