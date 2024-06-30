class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] tmp = new int[m+n];
        int i = 0, j = 0, idx = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j]) {
                tmp[idx] = nums1[i];
                i++;
            } else {
                tmp[idx] = nums2[j];
                j++;
            }
            idx++;
        }
        while (i < m) {
            tmp[idx++] = nums1[i++];
        }
        while (j < n) {
            tmp[idx++] = nums2[j++];
        }
        for (int k = 0; k < m+n; ++k) {
            nums1[k] = tmp[k];
        }
    }
}
