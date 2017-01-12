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

int main()
{

    return 0;
}
