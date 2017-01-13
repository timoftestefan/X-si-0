#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;
int nivel,y,n,z,ok;
bool co;
char c,d,g[18][29],r,trap[255],difc[255];
short a[3][3],bad,p,com,p1,p2,s1,s2,g1,g2,s;
short PZ(int x)
{
    int t=0;
    while(x>9)
    {
        x=x/10;t++;
    }
    return t;
}
void HumanInsertion(int pos,char symbol);
void ComputerInsertion(char symbol,int level);
bool PrintWinner2();
void PrintEgalitate();
void GameFrame();
void afiseaza();
bool PrintWinner1();
bool MakeProblems(char symbol);
bool SolveProblems(char symbol);
void Corner();
bool Cross();
void ChosenOne();
bool SemiCross();
bool Across();
bool L();
bool Bad();
bool Awkward();
int FirstInputVerification (char read[])
{
    if(strlen(read)>1) return 0;
    else if (read[0]=='1') return 1;
        else if (read[0]=='2') return 2;
        else return 0;
}

int GeneralInput(char input[])
{
    if (strlen(input)>1) return 0;
    else if (input[0]=='0') return 0;
     else if (input[0]=='1') return 1;
      else if (input[0]=='2') return 2;
       else if (input[0]=='3') return 3;
        else if (input[0]=='4') return 4;
         else if (input[0]=='5') return 5;
          else if (input[0]=='6') return 6;
           else if (input[0]=='7') return 7;
            else if (input[0]=='8') return 8;
             else if (input[0]=='9') return 9;
             else return 0;
}
int DificultyChoose(char difc[])
{
    if(strlen(difc)>1) return 0;
        else if (difc[0]=='1') return 1;
            else if (difc[0]=='2') return 2;
                else if (difc[0]=='3') return 3;
                    else return 0;
}




int main()
{
    cout << "\n                              X si 0             \n\n";
    cout << " Cum joci?\n\n" ;
    cout << " Fiecare casuta este numerotata de la 1 la 9, de la stanga la dreapta,\n";
    cout << " de sus in jos dupa cum urmeaza:\n\n";
    cout << "                              |   |   \n";
    cout << "                            1 | 2 | 3 \n";
    cout << "                           ___|___|___\n";
    cout << "                              |   |   \n";
    cout << "                            4 | 5 | 6 \n";
    cout << "                           ___|___|___\n";
    cout << "                              |   |   \n";
    cout << "                            7 | 8 | 9 \n";
    cout << "                              |   |   \n\n";
    cout << " Cand este randul sau, jucatorul va introduce numarul corespunzator \n";
    cout << " casutei in care vrea sa introduca X-ul sau 0-ul.\n\n";
    cout << " Doresti sa joci impotriva calculatorului( introdu 1) sau impotriva \n";
    cout << " altei persoane( introdu 2)?  ";
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    a[i][j]=-1;
    int x;
    char read[255];
    cin>>read;
   x=FirstInputVerification(read);
    int missclicks=0;
    while (x!=1&&x!=2)
    {   missclicks++;
        system("cls");
    cout<<endl<<endl<<endl;
    cout << "                          |   |   \n";
    cout << "                        1 | 2 | 3 \n";
    cout << "                       ___|___|___\n";
    cout << "                          |   |   \n";
    cout << "                        4 | 5 | 6 \n";
    cout << "                       ___|___|___\n";
    cout << "                          |   |   \n";
    cout << "                        7 | 8 | 9 \n";
    cout << "                          |   |   \n\n";
        if (missclicks==1)
            cout<<"             Am verificat deja!"<<endl<<"     Introdu o optiune de joc valida(1 sau 2):"<<endl;
        else if (missclicks==2)
            cout<<"             Incearca si un caracter!"<<endl;
        else if (missclicks==3)
            cout<<"             Hai totusi sa ne jucam !Doar prin 1 sau 2 ne putem juca!"<<endl;
        else cout<<"             Introdu o optiune de joc valida(1 sau 2):"<<endl;

    cin>>read;
  x=FirstInputVerification(read);
    }

    while(x==1||x==2)
    {
        if(x==1)
    {
        g1++;
        s=g1;
        system("cls");
        cout<<endl<<endl<<endl;
        cout << "\n     Alege nivelul de dificultate: \n\n";
        cout << "     Usor - 1 \n";
        cout << "     Mediu - 2 \n";
        cout << "     Imposibil de batut - 3 \n\n ";
        cin>>difc;
       nivel=DificultyChoose(difc);
       int prego;
      if (nivel==0) prego =0;
      else prego=1;
      while(!prego)
      {
          system("cls");
          cout<<endl<<endl<<endl;
        cout << "\n    Am mai avut aceasta discutie, te rog sa alegi corect nivelul de dificultate: \n\n";
        cout << "     Usor - 1 \n";
        cout << "     Mediu - 2 \n";
        cout << "     Imposibil de batut - 3 \n\n ";
        cin>>difc;
        nivel=DificultyChoose(difc);
        if(nivel==0) prego=0;
        else prego=1;
      }
        system("cls");
        GameFrame();
        n=0;
        ok=0;
        co=0;
        bad=0;
        s1=p;
        s2=com;
        y=rand() % 2 + 1;
        if(y==1)
        {
            c='X';
            d='0';
        }
        else
        {
            d='X';
            c='0';
        }
        while(ok==0&&n<9)
        {
            if(y==1)
            {
                system("cls");
                afiseaza();
                cout<<"\n Introdu pozitia pe care vrei sa plasezi "<<c<<" ";
                cin>>trap;
              z=GeneralInput(trap);
            if(z){
                if(a[(z-1)/3][(z+2)%3]==-1)
                {
                    n++;
                    HumanInsertion(z,c);
                    y=2;
                }
                else
                {
                    while(a[(z-1)/3][(z+2)%3]!=-1)
                    {
                        system("cls");
                        afiseaza();
                        cout<<"\n    Introdu o pozitie valida unde vrei sa plasezi "<<c<<" ";
                        cin>>z;
                    }
                    n++;
                    HumanInsertion(z,c);
                    y=2;
                }
            }
            }
            else
            {
                n++;
                ComputerInsertion(d,nivel);
                y=1;
            }
            if(PrintWinner1())
            {
                ok=1;
            }
        }
        s1=p;
        s2=com;
        if(ok==0)
        {
            system("cls");
            afiseaza();
            PrintEgalitate();
        }
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        a[i][j]=-1;
        cout<<endl;
        cout << "      Doresti sa mai joci? Da? Impotriva calculatorului (introdu 1), impotriva altei\n";
        cout << "   persoane(introdu 2). Nu? Introdu 0.  ";
        cin>>x;
        }
        if(x==2)
    {
        g2++;
        s=g2;
        system("cls");
        GameFrame();
        n=0;
        ok=0;
        s1=p1;
        s2=p2;
        y=rand() % 2 + 1;
        if(y==1)
        {
            c='X';
            d='0';
        }
        else
        {
            d='X';
            c='0';
        }
        while(ok==0&&n<9)
        {
            system("cls");
            if(y==1)
            {
                afiseaza();
                cout<<"\n Jucatorul numarul 1 introdu pozitia pe care vrei sa plasezi "<<c<<" ";
                cin>>z;
                if(a[(z-1)/3][(z+2)%3]==-1)
                {
                    n++;
                    HumanInsertion(z,c);
                    y=2;
                }
                else
                {
                    while(a[(z-1)/3][(z+2)%3]!=-1)
                    {
                        system("cls");
                        afiseaza();
                        cout<<"\n Introdu o pozitie valida unde vrei sa plasezi "<<c<<" ";
                        cin>>z;
                    }
                    n++;
                    HumanInsertion(z,c);
                    y=2;
                }
            }
            else
            {
                afiseaza();
                cout<<"\n Jucatorul numarul 2 introdu pozitia pe care vrei sa plasezi "<<d<<" ";
                cin>>z;
                 if(a[(z-1)/3][(z+2)%3]==-1)
                {
                    n++;
                    HumanInsertion(z,d);
                    y=1;
                }
                else
                {
                while(a[(z-1)/3][(z+2)%3]!=-1)
                    {
                        system("cls");
                        afiseaza();
                        cout<<"\n Introdu o pozitie valida unde vrei sa plasezi "<<d<<" ";
                        cin>>z;
                    }
                n++;
                HumanInsertion(z,d);
                y=1;
                }
            }
            if(PrintWinner2())
            {

                ok=1;
            }
        }
        s1=p1;
        s2=p2;
        if(ok==0)
        {
            system("cls");
            afiseaza();
            PrintEgalitate();
        }
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        a[i][j]=-1;
        cout << " Doresti sa mai joci? Da? Impotriva calculatorului (introdu 1), impotriva altei\n";
        cout << " persoane(introdu 2). Nu? Introdu 0.  ";
        cin>>x;
    }

    }
    system("cls");
    return 0;
}


void HumanInsertion(int pos,char symbol)
{
    if(symbol=='X')
    {
                a[(pos-1)/3][(pos+2)%3]=1;
                g[((pos-1)/3)*6][((pos+2)%3)*10+1]='_';
                g[((pos-1)/3)*6][((pos+2)%3)*10+2]='_';
                g[((pos-1)/3)*6][((pos+2)%3)*10+5]='_';
                g[((pos-1)/3)*6][((pos+2)%3)*10+6]='_';
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+2]='_';
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+5]='_';
                g[((pos-1)/3)*6+1][((pos+2)%3)*10+1]='['+1;
                g[((pos-1)/3)*6+1][((pos+2)%3)*10+3]='['+1;
                g[((pos-1)/3)*6+2][((pos+2)%3)*10+2]='['+1;
                g[((pos-1)/3)*6+3][((pos+2)%3)*10+5]='['+1;
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+6]='['+1;
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+4]='['+1;
                g[((pos-1)/3)*6+1][((pos+2)%3)*10+4]='/';
                g[((pos-1)/3)*6+1][((pos+2)%3)*10+6]='/';
                g[((pos-1)/3)*6+2][((pos+2)%3)*10+5]='/';
                g[((pos-1)/3)*6+3][((pos+2)%3)*10+2]='/';
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+1]='/';
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+3]='/';
    }
    else
    {
                a[(pos-1)/3][(pos+2)%3]=0;
                g[((pos-1)/3)*6][((pos+2)%3)*10+3]='_';
                g[((pos-1)/3)*6][((pos+2)%3)*10+4]='_';
                g[((pos-1)/3)*6][((pos+2)%3)*10+5]='_';
                g[((pos-1)/3)*6+1][((pos+2)%3)*10+4]='_';
                g[((pos-1)/3)*6+3][((pos+2)%3)*10+4]='_';
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+3]='_';
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+4]='_';
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+5]='_';
                g[((pos-1)/3)*6+1][((pos+2)%3)*10+6]='['+1;
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+2]='['+1;
                g[((pos-1)/3)*6+1][((pos+2)%3)*10+2]='/';
                g[((pos-1)/3)*6+4][((pos+2)%3)*10+6]='/';
                g[((pos-1)/3)*6+2][((pos+2)%3)*10+1]='|';
                g[((pos-1)/3)*6+2][((pos+2)%3)*10+3]='|';
                g[((pos-1)/3)*6+2][((pos+2)%3)*10+5]='|';
                g[((pos-1)/3)*6+2][((pos+2)%3)*10+7]='|';
                g[((pos-1)/3)*6+3][((pos+2)%3)*10+1]='|';
                g[((pos-1)/3)*6+3][((pos+2)%3)*10+3]='|';
                g[((pos-1)/3)*6+3][((pos+2)%3)*10+5]='|';
                g[((pos-1)/3)*6+3][((pos+2)%3)*10+7]='|';
    }
}
void GameFrame()
{
    for(int i=0;i<18;i++)
    for(int j=0;j<29;j++)
    {
        if(j==9||j==19)
        g[i][j]='|';
        else
        if(i==5||i==11)
        g[i][j]='_';
        else
        g[i][j]=' ';
    }
}
void afiseaza()
{
    cout<<"\n";
    for(int i=0;i<18;i++)
        {
            cout<<"          ";
            for(int j=0;j<29;j++)
            cout<<g[i][j];
            if(i==1)
            {
                cout<<"           Scor:    ";
            }
            if(i==2)
            {
                cout<<"       _____________";
                for(int h=1;h<=(PZ(s1)+2*(PZ(s))+PZ(s2));h++)
                cout<<'_';
            }
            if(i==3)
            {
                cout<<"      |             ";
                for(int h=1;h<=(PZ(s1)+2*(PZ(s))+PZ(s2));h++)
                cout<<' ';
                cout<<'|';
            }
            if(i==4)
            {
                cout<<"      |  "<<s1<<'/'<<s<<" - "<<s2<<'/'<<s;
                for(int h=1;h<=2;h++)
                cout<<' ';
                cout<<'|';
            }
            if(i==5)
            {
                cout<<"      |_____________";
                for(int h=1;h<=(PZ(s1)+2*(PZ(s))+PZ(s2));h++)
                cout<<'_';
                cout<<'|';
            }
            cout<<'\n';
        }
    cout<<"\n";
}
void ComputerInsertion(char symbol,int level)
{
    int x;

    if(level==1)
    {
        x=rand()%9+1;
        while(a[(x-1)/3][(x+2)%3]!=-1)
        {
            x=rand()%9+1;
        }
        HumanInsertion(x,symbol);
        system("cls");
        afiseaza();
        cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
        cout<<" pentru a-ti face mutarea.\n ";
        cin>>r;
    }
    else
    {
        if(n==1)
        {
        HumanInsertion(5,symbol);
        system("cls");
        afiseaza();
        cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
        cout<<" pentru a-ti face mutarea.\n ";
        cin>>r;
        }
        if(n==2&&a[1][1]!=-1&&level==2)
        {
            ComputerInsertion(symbol,1);
        }
        if(n==2&&a[1][1]!=-1&&level==3)
        {
            Corner();
            system("cls");
            afiseaza();
            cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
            cout<<" pentru a-ti face mutarea.\n ";
            cin>>r;
        }
        if(n==2&&a[1][1]==-1)
        {
        HumanInsertion(5,symbol);
        system("cls");
        afiseaza();
        cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
        cout<<" pentru a-ti face mutarea.\n ";
        cin>>r;
        }
        if(level==2&&n>2)
        {
            if(MakeProblems(symbol))
            {
                system("cls");
                afiseaza();
                cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                cout<<" pentru a-ti face mutarea.\n ";
                cin>>r;
            }
            else
            {
                if(SolveProblems(symbol))
                {
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                }
                else
                {
                ComputerInsertion(symbol,1);
                }
            }
        }
        if(level==3)
        {
            if(n==3)
            {
                if(Cross())
                {
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                }
                else
                {
                    ChosenOne();
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                }
            }
            if(n==5)
            {
                if(!co)
                {
                    ComputerInsertion(symbol,2);
                }
                else
                {
                    if(SolveProblems(symbol))
                    {
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                    }
                    else
                    if(SemiCross())
                    {
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                    }
                }
            }
            if(n==7)
                ComputerInsertion(symbol,2);
            if(n==4)
            {
                if(Across())
                {
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                }
                else
                {
                    if(Bad())
                    {
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                    }
                    else
                    {

                        if(L())
                        {
                        system("cls");
                        afiseaza();
                        cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                        cout<<" pentru a-ti face mutarea.\n ";
                        cin>>r;
                        }
                        else
                        {
                        if(Awkward())
                        {
                        system("cls");
                        afiseaza();
                        cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                        cout<<" pentru a-ti face mutarea.\n ";
                        cin>>r;

                        }
                            else
                            {
                                if(SolveProblems(symbol))
                                {
                                system("cls");
                                afiseaza();
                                cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                                cout<<" pentru a-ti face mutarea.\n ";
                                cin>>r;
                                }
                                else
                                {
                                Corner();
                                system("cls");
                                afiseaza();
                                cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                                cout<<" pentru a-ti face mutarea.\n ";
                                cin>>r;
                                }
                            }
                        }
                    }
                }
            }
            if(n==6)
            {
                if(bad==1)
                {
                    if(MakeProblems(symbol))
                {
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                }
                else
                {
                    HumanInsertion(3,'0');
                    system("cls");
                    afiseaza();
                    cout<<" Calculatorul a facut aceasta miscare. Introdu orice caracter\n";
                    cout<<" pentru a-ti face mutarea.\n ";
                    cin>>r;
                }
                }
                else
                {
                ComputerInsertion('0',2);
                }
            }
            if(n==8)
            {

                ComputerInsertion('0',2);
            }
            if(n==9)
            ComputerInsertion('X',2);
        }
    }
}
void PrintEgalitate()
{
cout<<" Egalitate!\n";
}

bool PrintWinner1()
{
    s1=p;s2=com;
    if(a[0][0]!=-1)
    {
        if(a[0][0]==a[0][1]&&a[0][2]==a[0][0])
            {

                if(a[0][0]==0)
                {
                    if(c=='0')
                    {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";

                    }
                    else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                p++;
                s1=p;
                s2=com;
                system("cls");
                afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                else
                {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                }
            }
            return 1;
            }
        if(a[0][0]==a[1][0]&&a[0][0]==a[2][0])
           {
               if(a[0][0]==0)
                {
                    if(c=='0')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                    else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
            }
            return 1;
           }
           if(a[0][0]==a[1][1]&&a[0][0]==a[2][2])
           {
               if(a[0][0]==0)
                {
                    if(c=='0')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                    else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
            }
            return 1;
           }
    }
        if(a[1][1]!=-1)
        {

        if(a[1][1]==a[0][1]&&a[1][1]==a[2][1])
            {
                if(a[1][1]==0)
                {
                    if(c=='0')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                    else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
            }
            return 1;
            }
        if(a[1][1]==a[1][0]&&a[1][1]==a[1][2])
           {
               if(a[1][1]==0)
                {
                    if(c=='0')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                    else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
            }
            return 1;
           }
           if(a[1][1]==a[2][0]&&a[0][2]==a[1][1])
           {
               if(a[1][1]==0)
                {
                    if(c=='0')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                    else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
            }
            return 1;
           }
        }
        if(a[2][2]!=-1)
            {
            if(a[2][2]==a[2][1]&&a[2][0]==a[2][2])
            {
                if(a[2][2]==0)
                {
                    if(c=='0')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";

                }
                    else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
            }
            return 1;
            }
        if(a[2][2]==a[0][2]&&a[2][2]==a[1][2])
           {
               if(a[2][2]==0)
                {
                    if(c=='0')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";

                }
                    else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
                else
                {
                if(c=='X')
                {
                    p++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                cout<<"\n Felicitari, ai castigat in fata calculatorului!\n";
                }
                else
                    {
                    com++;
                    s1=p;
                    s2=com;
                    system("cls");
                    afiseaza();
                    cout<<"\n Calculatorul a castigat!\n";
                    }
                }
            return 1;
           }
        }
    return 0;
}
bool PrintWinner2()
{
        if(a[0][0]!=-1)
    {
        if(a[0][0]==a[0][1]&&a[0][2]==a[0][0])
            {

                if(a[0][0]==0)
                {
                    if(c=='0')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                    else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
            }
            return 1;
            }
        if(a[0][0]==a[1][0]&&a[0][0]==a[2][0])
           {
               if(a[0][0]==0)
                {
                    if(c=='0')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                    else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
            }
            return 1;
           }
           if(a[0][0]==a[1][1]&&a[0][0]==a[2][2])
           {
               if(a[0][0]==0)
                {
                    if(c=='0')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                    else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
            }
            return 1;
           }
    }
        if(a[1][1]!=-1)
        {

        if(a[1][1]==a[0][1]&&a[1][1]==a[2][1])
            {
                if(a[1][1]==0)
                {
                    if(c=='0')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                    else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
            }
            return 1;
            }
        if(a[1][1]==a[1][0]&&a[1][1]==a[1][2])
           {
               if(a[1][1]==0)
                {
                    if(c=='0')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                    else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
            }
            return 1;
           }
           if(a[1][1]==a[2][0]&&a[0][2]==a[1][1])
           {
               if(a[1][1]==0)
                {
                    if(c=='0')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                    else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";
                }
                else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
            }
            return 1;
           }
        }
            if(a[2][2]!=-1)
            {
            if(a[2][2]==a[2][1]&&a[2][0]==a[2][2])
            {
                if(a[2][2]==0)
                {
                    if(c=='0')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                    else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
            }
            return 1;
            }
        if(a[2][2]==a[0][2]&&a[2][2]==a[1][2])
           {
               if(a[2][2]==0)
                {
                    if(c=='0')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";
                }
                    else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
                }
            else
            {
                if(c=='X')
                {
                    p1++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 1, ai castigat!\n";

                }
                else
                    {
                    p2++;
                    s1=p1;
                    s2=p2;
                    system("cls");
                    afiseaza();
                    cout<<"\n Felicitari, jucatorule cu numarul 2, ai castigat!\n";
                    }
            }
            return 1;
            }
        }
    return 0;

}
bool MakeProblems(char symbol)
{
    int x,i,j;
    if(symbol=='X')
    x=1;
    else
    x=0;
    if((a[0][0]==a[1][1]&&a[2][2]==-1&&a[0][0]==x)
       ||(a[2][2]==a[1][1]&&a[0][0]==-1&&a[2][2]==x)
       ||(a[0][0]==a[2][2]&&a[1][1]==-1&&a[2][2]==x)
       )
       {
           i=0;
           while(a[i][i]==x)
           {
               i++;
           }
           HumanInsertion(i*4+1,symbol);
           return 1;
       }
    if((a[0][2]==a[1][1]&&a[2][0]==-1&&a[0][2]==x)
       ||(a[2][0]==a[1][1]&&a[0][2]==-1&&a[2][0]==x)
       ||(a[0][2]==a[2][0]&&a[1][1]==-1&&a[2][0]==x)
       )
       {
           i=0;
           while(a[i][2-i]==x)
           {
               i++;
           }
           HumanInsertion(i*2+3,symbol);
           return 1;
       }
       for(i=0;i<3;i++)
       {
        if((a[i][0]==a[i][1]&&a[i][2]==-1&&a[i][0]==x)
       ||(a[i][2]==a[i][1]&&a[i][0]==-1&&a[i][2]==x)
       ||(a[i][0]==a[i][2]&&a[i][1]==-1&&a[i][2]==x)
       )
       {
           j=0;
           while(a[i][j]==x)
           {
               j++;
           }
           HumanInsertion((3*i+j+1),symbol);
           return 1;
       }
       }
        for(i=0;i<3;i++)
       {
        if((a[0][i]==a[1][i]&&a[2][i]==-1&&a[0][i]==x)
       ||(a[2][i]==a[1][i]&&a[0][i]==-1&&a[2][i]==x)
       ||(a[0][i]==a[2][i]&&a[1][i]==-1&&a[2][i]==x)
       )
       {
           j=0;
           while(a[j][i]==x)
           {
               j++;
           }
           HumanInsertion((3*j+i+1),symbol);
           return 1;
       }
       }
       return 0;
}
bool SolveProblems(char symbol)
{
    int x,i,j;
    if(symbol=='X')
    x=1;
    else
    x=0;
    x=1-x;
    if((a[0][0]==a[1][1]&&a[2][2]==-1&&a[0][0]==x)
       ||(a[2][2]==a[1][1]&&a[0][0]==-1&&a[2][2]==x)
       ||(a[0][0]==a[2][2]&&a[1][1]==-1&&a[2][2]==x)
       )
       {
           i=0;
           while(a[i][i]==x)
           {
               i++;
           }
           HumanInsertion(i*4+1,symbol);
           return 1;
       }
    if((a[0][2]==a[1][1]&&a[2][0]==-1&&a[0][2]==x)
       ||(a[2][0]==a[1][1]&&a[0][2]==-1&&a[2][0]==x)
       ||(a[0][2]==a[2][0]&&a[1][1]==-1&&a[2][0]==x)
       )
       {
           i=0;
           while(a[i][2-i]==x)
           {
               i++;
           }
           HumanInsertion(i*2+3,symbol);
           return 1;
       }
       for(i=0;i<3;i++)
       {
        if((a[i][0]==a[i][1]&&a[i][2]==-1&&a[i][0]==x)
       ||(a[i][2]==a[i][1]&&a[i][0]==-1&&a[i][2]==x)
       ||(a[i][0]==a[i][2]&&a[i][1]==-1&&a[i][2]==x)
       )
       {
           j=0;
           while(a[i][j]==x)
           {
               j++;
           }
           HumanInsertion((3*i+j+1),symbol);
           return 1;
       }
       }
        for(i=0;i<3;i++)
       {
        if((a[0][i]==a[1][i]&&a[2][i]==-1&&a[0][i]==x)
       ||(a[2][i]==a[1][i]&&a[0][i]==-1&&a[2][i]==x)
       ||(a[0][i]==a[2][i]&&a[1][i]==-1&&a[2][i]==x)
       )
       {
           j=0;
           while(a[j][i]==x)
           {
               j++;
           }
           HumanInsertion((3*j+i+1),symbol);
           return 1;
       }
       }
    return 0;
}
void Corner()
{
    if(a[0][0]==-1)
    {
        HumanInsertion(1,'0');
    }
    else
        if(a[0][2]==-1)
        {
        HumanInsertion(3,'0');
        }
        else
        if(a[2][0]==-1)
        {
        HumanInsertion(7,'0');
        }
        else
        if(a[2][2]==-1)
        {
        HumanInsertion(9,'0');
        }
}
bool Cross()
{
    if(a[0][1]==0)
    {
        HumanInsertion(7,'X');

        return 1;
    }
    if(a[1][0]==0)
    {
        HumanInsertion(9,'X');

        return 1;
    }
    if(a[2][1]==0)
    {
        HumanInsertion(1,'X');

        return 1;
    }
    if(a[1][2]==0)
    {
        HumanInsertion(1,'X');

        return 1;
    }
    return 0;
}
void ChosenOne()
{
    if(a[0][0]==0)
    {
        co=1;
        HumanInsertion(9,'X');
    }
    if(a[2][2]==0)
    {
        co=1;
        HumanInsertion(1,'X');
    }
    if(a[0][2]==0)
    {
        co=1;
        HumanInsertion(7,'X');
    }
    if(a[2][0]==0)
    {
        co=1;
        HumanInsertion(3,'X');
    }
}
bool SemiCross()
{
    if(a[0][2]==0)
    {
        if(a[1][0]==0)
        HumanInsertion(9,'X');
        if(a[2][1]==0)
        HumanInsertion(1,'X');

        return 1;
    }
    if(a[0][0]==0)
    {
        if(a[1][2]==0)
        HumanInsertion(7,'X');
        if(a[2][1]==0)
        HumanInsertion(3,'X');

        return 1;
    }
    if(a[2][0]==0)
    {
        if(a[1][2]==0)
        HumanInsertion(1,'X');
        if(a[0][1]==0)
        HumanInsertion(9,'X');

        return 1;
    }
    if(a[2][2]==0)
    {
        if(a[1][0]==0)
        HumanInsertion(3,'X');
        if(a[0][1]==0)
        HumanInsertion(7,'X');

        return 1;
    }
    return 0;
}
bool Across()
{
    if(a[0][0]==1&&a[1][1]==0&&a[2][2]==1)
    {
        HumanInsertion(2,'0');
        return 1;
    }
    if(a[2][2]==1&&a[1][1]==0&&a[0][0]==1)
    {
        HumanInsertion(2,'0');
        return 1;
    }
    if(a[0][2]==1&&a[1][1]==0&&a[2][0]==1)
    {
        HumanInsertion(2,'0');
        return 1;
    }
    if(a[2][0]==1&&a[1][1]==0&&a[0][2]==1)
    {
        HumanInsertion(2,'0');
        return 1;
    }
    return 0;
}

bool L()
{
    if(a[0][1]==a[1][0]&&a[0][1]==1)
    {
        HumanInsertion(1,'0');
        return 1;
    }
    if(a[2][1]==a[1][2]&&a[2][1]==1)
    {
        HumanInsertion(9,'0');
        return 1;
    }
    if(a[0][1]==a[1][2]&&a[0][1]==1)
    {
        HumanInsertion(3,'0');
        return 1;
    }
    if(a[2][1]==a[1][0]&&a[2][1]==1)
    {
        HumanInsertion(7,'0');
        return 1;
    }
    return 0;
}
bool Bad()
{
    if(a[1][1]==0&&a[0][1]==1&&a[2][1]==1)
    {
        bad=1;
        HumanInsertion(6,'0');
        return 1;
    }
    if(a[1][1]==0&&a[1][0]==1&&a[1][2]==1)
    {
        bad=1;
        HumanInsertion(2,'0');
        return 1;
    }
    return 0;
}
bool Awkward()
{
    if(a[0][0]==1&&(a[1][2]==1||a[2][1]==1))
    {
        HumanInsertion(9,'0');
        return 1;
    }
    if(a[0][2]==1&&(a[1][0]==1||a[2][1]==1))
    {
        HumanInsertion(7,'0');
        return 1;
    }
    if(a[2][0]==1&&(a[1][2]==1||a[0][1]==1))
    {
        HumanInsertion(3,'0');
        return 1;
    }
    if(a[2][2]==1&&(a[0][1]==1||a[1][0]==1))
    {
        HumanInsertion(1,'0');
        return 1;
    }
    return 0;
}
