import java.util.Scanner;
interface A//���A�Ķ���
{
    int getsize();//���е����Ա��������?
    int getMsize();      
    void insert(int i,int x);
    void set(int i,int x);
    void delete(int i);
    void find(int x);	
}
public class List implements A//��List�Ķ��壬��ʵ�ֽӿ�A
{
    private int a[];             
    private int Maxsize;     
    private int nowsize;
    List ()        //�޲������캯������
    {
    	Maxsize=30;
    	a=new int [Maxsize];
    	nowsize=0;
    }
    public int getsize()//���ص�ǰ����Ԫ�ظ���
    {
    	return nowsize;
    }
    public int getMsize()//���ظ�˳�����󳤶�
    {
    	return Maxsize;
    }
    public void add(int a1)//�����������˳���Ԫ�أ��������ǰ����Ԫ�ظ���
    {
    	int i=0;                 
    	System.out.println("��ǰ˳�����"+(nowsize)+"��Ԫ��");
    	for(;nowsize<Maxsize;nowsize++)
	    {
	    	if(i==a1)                      
	            break;
	        System.out.println("�������"+(nowsize+1)+"��Ԫ�ص�ֵ");
	        Scanner s1=new Scanner(System.in);
	        a[nowsize]=s1.nextInt();
	        i++;
	    }
    }
    public void insert(int i,int x)//���뺯������,�ڵ�i��λ��֮ǰ������
    {                               
    	int j=0;
        if(i<1||i>nowsize)
            System.out.println("�Բ������λ�ò��Ϸ�");
        else 
        {
        	for(j=nowsize-1;j>=i-1;j--)
        	    a[j+1]=a[j];
        	a[i-1]=x;                 
        	nowsize++;                
        }	
    }
    public void set(int i,int x)//�޸ĺ������壬�ѵ�i��λ�õ�Ԫ���޸�Ϊx
    {
    	if(i<1||i>nowsize)
            System.out.println("�Բ���,�޸�λ�ò��Ϸ�");
    	a[i-1]=x;
    }
    public void delete(int i)//ɾ����������
    {
    	int j=0;
        if(i<1||i>nowsize)
            System.out.println("�Բ���,ɾ��λ�ò��Ϸ�");
        else
        {
        	for(j=i-1;j<nowsize-1;j++)
        	    a[j]=a[j+1];                  
        	nowsize--;             
        }
    }
    public void find(int x)//���Һ������壬�ҵ���xֵ����ϵ�Ԫ��,���������Ԫ��λ��
    {
    	int i=0,j=0;
    	for(i=0;i<nowsize;i++)
    	    if(a[i]==x)
    	    {
    	        System.out.println("�����"+(i+1)+"��Ԫ��ֵ���");
    	        j=1;
    	    }
    	if(j==0)
    	    System.out.println("�Բ���û�����Ԫ��");	
    }
    void show()//����������壬�����ǰ˳�������Ԫ��ֵ
    {
    	System.out.println("��ǰ˳�������Ԫ������Ϊ");
        for(int i=0;i<nowsize;i++)
        {
             System.out.println(a[i]);  	
        }	
    }
}
class One//������
{
    public static void main(String []args)//���
    {
	    List aa=new List();
	    System.out.println("��ǰ˳������󳤶�Ϊ"+aa.getMsize());
	    System.out.println("��������Ҫ��ӵ�Ԫ�صĸ���");
	    Scanner s1=new Scanner(System.in);
	    int a1=s1.nextInt();              
	    aa.add(a1);                   
	    aa.show();                   
	    System.out.println("��������Ҫ����Ԫ�صĵ�λ��(�ڼ���֮ǰ)");//����Ԫ��
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    System.out.println("��������Ҫ�ڴ˲����ֵ");
	    int a2;
	    s1=new Scanner(System.in);
	    a2=s1.nextInt();
	    aa.insert(a1,a2);         
	    aa.show();
	    System.out.println("��������Ҫɾ��Ԫ�ص�λ�ã��ڼ�����");//ɾ��Ԫ��
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    aa.delete(a1);            
	    aa.show();
	    System.out.println("��������Ҫ�޸�Ԫ�ص�λ�ã��ڼ�����");//�޸�Ԫ��ֵ
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    System.out.println("�����޸�Ϊ");
	    s1=new Scanner(System.in);
	    a2=s1.nextInt();
	    aa.set(a1,a2);          
	    aa.show(); 
	    System.out.println("��������Ҫ���ҵ�Ԫ��");//����Ԫ��
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    int ac=-1;
	    aa.find(a1);
	    aa.show();
	    System.out.println("��������Ҫ��ӵ�Ԫ�صĸ���");//�ٴμ�����Ӻ����Ƿ���ȷ
	    s1=new Scanner(System.in);
	    a1=s1.nextInt();
	    aa.add(a1);             
	    aa.show();
    }
}
