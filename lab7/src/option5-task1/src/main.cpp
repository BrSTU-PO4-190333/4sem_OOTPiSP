#include <iostream>
#include <memory>

//функция варианта 5 задания 1
void option5_task1();
//функция напечатает массив
template <typename T>
void print_1d_array(T* arr, int size);
//функция сгенерирует массив из int элементов в промежутке от a до b
void generate_int_elements_in_1d_array(int* arr, int size, int a = 1, int b = 99);
//функция, которая удалит элемент из массива
template <typename T>
std::shared_ptr<T []> del_index_in_1d_array(
    std::shared_ptr<T []> arr,
    int *size,
    int deleted_index
);

int main()
{
    srand(100); //Seed рандома. Программа всегда будет давать один и тот же результат при рандоме
    option5_task1();

    return 0;
}

void option5_task1()
{
    int size = 7;                                       //размер массива
    std::shared_ptr<int[]> arr(new int[size]);          //выделяем память под массив

    generate_int_elements_in_1d_array(arr.get(), size); //генерируем числа в массив
    print_1d_array(arr.get(), size);                    //печатаем массив

    arr = move(                                         //передаём владение
        del_index_in_1d_array(move(arr), &size, 3)      //возвратит умный указатель
    );
    print_1d_array(arr.get(), size);                    //печатаем массив
}

template <typename T>
void print_1d_array(T* arr, int size)
{
    std::cout << "[" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << "\t" << i << ": \"" << arr[i] << "\",\n";
    }
    std::cout << "]" << std::endl;
}

void generate_int_elements_in_1d_array(int* arr, int size, int a, int b)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % (b - a + 1) + a;
    }
}

template <typename T>
std::shared_ptr<T []> del_index_in_1d_array(
    std::shared_ptr<T []> arr,
    int *size,
    int deleted_index
)
{
    if (deleted_index <= 0 || deleted_index >= *size)   //if index in (-00; 0] u [size; ++00]
    {
        std::cout << deleted_index << " not in (0; " << *size << ")\n";
        return arr;
    }

    *size -= 1;                                         //уменьшаем размер массива
    for (int i = deleted_index; i < *size; i++)         //от удаляемого элемента до конца
    {
        arr[i] = arr[i + 1];                            //смещаем элементы
    }

    std::shared_ptr<T[]> temp_arr(new T[*size]);        //выделяем память под новый массив
    for (int i = 0; i < *size; i++)
    {
        temp_arr[i] = arr[i];                           //копируем элементы
    }

    arr = move(temp_arr);                               //передаём права
    return arr;
}