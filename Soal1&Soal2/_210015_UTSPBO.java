/*
* Nama :Amir Salim
* NPM : 140810210015
* Kelas : A
* Tanggal : 22 Oktober 2022
* Nama Program : _210015_UTSPBO.java
* Deskripsi :  UTS SOAL 1
*/
import java.util.Scanner;
class Bilangan{
    private int bilangan;
    
   
        Bilangan(){
            this.bilangan = 0 ;
        }
        Bilangan(int bilangan){
            this.bilangan = bilangan;
        }

        public void setNum(int bilangan){
            this.bilangan = bilangan;

        }

        public void inputNum(){
            Scanner input = new Scanner(System.in);
            System.out.print("Bilangan : ");
            this.bilangan = input.nextInt();
        }

        public int getNum(){
            return this.bilangan;
        }

        public void outputBilangan(){
            System.out.println("Bilangan = " + this.bilangan);
        }

}

class Perpangkatan{
    private Bilangan angka = new Bilangan();
    private Bilangan pangkat = new Bilangan();
    
        Perpangkatan(){
            this.angka.setNum(0);
            this.pangkat.setNum(0);
        }

        Perpangkatan(int angka,int pangkat){
            this.angka.setNum(angka);
            this.pangkat.setNum(pangkat);
        }

      

        public void inputPerpangkatan(){
            Scanner input = new Scanner(System.in);
            int n1,n2;
            System.out.print("Masukkan angka = ");
            n1 = input.nextInt();
            this.angka.setNum(n1);

            System.out.print("Masukkan pangkat = ");
            
            n2 = input.nextInt();
            this.pangkat.setNum(n2);
        }

        public int hitungPangkat(){
            int hasil=1;

       
            for(int i=1;i<=this.pangkat.getNum();i++){
                hasil*=this.angka.getNum();
            }
        
        return hasil;
        }

        public void outPutPerpangkatan(){
            System.out.println("Pangkat 3 -> (" + this.angka.getNum() + " , " + this.pangkat.getNum() + ")" + " = " + this.hitungPangkat());
         
        }

}

public class _210015_UTSPBO {
    public static void main(String[] args) {
        Perpangkatan p1 = new Perpangkatan();
        p1.inputPerpangkatan();
        p1.outPutPerpangkatan();
        
    }
}
