//...C++...     +3x+2=+8+x

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
int main()
{

    string egyenlet,elsoResz,masodikResz,szabadtag;
    ifstream book("Untitled1");
    int n;cin>>n;

    for(int a=0; a<n; a++)
    {
        getline(book,egyenlet);
        cout<<egyenlet<<endl;
        int equ = egyenlet.find('=');
        cout << "Az egyenlõ a(z) " << equ+1 << ". helyen van." << endl;
        elsoResz = egyenlet.substr(0,equ);
        masodikResz = egyenlet.substr(equ+1);
        cout <<  elsoResz << " " << masodikResz<<endl;

        bool elojel;
        bool elotag;
        int xosszeg=0;
        int osszeg = 0;
        // for(int k=0;k<2;k++){

        if(elsoResz[0]=='-'){elojel=false;    /***A muvelet elso eleme biztos egy szam lesz*/
                                        elsoResz = elsoResz.substr(1);}

        else                         elojel=true;

        int pos1 = elsoResz.find('+');
        int pos2 = elsoResz.find('-');
        int beginning = 0;
        int ending;
        int szam = 0;
        int xszam=0;


        while (pos1!= -1 || pos2!= -1)
        {

                                                    if((pos1 < pos2 && pos1!=string::npos && pos2!=string::npos)||(pos2==string::npos && pos1!=string::npos)){
                                                        ending = pos1;
                                                        elsoResz.replace(pos1,1, "P");                                                                                                                                    }

                                                    if((pos2 < pos1 && pos1!=string::npos && pos2!=string::npos)||(pos1==string::npos && pos2!=string::npos)){
                                                        ending = pos2;
                                                        elsoResz.replace(pos2,1, "M");                                                                                                                                   }



                                                    szabadtag = elsoResz.substr(beginning,ending-beginning);   /***Ez a 2 elojel kozotti resz*/


                                                    if(szabadtag=="x"){xszam=1;
                                                    }

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
            int utolsoBetu;
            if(elsoResz.rfind("M")==string::npos && elsoResz.rfind("P")!=string::npos)utolsoBetu = elsoResz.rfind("P");
            if(elsoResz.rfind("P")==string::npos && elsoResz.rfind("M")!=string::npos)utolsoBetu = elsoResz.rfind("M");
            cout<<utolsoBetu;

            /*cout<<"Ez meg vegleg"<<asd<<endl;
            szabadtag = elsoResz.substr(asd+1);
            cout<<"Ez a szabadtag:"<<szabadtag<<endl;

            if(szabadtag=="x")xszam;
            if(szabadtag.find("x")!=-1)
            {
                int x = szabadtag.find("x");
                szabadtag.erase(x,1);
                cout<<"Ez az uj  szabadtag:"<<szabadtag<<endl;
                for(int i=0; i<szabadtag.length(); i++)
                {
                    int szj = szabadtag[i]-48;
                    xszam = xszam * 10 + szj;
                }
                cout<<"Ez a xszamjegy:"<<xszam<<endl;
            }

            else
            {
                for(int i=0; i<szabadtag.length(); i++)
                {
                    int szj = szabadtag[i]-48;
                    szam = szam * 10 + szj;
                    cout<<"Ez a szamjegy"<<szam<<endl;
                }
            }

             char jel = elsoResz[asd];
                                                        if(jel=='P')
                                                            xosszeg+=xszam;
                                                        if(jel=='P')
                                                            osszeg+=szam;
                                                        if(jel=='M')
                                                            xosszeg-=xszam;
                                                        if(jel=='M')
                                                            osszeg-=szam;

*/
        }

        //elsoResz=masodikResz;

        //}

        cout<<"Az osszeg:"<<osszeg<<endl;
        cout<<"Az xosszeg:"<<xosszeg<<endl;

    }


    return 0;
}
