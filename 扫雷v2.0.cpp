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
string yanse[9]={"�Ұ�","����","����","��","����","��","����","��","��"};
int jj[111][111]={0},yinxiao=1,first=1,lll,x=0,y=0,wa=0,wapd=0,z=0,ying=0;
char b[111][111],c,bb[111][111];//b�ǵ�ͼ��bb�Ǳ��ÿ��������δ�ӡ���� 
int youxi=1,a[111][111]={0},cx,cy,n,m,fx[9]={0,1,1,1,0,-1,-1,-1,0},fy[9]={0,1,0,-1,-1,-1,0,1,1},l,ll,bc=0;//bc�Ǳ�����Ϸ�����׵��ܸ�����l�ǵ������� ��ll�Ǳ��ݣ�l���0�ˣ� 
void cc(int j)//��ɫ����
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),j);
	return;
}
void ys(string a)
{
	if(a=="��")   cc(0);
	if(a=="����") cc(1);
	if(a=="����") cc(2);
	if(a=="����") cc(3);
	if(a=="���") cc(4);
	if(a=="��")   cc(5);
	if(a=="���") cc(6);
	if(a=="�Ұ�") cc(7);
	if(a=="��")   cc(8);
	if(a=="��")   cc(9);
	if(a=="����")cc(10);
	if(a=="����")cc(11);
	if(a=="��")  cc(12);
	if(a=="��")  cc(13);
	if(a=="����")cc(14);
	if(a=="��")  cc(15);
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
			if(i==x&&j==y){ys("����");cout<<"�� ";ys("��");continue;}
			if(youxi==1&&p==n*m-lll&&b[i][j]=='*'||bb[i][j]=='k'){ys("����");cout<<"�� ";ys("��");}
			if(bb[i][j]==' '){cout<<"?  ";}//û������ĸ��� 
			if(bb[i][j]=='o'){ys(yanse[a[i][j]]);cout<<a[i][j]<<"  ";ys("��");}//������ĸ��� 
			if(bb[i][j]=='p'){ys("��");cout<<"�� ";ys("��");}//��� 
			if(bb[i][j]=='l'){ys("��");cout<<"�� ";ys("��");q=1;}//���ף�����Ż���ʾ�� 
			if(bb[i][j]=='x'){ys("���");cout<<"X  ";ys("��");q=1;}//����ǵķǵ�����������Ż� ��ʾ�� 
		}
		cout<<endl;
	}
	cout<<endl;
	if(youxi==2&&ll==0)
	{
		cout<<"��Ӯ�ˣ�"<<endl<<"������еĵ����ڵ��ˣ������"<<endl;system("pause");
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)bb[i][j]=' ',b[i][j]=' ',a[i][j]=0;
		x=0,y=0,first=1,ying=1;
		return;
	}
	if(p==n*m-lll&&youxi==1)
	{
		cout<<"��Ӯ�ˣ�"<<endl<<"������еķǵ��׸����˳����������"<<endl;system("pause");
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)bb[i][j]=' ',b[i][j]=' ',a[i][j]=0;
		x=0,y=0,first=1,ying=1;
		return;
	}
	if(q==1)
	{
		cout<<"�����ˣ�" <<endl<<"�㹲��Ǵ���"<<bc<<"������"<<endl;system("pause");
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)bb[i][j]=' ',b[i][j]=' ',a[i][j]=0;
		x=0,y=0,first=1,ying=1;
		return;
	} 
	if(q==0&&youxi==1)
	{
		cout<<"�۵���ǵ�����������"<<ll<<"������"<<endl;
		cout<<"������bΪ��ǣ�qΪȡ����ǣ�dΪ������������С���"<<endl;
	}
	if(q==0&&youxi==2)
	{
		cout<<"��ʣ"<<ll<<"������"<<endl;
		cout<<"��ʣ"<<wa<<"�����ӣ���bʹ��"<<endl;
		if(wapd==0)cout<<"������ͽ������"<<endl;
		else cout<<"������ʹ�ò��ӣ����������һ�������Ŀո�"<<endl; 
		if(first==1)cout<<"�����ڻ�����ʹ�ò��ӣ�"<<endl; 
	}
	if(youxi==2)cout<<"��o�˳�"<<endl; 
	return;
}
void lei()//�����еķǵ��׸��ӱ������� 
{
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)if(b[i][j]=='*')a[i][j]=-1;
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) 
	{
		if(b[i][j]=='?')continue;
		for(int k=1;k<=8;k++)if(a[i+fx[k]][j+fy[k]]!=-1)a[i+fx[k]][j+fy[k]]++;
	}
	return;
}
void ling(int x,int y)//�ѵ㵽��0��Χ��0����Χ��0������ʾ�������û�˷ 
{
	if(bb[x][y]=='p')ll++;
	bb[x][y]='o',jj[x][y]=1;
	if(a[x][y]>=1||x>n||x<1||y>m||y<1)return;
	for(int k=1;k<=8;k++)if(jj[x+fx[k]][y+fy[k]]==0)ling(x+fx[k],y+fy[k]);
	return;
}
void zou(int x,int y)//�����ܲ��ܴ�1,1�ߵ�n,m 
{
	if(x==n&&y==m)z=1;
	if(x==0||x>n||y==0||y>m||z==1)return;
	zou(x+1,y);
	zou(x-1,y);
	zou(x,y+1);
	zou(x,y-1);
}
void play()//��ʼ��Ϸ
{
	system("cls");
	pr();
	if(ying==1){ying=0;return;}
	cin>>c;
	if(c=='b')cout<<"����ڣ�"<<endl; 
	if(c=='q')cout<<"ȡ���ı���ڣ�"<<endl; 
	if(c=='d')cout<<"����ڣ�"<<endl;
	cin>>cx;
	cout<<"��"<<cx<<"��"<<endl; 
	cin>>cy;
	cout<<"��"<<cy<<"��"<<endl;
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
		if(first==1)//��һ�ε㣬���������ɵ�ͼ 
		{
			int o;
   			srand((unsigned)time(NULL));//ˢ������� ����������� 
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)//��ʼ����ͼ ���浽����b 
			{
				o=rand()%6;
				if(n*m-(i-1)*n-j<=1)o=1;
				if(l>0&&o==1&&i!=cx&&j!=cy)b[i][j]='*',l--;
				else b[i][j]='?';
			}
			lei();//�����ӱ�����֣���ǵ�����a 
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
		if(a[cx][cy]==-1)//�ȵ������� 
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
void play2()//���� 
{
	system("cls");
	pr();
	if(ying==1){ying=0;return;}
	c=getche();
	switch(c)
	{
		case 'w':x--;break;
		case 's':x++;break;
		case 'a':y--;break;
		case 'd':y++;break;
		case 'b':wapd=1;wa--;break;
		case 'o':return;break;
	}
	if(x==0)x=1;if(x==n+1)x=n;if(y==0)y=1;if(y==m+1)y=m;
	if(wa<0)wa=0,wapd=0;
	if(first==1&&(x==2||y==2))
	{
		bb[x][y]='o';
		int o;
	   	srand((unsigned)time(NULL));//ˢ������� ����������� 
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)//��ʼ����ͼ ���浽����b 
		{
			o=rand()%6;
			if(n*m-(i-1)*n-j<=1)o=1;
			if(l>0&&o==1&&i!=x&&j!=y)b[i][j]='*',l--;
			else b[i][j]='?';
		}
		lei();//�����ӱ�����֣���ǵ�����a 
		bb[cx][cy]='o';
		if(a[cx][cy]>=1)bb[cx][cy]='o';
		if(yinxiao==1)cout<<'\a';
		first=0;
		play2();
		return;
	}
	if(a[x][y]>=0&&a[x][y]<=9&&bb[x][y]==' ')bb[x][y]='o',wapd=0;
	if(a[x][y]==-1&&wapd==0)
	{
		if(bb[x][y]!='k')//�ȵ������� 
		{
			bb[x][y]='l';
			for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
			{
				if(bb[i][j]=='p'&&b[i][j]!='*')bb[i][j]='x',bc++;
			}
			if(yinxiao==1)for(int i=1;i<=3;i++){cout<<'\a';Sleep(100);}
			pr();
			return;
		}
	}
	if(a[x][y]==-1&&wapd==1)a[x][y]=-2,bb[x][y]='k',wapd=0,ll--;
	play2();
}
void menu() 
{
	if(youxi==1)goto ca;
	else if(youxi==2)goto cb;
ca:	
	youxi=1;
	system("cls");
	cout<<"||--------------------||"<<endl;
	cout<<"||        ɨ��        ||"<<endl;
	cout<<"||     v1.0�ĸ���     ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||     ��ѡ���ͼ     ||"<<endl;
	cout<<"||    ������ѡ��    ||"<<endl;
	cout<<"||   1 ������ϰ       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||   2 һȺ����       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||   3 �۾���ʹ       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||   4 �Զ���ͼ     ->||"<<endl;
	cout<<"||                 ��r||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"|| �˳���Ϸ  ��Ϸ˵�� ||"<<endl;
	cout<<"|| ����q��   ����h��  ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||                    ||"<<endl;
	if(yinxiao==1)cout<<"||          p �ر���Ч||"<<endl;
	else cout<<"||          p ����Ч||"<<endl;
	cout<<"||--------------------||"<<endl;
	c=getche();
	system("cls");
	if(c=='1')n=10,m=10,l=10;
	if(c=='2')n=20,m=20,l=30;
	if(c=='3')n=30,m=30,l=100;
	if(c=='4')
	{
		cout<<"�������ͼ�ĳ�����͵�������"<<endl;
		cout<<"����������100����";
		cin>>n;
		cout<<"��������100����";
		cin>>m;
		cout<<"���������������������3����";
		cin>>l;
		if(n>100||m>100||l>n*m/3){cout<<"������Ч���������˵���"<<endl;Sleep(1000);menu();return;}
	}
	if(c=='h')
	{
		cout<<"||--------------------||"<<endl;
		cout<<"||      ��Ϸ˵��      ||"<<endl;
		cout<<"||   �㿪�ո���Ҫ��   ||"<<endl;
		cout<<"||   ���롰d��,���   ||"<<endl;
		cout<<"||   ������Ҫ������   ||"<<endl;
		cout<<"||   ��b��,ȡ�����   ||"<<endl;
		cout<<"||   ��Ҫ�����롰q��; ||"<<endl;
		cout<<"||   ������ĸ��,����  ||"<<endl;
		cout<<"||   ����������ˡ�   ||"<<endl;
		cout<<"||   ����:���ϵ���,   ||"<<endl;
		cout<<"||   �����ҡ�       ||"<<endl;
		cout<<"|| ��������������˵� ||"<<endl;
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
	if(c=='r'){goto cb;return;}
	if(c=='q')return;
    ll=l,lll=ll,bc=0;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)bb[i][j]=' ';
	first=1;
	pr();
	play();
	menu();
	return;
cb: 
	youxi=2;
	system("cls");
	cout<<"||--------------------||"<<endl;
	cout<<"||        ����        ||"<<endl;
	cout<<"||     v2.0�ĸ���     ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||     ��ѡ���ͼ     ||"<<endl;
	cout<<"||    ������ѡ��    ||"<<endl;
	cout<<"||   1 ������ϰ       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||   2 һȺ����       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||   3 �۾���ʹ       ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||<- 4 �Զ���ͼ       ||"<<endl;
	cout<<"||��e                 ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"|| �˳���Ϸ  ��Ϸ˵�� ||"<<endl;
	cout<<"|| ����q��   ����h��  ||"<<endl;
	cout<<"||                    ||"<<endl;
	cout<<"||                    ||"<<endl;
	if(yinxiao==1)cout<<"||          p �ر���Ч||"<<endl;
	else cout<<"||          p ����Ч||"<<endl;
	cout<<"||--------------------||"<<endl;
	c=getche();
	system("cls");
	if(c=='1')n=10,m=10,l=10;
	if(c=='2')n=20,m=20,l=30;
	if(c=='3')n=30,m=30,l=100;
	if(c=='4')
	{
		cout<<"�������ͼ�ĳ�����͵�������"<<endl;
		cout<<"����������100����";
		cin>>n;
		cout<<"��������100����";
		cin>>m;
		cout<<"���������������������3����";
		cin>>l;
		if(n>100||m>100||l>n*m/3){cout<<"������Ч���������˵���"<<endl;Sleep(1000);menu();return;}
	}
	if(c=='h')
	{
		cout<<"||--------------------||"<<endl;
		cout<<"||      ��Ϸ˵��      ||"<<endl;
		cout<<"||   ����Ϸ��ɨ�׸�   ||"<<endl;
		cout<<"||   ��,��wasd��·��  ||"<<endl;
		cout<<"||   �ߵ��ո��򿪣� ||"<<endl;
		cout<<"||   ��bʹ�ò��ӣ���  ||"<<endl;
		cout<<"||   ���ڵ���һ���ߵ� ||"<<endl;
		cout<<"||   �Ŀո�Ҫ�ڹ�   ||"<<endl;
		cout<<"||   ���еĵ��ײ���   ||"<<endl;
		cout<<"||   ʤ����           ||"<<endl;
		cout<<"|| ��������������˵� ||"<<endl;
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
	if(c=='e'){goto ca;return;}
	if(c=='q')return;
    ll=l,lll=ll,bc=0,wa=l+5;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)bb[i][j]=' ';
    bb[1][1]='o';
	first=1;
	x=1,y=1;
	pr();
	play2();
	menu();
	return;
}
int main()
{
	menu();
	return 0;
}
