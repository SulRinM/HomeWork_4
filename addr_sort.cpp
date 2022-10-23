#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class addres
{
public:
    std::string city;
    std::string street;
    int house_num;
    int apart_num;
    std::string get_output_address();

private:
};

std::string addres::get_output_address()
{
    std::string data_addres = city + ", " + street + ", " +
                              std::to_string(house_num) + ", " + std::to_string(apart_num);
    return data_addres;
}

void sort(address* addresses, int size)
{
    // не совсем понятно как проводить сортировку учитывая, что города объявлены как string
    // нужно сортировать по первым буквам городов? 
}

int main()
{
    std::ifstream fin("in.txt");
    if (fin.is_open())
    {
        int size;
        fin >> size;
        addres *arr = new addres[size];

        for (int i = 0; i < size; i++)
        {
            fin >> arr[i].city;
            fin >> arr[i].street;
            fin >> arr[i].house_num;
            fin >> arr[i].apart_num;
        }
        fin.close();

        std::ofstream fout("out.txt");
        fout << size << std::endl;

      //  sort(arr, size);

        for (int k = 0; k < size; k++)
        {
            fout << arr[k].get_output_address() << std::endl;
        }
        fout.close();
        delete[] arr;
    }
    else
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
    }

    return 0;
}
