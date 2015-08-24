using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace 读写文件1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //创建 打开文件 对话框，可以直接拖控件哈。。
            OpenFileDialog ofd=new OpenFileDialog();
            //将文件路径显示在文本框
            if (ofd.ShowDialog() == DialogResult.OK)
             {
                 textBox1.Text = ofd.FileName;
             }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //richTextBox1.Text = "你好";
            //创建文件流、流操作要进行异常处理，并以using来释放对象
            try
            {
                using (FileStream fs = new FileStream(textBox1.Text, FileMode.Open))
                {
                    //定义缓存区,3M 大小
                    byte[] arrFileData = new byte[1024 * 1024 * 3];
                    //读文件 存在 arrFileData 中
                    fs.Read(arrFileData, 0, arrFileData.Length);
                    //转 编码格式 以便显示在 文本框 richTextBox1 中
                    string ChangeToString = Encoding.Default.GetString(arrFileData);
                    richTextBox1.Text = ChangeToString;
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("异常:" + ex.Message);
            } 

        }

        private void button3_Click(object sender, EventArgs e)
        {
            String ss = richTextBox1.Text;
            char[] s = ss.ToCharArray();
            for (int i = 0; i < s.Length;i++)
            {
                switch (s[i])
                {
                    case 'a':
                    case 'A': s[i] = 'z'; break;
                    case 'b':
                    case 'B': s[i] = 'y'; break;
                    case 'c':
                    case 'C': s[i] = 'v'; break;
                    case 'd':
                    case 'D': s[i] = 'x'; break;
                    case 'e':
                    case 'E': s[i] = 'u'; break;
                    case 'f':
                    case 'F': s[i] = 't'; break;
                    case 'g':
                    case 'G': s[i] = 's'; break;
                    case 'h':
                    case 'H': s[i] = 'r'; break;
                    case 'i':
                    case 'I': s[i] = 'p'; break;
                    case 'j':
                    case 'J': s[i] = 'o'; break;
                    case 'k':
                    case 'K': s[i] = 'm'; break;
                    case 'l':
                    case 'L': s[i] = 'n'; break;
                    case 'm':
                    case 'M': s[i] = 'l'; break;
                    case 'n':
                    case 'N': s[i] = 'j'; break;
                    case 'o':
                    case 'O': s[i] = 'x'; break;
                    case 'p':
                    case 'P': s[i] = 'k'; break;
                    case 'q':
                    case 'Q': s[i] = 'y'; break;
                    case 'r':
                    case 'R': s[i] = 'h'; break;
                    case 's':
                    case 'S': s[i] = 'i'; break;
                    case 't':
                    case 'T': s[i] = 'g'; break;
                    case 'u':
                    case 'U': s[i] = 'e'; break;
                    case 'v':
                    case 'V': s[i] = 'f'; break;
                    case 'W':
                    case 'w': s[i] = 'd'; break;
                    case 'x':
                    case 'X': s[i] = 'a'; break;
                    case 'y':
                    case 'Y': s[i] = 'c'; break;
                    case 'z':
                    case 'Z': s[i] = 'b'; break;
                    case '0': s[i] = '9'; break;
                    case '1': s[i] = '7'; break;
                    case '2': s[i] = '5'; break;
                    case '3': s[i] = '6'; break;
                    case '4': s[i] = '4'; break;
                    case '5': s[i] = '3'; break;
                    case '6': s[i] = '2'; break;
                    case '7': s[i] = '0'; break;
                    case '8': s[i] = '1'; break;
                    case '9': s[i] = '8'; break;
                    default:
                        s[i] = '#'; break;
                }
            }
            richTextBox1.Text = new string(s);
            //MessageBox.Show(s[3].ToString());
        }

        private void button4_Click(object sender, EventArgs e)
        {
            //获取要写入文本的数据
            string strWriteData = richTextBox1.Text;
            try
            {
                using (FileStream fs = new FileStream(textBox1.Text, FileMode.Create))
                {
                    //转为二进制写入文本
                    byte[] arrWriteData = Encoding.Default.GetBytes(strWriteData);
                    //fs.Write(数据缓存区，从第几个byte开始写，写多少个)
                    fs.Write(arrWriteData, 0, arrWriteData.Length);
                    MessageBox.Show("写入文本成功!");
                }
            }
            catch (Exception ex)
            {

                MessageBox.Show("异常:" + ex.Message);
            }
        }
    }
}
