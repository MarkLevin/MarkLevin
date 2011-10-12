#include <iostream>

using namespace std;

int main()
{
    string s[2];

    cin>>s[0]>>s[1];
   
    int flag1=0,flag2=0;

    if(s[0][0]=='-') 
    {
        flag1=1;
        s[0].erase(0,1);
    }

    if(s[1][0]=='-')
    {
        flag2=1;
        s[1].erase(0,1);
    }


 if (!flag1^flag2) 
  {
    int flag=0,leng=0;
    if(s[0]==s[1]) {cout<<0; return 0;}
    
    if(s[0].length()>s[1].length()) flag=+1;
    else if(s[0].length()<s[1].length()) flag=0;
    else 
    {
        for(int i=0;i<s[0].length();i++)
            if(s[0][i]>s[1][i]) {flag=+1; break;}
            else if(s[0][i]<s[1][i]) {flag=0;break;}
            else if(s[0][i]==s[1][i]) continue;
    }

    leng=(s[0].length()>s[1].length())?s[0].length():s[1].length();

    int min=s[!flag].length()-s[flag].length();

    for(int i=0;i<min;i++) s[flag]='0'+s[flag];

    for(int i=leng-1;i>=0;i--)
        {
            s[!flag][i]=s[!flag][i]-s[flag][i]+'0';
            if(s[!flag][i]<'0')
            {
                s[!flag][i]=s[!flag][i]+10;
                s[!flag][i-1]--;
            }
        }
              

    if(!(flag^flag1)) cout<<'-';

    int offl=1;
    for(int i=0;i<leng;i++)
        {
            if((s[!flag][i]=='0')&&offl) continue;
            else {offl=0;cout<<s[!flag][i];}
        }
    cout<<endl;
  }

  else 
    {
        int flagw=0,leng=0;
        if(s[0].length()<s[1].length())
            flagw=1;
        leng=(s[0].length()>s[1].length())?s[0].length():s[1].length();
        int min=s[flagw].length()-s[!flagw].length();

        for(int j=0;j<min;j++) s[!flagw]='0'+s[!flagw];

        s[flagw]='0'+s[flagw];
        s[!flagw]='0'+s[!flagw];
        for(int i=leng;i>=1;i--)
        {
            s[flagw][i]=s[flagw][i]+s[!flagw][i]-'0';
            if (s[flagw][i]>='0'+10)
            {
                s[flagw][i]=s[flagw][i]-10;
                s[flagw][i-1]++;
            }
        }
        
        if(flag1==1) cout<<'-';

        for(int i=0;i<=leng;i++)
        {
            if ((s[flagw][i]=='0')&&(i==0)) continue;
            cout<<s[flagw][i];
        }
        cout<<endl;
    }

    return 0;

}
