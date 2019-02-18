#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
int oldal;
float tomb[2][2];
void osszegek(string sztringek);

int main(){

    string egyenlet;
    string elsoResz;
    string masodikResz;
    string szabadtag;

    ifstream book("Untitled1");
    int n;cin>>n;

    for(int a=0; a<n; a++){
        oldal=0;
        getline(book,egyenlet);
        cout<<egyenlet<<" -->";
        int equ = egyenlet.find('=');
        elsoResz = egyenlet.substr(0,equ);
        masodikResz = egyenlet.substr(equ+1);

        osszegek(elsoResz);

        oldal++;
        osszegek(masodikResz);


        if(tomb[0][0]==tomb[1][0] && tomb[0][1]==tomb[1][1])cout<<"Vegtelen megoldas van!"<<endl;
        if(tomb[0][0]==tomb[1][0] && tomb[0][1]!=tomb[1][1])cout<<"Nincs valos megoldas!"<<endl;
        if(tomb[0][0]!=tomb[1][0]){
            float answ;
            answ = (tomb[1][1]-tomb[0][1])/(tomb[0][0]-tomb[1][0]);
            cout<<"X="<<answ<<endl;
        }
    }


return 0;
}
void osszegek(string sztringek ){
        string elsoResz = sztringek;
        string szabadtag;
        bool egyresz;
        bool elojel;
        bool elotag;
        int xosszeg=0;
        int osszeg = 0;
        if(elsoResz[0]=='-'){elojel=false;elsoResz = elsoResz.substr(1);}
        else elojel=true;


        int pos1 = elsoResz.find('+');
        int pos2 = elsoResz.find('-');
        int beginning = 0;
        int ending;
        int szam = 0;
        int xszam=0;

        if(pos1==string::npos && pos2==string::npos){
            szabadtag = elsoResz;
            bool volt=false;
            if(szabadtag.find("x")==string::npos && !volt){
                for(int i=0;i<szabadtag.length();i++){
                    int szj = szabadtag[i]-48; szam = szam * 10 + szj;}}

            if(szabadtag == "x"){xszam = 1;volt = true;}
            if(szabadtag.find("x")!=string::npos && !volt){
                                                        int x = szabadtag.find("x");
                                                        szabadtag.erase(x,1);
                                                        for(int i=0; i<szabadtag.length(); i++)
                                                        {
                                                            int szj = szabadtag[i]-48;
                                                            xszam = xszam * 10 + szj;}}

                    if(elojel==false){xosszeg-=xszam;
                                     osszeg-=szam;}
                    if(elojel==true){xosszeg+=xszam;
                                    osszeg+=szam;}
                    szam = 0;
                    xszam=0;
        }///ELSO IF....................................................................................
       else{

         while (pos1!= -1 || pos2!= -1)
        {

                                                    if((pos1 < pos2 && pos1!=string::npos && pos2!=string::npos)||(pos2==string::npos && pos1!=string::npos)){
                                                        ending = pos1;
                                                        elsoResz.replace(pos1,1, "P");                                                                                                                                    }

                                                    if((pos2 < pos1 && pos1!=string::npos && pos2!=string::npos)||(pos1==string::npos && pos2!=string::npos)){
                                                        ending = pos2;
                                                        elsoResz.replace(pos2,1, "M");                                                                                                                                   }



                                                    szabadtag = elsoResz.substr(beginning,ending-beginning);   /***Ez a 2 elojel kozotti resz*/


                                                    if(szabadtag=="x"){xszam=1;}

                                                    if(szabadtag.find("x")!=-1) {
                                                        int x = szabadtag.find("x");
                                                        szabadtag.erase(x,1);
                                                        for(int i=0; i<szabadtag.length(); i++)
                                                        {
                                                            int szj = szabadtag[i]-48;
                                                            xszam = xszam * 10 + szj;
                                                        }
                                                    }

                                                    else                                                                                                         /**..ha nincs akkor 'sima' osszeghez adjuk*/
                                                    {
                                                        for(int i=0; i<szabadtag.length(); i++)
                                                        {
                                                            int szj = szabadtag[i]-48;
                                                            szam = szam * 10 + szj;
                                                        }
                                                    }

                                                    if(beginning==0)
                                                    {
                                                        if(elojel==false)
                                                            xosszeg-=xszam;
                                                        if(elojel==false)
                                                            osszeg-=szam;
                                                        if(elojel==true)
                                                            xosszeg+=xszam;
                                                        if(elojel==true)
                                                            osszeg+=szam;
                                                    }
                                                    if(beginning>0)
                                                    {
                                                        char jel = elsoResz[beginning-1];
                                                        if(jel=='P')
                                                            xosszeg+=xszam;
                                                        if(jel=='P')
                                                            osszeg+=szam;
                                                        if(jel=='M')
                                                            xosszeg-=xszam;
                                                        if(jel=='M')
                                                            osszeg-=szam;
                                                    }


                                                    beginning = ending + 1;
                                                    szam = 0;
                                                    xszam=0;
                                                    pos1 = elsoResz.find('+');
                                                    pos2 = elsoResz.find('-');


        }
          if(pos1==string::npos && pos2==string::npos)
        {
            char jel;
            jel = elsoResz[beginning-1];
            szabadtag = elsoResz.substr(beginning);
            bool volt=false;
            if(szabadtag == "x"){xszam = 1;volt = true;}
            if(szabadtag.find("x")!=string::npos && !volt){
                int x = szabadtag.find("x");
                szabadtag.erase(x,1);
                for(int i=0; i<szabadtag.length(); i++)
                                                        {
                                                            int szj = szabadtag[i]-48;
                                                            xszam = xszam * 10 + szj;
                                                        }

            }
            if(szabadtag.find("x")==string::npos && !volt){
                for(int i=0;i<szabadtag.length();i++){
                    int szj = szabadtag[i]-48; szam = szam * 10 + szj;
                }
            }


                                                        if(jel=='P')
                                                            xosszeg+=xszam;
                                                        if(jel=='P')
                                                            osszeg+=szam;
                                                        if(jel=='M')
                                                            xosszeg-=xszam;
                                                        if(jel=='M')
                                                            osszeg-=szam;
        }}///ELSE....................................................................................................


        if(oldal==0){
            tomb[0][0]=xosszeg;
            tomb[0][1]=osszeg;}
        if(oldal==1){
            tomb[1][0]=xosszeg;
            tomb[1][1]=osszeg;
        }


}
