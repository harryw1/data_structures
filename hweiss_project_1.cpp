#include <iostream>
using namespace std;

void grow_array(int array[], int &array_count);
void shrink_array(int array[], int &array_count, int user_number_remove);
double report_size(int array[], int &array_count);
void exit_program();

int main()
{
    
    MyClass a;

}

void grow_array(int array[], int &array_count)
{            
    
    if(report_size > 65 && array.size() > 3)
    {
        int new_array_size = 0;
        new_array_size = (array_count * 100 / 62);
        int temp_array* = new int[new_array_size];
        for(int i = 0; i < array_count; i++)
        {
            temp_array[i] = array[i];
        }
        delete [] array;
        array = temp_array;
        temp_array = NULL;
    }

}

void shrink_array(int array[], int &array_count, int user_number_remove)
{            
    
    if(report_size < 60 && array.size() > 3)
    {
        int new_array_size = 0;
        new_array_size = (array_count * 100 / 62);
        int temp_array* = new int[new_array_size];
        int temp_array_count = 0;
        for(int i = 0; i < array_count && array[i] != user_number_remove; i++)
        {
            temp_array[i] = array[i];
            temp_array_count++;
        }
        for(int i = temp_array_count + 1; i < array_count; i++)
        {
            temp_array[i] = array[i];
        }
        delete [] array;
        array = temp_array;
        temp_array = NULL;
    }

}

double report_size(int array[], int &array_count)
{

    size_t tmp_array_size = 0;
    for(int i = 0; i < array.size(); i++)
    {
        tmp_array_size++;
    }
    size_t tmp_array_count = array_count;
    double percent_full;
    percent_full = (100 * tmp_array_count / tmp_array_size);

    return percent_full;

}

void exit_program()
{

    cout << endl;
    cout << "Program ended." << endl;
    cout << endl;

}
