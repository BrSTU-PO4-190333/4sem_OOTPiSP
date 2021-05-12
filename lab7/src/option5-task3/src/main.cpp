#include <iostream>
#include <memory>

//функция варианта 5 задания 3
void option5_task3();
//функция сгенерирует элементы для int массива
void generate_elements_in_2d_array(
    const std::unique_ptr<std::unique_ptr<int[]>[]> &arr,
    const int rows,
    const int cols,
    int a = 1,
    int b = 10
);
//функция напечатает функцию
template <typename T>
void print_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int cols
);
//печатает седловые точки
template <typename T>
void printf_saddle_points(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int cols
);
//если value равен минимальному элементу по колонке, то функция возвращает true, иначе false
template <typename T>
bool is_min_in_col_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int col_number,
    const T value
);
//если value равен максимальному элементу по колонке, то функция возвращает true, иначе false
template <typename T>
bool is_max_in_col_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int col_number,
    const T value
);
//если value равен минимальному элементу по строке, то функция возвращает true, иначе false
template <typename T>
bool is_min_in_row_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int row_number,
    const int cols,
    const T value
);
//если value равен минимальному элементу по строке, то функция возвращает true, иначе false
template <typename T>
bool is_max_in_row_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int row_number,
    const int cols,
    const T value
);

int main()
{
    srand(1);   //Seed рандома. Программа всегда будет давать один и тот же результат при рандоме
    option5_task3();

    return 0;
}

void option5_task3()
{
    int rows = 3;                               //количество строк
    int cols = 7;                               //количество столбцов
    std::unique_ptr<
        std::unique_ptr<int[]>[]
    > arr( std::make_unique<std::unique_ptr<int[]>[]>(rows) );  //выделение памяти под 2d массив
    for (int i = 0; i < rows; i++)              //заполняем одномерный массив массивом
    {
        arr[i] = std::make_unique<int[]>(cols); //в ячейке массива массив
    }

    generate_elements_in_2d_array(arr, rows, cols);//заполняем массив
    print_2d_array(arr, rows, cols);            //печатаем 2d массив
    printf_saddle_points(arr, rows, cols);
}

void generate_elements_in_2d_array(
    const std::unique_ptr<std::unique_ptr<int[]>[]> &arr,
    const int rows,
    const int cols,
    int a,
    int b
)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = rand() % (b - a + 1) + a;//рандом от a до b
        }
    }
}

template <typename T>
void print_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int cols
)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << arr[i][j] << "\t";     //печатаем элементы через табуляцию
        }
        std::cout << std::endl;                 //новая строка массива
    }
    std::cout << std::endl; //чтобы матрицы не слиплись, вызвав функцию два раза
}

template <typename T>
void printf_saddle_points(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int cols
)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (
                is_min_in_col_2d_array(arr, rows, j, arr[i][j])
                &&
                is_max_in_row_2d_array(arr, i, cols, arr[i][j])
                ||
                is_max_in_col_2d_array(arr, rows, j, arr[i][j])
                &&
                is_min_in_row_2d_array(arr, i, cols, arr[i][j])
            )
            {
                std::cout << "arr[" << i << "][" << j << "] = " << arr[i][j] << std::endl;
            }
        }
    }
}

template <typename T>
bool is_min_in_col_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int col_number,
    const T value
)
{
    T min = arr[0][col_number];
    for (int i = 0; i < rows; i++)              //поиск минимального в колонке
    {
        if(arr[i][col_number] < min)
        {
            min = arr[i][col_number];
        }
    }
    return (value == min);
}

template <typename T>
bool is_max_in_col_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int col_number,
    const T value
)
{
    T max = arr[0][col_number];
    for (int i = 0; i < rows; i++)              //поиск максимального в колонке
    {
        if(arr[i][col_number] > max)
        {
            max = arr[i][col_number];
        }
    }
    return (value == max);
}

template <typename T>
bool is_min_in_row_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int row_number,
    const int cols,
    const T value
)
{
    T min = arr[row_number][0];
    for (int j = 0; j < cols; j++)              //поиск минимального в строке
    {
        if (arr[row_number][j] < min)
        {
            min = arr[row_number][j];
        }
    }
    return (value == min);
}

template <typename T>
bool is_max_in_row_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int row_number,
    const int cols,
    const T value
)
{
    T max = arr[row_number][0];
    for (int j = 0; j < cols; j++)              //поиск максимального в строке
    {
        if (arr[row_number][j] > max)
        {
            max = arr[row_number][j];
        }
    }
    return (value == max);
}