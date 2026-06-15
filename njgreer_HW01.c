#include <stdio.h>
#include <math.h>
#include <string.h>

/* FUNCTION 1: sumOfDigits
   - Takes a positive integer n
   - Returns the sum of its digits
   - Returns -1 if n <= 0 */

int sumOfDigits(int n) {
    /* If n is 0 or negative, return -1 */
    if (n <= 0) {
        return -1;
    }

    int sum = 0;

    /* Keep pulling off the last digit until n becomes 0 */
    while (n > 0) {
        sum = sum + (n % 10);  /* % 10 gives the last digit */
        n = n / 10;            /* Remove the last digit */
    }

    return sum;
}

/* FUNCTION 2: UABMaxMinDiff
   - Takes an array of integers
   - Returns the difference between max and min */

int UABMaxMinDiff(int arr[], int size) {
    int max = arr[0];  /* Start by assuming first element is max */
    int min = arr[0];  /* Start by assuming first element is min */

    /* Loop through each element and update max/min */
    int i;
    for (i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return max - min;
}

/* FUNCTION 3: replaceEvenWithZero
   - Takes an array of integers
   - Replaces every even number with 0
   - Returns the modified array (modifies in place) */

void replaceEvenWithZero(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {   /* % 2 == 0 means the number is even */
            arr[i] = 0;
        }
    }
}

/* FUNCTION 4: perfectSquare
   - Takes an integer n
   - Returns 1 (True) if n is a perfect square
   - Returns 0 (False) otherwise */

int perfectSquare(int n) {
    /* Negative numbers cannot be perfect squares */
    if (n < 0) {
        return 0;
    }

    /* sqrt() gives the square root / cuts off the decimal */
    int root = (int)sqrt(n);

    /* If root * root equals n, it's a perfect square */
    if (root * root == n) {
        return 1;  /* True */
    } else {
        return 0;  /* False */
    }
}

/* FUNCTION 5: countVowels
   - Takes a string s
   - Returns the count of vowels (a, e, i, o, u)
   - Ignores uppercase vs lowercase */

int countVowels(char s[]) {
    int count = 0;
    int i;
    int len = strlen(s);  /* strlen gets the length of the string */

    for (i = 0; i < len; i++) {
        char c = s[i];

        /* Check if the character is a vowel (upper or lowercase) */
        if (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U') {
            count++;
        }
    }

    return count;
}

/* MAIN FUNCTION
   - Calls all five functions with sample inputs */
   
int main() {

    /* --- Testing sumOfDigits --- */
    printf("=== sumOfDigits ===\n");
    printf("n=123  -> %d\n", sumOfDigits(123));   /* Expected: 6  */
    printf("n=405  -> %d\n", sumOfDigits(405));   /* Expected: 9  */
    printf("n=0    -> %d\n", sumOfDigits(0));     /* Expected: -1 */
    printf("n=7    -> %d\n", sumOfDigits(7));     /* Expected: 7  */
    printf("n=-308 -> %d\n", sumOfDigits(-308));  /* Expected: -1 */

    /* --- Testing UABMaxMinDiff --- */
    printf("\n=== UABMaxMinDiff ===\n");
    int arr1[] = {3, 7, 2, 9};
    printf("arr=[3,7,2,9]      -> %d\n", UABMaxMinDiff(arr1, 4));  /* Expected: 7 */

    int arr2[] = {5, 5, 5, 5, 5, 5};
    printf("arr=[5,5,5,5,5,5]  -> %d\n", UABMaxMinDiff(arr2, 6));  /* Expected: 0 */

    int arr3[] = {-2, 4, -1, 6, 5};
    printf("arr=[-2,4,-1,6,5]  -> %d\n", UABMaxMinDiff(arr3, 5)); /* Expected: 8 */

    /* --- Testing replaceEvenWithZero --- */
    printf("\n=== replaceEvenWithZero ===\n");
    int arr4[] = {1, 2, 3, 4};
    replaceEvenWithZero(arr4, 4);
    printf("arr=[1,2,3,4]  -> [%d,%d,%d,%d]\n", arr4[0], arr4[1], arr4[2], arr4[3]); /* Expected: [1,0,3,0] */

    int arr5[] = {2, 4, 6};
    replaceEvenWithZero(arr5, 3);
    printf("arr=[2,4,6]    -> [%d,%d,%d]\n", arr5[0], arr5[1], arr5[2]); /* Expected: [0,0,0] */

    int arr6[] = {1, 3, 5};
    replaceEvenWithZero(arr6, 3);
    printf("arr=[1,3,5]    -> [%d,%d,%d]\n", arr6[0], arr6[1], arr6[2]); /* Expected: [1,3,5] */

    /* --- Testing perfectSquare --- */
    printf("\n=== perfectSquare ===\n");
    printf("n=16 -> %s\n", perfectSquare(16) ? "True" : "False");  /* Expected: True  */
    printf("n=15 -> %s\n", perfectSquare(15) ? "True" : "False");  /* Expected: False */
    printf("n=25 -> %s\n", perfectSquare(25) ? "True" : "False");  /* Expected: True  */
    printf("n=36 -> %s\n", perfectSquare(36) ? "True" : "False");  /* Expected: True  */

    /* --- Testing countVowels --- */
    printf("\n=== countVowels ===\n");
    printf("\"Hello World\" -> %d\n", countVowels("Hello World"));  /* Expected: 3 */
    printf("\"UAB CS\"      -> %d\n", countVowels("UAB CS"));       /* Expected: 2 */
    printf("\"Python\"      -> %d\n", countVowels("Python"));       /* Expected: 1 */
    printf("\"aeiou\"       -> %d\n", countVowels("aeiou"));        /* Expected: 5 */

    return 0;
}
