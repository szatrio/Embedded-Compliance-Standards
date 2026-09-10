#include <stdint.h>
#include <stdlib.h>

/**
 * Compliance Check: MISRA C:2012 Rule 21.9
 * Rule: The library functions bsearch and qsort of <stdlib.h> shall not be used.
 */

#define ARRAY_SIZE 5U

/* --- NON-COMPLIANT EXAMPLE --- */

static int compare_bad(const void *a, const void *b)
{
    const int32_t *arg1 = (const int32_t *)a;
    const int32_t *arg2 = (const int32_t *)b;

    return (*arg1 - *arg2);
}

void test_rule_21_9_bad(int32_t *arr, size_t count)
{
    /* Non-compliant: qsort and bsearch place unknown demands on stack space */
    /* qsort(arr, count, sizeof(int32_t), compare_bad); */
    
    /* int32_t key = 10; */
    /* (void)bsearch(&key, arr, count, sizeof(int32_t), compare_bad); */

    (void)arr;
    (void)count;
}


/* --- MISRA COMPLIANT EXAMPLE --- */

/* Compliant: Implement a simple, deterministic, non-recursive sorting algorithm 
   (e.g., Insertion Sort / Bubble Sort) with bounded stack usage */
static void insertion_sort_int32(int32_t *arr, uint32_t count)
{
    if ((arr != NULL) && (count > 1U))
    {
        uint32_t i;
        for (i = 1U; i < count; i++)
        {
            int32_t key = arr[i];
            int32_t j = (int32_t)i - 1;

            while ((j >= 0) && (arr[j] > key))
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}

/* Compliant: Implement a simple, iterative binary search without library calls */
static int32_t binary_search_int32(const int32_t *arr, uint32_t count, int32_t key)
{
    int32_t index = -1;

    if (arr != NULL)
    {
        uint32_t low = 0U;
        uint32_t high = count - 1U;

        while (low <= high)
        {
            uint32_t mid = low + ((high - low) / 2U);

            if (arr[mid] == key)
            {
                index = (int32_t)mid;
                break;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1U;
            }
            else
            {
                if (mid == 0U)
                {
                    break;
                }
                high = mid - 1U;
            }
        }
    }

    return index;
}

void test_rule_21_9_good(void)
{
    int32_t data[ARRAY_SIZE] = {50, 20, 10, 40, 30};

    /* Compliant: Deterministic sorting and searching without stdlib bsearch/qsort */
    insertion_sort_int32(data, ARRAY_SIZE);

    int32_t result_index = binary_search_int32(data, ARRAY_SIZE, 30);
    (void)result_index;
}