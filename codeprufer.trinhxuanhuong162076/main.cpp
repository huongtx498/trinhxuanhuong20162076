#include <iostream>
#include <stdlib.h>
#include <time.h>
#define nmax 100000
using namespace std;
// xoa 1 cot trong mang 2 chieu
void xoa (int A[2][nmax], int n, int cot)
  {
    for(int i= cot;i< n-1;i++)
    {
        A[0][i]=A[0][i+1];
        A[1][i]=A[1][i+1];
    }
       n--;
  }
//tim phan tu lon nhat trong mang
    int Timcucdai (int A[2][nmax], int n)
    {
        int M= A[0][0];
    for(int i= 0;i< n; i++)
      {
       if(A[0][i]> M)M= A[0][i];
       if(A[1][i]> M)M= A[1][i];
      }
      return M;
    }
  // tim phan tu xuat hien 1 lan be nhat khac 0 tren mang 1 chieu
    int Timkiem (int B[], int m, int l)
    {   // m la kich thuoc mang
        int Max= l;
        // Gia tri phan tu cuc dai cua mang
        for(int i= 0;i< m;i++)
        {
            int dem= 1;
            for(int k= 0;k< i;k++)
            {
                if(B[k]==B[i]){dem=0; break;}
            }
            for(int k= i+1;k< m;k++)
            {
                if(B[k]==B[i]){dem=0; break;}
            }
            if(dem==1)
            {
                if(B[i]!=0)
                {
                    if(B[i]<Max)Max=B[i];
                }
            }
        }
        return Max;
    }
    //xay dung ham prufer code
    void prufercode (int A[2][nmax], int n)
    {
        int Ketqua[n]; int k= 0;

     for(int i=1; i< n;i++)//moi lan lap se xoa di 1 cot, vay can n-1 vong lap de cho ra prufercode
     {
     int M=Timcucdai(A, n);             // cho ra M
    // chuyen doi mang ve mang 1 chieu
     int Mang[nmax];
     for(int i= 0; i< 2; i++)
     {
        for(int j= 0; j< n; j++)
        {
            int p= n*i+j;
            Mang[p]= A[i][j];
        }
	 }

     int Max= Timkiem(Mang, 2*n, M);      // cho ra Max
     for(int i= 0;i< 2;i++)
     {
         for(int j= 0;j< n;j++)
         {
             if(A[i][j]==Max)
             {
                 Ketqua[k]=A[1-i][j];
                 k++;
                 xoa(A, n, j);
             }
         }
     }
     }
     if(A[0][0]==0)Ketqua[k]=A[0][0];
     else if(A[0][0]!=0)Ketqua[k]=A[1][0];
     cout<<"\nprufer code can tim la: \n";
     for(int i= 0;i< k+1; i++)
    {
        cout<<Ketqua[i]<<"  ";
    }
    }
int main()
{
    //nhap vao danh sach cay duoi dang mang 2 chieu
    int A[2][nmax];
    int n;
    cout<< "\n so canh cua cay la: ";
    cin>>n;
    cout<<"\n nhap lan luot 2 dinh cua tung canh, luu y dinh sau lon hon dinh truoc ";
    for(int i= 0; i< n; i++)
    {
        cout<<"\n canh thu "<< i+1<< " la:\n";
        cin>> A[0][i]>> A[1][i];
    }
    prufercode(A, n);
    //for(int i=0; i< (2*n); i++)cout<<"\n "<<Mang[i];=> kiem tra xem chuyen doi mang da dung chua
    //Timkiem(Mang, 2*n, M);// => kiem tra ham chay tim max da hoat dong hay chua
    return 0;
}

