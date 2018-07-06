#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <windows.h>
using namespace std;
static int dizidoldur[1500];
static int dizicak[1500];
static int dizibos[1500];
static int ogr_no[500][10];
static char ogr_ad[500][10];
static char ogr_soy[500][10];
static stringstream ss[1500];
static long long dizi[1500];
static stringstream stringad[1500];
static stringstream stringsoyad[1500];
static stringstream stringno[1500];
static stringstream stringdeneme[1500];
static stringstream ss1[1500];
static stringstream stringad1[1500];
static stringstream stringsoyad1[1500];
static stringstream stringno1[1500];
static int islemsayac[7];
static int aramaislem[7];
static int toplamsayac[7];
class ogrenci {

  public:

    char no[10],ad[6],soyad[6];
} ogrn;
int islembosalt();
int bosalt();
int dosya_ac ();
int dosyat();
int bolkalaytas();
int bolkallinyok();
int kataytas();
int katlinyok();
int karortaytas();
int karortlinyok();
int arama();

int main () {
    islembosalt();
    dosya_ac();
    dosyat();
    arama();

  return 0;
}
int islembosalt()
{
    int i;
    for(i=0;i<7;i++)
    {
        islemsayac[i]=0;
        aramaislem[i]=0;
    }
}
int bosalt()
{
     int i;
    char s[1]={};
    for(i=0;i<1500;i++){
    ss[i].clear();
    ss[i].str("");
    stringad[i].clear();
    stringad[i].str("");
    stringsoyad[i].clear();
    stringsoyad[i].str("");
    stringno[i].clear();
    stringno[i].str("");
    dizi[i]=0;
    dizicak[i]=9999;
    dizibos[i]=9999;
    dizidoldur[i]=0;
    }
}

static ogrenci ogr[501];
int dosya_ac()
{
    ofstream fp ("Kayit.txt");
    int i,j,k,no[10];
    char ogr[500];
    srand(time(NULL));

    for(i=0;i<500;i++)
        {
        islemsayac[0]++;
        for(j=0;j<9;j++)
        {
            islemsayac[0]++;
            no[j] = rand()%10;
            islemsayac[0]++;
            fp << no[j];
            islemsayac[0]++;
        }
        for(k=0;k<10;k++)
        {
            islemsayac[0]++;
            if(k==0 || k==5)
            {
                islemsayac[0]++;
                fp<<" ";
                islemsayac[0]++;
                fp<<char(65+rand()%26);
                islemsayac[0]++;
            }
            else
                {
                    islemsayac[0]++;
                    fp<<char(97+rand()%26);
                    islemsayac[0]++;
                }

        }

        fp<<endl;
        islemsayac[0]++;

        }

}

int dosyat()
{

    char s[22];
    int i,j,sayac=0;
    long long temp;
    ifstream op ("Kayit.txt");
    for(i=0;i<1500;i++)
    {
        if(i%3==0)
        {
            op>>ogr[sayac].no;
        }
        if(i%3==1)
        {
            op>>ogr[sayac].ad;
        }
        if(i%3==2)
        {
            op>>ogr[sayac].soyad;
            sayac++;
        }
    }


bolkalaytas();
bolkallinyok();
karortaytas();
karortlinyok();
kataytas();
katlinyok();

}
int bolkalaytas()
{
    bosalt();
    ofstream fp ("BolenKalanveAyrikTasma.txt");
    int i,j,k,sayac=0,sayimod,tmp=0,atamasirasi=0,cakismasira=0;
    char ogrno[10],ograd[6],ogrsoyad[6],ogrno1[10];
    long long sayi;

    for(i=0;i<500;i++)
    {
        islemsayac[1]++;
        //cout<<ogr[i].no<<endl;
        ss[i]<<ogr[i].no;
        islemsayac[1]++;
        ss[i]>>sayi;
        islemsayac[1]++;
        sayimod=sayi%1000;
        islemsayac[1]++;
        dizicak[i]=sayimod;
        islemsayac[1]++;
        for(k=0;k<i;k++)
        {
            islemsayac[1]++;
            if(dizicak[k]==dizicak[i]){
            islemsayac[1]++;
            tmp=1;
            islemsayac[1]++;
            dizibos[atamasirasi]=i;
            islemsayac[1]++;
            //cout<<endl<<endl<<"SIRA = "<<atamasirasi<<" DIZIBOS = "<<i<<endl<<endl;
            atamasirasi++;
            islemsayac[1]++;
            break;
            }
        }
        if(tmp==0){
        islemsayac[1]++;
        //cout<<"dizi("<<sayimod<<") = "<<sayi<<endl;
        dizi[sayimod]=sayi;
        islemsayac[1]++;
        stringno[sayimod]<<ogr[i].no;
        islemsayac[1]++;
        stringad[sayimod]<<ogr[i].ad;
        islemsayac[1]++;
        stringsoyad[sayimod]<<ogr[i].soyad;
        islemsayac[1]++;
        }
        //cout<<sayimod<<" "<<ogr[i].ad<<" "<<ogr[i].soyad<<endl;
        tmp=0;
        islemsayac[1]++;
    }

    for(j=0;j<1500;j++)
    {
        islemsayac[1]++;
        if(dizi[j]!=0){
        islemsayac[1]++;
        stringad[j]>>ograd;
        islemsayac[1]++;
        stringsoyad[j]>>ogrsoyad;
        islemsayac[1]++;
        stringno[j]>>ogrno;
        islemsayac[1]++;
        fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
        islemsayac[1]++;
        }
        else
        {
            islemsayac[1]++;
            if(dizibos[sayac]!=9999&&j>1003)
            {
                islemsayac[1]++;
                cakismasira=dizibos[sayac];
                islemsayac[1]++;
                stringno[j]<<ogr[cakismasira].no;
                islemsayac[1]++;
                stringno[j]>>ogrno;
                islemsayac[1]++;
                stringsoyad[j]<<ogr[cakismasira].soyad;
                islemsayac[1]++;
                stringsoyad[j]>>ogrsoyad;
                islemsayac[1]++;
                stringad[j]<<ogr[cakismasira].ad;
                islemsayac[1]++;
                stringad[j]>>ograd;
                islemsayac[1]++;
                fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
                islemsayac[1]++;
                sayac++;
                islemsayac[1]++;
            }
            else
            {
                islemsayac[1]++;
                fp<<endl;
                islemsayac[1]++;
            }

        }

    }
}
int bolkallinyok()
{
    bosalt();
    ofstream fp ("BolenKalanveLineerYoklama.txt");
    int i,cakisma=0,j,k,sayac=0,sayimod=0,tmp=0,atamasirasi=0,cakismasira=0,cakismagirme=0;
    char ogrno[10],ograd[6],ogrsoyad[6];
    long long sayi=0;

    for(i=0;i<500;i++)
    {
        //cout<<ogr[i].no<<endl;
        islemsayac[2]++;
        ss[i]<<ogr[i].no;
        islemsayac[2]++;
        ss[i]>>sayi;
        islemsayac[2]++;
        sayimod=sayi%1000;
        islemsayac[2]++;
        if(dizicak[i]==9999)
        {
            islemsayac[2]++;
            dizicak[i]=sayimod;
            islemsayac[2]++;
        }
        if(dizicak[i]!=9999)
        {
            islemsayac[2]++;
            while(dizidoldur[sayimod]==1)
            {
                islemsayac[2]++;
                cakismagirme=1;
                islemsayac[2]++;
                //cout<<"CAKISMAGIRME = 1"<<endl;
                sayimod++;
                islemsayac[2]++;
                if(sayimod==1000)
                {
                    islemsayac[2]++;
                    sayimod=0;
                    islemsayac[2]++;
                }

            }
        }
        //cout<<sayimod<<endl;
        if(dizidoldur[sayimod]!=1)
        {
            islemsayac[2]++;
            dizidoldur[sayimod]=1;
            islemsayac[2]++;
        //cout<<"DIZIDOLDUR("<<sayimod<<") ="<<dizidoldur[sayimod]<<endl<<"SIRA = "<<sayimod<<endl;
        }
            for(k=0;k<i;k++)
            {
                islemsayac[2]++;
                if(dizicak[k]==dizicak[i])
                {
                    islemsayac[2]++;
                    cakisma=1;
                    islemsayac[2]++;
                    atamasirasi=sayimod;
                    islemsayac[2]++;
                    while(dizidoldur[atamasirasi]==1&&cakismagirme==0)
                    {
                        islemsayac[2]++;
                        atamasirasi++;
                        islemsayac[2]++;
                        //cout<<"DIZIDOLDUR("<<atamasirasi<<") ="<<dizidoldur[atamasirasi]<<endl<<"SIRA = "<<atamasirasi<<endl;
                        //cout<<"CAKISMAAA GIRMEEE 0"<<" ATAMA SIRASI ="<<atamasirasi<<endl;
                        if(atamasirasi==1000)
                        {
                        islemsayac[2]++;
                        atamasirasi=0;
                        islemsayac[2]++;
                        }


                    }
                        dizidoldur[atamasirasi]=1;
                        islemsayac[2]++;
                        dizibos[atamasirasi]=i;
                        islemsayac[2]++;
                        //cout<<"DIZIDOLDUR("<<atamasirasi<<") = "<<dizidoldur[atamasirasi]<<endl<<"DIZIBOS("<<atamasirasi<<" = "<<i<<endl<<ogr[i].no<<endl;
                        stringno[atamasirasi]<<ogr[i].no;
                        islemsayac[2]++;
                        stringad[atamasirasi]<<ogr[i].ad;
                        islemsayac[2]++;
                        stringsoyad[atamasirasi]<<ogr[i].soyad;
                        islemsayac[2]++;
                        dizi[atamasirasi]=sayi;
                        islemsayac[2]++;
                        //cout<<"DIZIMOD("<<atamasirasi<<") = "<<dizi[atamasirasi]<<"CAKKKKISMA = "<<cakisma<<endl;
                        dizicak[atamasirasi]=sayimod;
                        islemsayac[2]++;
                        atamasirasi=0;
                        islemsayac[2]++;
                        break;
                }

            }
            if(cakisma==0)
                {
                    islemsayac[2]++;
                    stringno[sayimod]<<ogr[i].no;
                    islemsayac[2]++;
                    stringad[sayimod]<<ogr[i].ad;
                    islemsayac[2]++;
                    stringsoyad[sayimod]<<ogr[i].soyad;
                    islemsayac[2]++;
                    dizi[sayimod]=sayi;
                    islemsayac[2]++;
                    //cout<<"DIZI("<<sayimod<<") = "<<dizi[sayimod]<<"CAKISMA = "<<cakisma<<endl;
                }

                cakisma=0;
                islemsayac[2]++;
                cakismagirme=0;
                islemsayac[2]++;

    }

    for(j=0;j<1000;j++)
    {islemsayac[2]++;
        if(dizi[j]!=0){
        islemsayac[2]++;
        stringad[j]>>ograd;
        islemsayac[2]++;
        stringsoyad[j]>>ogrsoyad;
        islemsayac[2]++;
        stringno[j]>>ogrno;
        islemsayac[2]++;
        fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
        islemsayac[2]++;
        }

            else
            {
                islemsayac[2]++;
                fp<<endl;
                islemsayac[2]++;
            }
    }
}

int karortaytas()
{
    bosalt();
    ofstream fp ("KareOrtasiveAyrikTasma.txt");
    int i,j,k,sayac=0,sayimod,tmp=0,atamasirasi=0,cakismasira=0;
    char ogrno[10],ograd[6],ogrsoyad[6];
    long long sayi;
    for(i=0;i<500;i++)
    {
        islemsayac[3]++;
        //cout<<ogr[i].no<<endl;
        ss[i]<<ogr[i].no;
        islemsayac[3]++;
        ss[i]>>sayi;
        islemsayac[3]++;
        sayimod=((sayi*sayi)/10000000)%1000;
        islemsayac[3]++;
        dizicak[i]=sayimod;
        islemsayac[3]++;
        for(k=0;k<i;k++)
        {
            islemsayac[3]++;
            if(dizicak[k]==dizicak[i]){
            islemsayac[3]++;
            tmp=1;
            islemsayac[3]++;
            dizibos[atamasirasi]=i;
            islemsayac[3]++;
            //cout<<endl<<endl<<"SIRA = "<<atamasirasi<<" DIZIBOS = "<<i<<endl<<endl;
            atamasirasi++;
            islemsayac[3]++;
            break;
            }
        }
        if(tmp==0){
        islemsayac[3]++;
        //cout<<"dizi("<<sayimod<<") = "<<sayi<<endl;
        dizi[sayimod]=sayi;
        islemsayac[3]++;
        stringno[sayimod]<<ogr[i].no;
        islemsayac[3]++;
        stringad[sayimod]<<ogr[i].ad;
        islemsayac[3]++;
        stringsoyad[sayimod]<<ogr[i].soyad;
        islemsayac[3]++;
        }
        //cout<<sayimod<<" "<<ogr[i].ad<<" "<<ogr[i].soyad<<endl;
        tmp=0;
        islemsayac[3]++;
    }

    for(j=0;j<1500;j++)
    {
        islemsayac[3]++;
        if(dizi[j]!=0){
        islemsayac[3]++;
        stringad[j]>>ograd;
        islemsayac[3]++;
        stringsoyad[j]>>ogrsoyad;
        islemsayac[3]++;
        stringno[j]>>ogrno;
        islemsayac[3]++;
        fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
        islemsayac[3]++;
        }
        else
        {
            islemsayac[3]++;
            if(dizibos[sayac]!=9999&&j>1003)
            {
                islemsayac[3]++;
                cakismasira=dizibos[sayac];
                islemsayac[3]++;
                stringno[j]<<ogr[cakismasira].no;
                islemsayac[3]++;
                stringno[j]>>ogrno;
                islemsayac[3]++;
                stringsoyad[j]<<ogr[cakismasira].soyad;
                islemsayac[3]++;
                stringsoyad[j]>>ogrsoyad;
                islemsayac[3]++;
                stringad[j]<<ogr[cakismasira].ad;
                islemsayac[3]++;
                stringad[j]>>ograd;
                islemsayac[3]++;
                fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
                islemsayac[3]++;
                sayac++;
                islemsayac[3]++;
            }
            else
            {
                islemsayac[3]++;
                fp<<endl;
                islemsayac[3]++;
            }

        }

    }
}
int karortlinyok()
{
    bosalt();
    ofstream fp ("KareOrtasiveLineerYoklama.txt");
    int i,cakisma=0,j,k,sayac=0,sayimod=0,tmp=0,atamasirasi=0,cakismasira=0,cakismagirme=0;
    char ogrno[10],ograd[6],ogrsoyad[6];
    long long sayi=0;


    for(i=0;i<500;i++)
    {
        //cout<<ogr[i].no<<endl;
        islemsayac[4]++;
        ss[i]<<ogr[i].no;
        islemsayac[4]++;
        ss[i]>>sayi;
        islemsayac[4]++;
        sayimod=((sayi*sayi)/10000000)%1000;
        islemsayac[4]++;
        if(dizicak[i]==9999)
        {
            islemsayac[4]++;
            dizicak[i]=sayimod;
            islemsayac[4]++;
        }
        if(dizicak[i]!=9999)
        {
            islemsayac[4]++;
            while(dizidoldur[sayimod]==1)
            {
                islemsayac[4]++;
                cakismagirme=1;
                islemsayac[4]++;
                //cout<<"CAKISMAGIRME = 1"<<endl;
                sayimod++;
                islemsayac[4]++;
                if(sayimod==1000)
                {
                    islemsayac[4]++;
                    sayimod=0;
                    islemsayac[4]++;
                }

            }
        }
        //cout<<sayimod<<endl;
        if(dizidoldur[sayimod]!=1)
        {
            islemsayac[4]++;
            dizidoldur[sayimod]=1;
            islemsayac[4]++;
        //cout<<"DIZIDOLDUR("<<sayimod<<") ="<<dizidoldur[sayimod]<<endl<<"SIRA = "<<sayimod<<endl;
        }
            for(k=0;k<i;k++)
            {
                islemsayac[4]++;
                if(dizicak[k]==dizicak[i])
                {
                    islemsayac[4]++;
                    cakisma=1;
                    islemsayac[4]++;
                    atamasirasi=sayimod;
                    islemsayac[4]++;
                    while(dizidoldur[atamasirasi]==1&&cakismagirme==0)
                    {
                        islemsayac[4]++;
                        atamasirasi++;
                        islemsayac[4]++;
                        //cout<<"DIZIDOLDUR("<<atamasirasi<<") ="<<dizidoldur[atamasirasi]<<endl<<"SIRA = "<<atamasirasi<<endl;
                        //cout<<"CAKISMAAA GIRMEEE 0"<<" ATAMA SIRASI ="<<atamasirasi<<endl;
                        if(atamasirasi==1000)
                        {
                        islemsayac[4]++;
                        atamasirasi=0;
                        islemsayac[4]++;
                        }


                    }
                        dizidoldur[atamasirasi]=1;
                        islemsayac[4]++;
                        dizibos[atamasirasi]=i;
                        islemsayac[4]++;
                        //cout<<"DIZIDOLDUR("<<atamasirasi<<") = "<<dizidoldur[atamasirasi]<<endl<<"DIZIBOS("<<atamasirasi<<" = "<<i<<endl<<ogr[i].no<<endl;
                        stringno[atamasirasi]<<ogr[i].no;
                        islemsayac[4]++;
                        stringad[atamasirasi]<<ogr[i].ad;
                        islemsayac[4]++;
                        stringsoyad[atamasirasi]<<ogr[i].soyad;
                        islemsayac[4]++;
                        dizi[atamasirasi]=sayi;
                        islemsayac[4]++;
                        //cout<<"DIZIMOD("<<atamasirasi<<") = "<<dizi[atamasirasi]<<"CAKKKKISMA = "<<cakisma<<endl;
                        dizicak[atamasirasi]=sayimod;
                        islemsayac[4]++;
                        atamasirasi=0;
                        islemsayac[4]++;
                        break;
                }

            }
            if(cakisma==0)
                {
                    islemsayac[4]++;
                    stringno[sayimod]<<ogr[i].no;
                    islemsayac[4]++;
                    stringad[sayimod]<<ogr[i].ad;
                    islemsayac[4]++;
                    stringsoyad[sayimod]<<ogr[i].soyad;
                    islemsayac[4]++;
                    dizi[sayimod]=sayi;
                    islemsayac[4]++;
                    //cout<<"DIZI("<<sayimod<<") = "<<dizi[sayimod]<<"CAKISMA = "<<cakisma<<endl;
                }

                cakisma=0;
                islemsayac[4]++;
                cakismagirme=0;
                islemsayac[4]++;

    }

    for(j=0;j<1000;j++)
    {islemsayac[4]++;
        if(dizi[j]!=0){
        islemsayac[4]++;
        stringad[j]>>ograd;
        islemsayac[4]++;
        stringsoyad[j]>>ogrsoyad;
        islemsayac[4]++;
        stringno[j]>>ogrno;
        islemsayac[4]++;
        fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
        islemsayac[4]++;
        }

            else
            {
                islemsayac[4]++;
                fp<<endl;
                islemsayac[4]++;
            }
    }
}
int kataytas()
{

    bosalt();
    ofstream fp ("KatlamaveAyrikTasma.txt");
    int i,j,k,sayac=0,sayimod,tmp=0,atamasirasi=0,cakismasira=0;
    char ogrno[10],ograd[6],ogrsoyad[6];
    long long sayi;
    for(i=0;i<500;i++)
    {
        islemsayac[5]++;
        //cout<<ogr[i].no<<endl;
        ss[i]<<ogr[i].no;
        islemsayac[5]++;
        ss[i]>>sayi;
        islemsayac[5]++;
        sayimod=(((((sayi/1000000)%10)*100)+((sayi/1000000)/100)+(((((sayi/1000000)%100)/10)*10)))+((sayi/1000)%1000)+((((sayi%1000)%10)*100)+((sayi%1000)/100)+(((((sayi%1000)%100)/10)*10))))%1000;
        islemsayac[5]++;
        dizicak[i]=sayimod;
        islemsayac[5]++;
        for(k=0;k<i;k++)
        {
            islemsayac[5]++;
            if(dizicak[k]==dizicak[i]){
            islemsayac[5]++;
            tmp=1;
            islemsayac[5]++;
            dizibos[atamasirasi]=i;
            islemsayac[5]++;
            //cout<<endl<<endl<<"SIRA = "<<atamasirasi<<" DIZIBOS = "<<i<<endl<<endl;
            atamasirasi++;
            islemsayac[5]++;
            break;
            }
        }
        if(tmp==0){
        islemsayac[5]++;
        //cout<<"dizi("<<sayimod<<") = "<<sayi<<endl;
        dizi[sayimod]=sayi;
        islemsayac[5]++;
        stringno[sayimod]<<ogr[i].no;
        islemsayac[5]++;
        stringad[sayimod]<<ogr[i].ad;
        islemsayac[5]++;
        stringsoyad[sayimod]<<ogr[i].soyad;
        islemsayac[5]++;
        }
        //cout<<sayimod<<" "<<ogr[i].ad<<" "<<ogr[i].soyad<<endl;
        tmp=0;
        islemsayac[5]++;
    }

    for(j=0;j<1500;j++)
    {
        islemsayac[5]++;
        if(dizi[j]!=0){
        islemsayac[5]++;
        stringad[j]>>ograd;
        islemsayac[5]++;
        stringsoyad[j]>>ogrsoyad;
        islemsayac[5]++;
        stringno[j]>>ogrno;
        islemsayac[5]++;
        fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
        islemsayac[5]++;
        }
        else
        {
            islemsayac[5]++;
            if(dizibos[sayac]!=9999&&j>1003)
            {
                islemsayac[5]++;
                cakismasira=dizibos[sayac];
                islemsayac[5]++;
                stringno[j]<<ogr[cakismasira].no;
                islemsayac[5]++;
                stringno[j]>>ogrno;
                islemsayac[5]++;
                stringsoyad[j]<<ogr[cakismasira].soyad;
                islemsayac[5]++;
                stringsoyad[j]>>ogrsoyad;
                islemsayac[5]++;
                stringad[j]<<ogr[cakismasira].ad;
                islemsayac[5]++;
                stringad[j]>>ograd;
                islemsayac[5]++;
                fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
                islemsayac[5]++;
                sayac++;
                islemsayac[5]++;
            }
            else
            {
                islemsayac[5]++;
                fp<<endl;
                islemsayac[5]++;
            }

        }

    }
}

int katlinyok()
{
    bosalt();
    ofstream fp ("KatlamaveLineerYoklama.txt");
    int i,cakisma=0,j,k,sayac=0,sayimod=0,tmp=0,atamasirasi=0,cakismasira=0,cakismagirme=0;
    char ogrno[10],ograd[6],ogrsoyad[6];
    long long sayi=0;

    for(i=0;i<500;i++)
    {
        islemsayac[6]++;
        //cout<<ogr[i].no<<endl;
        ss[i]<<ogr[i].no;
        islemsayac[6]++;
        ss[i]>>sayi;
        islemsayac[6]++;
        sayimod=(((((sayi/1000000)%10)*100)+((sayi/1000000)/100)+(((((sayi/1000000)%100)/10)*10)))+((sayi/1000)%1000)+((((sayi%1000)%10)*100)+((sayi%1000)/100)+(((((sayi%1000)%100)/10)*10))))%1000;
        islemsayac[6]++;
        if(dizicak[i]==9999)
        {
            islemsayac[6]++;
            dizicak[i]=sayimod;
            islemsayac[6]++;
        }
        if(dizicak[i]!=9999)
        {
            islemsayac[6]++;
            while(dizidoldur[sayimod]==1)
            {
                islemsayac[6]++;
                cakismagirme=1;
                islemsayac[6]++;
                //cout<<"CAKISMAGIRME = 1"<<endl;
                sayimod++;
                islemsayac[6]++;
                if(sayimod==1000)
                {
                    islemsayac[6]++;
                    sayimod=0;
                    islemsayac[6]++;
                }

            }
        }
        //cout<<sayimod<<endl;
        if(dizidoldur[sayimod]!=1)
        {
            islemsayac[6]++;
            dizidoldur[sayimod]=1;
            islemsayac[6]++;
        //cout<<"DIZIDOLDUR("<<sayimod<<") ="<<dizidoldur[sayimod]<<endl<<"SIRA = "<<sayimod<<endl;
        }
            for(k=0;k<i;k++)
            {
                islemsayac[6]++;
                if(dizicak[k]==dizicak[i])
                {
                    islemsayac[6]++;
                    cakisma=1;
                    islemsayac[6]++;
                    atamasirasi=sayimod;
                    islemsayac[6]++;
                    while(dizidoldur[atamasirasi]==1&&cakismagirme==0)
                    {
                        islemsayac[6]++;
                        atamasirasi++;
                        islemsayac[6]++;
                        //cout<<"DIZIDOLDUR("<<atamasirasi<<") ="<<dizidoldur[atamasirasi]<<endl<<"SIRA = "<<atamasirasi<<endl;
                        //cout<<"CAKISMAAA GIRMEEE 0"<<" ATAMA SIRASI ="<<atamasirasi<<endl;
                        if(atamasirasi==1000)
                        {
                        islemsayac[6]++;
                        atamasirasi=0;
                        islemsayac[6]++;
                        }


                    }
                        dizidoldur[atamasirasi]=1;
                        islemsayac[6]++;
                        dizibos[atamasirasi]=i;
                        islemsayac[6]++;
                        //cout<<"DIZIDOLDUR("<<atamasirasi<<") = "<<dizidoldur[atamasirasi]<<endl<<"DIZIBOS("<<atamasirasi<<" = "<<i<<endl<<ogr[i].no<<endl;
                        stringno[atamasirasi]<<ogr[i].no;
                        islemsayac[6]++;
                        stringad[atamasirasi]<<ogr[i].ad;
                        islemsayac[6]++;
                        stringsoyad[atamasirasi]<<ogr[i].soyad;
                        islemsayac[6]++;
                        dizi[atamasirasi]=sayi;
                        islemsayac[6]++;
                        //cout<<"DIZIMOD("<<atamasirasi<<") = "<<dizi[atamasirasi]<<"CAKKKKISMA = "<<cakisma<<endl;
                        dizicak[atamasirasi]=sayimod;
                        islemsayac[6]++;
                        atamasirasi=0;
                        islemsayac[6]++;
                        break;
                }

            }
            if(cakisma==0)
                {
                    islemsayac[6]++;
                    stringno[sayimod]<<ogr[i].no;
                    islemsayac[6]++;
                    stringad[sayimod]<<ogr[i].ad;
                    islemsayac[6]++;
                    stringsoyad[sayimod]<<ogr[i].soyad;
                    islemsayac[6]++;
                    dizi[sayimod]=sayi;
                    islemsayac[6]++;
                    //cout<<"DIZI("<<sayimod<<") = "<<dizi[sayimod]<<"CAKISMA = "<<cakisma<<endl;
                }

                cakisma=0;
                islemsayac[6]++;
                cakismagirme=0;
                islemsayac[6]++;

    }

    for(j=0;j<1000;j++)
    {
        islemsayac[6]++;
        if(dizi[j]!=0){
        islemsayac[6]++;
        stringad[j]>>ograd;
        islemsayac[6]++;
        stringsoyad[j]>>ogrsoyad;
        islemsayac[6]++;
        stringno[j]>>ogrno;
        islemsayac[6]++;
        fp<<ogrno<<" "<<ograd<<" "<<ogrsoyad<<endl;
        islemsayac[6]++;
        }

            else
            {
                islemsayac[6]++;
                fp<<endl;
                islemsayac[6]++;
            }
    }
}
int arama()
{
    string aranan,line;
    int sira=0,bulunma=1,i,tmp=0;
    char ogrno[10];
    int pos;
    for(i=0;i<500;i++)
    {
    ifstream f1 ("kayit.txt");
    ifstream f2 ("BolenKalanveAyrikTasma.txt");
    ifstream f3 ("BolenKalanveLineerYoklama.txt");
    ifstream f4 ("KareOrtasiveAyrikTasma.txt");
    ifstream f5 ("KareOrtasiveLineerYoklama.txt");
    ifstream f6 ("KatlamaveAyrikTasma.txt");
    ifstream f7 ("KatlamaveLineerYoklama.txt");
    stringad1[i]<<ogr[i].no;
    stringad1[i]>>ogrno;
    cout<<endl;
    if(f1.is_open())
    {
        aramaislem[0]++;
        aramaislem[0]++;
        while(!f1.eof())
            {
                aramaislem[0]++;
                getline(f1,line);
                aramaislem[0]++;
                sira++;
                aramaislem[0]++;
            if((pos = line.find(ogrno))!=string::npos)
                {
                    aramaislem[0]++;
                    cout <<line<<" Kayit Dosyasi Sirasi :"<<sira<<endl;
                    aramaislem[0]++;
                    break;
                }

            }

    }
    sira=0;
    aramaislem[0]++;

    if(f2.is_open())
    {
        aramaislem[1]++;
        while(!f2.eof())
            {
                aramaislem[1]++;
                getline(f2,line);
                aramaislem[1]++;
                sira++;
                aramaislem[1]++;
            if((pos = line.find(ogrno))!=string::npos)
                {
                    aramaislem[1]++;
                    cout <<line<<" Bolen Kalan ve Ayrik Tasma Dosyasi Sirasi :"<<sira<<endl;
                    aramaislem[1]++;
                    break;
                }

            }
    }
    sira=0;
    aramaislem[1]++;
    if(f3.is_open())
    {
        aramaislem[2]++;
        while(!f3.eof())
            {
                aramaislem[2]++;
                getline(f3,line);
                aramaislem[2]++;
                sira++;
                aramaislem[2]++;
            if((pos = line.find(ogrno))!=string::npos)
                {
                    aramaislem[2]++;
                    cout <<line<<" Bolen Kalan ve Lineer Yoklama Dosyasi Sirasi :"<<sira<<endl;
                    aramaislem[2]++;
                    break;
                }

            }
    }
    sira=0;
    aramaislem[2]++;
    if(f4.is_open())
    {
        aramaislem[3]++;
        while(!f4.eof())
            {
                aramaislem[3]++;
                getline(f4,line);
                aramaislem[3]++;
                sira++;
                aramaislem[3]++;
            if((pos = line.find(ogrno))!=string::npos)
                {
                    aramaislem[3]++;
                    cout <<line<<" Kare Ortasi ve Ayrik Tasma Dosyasi Sirasi :"<<sira<<endl;
                    aramaislem[3]++;
                    break;
                }

            }
    }
    sira=0;
    aramaislem[3]++;
    if(f5.is_open())
    {
        aramaislem[4]++;
        while(!f5.eof())
            {
                aramaislem[4]++;
                getline(f5,line);
                aramaislem[4]++;
                sira++;
                aramaislem[4]++;
            if((pos = line.find(ogrno))!=string::npos)
                {
                    aramaislem[4]++;
                    cout <<line<<" Kare Ortasi ve Lineer Yoklama Dosyasi Sirasi :"<<sira<<endl;
                    aramaislem[4]++;
                    break;
                }

            }
    }
    sira=0;
    aramaislem[4]++;

    if(f6.is_open())
    {
        aramaislem[5]++;
        while(!f6.eof())
            {
                aramaislem[5]++;
                getline(f6,line);
                aramaislem[5]++;
                sira++;
                aramaislem[5]++;
            if((pos = line.find(ogrno))!=string::npos)
                {
                    aramaislem[5]++;
                    cout <<line<<" Katlama ve Ayrik Tasma Dosyasi Sirasi :"<<sira<<endl;
                    aramaislem[5]++;
                    break;
                }

            }

    }
    sira=0;
    aramaislem[5]++;

    if(f7.is_open())
    {
        aramaislem[6]++;
        while(!f7.eof())
            {
                aramaislem[6]++;
                getline(f7,line);
                aramaislem[6]++;
                sira++;
                aramaislem[6]++;
            if((pos = line.find(ogrno))!=string::npos)
                {
                    aramaislem[6]++;
                    cout <<line<<" Katlama ve Lineer Yoklama Dosyasi Sirasi :"<<sira<<endl;
                    aramaislem[6]++;
                    break;
                }

            }

    }
    sira=0;
    aramaislem[6]++;


    }
    int j,min=99999999;

    for(i=0;i<7;i++)
    {
        if(i==0){cout<<endl<<"Lineer Dosyada Arama "<<endl;}
        if(i==1){cout<<"Bolen Kalan ve Ayrik Tasma "<<endl;}
        if(i==2){cout<<"Bolen Kalan ve Lineer Yoklama "<<endl;}
        if(i==3){cout<<"Kare Ortasi ve Ayrik Tasma "<<endl;}
        if(i==4){cout<<"Kare Ortasi ve Lineer Yoklama "<<endl;}
        if(i==5){cout<<"Katlama ve Ayrik Tasma "<<endl;}
        if(i==6){cout<<"Katlama ve Lineer Yoklama "<<endl;}
        cout<<"Dosya Olusturma Islemi Sayisi : "<<islemsayac[i]<<" Arama Islemi Sayisi : "<<aramaislem[i]<<endl;
        toplamsayac[i]=islemsayac[i]+aramaislem[i];
        cout<<"Toplam Islem Sayisi :"<<toplamsayac[i]<<endl;
        if(toplamsayac[i] < min)
        min=toplamsayac[i];

    }

        cout<<endl;
        if(toplamsayac[0]==min){cout<<"Lineer Dosyada Arama en hizli yontemdir."<<endl;}
        if(toplamsayac[1]==min){cout<<"Bolen Kalan ve Ayrik Tasma en hizli yontemdir."<<endl;}
        if(toplamsayac[2]==min){cout<<"Bolen Kalan ve Lineer Yoklama en hizli yontemdir."<<endl;}
        if(toplamsayac[3]==min){cout<<"Kare Ortasi ve Ayrik Tasma en hizli yontemdir."<<endl;}
        if(toplamsayac[4]==min){cout<<"Kare Ortasi ve Lineer Yoklama en hizli yontemdir."<<endl;}
        if(toplamsayac[5]==min){cout<<"Katlama ve Ayrik Tasma en hizli yontemdir."<<endl;}
        if(toplamsayac[6]==min){cout<<"Katlama ve Lineer Yoklama en hizli yontemdir."<<endl;}


}


