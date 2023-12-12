#include <iostream> 
#include <stdlib.h>  
#include <time.h>  
#include <windows.h>
#include <conio.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
string yanse[9]={"灰白","天蓝","淡绿","红","深蓝","紫","深绿","红","灰"};
int jj[111][111]={0},yinxiao=1,first=1,lll;
char b[111][111],c,bb[111][111];//b是地图，bb是标记每个格子如何打印出来 
int a[111][111]={0},cx,cy,n,m,fx[9]={0,1,1,1,0,-1,-1,-1,0},fy[9]={0,1,0,-1,-1,-1,0,1,1},l,ll,bc=0;//bc是本次游戏标错地雷的总格数，l是地雷总数 ，ll是备份（l变成0了） 
void cc(int j)//颜色函数
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),j);
	return;
}
void ys(string a)
{
	if(a=="黑")   cc(0);
	if(a=="深蓝") cc(1);
	if(a=="深绿") cc(2);
	if(a=="淡蓝") cc(3);
	if(a=="深红") cc(4);
	if(a=="紫")   cc(5);
	if(a=="深黄") cc(6);
	if(a=="灰白") cc(7);
	if(a=="灰")   cc(8);
	if(a=="蓝")   cc(9);
	if(a=="淡绿")cc(10);
	if(a=="天蓝")cc(11);
	if(a=="红")  cc(12);
	if(a=="粉")  cc(13);
	if(a=="淡黄")cc(14);
	if(a=="白")  cc(15);
}
void pr()
{
	bool q=0;
	int p=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(bb[i][j]=='o')p++;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(p==n*m-lll&&b[i][j]=='*'){ys("深红");cout<<"雷 ";ys("白");}
			if(bb[i][j]==' '){cout<<"?  ";}//没被点过的格子 
			if(bb[i][j]=='o'){ys(yanse[a[i][j]]);cout<<a[i][j]<<"  ";ys("白");}//被点过的格子 
			if(bb[i][j]=='p'){ys("粉");cout<<"旗 ";ys("白");}//标记 
			if(bb[i][j]=='l'){ys("白");cout<<"雷 ";ys("白");q=1;}//地雷（死后才会显示） 
			if(bb[i][j]=='x'){ys("深红");cout<<"X  ";ys("白");q=1;}//被标记的非地雷区（死后才会 显示） 
		}
		cout<<endl;
	}
	if(p==n*m-lll)
	{
		cout<<"你赢了！"<<endl<<"你把所有的非地雷格找了出来，真棒！"<<endl;system("pause");
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)bb[i][j]=' ',b[i][j]=' ',a[i][j]=0;
		return;
	}
	if(q==1)
	{
		cout<<"你死了！" <<endl<<"你共标记错了"<<bc<<"个地雷"<<endl;system("pause");
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)bb[i][j]=' ',b[i][j]=' ',a[i][j]=0;
		return;
	} 
	if(q==0){cout<<"扣掉标记的数量，还有"<<ll<<"个地雷"<<endl;}
	return;
}
void lei()//将所有的非地雷格子标上数字 
{
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(b[i][j]=='*')a[i][j]=-1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) 
	{
		if(b[i][j]=='?')continue;
		for(int k=1;k<=8;k++)if(a[i+fx[k]][j+fy[k]]!=-1)a[i+fx[k]][j+fy[k]]++;
	}
	return;
}
void ling(int x,int y)//把点到的0周围的0再周围的0……显示出来，用回朔 
{
	if(bb[x][y]=='p')ll++;
	bb[x][y]='o',jj[x][y]=1;
	if(a[x][y]>=1||x>n||x<1||y>m||y<1)return;
	for(int k=1;k<=8;k++)if(jj[x+fx[k]][y+fy[k]]==0)ling(x+fx[k],y+fy[k]);
	return;
}
void play()//开始游戏
{
	system("cls");
	pr();
	cin>>c;
	if(c=='b')cout<<"标记在："<<endl; 
	if(c=='q')cout<<"取消的标记在："<<endl; 
	if(c=='d')cout<<"点击在："<<endl;
	cin>>cx;
	cout<<"第"<<cx<<"行"<<endl; 
	cin>>cy;
	cout<<"第"<<cy<<"列"<<endl;
	Sleep(1500);
	//if(cx>n||cy>m||(c!='b'&&c!='q'&&c!='d')){play();return;}
	system("cls");
	if(c=='b'&&ll>0&&bb[cx][cy]!='o'&&bb[cx][cy]!='p')
	{
		bb[cx][cy]='p',ll--;
		play();
		return;
	}
	if(c=='q')
	{
		if(bb[cx][cy]=='p')bb[cx][cy]=' ',ll++;
		play();
		return;
	}
	if(c=='d')
	{
		if(first==1)//第一次点，点完后才生成地图 
		{
			int o;
   			srand((unsigned)time(NULL));//刷新随机数 （不会产生） 
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)//初始化地图 ，存到数组b 
			{
				o=rand()%6;
				if(n*m-(i-1)*n-j<=1)o=1;
				if(l>0&&o==1&&i!=cx&&j!=cy)b[i][j]='*',l--;
				else b[i][j]='?';
			}
			lei();//给格子标记数字，标记到数组a 
			bb[cx][cy]='o';
			if(a[cx][cy]==0)
			{
				for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)jj[i][j]=0;
				ling(cx,cy);
			}
			if(a[cx][cy]>=1)bb[cx][cy]='o';
			if(yinxiao==1)cout<<'\a';
			first=0;
			play();
			return;
		}
		if(a[cx][cy]==0)
		{
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)jj[i][j]=0;
			ling(cx,cy);
		}
		if(a[cx][cy]>=1)bb[cx][cy]='o';
		if(yinxiao==1)cout<<'\a';
		if(a[cx][cy]==-1)//踩到地雷了 
		{
			bb[cx][cy]='l';
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			{
				if(bb[i][j]=='p'&&b[i][j]!='*')bb[i][j]='x',bc++;
			}
			if(yinxiao==1)for(int i=1;i<=3;i++){cout<<'\a';Sleep(100);}
			pr();
			return;
		}
		play();
		return;
	}
	play();
	return;
} 
void menu() 
{
ca:
	system("cls");
	cout<<"||--------------------||"<<endl;
	cout<<"||        扫雷        ||"<<endl;
	cout<<"||     v1.0的更新     ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||     请选择地图     ||"<<endl;
	cout<<"||    （按键选择）    ||"<<endl;
	cout<<"||   1 新手练习       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||   2 一群地雷       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||   3 眼睛酸痛       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||   4 自定地图       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"|| 退出游戏  游戏说明 ||"<<endl;
	cout<<"|| （按q）   （按h）  ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||                    ||"<<endl;
	if(yinxiao==1)cout<<"||          p 关闭音效||"<<endl;
	else cout<<"||          p 打开音效||"<<endl;
	cout<<"||--------------------||"<<endl;
	c=getche();
	system("cls");
	if(c=='1')n=10,m=10,l=10;
	if(c=='2')n=20,m=20,l=30;
	if(c=='3')n=30,m=30,l=100;
	if(c=='4')
	{
		cout<<"请输入地图的长、宽和地雷数。"<<endl;
		cout<<"长（不超过100）：";
		cin>>n;
		cout<<"宽（不超过100）：";
		cin>>m;
		cout<<"地雷数（不超过长×宽÷3）：";
		cin>>l;
		if(n>100||m>100||l>n*m/3){cout<<"输入无效，返回主菜单！"<<endl;Sleep(1000);menu();return;}
	}
	if(c=='h')
	{
		cout<<"||--------------------||"<<endl;
		cout<<"||      游戏说明      ||"<<endl;
		cout<<"||   点开空格需要先   ||"<<endl;
		cout<<"||   输入“d”,标记   ||"<<endl;
		cout<<"||   地雷需要先输入   ||"<<endl;
		cout<<"||   “b”,取消标记   ||"<<endl;
		cout<<"||   需要先输入“q”; ||"<<endl;
		cout<<"||   输入字母后,再输  ||"<<endl;
		cout<<"||   入坐标就行了。   ||"<<endl;
		cout<<"||   坐标:从上到下,   ||"<<endl;
		cout<<"||   从左到右。       ||"<<endl;
		cout<<"|| 按任意键返回主菜单 ||"<<endl;
		cout<<"||--------------------||"<<endl;
		c=getche();
		menu();
		return;
	}
	if(c=='p')
	{
		yinxiao=1-yinxiao;
		menu();
		return;
	}
	if(c=='q')return;
    ll=l,lll=ll;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)bb[i][j]=' ';
	first=1;
	pr();
	play();
	menu();
	return;
}
int main()
{
	menu();
	return 0;
}
