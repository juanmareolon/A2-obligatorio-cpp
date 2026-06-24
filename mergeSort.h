template <typename T, typename Comparador>
void merge(T arr[], int inicio, int medio, int fin, Comparador comp)
{
    int tamano = fin - inicio + 1;
    T* aux = new T[tamano];

    int i = inicio;
    int j = medio + 1;
    int k = 0;

    while (i <= medio && j <= fin)
    {
        if (comp(arr[i], arr[j]))
        {
            aux[k++] = arr[i++];
        }
        else
        {
            aux[k++] = arr[j++];
        }
    }

    while (i <= medio)
        aux[k++] = arr[i++];

    while (j <= fin)
        aux[k++] = arr[j++];

    for (int x = 0; x < tamano; x++)
        arr[inicio + x] = aux[x];

    delete[] aux;
}

template <typename T, typename Comparador>
void mergeSort(T arr[], int inicio, int fin, Comparador comp)
{
    if (inicio >= fin)
        return;

    int medio = (inicio + fin) / 2;

    mergeSort(arr, inicio, medio, comp);
    mergeSort(arr, medio + 1, fin, comp);
    merge(arr, inicio, medio, fin, comp);
}