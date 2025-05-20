#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string genre;

public:
    // ������������
    Book() : title(""), author(""), genre("") {
        cout << "������ ����������� Book() ��� ����������" << endl;
    }

    Book(string t, string a) : title(t), author(a), genre("�� ������") {
        cout << "������ ����������� Book(string, string) � �����������" << endl;
    }

    Book(string t, string a, string g) : title(t), author(a), genre(g) {
        cout << "������ ����������� Book(string, string, string) � �����������" << endl;
    }

    Book(const Book& other) : title(other.title), author(other.author), genre(other.genre) {
        cout << "������ ����������� ����������� Book(const Book&)" << endl;
    }

    // ����������
    ~Book() {
        cout << "������ ���������� ~Book() ��� �����: " << title << endl;
    }

    // ������
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }

    void display() const {
        cout << "�����: " << title << " | �����: " << author << " | ����: " << genre << endl;
    }
};

class Library {
private:
    string name;
    string address;
    vector<Book> books;

public:
    // ������������
    Library() : name(""), address("") {
        cout << "������ ����������� Library() ��� ����������" << endl;
    }

    Library(string n, string a) : name(n), address(a) {
        cout << "������ ����������� Library(string, string) � �����������" << endl;
    }

    Library(const Library& other) : name(other.name), address(other.address), books(other.books) {
        cout << "������ ����������� ����������� Library(const Library&)" << endl;
    }

    // ����������
    ~Library() {
        cout << "������ ���������� ~Library() ��� ����������: " << name << endl;
    }

    // ������
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // ����� ��� ������ 5
    void addNewBook(string title, string author, string genre) {
        Book newBook(title, author, genre);
        books.push_back(newBook);
    }

    // ����� ��� ������ 6
    void addCopies(const Book& original, int count) {
        for (int i = 0; i < count; i++) {
            books.push_back(Book(original));
        }
    }

    void display() const {
        cout << "����������: " << name << endl;
        cout << "�����: " << address << endl;
        cout << "����� � ���������� (" << books.size() << "):" << endl;

        for (const auto& book : books) {
            book.display();
        }
    }
};

int main() {
    cout << "=== ������������ ������ ������������� � ������������ ===" << endl;

    // 1. �������� ����������
    cout << "\n�������� ����������� ����������:" << endl;
    Library centralLib("����������� ��������� ����������", "��. ������, 10");

    // 2. �������� ���� ������� ��������������
    cout << "\n�������� ����:" << endl;
    Book book1; // ����������� ��� ����������
    Book book2("1984", "��. ������"); // ����������� � 2 �����������
    Book book3("������ � ���������", "�. ��������", "����������"); // ����������� � 3 �����������
    Book book4(book3); // ����������� �����������

    // 3. ���������� ���� � ����������
    cout << "\n���������� ����:" << endl;
    centralLib.addBook(book1);
    centralLib.addBook(book2);
    centralLib.addBook(book3);

    // 4. ������������� ������ ������ (����� 5)
    cout << "\n���������� ����� ����� ����� addNewBook:" << endl;
    centralLib.addNewBook("������������ � ���������", "�. �����������", "�����");

    // 5. ������������� ������ ��� ����� (����� 6)
    cout << "\n���������� ����� �����:" << endl;
    centralLib.addCopies(book2, 2);

    // 6. �������� ��������� ����������
    cout << "\n�������� ��������� ����������:" << endl;
    {
        Library tempLib;
        tempLib.addNewBook("����� � ���", "�. �������", "�����");
        tempLib.display();
    } // ����� ��������� ���������� tempLib

    // 7. ����� ���������� � ����������
    cout << "\n�������� ��������� ����������� ����������:" << endl;
    centralLib.display();

    cout << "\n=== ���������� ��������� ===" << endl;
    return 0;
}