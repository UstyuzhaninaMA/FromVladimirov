void sort(int arr[], int size)
{
    int v1;
    int v2;
    int v3_itr = 2;
    int v4;

    if (size < 2)
    {
        return;
    }

    for (v3_itr = 1; v3_itr < n; v3_itr++)
    {
        key = arr[i];
        v2 = v3_itr - 1;
        while (v2 >= 0 && arr[v2] > key)
        {
            arr[v2 + 1] = arr[v2];
            v2 = v2 - 1;
        }
        arr[v2 + 1] = key;
    }
}