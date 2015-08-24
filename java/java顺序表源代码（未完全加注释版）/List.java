import java.util.Scanner;
interface A//借口A的定义
{
    int getsize();//公有的虚成员函数定义?
    int getMsize();      
    void insert(int i,int x);
    void set(int i,int x);
    void delete(int i);
    void find(int x);	
}
public class List implements A//类List的定义，并实现接口A
{
    private int a[];             
    private int Maxsize;     
    private int nowsize;
    List ()        //无参数构造函数定义
    {
    	Maxsize=30;
    	a=new int [Maxsize];
    	nowsize=0;
    }
    public int getsize()//返回当前现有元素个数
    {
    	return nowsize;
    }
    public int getMsize()//返回该顺序表最大长度
    {
    	return Maxsize;
    }
    public void add(int a1)//用来依次添加顺序表元素，并输出当前已有元素个数
    {
    	int i=0;                 
    	System.out.println("当前顺序表有"+(nowsize)+"个元素");
    	for(;nowsize<Maxsize;nowsize++)
	    {
	    	if(i==a1)                      
	            break;
	        System.out.println("请输入第"+(nowsize+1)+"个元素的值");
	        Scanner s1=new Scanner(System.in);
	        a[nowsize]=s1.nextInt();
	        i++;
	    }
    }
    public void insert(int i,int x)//插入函数定义,在第i个位置之前，插入
    {                               
    	int j=0;
        if(i<1||i>nowsize)
            System.out.println("对不起，添加位置不合法");
        else 
        {
        	for(j=nowsize-1;j>=i-1;j--)
        	    a[j+1]=a[j];
        	a[i-1]=x;                 
        	nowsize++;                
        }	
    }
    public void set(int i,int x)//修改函数定义，把第i个位置的元素修改为x
    {
    	if(i<1||i>nowsize)
            System.out.println("对不起,修改位置不合法");
    	a[i-1]=x;
    }
    public void delete(int i)//删除函数定义
    {
    	int j=0;
        if(i<1||i>nowsize)
            System.out.println("对不起,删除位置不合法");
        else
        {
        	for(j=i-1;j<nowsize-1;j++)
        	    a[j]=a[j+1];                  
        	nowsize--;             
        }
    }
    public void find(int x)//查找函数定义，找到与x值相符合的元素,若有则输出元素位置
    {
    	int i=0,j=0;
    	for(i=0;i<nowsize;i++)
    	    if(a[i]==x)
    	    {
    	        System.out.println("它与第"+(i+1)+"个元素值相等");
    	        j=1;
    	    }
    	if(j==0)
    	    System.out.println("对不起，没有这个元素");	
    }
    void show()//输出函数定义，输出当前顺序表所有元素值
    {
    	System.out.println("当前顺序表现有元素依次为");
        for(int i=0;i<nowsize;i++)
        {
             System.out.println(a[i]);  	
        }	
    }
}
class One//测试类
{
    public static void main(String []args)//入口
    {
	    List aa=new List();
	    System.out.println("当前顺序表的最大长度为"+aa.getMsize());
	    System.out.println("请输入你要添加的元素的个数");
	    Scanner s1=new Scanner(System.in);
	    int a1=s1.nextInt();              
	    aa.add(a1);                   
	    aa.show();                   
	    System.out.println("请输入你要插入元素的的位置(第几个之前)");//插入元素
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    System.out.println("请输入你要在此插入的值");
	    int a2;
	    s1=new Scanner(System.in);
	    a2=s1.nextInt();
	    aa.insert(a1,a2);         
	    aa.show();
	    System.out.println("请输入你要删除元素的位置（第几个）");//删除元素
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    aa.delete(a1);            
	    aa.show();
	    System.out.println("请输入你要修改元素的位置（第几个）");//修改元素值
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    System.out.println("把他修改为");
	    s1=new Scanner(System.in);
	    a2=s1.nextInt();
	    aa.set(a1,a2);          
	    aa.show(); 
	    System.out.println("请输入你要查找的元素");//查找元素
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    int ac=-1;
	    aa.find(a1);
	    aa.show();
	    System.out.println("请输入你要添加的元素的个数");//再次检验添加函数是否正确
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    aa.add(a1);             
	    aa.show();
    }
}
