using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeapSortingTest1
{
    class Program
    {
        static void Main(string[] args)
        {

            Console.WriteLine("asdf");


            int[] mykeys = new int[] { 2, 5, -4, 11, 0, 18, 22, 67, 51, 6 };
            int[] testKeys = new int[] { 2, 8, 5, 3, 9, 1 };

            //double[] mykeys = new double[] {2.22, 0.5, 2.7, -1.0, 11.2};

            //string[] mykeys = new string[] {"Red", "White", "Black", "Green", "Orange"};

            Console.WriteLine("\nOriginal Array Elements :");
            HeapSortOthers1 hsOther1;
            HeapSort hs;

            hs = new HeapSort();
            //hs.BuildHeap(mykeys);
            hs.BuildHeap(testKeys);

            foreach (int mykey in mykeys)
            {
                Console.WriteLine(mykey);
            }




            /*
            hsOther1 = new HeapSortOthers1();
            
            hsOther1.printArray(mykeys);

            hsOther1.heapSort(mykeys);

            Console.WriteLine("\n\nSorted Array Elements :");
            hsOther1.printArray(mykeys);
            Console.WriteLine("\n");
            */

            Console.ReadLine();


        }
    }
}
