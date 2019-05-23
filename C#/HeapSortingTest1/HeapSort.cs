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
            if(right <= heapSize && arr[right] > arr[largest])
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
            // after build max heap, heap sorting.
            // 4 10 3 5 1
            // 10 5 4 3 1

            BuildHeap(arr);

            for (int i = arr.Length - 1; i >= 0; i--) 
            {
                Swap(arr, 0, i); // largest to last
                heapSize--; // delete last and consider it's sorted

                Heapify(arr, 0); // again.

            }
                
            
            
        }
        private void DisplayArray(int[] arr)
        {

        }


    }
}
