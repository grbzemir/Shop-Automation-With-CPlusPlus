#include<iostream>
#include<cstring>
#include<cstdlib>


#define N 1
#define M 2

using namespace std;

  struct urun

  {
    
    char referans_kodu[10];
    float fiyat;
 
  };

  struct isci
  {
     
        char isim[10];
        char soyisim[10];
        int yas;
        char cinsiyet;
        char gorev[10];
        int maas;
        int calisma_saati;
        
  };
     
     struct magaza
 {

    char isim[10];
    char sokak_ismi[20];
    char mahalle[12];
    char telefon[15];
    float satis;

    struct isci e1;
    struct isci e2;
    struct isci e3;
    struct urun p[M];

 };

  void urunu_olustur(struct urun *pr)

  {

    cout<<"Urunun referans kodunu giriniz: ";
    cin>>pr->referans_kodu;

    cout<<"Urunun fiyatini giriniz: ";
    cin>>pr->fiyat;

  }


   void isciyi_olustur(struct isci *em)
 {

    int i;

    cout<<"Iscinin ismini giriniz: ";
    cin>>em->isim;

    cout<<"Iscinin soyismini giriniz: ";
    cin>>em->soyisim;

    cout<<"Iscinin yasini giriniz: ";
    cin>>em->yas;

    cout<<"Iscinin cinsiyetini giriniz: ";
    cin>>em->cinsiyet;

    cout<<"Iscinin gorevini giriniz: ";
    cin>>em->gorev;

    cout<<"Iscinin maasini giriniz: ";
    cin>>em->maas;

    cout<<"Iscinin calisma saatinizi giriniz: ";
    cin>>em->calisma_saati;

 }

   void magazayi_olustur(struct magaza *m)

   {

    int i;

    cout<<"Magazanin ismini giriniz: ";
    cin>>m->isim;

    cout<<"Magazanin sokak ismini giriniz: ";
    cin>>m->sokak_ismi;

    cout<<"Magazanin mahallesini giriniz: ";
    cin>>m->mahalle;

    cout<<"Magazanin telefonunu giriniz: ";
    cin>>m->telefon;

    cout<<"Magazanin satisini giriniz: ";
    cin>>m->satis;

    isciyi_olustur(&m->e1);
    cout<<"isci 1 olusturuldu"<<endl; 

    isciyi_olustur(&m->e2);
    cout<<"isci 2 olusturuldu"<<endl;

    isciyi_olustur(&m->e3);
    cout<<"isci 3 olusturuldu"<<endl;



    for(i=0;i<M;i++)
    {

        urunu_olustur(&m->p[i]);

    }

   }

   void urun_bas (struct urun p)
   {

    cout<<"Urunun referans kodu: "<<p.referans_kodu<<endl;
    cout<<"Urunun fiyati: "<<p.fiyat<<endl;

   }

    void isciyi_bas (struct isci e)
    {
    
     cout<<"Iscinin ismi: "<<e.isim<<endl;
     cout<<"Iscinin soyismi: "<<e.soyisim<<endl;
     cout<<"Iscinin yasi: "<<e.yas<<endl;
     cout<<"Iscinin cinsiyeti: "<<e.cinsiyet<<endl;
     cout<<"Iscinin gorevi: "<<e.gorev<<endl;
     cout<<"Iscinin maasi: "<<e.maas<<endl;
     cout<<"Iscinin calisma saati: "<<e.calisma_saati<<endl;
    
    }

    void magazayi_bas(struct magaza m)

    {

    int i;

    cout<<"Magazanin ismi: "<<m.isim<<endl;
    cout<<"Magazanin sokak ismi: "<<m.sokak_ismi<<endl;
    cout<<"Magazanin mahallesi: "<<m.mahalle<<endl;
    cout<<"Magazanin telefonu: "<<m.telefon<<endl;
    cout<<"Magazanin satisi: "<<m.satis<<endl;

    cout<<"Isci 1 :"<<endl;
    isciyi_bas(m.e1);

    cout<<"Isci 2 :"<<endl;
    isciyi_bas(m.e2);

    cout<<"Isci 3 :"<<endl;
    isciyi_bas(m.e3);

    for(i=0;i<M;i++)
    {
        
        cout<<"Urun "<<i+1<<":"<<endl;
        urun_bas(m.p[i]);

    }

}

  void en_yasli (struct magaza m)

  {
     
     struct isci yasli;

    if (m.e1.yas >yasli.yas)

    {
        yasli = m.e1;

    }

    if (m.e2.yas >yasli.yas)

    {
        yasli = m.e2;

    }

    if (m.e3.yas >yasli.yas)

    {
        yasli = m.e3;

    }
     
     cout<<"En yasli isci: "<<endl;
     isciyi_bas(yasli);

  }

 void ortalama_fiyat(struct magaza m)

 {

    int i;
    int j;
    float s;

     for ( i=0; i<N; i++)

    {
        for( j =0; j<M; j++)

        {

            s = s + m.p[j].fiyat;

        }

        cout<<"Magazanin "<<i+1<<". urunlerinin ortalamasi: "<<s/M<<endl;
    }
}

void bulundugu_mahalle ( struct magaza m[N] , char q[12])

{
    int i;

    for ( i = 0; i <N; i++)
    {

        if (strcmp(m[i].mahalle,q)==0)

        

            cout<<"Magaza "<<i+1<<endl;
            magazayi_bas(m[i]);

        }

        
    }

    
    int main()

 {

   system("color 20");
   struct magaza m[N];

   int i;

   for ( i = 0; i <N; i++)

   {
      cout<<i+1<<". magazayi olusturunuz"<<endl;
      magazayi_olustur(&m[i]);
    
   }

   for ( i=0 ; i<N; i++)

   {
      
      cout<<i+1<<". magazanin bilgileri: "<<endl;
      magazayi_bas(m[i]);


   }

    en_yasli(m[0]);
    en_yasli(m[1]);
    en_yasli(m[2]);

    ortalama_fiyat(m[0]);
    ortalama_fiyat(m[1]);
    ortalama_fiyat(m[2]);

    bulundugu_mahalle(m,"Kadikoy");

   

    return 0;

}




   