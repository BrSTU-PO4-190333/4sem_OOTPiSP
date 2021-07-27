#include <iostream>
#include <memory>

//функция варианта 5 задания 2
void option5_task2();
//функция сгенерирует элементы для int массива
void generate_elements_in_2d_array(
    const std::unique_ptr<std::unique_ptr<int[]>[]> &arr,
    const int rows,
    const int cols,
    int a = 1,
    int b = 99
);
//функция напечатает функцию
template <typename T>
void print_2d_array(
    const std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    const int rows,
    const int cols
);
//функция вставит строку в функцию
template <typename T>
void add_line_to_2d_array(
    std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    int *rows,
    const int cols
);

int main()
{
    srand(100); //Seed рандома. Программа всегда будет давать один и тот же результат при рандоме
    option5_task2();

    return 0;
}

void option5_task2()
{
    int rows = 5;                               //количество строк
    int cols = 12;                              //количество столбцов
    std::unique_ptr<
        std::unique_ptr<int[]>[]
    > arr( std::make_unique<std::unique_ptr<int[]>[]>(rows) );  //выделение памяти под 2d массив
    for (int i = 0; i < rows; i++)              //заполняем одномерный массив массивом
    {
        arr[i] = std::make_unique<int[]>(cols); //в ячейке массива массив
    }

    generate_elements_in_2d_array(arr, rows, cols);             //заполняем массив
    print_2d_array(arr, rows, cols);            //печатаем 2d массив

    add_line_to_2d_array(arr, &rows, cols);     //добавляем строку в массив
    print_2d_array(arr, rows, cols);            //печатаем 2d массив
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
void add_line_to_2d_array(
    std::unique_ptr<std::unique_ptr<T[]>[]> &arr,
    int *rows,
    const int cols
)
{
    *rows += 1;                                 //увеличиваем количество строк
    std::unique_ptr<
        std::unique_ptr<T[]>[]
    > temp(std::make_unique<std::unique_ptr<T[]>[]>(*rows));    //память под 2d массив
    for (int i = 0; i < *rows; i++)             //заполняем массив массивами
    {
        temp[i] = std::make_unique<T[]>(cols);  //в ячейке массива массив
    }
    
    for (int i = 1; i < *rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp[i][j] = arr[i - 1][j];         //переносим элементы из массива в новый массив
        }
    }

    arr = move(temp);                           //передаём права
}