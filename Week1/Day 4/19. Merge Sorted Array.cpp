class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // m aur n ko 1 se kam karke last index pe point karte hain
        m--;
        n--;
        // i ko nums1 ke last index pe point karte hain
        int i = nums1.size() - 1;

        // Jab tak nums1 aur nums2 ke elements bachte hain
        while (m >= 0 && n >= 0) {
            // Agar nums1 ka element bada ya barabar hai nums2 ke element se
            if (nums1[m] >= nums2[n]) {
                // Toh nums1 ke element ko i index pe daalte hain
                nums1[i] = nums1[m];
                // m ko 1 se kam karke nums1 ke agle element pe point karte
                // hain
                m--;
            } else {
                // Varna nums2 ke element ko i index pe daalte hain
                nums1[i] = nums2[n];
                // n ko 1 se kam karke nums2 ke agle element pe point karte
                // hain
                n--;
            }
            // i ko 1 se kam karke nums1 ke agle index pe point karte hain
            i--;
        }

        // Agar nums2 ke elements bach gaye hain
        while (n >= 0) {
            // Toh unko nums1 me daalte hain
            nums1[i] = nums2[n];
            // n aur i ko 1 se kam karte hain
            n--;
            i--;
        }
        // Agar nums1 ke elements bach gaye hain, toh unko wahi rehne dete
        // hain Kyunki nums1 already sorted hai
    }
};
