
double findMedianSortedArrays(int* nums1, int Size1, int* nums2, int Size2)
{
    int nums3[2000];
    int index1 = 0,index2 = 0,index3 = 0;
    int mid = (Size1 + Size2 + 1) / 2;
    double midnum;
    while(index1 < Size1 || index2 < Size2)
    {
        if(index1 == Size1)
        {
            while(index2 < Size2)
                nums3[index3++] = nums2[index2++];
            break;
        }
        if(index2 == Size2)
        {
            while(index1 < Size1)
                nums3[index3++] = nums1[index1++];
            break;
        }
        if(nums1[index1] < nums2[index2])
            nums3[index3++] = nums1[index1++];
        else
            nums3[index3++] = nums2[index2++];
    }
    if((Size1 + Size2) % 2 == 0)
        midnum = ((double)nums3[mid] + (double)nums3[mid+1]) / 2;
    else
        midnum = nums3[mid];
    return midnum;
}
