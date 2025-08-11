class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // idx → index for placing elements in nums1 (starting from end)
        // i   → last valid element index in nums1
        // j   → last element index in nums2
        int idx = (m + n) - 1; // last index in nums1 (full size)
        int i = m - 1;         // last index of initialized elements in nums1
        int j = n - 1;         // last index in nums2

        // Merge from the end so we don't overwrite nums1's original values
        while (j >= 0 && i >= 0) {
            if (nums1[i] >= nums2[j]) {
                // If nums1[i] is greater, place it at nums1[idx]
                nums1[idx] = nums1[i];
                i--;   // Move left in nums1
                idx--; // Move left in merged position

                /*
                Alternative shorthand:
                nums1[idx--] = nums1[i--];
                */
            }
            else {
                // If nums2[j] is greater, place it at nums1[idx]
                nums1[idx] = nums2[j];
                j--;   // Move left in nums2
                idx--; // Move left in merged position

                /*
                Alternative shorthand:
                nums1[idx--] = nums2[j--];
                */
            }
        }

        // If any elements remain in nums2 (nums1 already in place),
        // copy them to nums1
        while (j >= 0) {
            nums1[idx] = nums2[j];
            idx--;
            j--;
        }
    }
};

