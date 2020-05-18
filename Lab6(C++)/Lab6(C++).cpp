#include <iostream>
#include <string>
#include <fstream> 

using namespace std;

struct Goods
{
    string name;
    short year;
    int amount;
    string manufacturer;
    int price;
};

void taskEase18()
{
    cout << "Task 18 (ease)" << endl;
    /*Создать бинарный файл с информацией о продовольственых товарах,
    храняшихся на складе: 
        - наименование товара;
        - год поступления на склад;
        - количество;
        - протзводитель;
        - цена.*/
    
    int x, nowYear;
    cout << "\nВведите количесво товаров: ";
    while (!(cin >> x))
    {
        cout << "\nВведите количесво товаров: ";
        cin >> x;
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
    }

    Goods* goods = new Goods[x];

    cout << "Введите год: ";
    while (!(cin >> nowYear))
    {
        cout << "Введите год: ";
        cin >> nowYear;
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
    }

    for (int i = 0; i < x; i++)
    {
        cout << "------------------" << endl;

        cout << "Введите наименование товара: ";
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
        getline(cin, goods[i].name);

        do
        {
            cout << "Введите год поступление на склад: ";
            cin.clear();
            cin.ignore(std::cin.rdbuf()->in_avail());
            cin >> goods[i].year;
        } while (goods[i].year < 1);

        cout << "Введите количество товара: ";
        while (!(cin >> goods[i].amount))
        {
            cout << "Введите количество товара: ";
            cin >> goods[i].amount;
            cin.clear();
            cin.ignore(std::cin.rdbuf()->in_avail());
        }

        cout << "Введите производителя товара: ";
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
        getline(cin, goods[i].manufacturer);

        cout << "Введите цену товара: ";
        while (!(cin >> goods[i].price))
        {
            cout << "Введите цену товара: ";
            cin >> goods[i].price;
            cin.clear();
            cin.ignore(std::cin.rdbuf()->in_avail());
        }
    }

    //Открываем файл для записи в бинарном режиме
    ofstream out("taskEase18.dat", ios::binary | ios::out);
        out.write((char*)&goods, sizeof goods); //Записываем объект goods в открытый нами файл
    out.close();//Закрываем открытый файл

    Goods* goods2 = new Goods[x];

    // Открываем файл только для чтения, открываем в бинарном режиме
    fstream in("taskEase18.dat", ios::binary | ios::in);
        in.read((char*)&goods2, sizeof goods2); //Считываем информацию в объект goods2
    in.close(); //Закрываем открытый файл

    int writeOff = 0;
    for (int i = 0; i < x; i++)
    {
        if (nowYear - goods2[i].year > 5)
        {
            writeOff += goods2[i].price * goods2[i].amount;
        }
    }

    cout << "\nСумма потерь: " << writeOff << endl;
}

void taskMedium18()
{
    cout << "\nTask 18 (medium)\n" << endl;
    /*Ввести в Memo или в StringGrid некоторое количесто как положительных так и отрицательных
    целых чисел и записать в бинарный файл. Переписать бинарный фацй так чтобы каждое отвецательное
    значение было увеличено на 3, а положительное - уменьшено на 3. Распечатать числа до и после изменения.*/

    const int N = 2, M = 3;
    int arr[N][M], arr2[N][M];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            cout << "Введите [" << i + 1 << "][" << j + 1 << "]: ";
            while (!(cin >> arr[i][j]))
            {
                cout << "Введите [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> arr[i][j];
                cin.clear();
                cin.ignore(std::cin.rdbuf()->in_avail());
            }
        }

    //Открываем файл для записи в бинарном режиме
    ofstream out("taskMedium18.dat", ios::binary | ios::out);
        out.write((char*)&arr, sizeof arr); //Записываем объект goods в открытый нами файл
    out.close();//Закрываем открытый файл

    // Открываем файл только для чтения, открываем в бинарном режиме
    fstream in("taskMedium18.dat", ios::binary | ios::in);
        in.read((char*)&arr2, sizeof arr2); //Считываем информацию в объект goods2
    in.close(); //Закрываем открытый файл

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
        {
            if (arr[i][j] > 0)
                arr2[i][j] -= 3;
            if (arr[i][j] < 0)
                arr2[i][j] += 3;
        }

    //Открываем файл для записи в бинарном режиме
    ofstream out2("taskMedium18.dat", ios::binary | ios::out);
        out2.write((char*)&arr2, sizeof arr); //Записываем объект goods в открытый нами файл
    out2.close();//Закрываем открытый файл

    cout << "До изменений:" << endl;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    cout << "\nПосле измеенения:" << endl;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            cout << arr2[i][j] << " ";
        cout << endl;
    }     
}

struct Worker
{
    char surname[56];
    char name[2];
    char thirdname[2];
    short yearBirth;
    string study;
    short yearEntry;
    string position;
    int salary;
};

void taskHard18()
{
    cout << "\nTask 18 (hard)" << endl;
    /*Создать бинарный фаил комонентами которого является структура,
    содержашия следующие поля:
        - фамилия и инициалы работника предприятия;
        - год рождения;
        - оброзование;
        - год поступления на работу;
        - должность;
        - заработная плата;
    Переписать бинарный файл так, чтобы увеличить размер заработной платы
    на 10% если сотрудник проработал на предприятие более 10 лет.*/

    int x,nowYear;
    cout << "\nВведите количесво работников: ";
    while (!(cin >> x))
    {
        cout << "\nВведите количесво работников: ";
        cin >> x;
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
    }

    cout << "Введите год: ";
    while (!(cin >> nowYear))
    {
        cout << "Введите год: ";
        cin >> nowYear;
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
    }

    Worker* workers = new Worker[x];

    for (int i = 0; i < x; i++)
    {
        cout << "------------------" << endl;

        cout << "Введите фамилию и инициалы: ";
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
        cin >> workers[i].surname >> workers[i].name >> workers[i].thirdname;
 
        cout << "Введите год рождения: ";
        while (!(cin >> workers[i].yearBirth))
        {
            cout << "Введите год рождения: ";
            cin >> workers[i].yearBirth;
            cin.clear();
            cin.ignore(std::cin.rdbuf()->in_avail());
        }

        cout << "Введите образование: ";
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
        getline(cin, workers[i].study);

        cout << "Введите год поступления на работу: ";
        while (!(cin >> workers[i].yearEntry))
        {
            cout << "Введите год поступления на работу: ";
            cin >> workers[i].yearEntry;
            cin.clear();
            cin.ignore(std::cin.rdbuf()->in_avail());
        }

        cout << "Введите должность: ";
        cin.clear();
        cin.ignore(std::cin.rdbuf()->in_avail());
        getline(cin, workers[i].position);

        cout << "Введите зарплату: ";
        while (!(cin >> workers[i].salary))
        {
            cout << "Введите зарплату: ";
            cin >> workers[i].salary;
            cin.clear();
            cin.ignore(std::cin.rdbuf()->in_avail());
        }
    }

    //Открываем файл для записи в бинарном режиме
    ofstream out("taskHard18.dat", ios::binary | ios::out);
    out.write((char*)&workers, sizeof workers); //Записываем объект goods в открытый нами файл
    out.close();//Закрываем открытый файл

    Worker* workers2 = new Worker[x];

    // Открываем файл только для чтения, открываем в бинарном режиме
    fstream in("taskHard18.dat", ios::binary | ios::in);
    in.read((char*)&workers2, sizeof workers2); //Считываем информацию в объект goods2
    in.close(); //Закрываем открытый файл

    for (int i = 0; i < x; i++)
    {
        if (nowYear - workers2[i].yearEntry > 10)
            workers2[i].salary += workers2[i].salary / 100 * 10;
        cout << workers2[i].salary << " ";
    }

    //Открываем файл для записи в бинарном режиме
    ofstream out2("taskHard18.dat", ios::binary | ios::out);
        out2.write((char*)&workers2, sizeof workers2); //Записываем объект goods в открытый нами файл
    out2.close();//Закрываем открытый файл
}

int main()
{
    setlocale(0, "ru");

    taskEase18();
    taskMedium18();
    taskHard18();
}