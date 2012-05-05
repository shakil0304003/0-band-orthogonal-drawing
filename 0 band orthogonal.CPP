#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<math.h>
#define max(x,y)(x>y?x:y)
#define min(x,y)(x>y?y:x)


hidemouseptr();
getmousepos(int *button,int *x,int *y);
restrictmouseptr(int x1,int y1,int x2, int y2);
showmouseptr();
union REGS isa,o;


class se_pa
{
public:
long sa[39][39];
long s[39][39];
long node[39];
long n;
long A[39][39];
long a[39];
long start[39];
long end[39];
long ABC[39];
char type[39];
char fix[39];
long tree;
long count;
long X1[39];
long X2[39];
long Y[39];
long position_x[39];
long position_y[39];

public:
long band0;
long spqy;
 //////////////////start//////////////////
 int start_input()
 {
 int button,x,y;
 clrscr();
 cleardevice();
 rectangle(100,50,500,100);
/////////settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 settextstyle(7, 0, 1);
 outtextxy(140,60,"No - band orthogonal drawing.");
 rectangle(100,200,200,250);
 outtextxy(105,210,"Graphical");
 rectangle(300,200,400,250);
 outtextxy(320,210,"Table");
 rectangle(200,300,300,350);
 outtextxy(230,310,"Exit");
 restrictmouseptr(0,0,600,600);  //55,445,585,455
 delay(500);
 showmouseptr();

int input_type=-1;

while(1)
{
 getmousepos(&button,&x,&y);
 if((button & 2)==2)
  {
  input_type=-1;
  break;
  }
 if((button & 1)==1)
 {
 if(x>=200&&x<=300&&y>=300&&y<=350)
 {
 input_type=-1;
 break;
 }
 if(x>=100&&x<=200&&y>=200&&y<=250)
 {

  input_type=2;
  break;
 }
 if(x>=300&&x<=400&&y>=200&&y<=250)
 {
 input_type=1;
 break;
 }

 }

 }

 hidemouseptr();
 return input_type;

 }

 ///////////////////start/////////////////
 /////////graphycal input///////////////
void grapicaly()
{
fas:
cleardevice();
clrscr();
settextstyle(6, 0, 1);
rectangle(50,50,100,100);
outtextxy(58,60,"Node");
rectangle(150,50,200,100);
outtextxy(158,60,"Edge");
rectangle(250,50,300,100);
outtextxy(260,60,"End");
rectangle(350,50,400,100);
outtextxy(355,60,"Clear");
delay(500);
showmouseptr();
settextstyle(0, 0, 1);
int lo_x[100],lo_y[100],node=1;
int indicator=0;
int button,x,y;
int p_f = -1;
int i,j;
char strp[10];
  for(i=1;i<=36;i++)
  for(j=1;j<=36;j++)
  s[i][j]=0;

while(1)
{
 getmousepos(&button,&x,&y);
 if((button & 2)==2)
  {
  break;
  }
 if((button & 1)==1)
 {
 if(x>=250&&x<=300&&y>=50&&y<=100)
 break;
 else if(x>=350&&x<=400&&y>=50&&y<=100)
 {
 goto fas;
 }
 else if(x>=50&&x<=100&&y>=50&&y<=100)
 indicator=1;
 else if(x>=150&&x<=200&&y>=50&&y<=100)
 {
  indicator=2;
 }
 else if(indicator==1)
 {
 lo_x[node]=x;
 lo_y[node]=y;
 node++;
 hidemouseptr();
 circle(x,y,5);
 strp[0]=0;
 sprintf(strp,"%d",node-1);
 outtextxy(x+10,y+10,strp);
 delay(500);
 showmouseptr();
 }
 else if(indicator==2)
 {
 int nop=-1;
 float g1,g2;
 for(i=1;i<node;i++)
 {
 g1=x-lo_x[i];
 g2=y-lo_y[i];
 g1=g1*g1+g2*g2;
 g1=sqrt(g1);
 if(g1<=5.0)
 {  nop=i; break; }
 }
 if(p_f==-1)
 {
 p_f=nop;
 delay(500);
 }
 else
 {
 s[p_f][nop]=1;
 s[nop][p_f]=1;
 hidemouseptr();
 line(lo_x[p_f],lo_y[p_f],lo_x[nop],lo_y[nop]);
 delay(500);
 showmouseptr();
 p_f=-1;
 }

 }
 }


}

 hidemouseptr();
n=node-1;
   for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
   {
    sa[i][j]=s[i][j];
    }

}

 /////////graphycal input///////////////
 ////////get table input//////////////////////

void input()
{
long m,i,j,x,y;
clrscr();
cleardevice();
printf("\n\n\t=>");
scanf("%ld %ld",&n,&m);
{
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{ sa[i][j]=0;
  s[i][j]=0;
  }

for(i=1;i<=m;i++)
{
printf("\t=>");
scanf("%ld %ld",&x,&y);
sa[x][y]=1;
sa[y][x]=1;
s[x][y]=1;
s[y][x]=1;

}
}

}

  ////////get table input//////////////////////

  //////// conected region///////////////

void ABCected(long h1)
{
long i;
for(i=1;i<=n;i++)
if(sa[h1][i]==1&&node[i]==0)
{
node[i]=node[h1];
ABCected(i);
}
}

//////// conected region///////////////

///////// SPQ tree////////////////////

void nc(long h1,long h2)
{
long i;
for(i=1;i<=n;i++)
if(sa[h1][i]==1&&node[i]==h2)
{
node[i]=node[h1];
nc(i,h2);
}
}
long multi_para(long x,long y,long m)
{
long i,fl[39],temp[39],temp1[39],k1,k2,st,state[39];
long sa1;
for(i=1;i<=n;i++)
fl[i]=0;
temp[0]=x;
fl[x]=1;
temp1[0]=-1;
k1=0;
k2=1;
while(k1!=k2)
{
for(i=1;i<=n;i++)
if(sa[temp[k1]][i]==1&&fl[i]==0&&node[i]==ABC[m])
{
temp[k2]=i;
temp1[k2]=k1;
fl[i]=1;
k2++;
if(i==y)
break;
}
if(temp[k2-1]==y)
break;
k1++;
}
k2--;
k1=0;
while(k2!=-1)
{
state[k1]=temp[k2];
k1++;
k2=temp1[k2];
}
node[x]=ABC[m];
node[y]=ABC[m];

st=k1-2;

while(x!=y)
{
for(sa1=st;sa1>=0;sa1--)
{
for(i=1;i<=n;i++)
fl[i]=0;
temp[0]=x;
fl[x]=1;
temp1[0]=-1;
k1=0;
k2=1;
while(k1!=k2)
{
for(i=1;i<=n;i++)
if(sa[temp[k1]][i]==1&&fl[i]==0&&node[i]==ABC[m]&&i!=state[sa1])
{
temp[k2]=i;
temp1[k2]=k1;
fl[i]=1;
k2++;
if(i==y)
break;
}
if(temp[k2-1]==y)
break;
k1++;
}
if(temp[k2-1]!=y)
{
A[m][a[m]]=tree;
a[m]++;
start[tree]=x;
end[tree]=state[sa1];
st=sa1-1;
x=state[sa1];
type[tree]='P';
fix[tree]='N';
ABC[tree]=count;
a[tree]=0;
for(i=0;i<k2;i++)
node[temp[i]]=count;
node[state[sa1]]=count;
tree++;
count++;
break;
}
}

while(x!=y)
{
k1=0;
for(i=1;i<=n;i++)
if(sa[x][i]==1&&node[i]==ABC[m])
{k1++;k2=i;}
if(k1==1&&k2==state[st])
{
sa[x][k2]=0;
sa[k2][x]=0;
A[m][a[m]]=tree;
a[m]++;
start[tree]=x;
end[tree]=k2;
type[tree]='S';
fix[tree]='Y';
a[tree]=0;
tree++;
x=k2;
st--;
}
else
break;
}
}

return 1;

}
void generate()
{
long m,x,y,u,v;
long i,past,t1,temp[109];
m=1;
while(m!=tree)
{
if(tree>35)
{
spqy=0;
break;
}
if(fix[m]!='Y')
{
if(type[m]=='P')
{
past=count;
x=start[m];
y=end[m];
node[x]=0;
node[y]=0;
for(i=1;i<=n;i++)
if(sa[x][i]==1&&node[i]==ABC[m])
{
node[i]=count;
count++;
nc(i,ABC[m]);
}
for(i=past;i<count;i++)
{
A[m][a[m]]=tree;
a[m]++;
start[tree]=x;
a[tree]=0;
end[tree]=y;
ABC[tree]=i;
type[tree]='S';
fix[tree]='N';
tree++;
}

}
else if(type[m]=='S')
{
x=start[m];
y=end[m];
node[x]=ABC[m];
node[y]=ABC[m];
while(x!=y)
{
u=0;
for(i=1;i<=n;i++)
if(sa[x][i]==1&&node[i]==ABC[m])
{u++;v=i;}
if(u==1)
{
sa[x][v]=0;
sa[v][x]=0;
A[m][a[m]]=tree;
a[m]++;
start[tree]=x;
end[tree]=v;
type[tree]='S';
fix[tree]='Y';
a[tree]=0;
tree++;
x=v;
}
else
{
t1=0;
while(1)
{
u=0;
for(i=1;i<=n;i++)
if(sa[y][i]==1&&node[i]==ABC[m])
{u++;v=i;}
if(u==1)
{
sa[y][v]=0;
sa[v][y]=0;
if(t1==0)
{
temp[t1]=y;
t1++;
}
temp[t1]=v;
t1++;
y=v;
}
else
break;
}
long op;

op=multi_para(x,y,m);

if(op==-1)
{
A[m][a[m]]=tree;
a[m]++;
start[tree]=x;
end[tree]=y;
type[tree]='P';
fix[tree]='N';
ABC[tree]=ABC[m];
a[tree]=0;
tree++;
}

if(t1>0)
{
for(i=t1-2;i>=0;i--)
{
A[m][a[m]]=tree;
a[m]++;
start[tree]=y;
end[tree]=temp[i];
type[tree]='S';
fix[tree]='Y';
a[tree]=0;
tree++;
y=temp[i];
}
}
break;
}
}
}



}
m++;


}
}



void SPQ()
{
long x,y,i;
long max_count=0,xx,yy;
spqy=1;
for(x=1;x<=n;x++)
for(y=x+1;y<=n;y++)
{

for(i=1;i<=n;i++)
{
node[i]=0;
sa[x][i]=0;
sa[i][x]=0;
sa[y][i]=0;
sa[i][y]=0;
}
count=1;
for(i=1;i<=n;i++)
if(node[i]==0&&x!=i&&y!=i)
{
node[i]=count;
ABCected(i);
count++;
}

for(i=1;i<=n;i++)
{
sa[x][i]=s[x][i];
sa[y][i]=s[y][i];
sa[i][x]=s[i][x];
sa[i][y]=s[i][y];
}
if(count>max_count)
{max_count=count;xx=x;yy=y;}
}

x=xx;
y=yy;

for(i=1;i<=n;i++)
{
node[i]=0;
sa[x][i]=0;
sa[i][x]=0;
sa[y][i]=0;
sa[i][y]=0;
}
count=1;
for(i=1;i<=n;i++)
if(node[i]==0&&x!=i&&y!=i)
{
node[i]=count;
ABCected(i);
count++;
}

for(i=1;i<=n;i++)
{
sa[x][i]=s[x][i];
sa[y][i]=s[y][i];
sa[i][x]=s[i][x];
sa[i][y]=s[i][y];
}


start[0]=x;
end[0]=y;
ABC[0]=0;
type[0]='P';
fix[0]='N';
a[0]=0;

for(i=1;i<=n;i++)
{
sa[x][i]=s[x][i];
sa[y][i]=s[y][i];
sa[i][x]=s[i][x];
sa[i][y]=s[i][y];
}

for(i=1;i<count;i++)
{
A[0][a[0]]=i;
a[0]++;
start[i]=x;
a[i]=0;
end[i]= y;
ABC[i]= i;
type[i]='S';
fix[i]='N';
}
tree=count;
generate();
if(spqy==1)
show();
else
shown();
}
void shown()
{
clrscr();
cleardevice();
outtextxy(100,100,"SPQ tree not possible.");
getch();
cleardevice();
clrscr();
}
void show()
{

   clrscr();
   cleardevice();
   settextstyle(0, 1, 1);
long i,j,x,k;
char str[100];
X1[0]=10;
X2[0]=550;
Y[0]=50;
for(i=0;i<tree;i++)
{
circle((X1[i]+X2[i])/2,Y[i],3);
if(fix[i]=='Y')
{
str[0]=0;
sprintf(str,"(%ld,%ld)",start[i],end[i]);
outtextxy((X1[i]+X2[i])/2+4,Y[i]+5,str);
}
else
{
str[0]=0;
sprintf(str,"%c",type[i]);
outtextxy((X1[i]+X2[i])/2+4,Y[i]+5,str);

x=(X2[i]-X1[i])/a[i];
for(j=0;j<a[i];j++)
{
X1[A[i][j]]=X1[i]+x*j;
X2[A[i][j]]=X1[i]+x*(j+1);
Y[A[i][j]]=Y[i]+50;
line((X1[i]+X2[i])/2,Y[i],(X1[A[i][j]]+X2[A[i][j]])/2,Y[A[i][j]]);
}
}
}

 getch();
 cleardevice();
 clrscr();

}

///////// SPQ tree////////////////////
///////////conected check//////////////
long conected()
{
long i,j,k,te[39][39],te1[39][39];
long x,y,ret=0;

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
te[i][j]=s[i][j];

for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(te[i][k]==1&&te[k][j]==1)
te[i][j]=1;

for(x=1;x<=n;x++)
{
for(y=x+1;y<=n;y++)
{
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
te1[i][j]=s[i][j];
for(i=1;i<=n;i++)
{
te1[i][x]=0;
te1[x][i]=0;
te1[i][y]=0;
te1[y][i]=0;
}

for(k=1;k<=n;k++)
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(te1[i][k]==1&&te1[k][j]==1)
te1[i][j]=1;

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
if(i!=x&&i!=y&&j!=x&&j!=y)
if(te[i][j]==1&&te1[i][j]==0)
ret = 1;
if(ret==1)
break;
}
if(ret==1)
break;
}
return ret;

}
///////////conected check//////////////
///////////max degree//////////////
long max_de()
{
long i,j,max,co;
max=0;
for(i=1;i<=n;i++)
{
co=0;
for(j=1;j<=n;j++)
co+=s[i][j];
if(co>max)
max=co;
}

if(max>4)
band0=0;

if(max>=3)
return 1;
else
return 0;
}
///////////max degree//////////////
//////////cycle////////////////////
void cycle1(long h1,long h2,long h3)
{
if(h1>2&&s[h2][h3]==1)
{
if(h1<tree)
tree=h1;
}
else
{
long i;
for(i=1;i<=n;i++)
if(s[h2][i]==1&&node[i]==0)
{
node[i]=1;
cycle1(h1+1,i,h3);
node[i]=0;
}
}
}
long cycle()
{
long min,i;

for(i=1;i<=n;i++)
node[i]=0;

tree=4;

for(i=1;i<=n;i++)
{
node[i]=1;
cycle1(1,i,i);
node[i]=0;
if(tree<4)
break;
}
min=tree;
if(min>=4)
return 1;
else
return 0;
}
//////////cycle////////////////////
////////////0 band/////////////////
void band()
{
long i,j;

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
sa[i][j]=s[i][j];

for(i=1;i<=n;i++)
{
position_x[i]=0;
position_y[i]=0;
}

position_x[start[0]]=250;
position_y[start[0]]=250;
position_x[end[0]]=350;
position_y[end[0]]=350;

parallel(0);

}
void parallel(long h1)
{
long i,lev[39],j,k,max_h1,dx,dy;
long sm[6]={0};

/////if(start[h1]==2)
/////getch();

for(i=1;i<=n;i++)
{
if(s[start[h1]][i]==1)
{
if(position_x[i]==position_x[start[h1]]&&position_y[i]>position_y[start[h1]])
sm[0]=1;
if(position_x[i]==position_x[start[h1]]&&position_y[i]<position_y[start[h1]])
sm[2]=1;
if(position_y[i]==position_y[start[h1]]&&position_x[i]<position_x[start[h1]])
sm[3]=1;
if(position_y[i]==position_y[start[h1]]&&position_x[i]>position_x[start[h1]])
sm[1]=1;
}
}

for(i=1;i<=n;i++)
{
if(s[end[h1]][i]==1)
{
if(position_x[i]==position_x[end[h1]]&&position_y[i]>position_y[end[h1]])
sm[3]=1;
if(position_x[i]==position_x[end[h1]]&&position_y[i]<position_y[end[h1]])
sm[1]=1;
if(position_y[i]==position_y[end[h1]]&&position_x[i]<position_x[end[h1]])
sm[0]=1;
if(position_y[i]==position_y[end[h1]]&&position_x[i]>position_x[end[h1]])
sm[2]=1;
}
}

for(i=0;i<a[h1];i++)
lev[i]=0;

if(sm[0]==0)
{
max_h1=100;
for(i=0;i<a[h1];i++)
if(a[A[h1][i]]<max_h1&&lev[i]==0)
{max_h1=a[A[h1][i]];k=i;}
if(max_h1!=100)
{
series(A[h1][k],position_x[start[h1]],position_y[start[h1]],min(position_x[start[h1]],position_x[end[h1]]),max(position_y[start[h1]],position_y[end[h1]]),position_x[end[h1]],position_y[end[h1]],1);
lev[k]=1;
}
}

for(i=1;i<=n;i++)
{
if(s[start[h1]][i]==1)
{
if(position_x[i]==position_x[start[h1]]&&position_y[i]>position_y[start[h1]])
sm[0]=1;
if(position_x[i]==position_x[start[h1]]&&position_y[i]<position_y[start[h1]])
sm[2]=1;
if(position_y[i]==position_y[start[h1]]&&position_x[i]<position_x[start[h1]])
sm[3]=1;
if(position_y[i]==position_y[start[h1]]&&position_x[i]>position_x[start[h1]])
sm[1]=1;
}
}

for(i=1;i<=n;i++)
{
if(s[end[h1]][i]==1)
{
if(position_x[i]==position_x[end[h1]]&&position_y[i]>position_y[end[h1]])
sm[3]=1;
if(position_x[i]==position_x[end[h1]]&&position_y[i]<position_y[end[h1]])
sm[1]=1;
if(position_y[i]==position_y[end[h1]]&&position_x[i]<position_x[end[h1]])
sm[0]=1;
if(position_y[i]==position_y[end[h1]]&&position_x[i]>position_x[end[h1]])
sm[2]=1;
}
}

if(sm[1]==0)
{
max_h1=100;
for(i=0;i<a[h1];i++)
if(a[A[h1][i]]<max_h1&&lev[i]==0)
{max_h1=a[A[h1][i]];k=i;}
if(max_h1!=100)
{
series(A[h1][k],position_x[start[h1]],position_y[start[h1]],max(position_x[start[h1]],position_x[end[h1]]),min(position_y[start[h1]],position_y[end[h1]]),position_x[end[h1]],position_y[end[h1]],1);
lev[k]=1;
}
}

for(i=1;i<=n;i++)
{
if(s[start[h1]][i]==1)
{
if(position_x[i]==position_x[start[h1]]&&position_y[i]>position_y[start[h1]])
sm[0]=1;
if(position_x[i]==position_x[start[h1]]&&position_y[i]<position_y[start[h1]])
sm[2]=1;
if(position_y[i]==position_y[start[h1]]&&position_x[i]<position_x[start[h1]])
sm[3]=1;
if(position_y[i]==position_y[start[h1]]&&position_x[i]>position_x[start[h1]])
sm[1]=1;
}
}

for(i=1;i<=n;i++)
{
if(s[end[h1]][i]==1)
{
if(position_x[i]==position_x[end[h1]]&&position_y[i]>position_y[end[h1]])
sm[3]=1;
if(position_x[i]==position_x[end[h1]]&&position_y[i]<position_y[end[h1]])
sm[1]=1;
if(position_y[i]==position_y[end[h1]]&&position_x[i]<position_x[end[h1]])
sm[0]=1;
if(position_y[i]==position_y[end[h1]]&&position_x[i]>position_x[end[h1]])
sm[2]=1;
}
}

if(sm[2]==0)
{
for(i=0;i<a[h1];i++)
if(lev[i]==0)
{
dx=position_x[end[h1]]-position_x[start[h1]];
dy=position_y[end[h1]]-position_y[start[h1]];
series(A[h1][i],position_x[start[h1]],position_y[start[h1]]-dy,max(position_x[start[h1]],position_x[end[h1]]+dx),min(position_y[start[h1]]-dy,position_y[end[h1]]),position_x[end[h1]]+dx,position_y[end[h1]],0);
lev[i]=1;
break;
}
}

for(i=1;i<=n;i++)
{
if(s[start[h1]][i]==1)
{
if(position_x[i]==position_x[start[h1]]&&position_y[i]>position_y[start[h1]])
sm[0]=1;
if(position_x[i]==position_x[start[h1]]&&position_y[i]<position_y[start[h1]])
sm[2]=1;
if(position_y[i]==position_y[start[h1]]&&position_x[i]<position_x[start[h1]])
sm[3]=1;
if(position_y[i]==position_y[start[h1]]&&position_x[i]>position_x[start[h1]])
sm[1]=1;
}
}

for(i=1;i<=n;i++)
{
if(s[end[h1]][i]==1)
{
if(position_x[i]==position_x[end[h1]]&&position_y[i]>position_y[end[h1]])
sm[3]=1;
if(position_x[i]==position_x[end[h1]]&&position_y[i]<position_y[end[h1]])
sm[1]=1;
if(position_y[i]==position_y[end[h1]]&&position_x[i]<position_x[end[h1]])
sm[0]=1;
if(position_y[i]==position_y[end[h1]]&&position_x[i]>position_x[end[h1]])
sm[2]=1;
}
}

if(sm[3]==0)
{
for(i=0;i<a[h1];i++)
if(lev[i]==0)
{
dx=position_x[end[h1]]-position_x[start[h1]];
dy=position_y[end[h1]]-position_y[start[h1]];
series(A[h1][i],position_x[start[h1]]-dx,position_y[start[h1]],min(position_x[start[h1]]-dx,position_x[end[h1]]),max(position_y[start[h1]],position_y[end[h1]]+dy),position_x[end[h1]],position_y[end[h1]]+dy,0);
lev[i]=1;
break;
}
}

for(i=0;i<a[h1];i++)
if(lev[i]==0)
band0=0;

}
void series(long h1,long x1,long y1,long x2,long y2,long x3,long y3,long hh1)
{
long i,pa=0,item,h2,j;
for(i=0;i<a[h1];i++)
if(type[A[h1][i]]=='P')
pa++;
if(pa==0)
{
if(a[h1]==2)
{
if(hh1==1)
{
position_x[start[A[h1][1]]]=x2;
position_y[start[A[h1][1]]]=y2;
}
else
band0=0;
}
else
{
item=a[h1]-1;
if(hh1==0&&item<3)
band0=0;
if(item!=0)
{
if(x1==x2)
{
h2=(y2-y1)/(item);
for(i=1;i<=item;i++)
{ position_x[start[A[h1][i]]]=x1;
  position_y[start[A[h1][i]]]=y1+h2*(i-1+hh1); }
}
else if(y1==y2)
{
h2=(x2-x1)/(item);
for(i=1;i<=item;i++)
{ position_x[start[A[h1][i]]]=x1+h2*(i-1+hh1);
  position_y[start[A[h1][i]]]=y1; }
}
if(hh1==0)
{
  position_x[start[A[h1][item-1]]]=x2;
  position_y[start[A[h1][item-1]]]=y2;
  position_x[start[A[h1][item]]]=x3;
  position_y[start[A[h1][item]]]=y3;
}
else
{
  position_x[start[A[h1][item]]]=x2;
  position_y[start[A[h1][item]]]=y2;
}
}

}
}
else if(pa==1)
{
if(hh1==0&&a[h1]<3)
band0=0;
for(i=0;i<a[h1];i++)
if(type[A[h1][i]]=='P')
break;
item=i;
if(item!=0)
{
if(x1==x2)
{
h2=(y2-y1)/(item+1);
for(i=1;i<=item;i++)
{ position_x[start[A[h1][i]]]=x1;
  position_y[start[A[h1][i]]]=y1+h2*(i-1+hh1); }
}
else if(y1==y2)
{
h2=(x2-x1)/(item+1);
for(i=1;i<=item;i++)
{ position_x[start[A[h1][i]]]=x1+h2*(i-1+hh1);
  position_y[start[A[h1][i]]]=y1; }
}
}
j=item;
item=a[h1]-(j+1);
if(item!=0)
{
if(x2==x3)
{
h2=(y3-y2)/(item+1);
for(i=j+1;i<a[h1];i++)
{ position_x[start[A[h1][i]]]=x2;
  position_y[start[A[h1][i]]]=y2+h2*(i-j); }
}
else if(y1==y2)
{
h2=(x3-x2)/(item+1);
for(i=j+1;i<a[h1];i++)
{ position_x[start[A[h1][i]]]=x2+h2*(i-j);
  position_y[start[A[h1][i]]]=y2; }
}
if(hh1==0)
{
  position_x[start[A[h1][a[h1]-1]]]=x3;
  position_y[start[A[h1][a[h1]-1]]]=y3;
}
}
parallel(A[h1][j]);
}
else
{
long yp,xp,xs,ys;
if(hh1==0&&a[h1]<3)
band0=0;
if(x1==x2)
{
yp=(y2-y1)/a[h1];
xp=(x3-x2)/(2*pa+1);
}
else
{
yp=(y3-y2)/(2*pa+1);
xp=(x2-x1)/a[h1];
}
xs=x1;
ys=y1;
if(x1==x2)
ys+=yp*hh1;
else
xs+=xp*hh1;
for(i=0;i<a[h1]-1;i++)
{
if(type[A[h1][i]]=='P')
{
if(x1==x2)
xs+=xp;
else
ys+=yp;
}
  position_x[end[A[h1][i]]]=xs;
  position_y[end[A[h1][i]]]=ys;
if(x1==x2)
ys+=yp;
else
xs+=xp;
}
if(hh1==1)
{
if(x1==x2)
{position_y[end[A[h1][a[h1]-2]]]=y3;}
else
{position_x[end[A[h1][a[h1]-2]]]=x3;}
}
else
{
position_x[end[A[h1][a[h1]-2]]]=x3;
position_y[end[A[h1][a[h1]-2]]]=y3;
if(x1==x2)
{position_y[end[A[h1][a[h1]-3]]]=y3;}
else
{position_x[end[A[h1][a[h1]-3]]]=x3;}
}
for(i=0;i<a[h1];i++)
if(type[A[h1][i]]=='P')
{
parallel(A[h1][i]);
}

}
}
////////////0 band/////////////////
////////////show band//////////////
void show_band()
{
long i,j;
char ch[10];
clrscr();
cleardevice();
settextstyle(0, 0, 1);
for(i=1;i<=n;i++)
{
circle(position_x[i],position_y[i],3);
ch[0]=0;
sprintf(ch,"%ld",i);
outtextxy(position_x[i]+3,position_y[i]+3,ch);
}
for(i=1;i<=n;i++)
for(j=i+1;j<=n;j++)
if(s[i][j]==1)
line(position_x[i],position_y[i],position_x[j],position_y[j]);
getch();
}
////////////show band//////////////
};

int main()
{
   int d,m;
   d=DETECT;
   initgraph(&d,&m,"G:\\Install\\tc\\bgi");


long i,flag;
se_pa A;

while(1)
{
flag=1;
i=A.start_input();
if(i==-1)
break;
else if(i==1)
A.input();
else if(i==2)
A.grapicaly();

clrscr();

A.band0 = 1;

i=A.conected();
if(i==0)
{
printf("\n\n\t It is not a 2 conected Graph.");
flag=0;
}

i=A.max_de();
if(i==0)
{
printf("\n\n\t Max degree less than 3.");
flag=0;
}

i=A.cycle();
if(i==0)
{
printf("\n\n\t Cycle less than 4 node.");
flag=0;
}


if(flag==1)
{
A.SPQ();
if(A.spqy==1)
{
A.band();
if(A.band0==1)
A.show_band();
else
{
printf("\n\tNo-Bend Drawing is not possible for the graph.");
getch();
}
}
}
else
{
printf("\n\tSPQ tree not posible.");
getch();
}

}
closegraph();
return 0;
}


initmouse()
{isa.x.ax=0;
 int86(0x33,&isa,&o);
 return(o.x.ax);
}
getmousepos(int *button,int *x,int *y)
{isa.x.ax=3;
 int86(0x33,&isa,&o);
 *button=o.x.bx;
 *x=o.x.cx;
 *y=o.x.dx;
}
showmouseptr()
{isa.x.ax=1;
 int86(0x33,&isa,&o);
}
restrictmouseptr(int x1,int y1,int x2, int y2)
{isa.x.ax=7;
 isa.x.cx=x1;
 isa.x.dx=x2;
 int86(0x33,&isa,&o);
 isa.x.ax=8;
 isa.x.cx=y1;
 isa.x.dx=y2;
 int86(0x33,&isa,&o);
 }

hidemouseptr()
{
	isa.x.ax=2;
    int86(0x33,&isa,&o);


}