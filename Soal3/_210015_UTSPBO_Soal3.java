/*
* Nama :Amir Salim
* NPM : 140810210015
* Kelas : A
* Tanggal : 19 Oktober 2022
* Nama Program : 210015_UTSPBO_Soal3.java
* Deskripsi :  UTS SOAL 3
*/

import java.util.Scanner;
class Matriks{
    private int baris,kolom;
    private int [][]data;

    public Matriks(int baris,int kolom){
        this.baris=baris;
        this.kolom=kolom;

        this.data = new int[baris][kolom];
    }

    public Matriks(){
        this.baris = 2;
        this.kolom = 2;
        this.data = new int[baris][kolom];
        System.out.println("Objek Matriks telah dibuat...");
    }

    //Input
    public void setDimensiMatriks(){
        this.data = new int[baris][kolom];
    }
    public void setBaris(int baris){
        this.baris=baris;
    }

    public void setKolom(int kolom){
        this.kolom = kolom;
    }

    public void setMatriks(int [][] x){
        this.data = x;
    }

    public void setElemByIndex(int i,int j,int x){
        this.data[i][j]=x;
    }

    public void inputBaris(){
        Scanner input = new Scanner(System.in);
        System.out.print("Masukkan baris : ");
        this.baris = input.nextInt();
    }

    public void inputKolom(){
        Scanner input = new Scanner(System.in);
        System.out.print("Masukkan kolom : ");
        this.kolom = input.nextInt();
    }

    public void isiMatriks(){
        Scanner input = new Scanner(System.in);
        for (int i = 0; i < this.baris; i++) {
            System.out.println("Input baris ke - " + (i+1));
            for (int j = 0; j < this.kolom; j++) {
                System.out.print("  Input kolom ke - " + (j+1) + " = ");
                this.data[i][j] = input.nextInt();
            }
        }
    }

    //Proses
   
    public Matriks prosesFungsi(Matriks b){
        Matriks temp = new Matriks(this.baris,this.kolom);

        for(int i=0;i<this.baris;i++){
            for(int j=0;j<this.kolom;j++){
                if(this.getElemenByIndex(i, j) >= b.getElemenByIndex(i, j)){
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

    public int getBaris(){
        return this.baris;
    }

    public int getKolom(){
        return this.kolom;
    }

    public int getElemenByIndex(int i,int j){
        return this.data[i][j];
    }

    public void cetakMatriks(){
        for(int i=0;i<this.baris;i++){
            for(int j=0;j<this.kolom;j++){
                System.out.print(this.data[i][j] + " ");
            }
            System.out.println();
        }
    }

}


public class _210015_UTSPBO_Soal3{

  
    public static void main(String[] args) {
        Matriks m1 = new Matriks(3,4);
        Matriks m2 = new Matriks(3,4);
        Matriks hasil = new Matriks(3,4);

        System.out.println("\n--- Input Matriks 1 ---\n");
        m1.isiMatriks();

        System.out.println("\n--- Input Matriks 2 ---\n");
        m2.isiMatriks();

        hasil = m1.prosesFungsi(m2);

        System.out.println("\n--- Matriks Hasil---\n");
        hasil.cetakMatriks();
        



    }
}