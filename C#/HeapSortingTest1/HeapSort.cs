using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HeapSortingTest1
{
    class HeapSort
    {
        private int heapSize=0;

        public void BuildHeap(int[] arr)
        {
            heapSize = arr.Length - 1;
            for (int i = heapSize / 2; i >= 0; i--) 
            {
                Heapify(arr, i);
            }

            

        }
        private void Swap(int[] arr, int x, int y)
        {
            int temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
        private void Heapify(int[] arr, int index)
        {
            int left = index * 2;
            int right = index * 2 + 1;
            int largest = index;

            if (left <= heapSize && arr[left] > arr[index]) 
            {
                largest = left;
            }
            if(right <= heapSize && arr[right] > arr[left])
            {
                largest = right;
            }
            if(index != largest)
            {
                Swap(arr, index, largest);
                Heapify(arr, largest);
            }


        }
        public void PerformHeapSort(int[] arr)
        {

        }
        private void DisplayArray(int[] arr)
        {

        }


    }
}
