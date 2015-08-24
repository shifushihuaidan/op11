using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace 指针探索
{
    unsafe class Program
    {
         static void fun(int *p)
        {
            *p = 123;
        }
        static void Main(string[] args)
        {
            int a = 456;
            Console.WriteLine("开始时a的值是{0}",a);
            fun(&a);
            Console.WriteLine("现在a的值是{0}", a);

        }
    }
}
