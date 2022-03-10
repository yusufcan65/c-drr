/*
Adý soyadý: Yusuf Can
Numara: 02210224038
Ödev-1
*/
#include <stdio.h>
#define max 20
int kuyruk[max];//kuyruk tanýmladým
int yigit[max];//yýðýt tanýmladým
int top=-1;//yýðýt için top deðeri tanýmladým
int front=-1,rear=-1;//kuyruk için front ve rear deðeri tanýmladým
void enqueu(int b){//kuyruk için ekle fonksiyonu tanýmladým
	front=0;
	kuyruk[++rear]=b;//ekle iþlemi yapýldýðýnda rear'ý arttýrdýðým için boþluk oluþur ve kuyruða eleman eklenir
}
int dequeu(){//kuyruk için çýkar fonksiyonu tanýmladým
	if(front==(max/2)-1){
    	front=-1;
    	rear=-1;
	}
	return kuyruk[front++];//çýkar iþlemi yapýldýðýnda kuyruktan eleman çýkarýldýktan sonra front birer birer artacak
}
void kuyrukyazdir(){//kuyruk için yazdýrma fonksiyonu tanýmladým
    int f;
   	printf("kuyruk=");
   	for(f=front;f<=rear;f++){// kuyruk yazdýrma iþlemi yapýlmasý için kontroller yapýlýyor
   		printf("%d\t ",kuyruk[f]);//kuyruk yazdýr fonksiyonu çaðýrýldýðýnda kuyruktaki elemanlar tek tek yazdýrýlacak
   	}
   	printf("\t");
}
void push(int a){//yýðýt için ekle fonksiyonu tanýmladým
	top++;
	yigit[top]=a;//ekle iþlemi yapýldýðýnda top artýrdýðým için bir boþluk oluþur ve eleman eklenir
}
int pop(){//yýðýt için çýkar fonksiyonu tanýmladým
	return yigit[top--];//çýkar iþlemi yapýldýðýnda yýðýttan eleman çýkarýldýktan sonra top birer birer azalacak
}
void yigityazdir(){//yýðýt için yazdýrma fonksiyonu tanýmladým
    int s;
   	printf("yigit=");
    for(s=0;s<=top;s++){// yýðýt yazdýrma iþlemi yapýlmasý için kontroller yapýlýyor
        printf("%d \t",yigit[s]);//yýðýt yazdýr fonksiyonu çaðýrýldýðýnda kuyruktaki elemanlar tek tek yazdýrýlacak
	}
	printf("\t");
}
int main(){
    int x;
    printf("kac rakam girilecek:");
    scanf("%d",&x);
        if(x>max){//girilecek rakamlarýn max deðerini aþmamasý için bir þart yaptým
    	return 0;
	}
    printf("rakamlari giriniz:\n");
    
    int dizi[x];
    int i;
    for(i=0;i<x;i++){//rakam giriþi için kontroller yapýlýyor
    	printf("%d.sayi gir:",i+1);//sayý giriþi isteniyor
    	scanf("%d",&dizi[i]);//girilen sayýlar yazdýrýlýyor
    
	}
	int j;
	for(j=0;j<x/2;j++){//girilen sayýlarýn nereye kadar kuyruða ekleneceði kontrol ediliyor
		enqueu(dizi[j]);// girilen sayýlar kuyruða ekleniyor
    }
    kuyrukyazdir();//kuyruða eklenen sayýlar yazdýrýlýyor
	printf("\n");

	int k;
	if(x%2==0){// girilen sayý adedinin tek mi çift mi olduðu kontrol ediliyor
	    for(k=x/2;k<x;k++){//girilen sayýlar yýðýta ekleniyor
	    	push(dizi[k]);//yýðýta eklenen sayýlar yazdýrýlýyor
	    }
	}
	else{
	    for(k=(x/2)+1;k<x;k++){//girilen sayýlar yýðýta ekleniyor
	    	push(dizi[k]);//yýðýta eklenen sayýlar yazdýrýlýyor
    	}
    }
    yigityazdir();//yýðýta eklenen sayýlar yazdýrýlýyor
	printf("\n");
	
	int sayac=0;
	int r;
	for(r=0;r<x/2;r++){
		if(dequeu() == pop()){//palindrom olma veya olmama durumu için iþlemler yapýlýyor
			sayac++;
		}
	}
	if(sayac==x/2){//palindrom durumu kontrol ediliyor
		printf("palindromdur.\n");//palindrom olup olmadýðý yazdýrýlýyor
	}
	else{
		printf("palindrom degil.");//palindrom olup olmadýðý yazdýrýlýyor
	}	
}

