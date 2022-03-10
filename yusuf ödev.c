/*
Ad� soyad�: Yusuf Can
Numara: 02210224038
�dev-1
*/
#include <stdio.h>
#define max 20
int kuyruk[max];//kuyruk tan�mlad�m
int yigit[max];//y���t tan�mlad�m
int top=-1;//y���t i�in top de�eri tan�mlad�m
int front=-1,rear=-1;//kuyruk i�in front ve rear de�eri tan�mlad�m
void enqueu(int b){//kuyruk i�in ekle fonksiyonu tan�mlad�m
	front=0;
	kuyruk[++rear]=b;//ekle i�lemi yap�ld���nda rear'� artt�rd���m i�in bo�luk olu�ur ve kuyru�a eleman eklenir
}
int dequeu(){//kuyruk i�in ��kar fonksiyonu tan�mlad�m
	if(front==(max/2)-1){
    	front=-1;
    	rear=-1;
	}
	return kuyruk[front++];//��kar i�lemi yap�ld���nda kuyruktan eleman ��kar�ld�ktan sonra front birer birer artacak
}
void kuyrukyazdir(){//kuyruk i�in yazd�rma fonksiyonu tan�mlad�m
    int f;
   	printf("kuyruk=");
   	for(f=front;f<=rear;f++){// kuyruk yazd�rma i�lemi yap�lmas� i�in kontroller yap�l�yor
   		printf("%d\t ",kuyruk[f]);//kuyruk yazd�r fonksiyonu �a��r�ld���nda kuyruktaki elemanlar tek tek yazd�r�lacak
   	}
   	printf("\t");
}
void push(int a){//y���t i�in ekle fonksiyonu tan�mlad�m
	top++;
	yigit[top]=a;//ekle i�lemi yap�ld���nda top art�rd���m i�in bir bo�luk olu�ur ve eleman eklenir
}
int pop(){//y���t i�in ��kar fonksiyonu tan�mlad�m
	return yigit[top--];//��kar i�lemi yap�ld���nda y���ttan eleman ��kar�ld�ktan sonra top birer birer azalacak
}
void yigityazdir(){//y���t i�in yazd�rma fonksiyonu tan�mlad�m
    int s;
   	printf("yigit=");
    for(s=0;s<=top;s++){// y���t yazd�rma i�lemi yap�lmas� i�in kontroller yap�l�yor
        printf("%d \t",yigit[s]);//y���t yazd�r fonksiyonu �a��r�ld���nda kuyruktaki elemanlar tek tek yazd�r�lacak
	}
	printf("\t");
}
int main(){
    int x;
    printf("kac rakam girilecek:");
    scanf("%d",&x);
        if(x>max){//girilecek rakamlar�n max de�erini a�mamas� i�in bir �art yapt�m
    	return 0;
	}
    printf("rakamlari giriniz:\n");
    
    int dizi[x];
    int i;
    for(i=0;i<x;i++){//rakam giri�i i�in kontroller yap�l�yor
    	printf("%d.sayi gir:",i+1);//say� giri�i isteniyor
    	scanf("%d",&dizi[i]);//girilen say�lar yazd�r�l�yor
    
	}
	int j;
	for(j=0;j<x/2;j++){//girilen say�lar�n nereye kadar kuyru�a eklenece�i kontrol ediliyor
		enqueu(dizi[j]);// girilen say�lar kuyru�a ekleniyor
    }
    kuyrukyazdir();//kuyru�a eklenen say�lar yazd�r�l�yor
	printf("\n");

	int k;
	if(x%2==0){// girilen say� adedinin tek mi �ift mi oldu�u kontrol ediliyor
	    for(k=x/2;k<x;k++){//girilen say�lar y���ta ekleniyor
	    	push(dizi[k]);//y���ta eklenen say�lar yazd�r�l�yor
	    }
	}
	else{
	    for(k=(x/2)+1;k<x;k++){//girilen say�lar y���ta ekleniyor
	    	push(dizi[k]);//y���ta eklenen say�lar yazd�r�l�yor
    	}
    }
    yigityazdir();//y���ta eklenen say�lar yazd�r�l�yor
	printf("\n");
	
	int sayac=0;
	int r;
	for(r=0;r<x/2;r++){
		if(dequeu() == pop()){//palindrom olma veya olmama durumu i�in i�lemler yap�l�yor
			sayac++;
		}
	}
	if(sayac==x/2){//palindrom durumu kontrol ediliyor
		printf("palindromdur.\n");//palindrom olup olmad��� yazd�r�l�yor
	}
	else{
		printf("palindrom degil.");//palindrom olup olmad��� yazd�r�l�yor
	}	
}

