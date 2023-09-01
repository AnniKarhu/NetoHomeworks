// homework-4-2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

struct Address_struct
{
    std::string city;
    std::string street;
    int building;
    int flat_num;
};

class Addresses
{
private:
    int declared_addresses_num = 0;     //заявленное в первой строке файла количество адресов, доступных для чтения
    int real_addresses_num = 0;         //фактическое число  прочитанных из файла адресов

    std::string in_file_name_str;       //имя входного файла
    std::string out_file_name_str;      //имя выходного файла

    Address_struct* addresses_array = nullptr;  //указатель на массив адресов
    std::string* addresses_str_array = nullptr; //указатель на массив адресов в виде строк

    bool read_addresses_num(std::ifstream& fin)     //считать из файла количество адресов
    {
        //если файл пустой
        if (fin.eof())
        {
            std::cout << "Файл " << in_file_name_str << " пустой. \n";
            fin.close();
            return false;
        }

        //считать первую строку 
        std::string s = "";
        fin >> s;

        declared_addresses_num = std::stoi(s); //to-do - добавить обработку исключения

        if (declared_addresses_num <= 0) //количество адресов должно быть больше 0
        {
            std::cout << "Неверное количество адресов в первой строке в файле " << in_file_name_str << "\n";
            return false;
        }

        return true;
    }

    void read_addresses_from_file(std::ifstream& fin) //считать addr_count адресов из файла fin
    {
        std::string s;

        //выделить память под массив адресов
        addresses_array = new Address_struct[declared_addresses_num];

        for (int i = 0; i < declared_addresses_num; ++i)
        {
            //считать город
            if (fin.eof())
                break;
            fin >> addresses_array[i].city;

            //считать улицу
            if (fin.eof())
                break;
            fin >> addresses_array[i].street;

            //считать номер дома
            if (fin.eof())
                break;
            fin >> s;
            addresses_array[i].building = std::stoi(s); //to-do - добавить обработку исключения

            //считать номер квартиры
            if (fin.eof())
                break;
            fin >> s;
            addresses_array[i].flat_num = std::stoi(s); //to-do - добавить обработку исключения

            ++real_addresses_num;         //увеличить счетчик фактических прочитанных из файла адресов
        }
    }

    void fill_in_addresses_str_array()
    {
        //выделить память под массив адресов
        addresses_str_array = new std::string[real_addresses_num];
        
        for (int i = 0; i < real_addresses_num; ++i)
        {
            addresses_str_array[i] = addresses_array[i].city + ", " + addresses_array[i].street + ", ";
            addresses_str_array[i] += std::to_string(addresses_array[i].building) + ", ";
            addresses_str_array[i] += std::to_string(addresses_array[i].flat_num) + "\n";
        }
    }

    int partition_str(std::string a[], int start, int end) //разделение массива при сортировке
    {
        // выбрать крайний правый элемент в качестве опорного элемента массива
        std::string pivot = a[end];

        // элементы, меньшие точки пивота, будут перемещены влево от `pIndex`
        // элементы больше, чем пивот, будут сдвинуты вправо от `pIndex`
        // равные элементы могут идти в любом направлении
        int pIndex = start;

        // каждый раз, когда мы находим элемент, меньший или равный опорному, `pIndex`
        // увеличивается, и этот элемент будет помещен перед опорной точкой.
        for (int i = start; i < end; i++)
        {
            // int compare_res = a[i].city.compare(pivot.city);

            if (a[i].compare(pivot) < 0)
            {
                swap(a[i], a[pIndex]);
                pIndex++;
            }
        }

        // поменять местами `pIndex` с пивотом
        swap(a[pIndex], a[end]);

        // вернуть `pIndex` (индекс опорного элемента)
        return pIndex;
    }


    void swap(std::string& str_a, std::string& str_b) //поменять местами строки
    {
        std::string temp_str = str_a;
        str_a = str_b;
        str_b = temp_str;
    }

    void quicksort_str(std::string a[], int start, int end) // сортировка строк
    {
        // базовое условие
        if (start >= end) {
            return;
        }

        // переставить элементы по оси
        int pivot = partition_str(a, start, end);

        // повторяем подмассив, содержащий элементы, меньшие опорной точки
        quicksort_str(a, start, pivot - 1);

        // повторяем подмассив, содержащий элементы, превышающие точку опоры
        quicksort_str(a, pivot + 1, end);
    }


    void sort_alphabetically()
    {
        //не сортировать пустой массив
        if ((real_addresses_num <= 0) ||
           (addresses_str_array == nullptr))
            return;

        quicksort_str(addresses_str_array, 0, real_addresses_num - 1);

    }

    void write_addresses_to_file(std::ofstream& fout) //записать адреса в файл
    {
        if (real_addresses_num > 0)
            fout << real_addresses_num << "\n";

        for (int i = 0; i < real_addresses_num; ++i)
        {
            fout << addresses_str_array[i]; 
        }

    }

    bool set_new_in_file() //применить новый файл для считывания адресов 
    {
        finish(); //перед открытием нового файла удалить старые данные

        std::ifstream fin(in_file_name_str); // открыть файл для чтения

        if (!fin.is_open())
        {
            std::cout << "Невозможно открыть файл " << in_file_name_str << "\n";
            return false;
        }


        if (!read_addresses_num(fin))     //считать из файла количество адресов
        {
            fin.close();
            return false;
        }

        read_addresses_from_file(fin); //считать declared_addresses_num адресов из файла
        fin.close();

        fill_in_addresses_str_array(); //преобразовать адреса из структур в строки и заполнить массив addresses_str_array
        sort_alphabetically(); //сортировать адреса по алфавиту
    }

    void set_new_out_file() //применить новый файл для записи адресов 
    {
        if (addresses_array == nullptr)
        {
            std::cout << "Нет данных для записи в файл " << out_file_name_str << "\n";
            return;
        }

        std::ofstream fout(out_file_name_str);    //открыть файл для записи

        if (!fout.is_open())
        {
            std::cout << "Невозможно открыть или создать файл " << out_file_name_str << "\n";
            return;
        }

        write_addresses_to_file(fout);
        fout.close();
    }

public:

    Addresses()
    {
        in_file_name_str = "in.txt";       //имя входного файла
        out_file_name_str = "out.txt";      //имя выходного файла

        if (set_new_in_file()) //задать новый файл для считывания адресов
            set_new_out_file();   //задать новый файл для записи адресов
    }

    Addresses(std::string in_file_name, std::string out_file_name)
    {
        in_file_name_str = in_file_name;       //имя входного файла
        out_file_name_str = out_file_name;      //имя выходного файла

        if (set_new_in_file()) //задать новый файл для считывания адресов
            set_new_out_file();   //задать новый файл для записи адресов
    }


    void finish() {

        //освободить память массивов адресов
        if (addresses_array != nullptr)  //указатель на массив адресов
            delete[] addresses_array;
        addresses_array = nullptr;

        if (addresses_str_array != nullptr) //указатель на массив адресов в виде строк
            delete[] addresses_str_array;
        addresses_str_array = nullptr;

        declared_addresses_num = 0;     //заявленное в первой строке файла количество адресов, доступных для чтения
        real_addresses_num = 0;         //фактическое число  прочитанных из файла адресов
    }


    int get_addresses_q_ty() //сколько адресов в файле
    {
        return real_addresses_num;
    }

    bool set_new_in_file(std::string in_file_name) //задать новый файл для считывания адресов
    {
        in_file_name_str = in_file_name;       //имя входного файла
        if (set_new_in_file()) //задать новый файл для считывания адресов
        {
            return true;
        }
        else
            return false;
    }

    void set_new_out_file(std::string out_file_name) //задать новый файл для записи адресов
    {
        out_file_name_str = out_file_name;       //имя выходного файла
        set_new_out_file();
    }

};



int main()
{
    setlocale(LC_ALL, "rus");    

    Addresses Addresses_1;
    std::cout << "Считано и записано " << Addresses_1.get_addresses_q_ty() << " адресов \n";

    std::string in_file_name = "in_2.txt";
    std::string out_file_name = "out_2.txt";

    Addresses Addresses_2(in_file_name, out_file_name);

    std::cout << "Считано и записано " << Addresses_2.get_addresses_q_ty() << " адресов в файлах " << in_file_name << " и " << out_file_name << "\n";

    in_file_name = "in_3.txt";
    out_file_name = "out_3.txt";

    Addresses_2.set_new_in_file(in_file_name);
    Addresses_2.set_new_out_file(out_file_name);

    std::cout << "Считано и записано " << Addresses_2.get_addresses_q_ty() << " адресов в файлах " << in_file_name << " и " << out_file_name << "\n";
    Addresses_2.finish();

    return 0;

}

