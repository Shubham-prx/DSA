#include <bits/stdc++.h>
using namespace std;



void merge(int arr[], int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high) {
        if(arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
            temp.push_back(arr[left]);
            left++;
        }
    while(right <= high){
            temp.push_back(arr[right]);
            right++;
        }

    for(int i = low; i<=high; i++){
            arr[i] = temp[i-low];
        }

}

void mergeSort(int arr[], int low, int high) {
    int mid = low + (high - low)/2;                         //NOTE
    if(low < high){
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {3,4,2,3,6,75,3};
    mergeSort(arr, 0, 6);
    for(auto it: arr){
        cout<< it <<" ";
    }
}




{
// (low + high) / 2 risks overflow when low + high > 2,147,483,647 (in 32-bit int).

// low + (high - low)/2 is always safe because it never sums two large numbers directly.


// That’s an amazing question 🚀 — and honestly, this is the real difference between just *writing code* and *thinking like a computer scientist*.
// Let me break down how you can **discover or derive such formulas yourself** instead of memorizing them.

// ---

// ## 🔑 Step 1: Ask "What’s the intent?"

// When you see a formula like:

// ```cpp
// mid = (low + high) / 2;
// ```

// Stop and think:

// 👉 **What am I really trying to compute?**
// Answer: I want the midpoint between two numbers.

// So the core idea is:
// [
// mid = low + \frac{(high - low)}{2}
// ]

// This is just algebra:
// [
// \frac{low + high}{2} = low + \frac{(high - low)}{2}
// ]

// So both are *mathematically identical*.

// ---

// ## 🔑 Step 2: Ask "Where can it break?"

// Computer science = math + machine limitations.
// Now think:

// * Computers have **finite ranges** for integers (`int`, `long long`, etc.).
// * Adding two large numbers (like `low + high`) risks overflow.
// * Subtracting (`high - low`) is safer, because it’s always within the index range.

// So the safe formula comes from considering **machine constraints**.

// ---

// ## 🔑 Step 3: Generalize the Thinking

// Whenever you face a formula in coding, ask:

// 1. **What am I calculating mathematically?**
//    (derive the clean math expression first)
// 2. **What edge cases exist due to computer limitations?**

//    * Overflow?
//    * Division rounding?
//    * Precision loss in floating point?
// 3. **Can I restructure the math to avoid the risk?**
//    (like replacing `low + high` with `low + (high - low)`)

// ---

// ## 🔑 Step 4: Build the Habit

// You’ll start noticing patterns:

// * `(a+b)/2` → think about overflow → rewrite as `a + (b-a)/2`.
// * `(x*y)/z` → check if `x*y` overflows → maybe rearrange as `(x/z)*y`.
// * `pow(x, n)` for large `n` → maybe use fast exponentiation (`divide and conquer`).

// This is **mathematical restructuring for safe computation**.

// ---

// ## 🧠 How to train this skill?

// * **Dry run with extreme inputs** (like very large values).
// * **Play with limits** (`INT_MAX`, `LONG_MAX`).
// * Ask: *what happens if I push it to the edge?*
// * Always check: *can I rearrange algebra to avoid big intermediate values?*

// ---

// ✅ So the formula `(low + (high - low)/2)` is not some magic — it’s just algebra + awareness of integer overflow.

}

