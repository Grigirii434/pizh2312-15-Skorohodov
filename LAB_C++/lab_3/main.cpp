#include <iostream>
#include <string>
using namespace std;

// ������� ����� �����
class Book {
protected:
    string title;
    string author;
    string genre;
public:
    // ������������
    Book() : title(""), author(""), genre("") {
        cout << "����������� Book()" << endl;
    }

    Book(string t, string a, string g) : title(t), author(a), genre(g) {
        cout << "����������� Book(string, string, string)" << endl;
    }

    // ����������
    ~Book() {
        cout << "���������� ~Book()" << endl;
    }

    // ����� ������
    void display() {
        cout << title << " | " << author << " | " << genre;
    }
};

// ����� ��� ��������� ����
class MainHallBook : public Book {
private:
    int shelf;
public:
    MainHallBook(string t, string a, string g, int s) : Book(t, a, g), shelf(s) {
        cout << "����������� MainHallBook()" << endl;
    }

    ~MainHallBook() {
        cout << "���������� ~MainHallBook()" << endl;
    }

    void display() {
        Book::display();
        cout << " | �����: " << shelf << endl;
    }
};

// ����� ��� ���������� ����
class ReadingRoomBook : public Book {
private:
    string section;
public:
    ReadingRoomBook(string t, string a, string g, string s) : Book(t, a, g), section(s) {
        cout << "����������� ReadingRoomBook()" << endl;
    }

    ~ReadingRoomBook() {
        cout << "���������� ~ReadingRoomBook()" << endl;
    }

    void display() {
        Book::display();
        cout << " | ������: " << section << endl;
    }
};

int main() {
    setlocale(LC_ALL, "RU");
    // 1. ������� �������
    Book b1("����� � ���", "�������", "�����");
    MainHallBook m1("1984", "������", "����������", 5);
    ReadingRoomBook r1("������ � ���������", "��������", "�����", "��������");

    // 2. ������� ��
    b1.display();
    m1.display();
    r1.display();

    // 3. ������ �������� ����
    Book* arr1[3] = {
        new Book("�����1", "�����1", "����1"),
        new MainHallBook("�����2", "�����2", "����2", 3),
        new ReadingRoomBook("�����3", "�����3", "����3", "������1")
    };

    // 4. ������� ������
    for (int i = 0; i < 3; i++) {
        arr1[i]->display();
        delete arr1[i];
    }

    // 5. ������ ����������
    MainHallBook arr2[2] = {
        MainHallBook("�����4", "�����4", "����4", 1),
        MainHallBook("�����5", "�����5", "����5", 2)
    };

    // 6. ������� ������
    for (int i = 0; i < 2; i++) {
        arr2[i].display();
    }

    return 0;
}