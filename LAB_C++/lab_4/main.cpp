#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

// ������� ����� - ����� (�������������� ����� �� ���. ������ �1)
class Book {
protected:
    string title;
    string author;
    string genre;

public:
    Book() : title("��� ��������"), author("����������"), genre("�� ������") {}
    Book(string t, string a, string g) : title(t), author(a), genre(g) {}
    virtual ~Book() {}

    // ����� ����������� ������� (���������� �.2)
    virtual void fullDisplay() const = 0;

    // ������ ��� ������� � ������
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getGenre() const { return genre; }
};

// �����-��������� - ����� ��������� ����
class MainHallBook : public Book {
private:
    int shelfNumber;
    bool canBorrow;

public:
    MainHallBook(string t, string a, string g, int sh, bool cb)
        : Book(t, a, g), shelfNumber(sh), canBorrow(cb) {}

    // ���������� ����������� ������� (���������� �.3)
    void fullDisplay() const override {
        cout << "=== ����� ��������� ���� ===" << endl;
        cout << "��������: " << title << endl;
        cout << "�����: " << author << endl;
        cout << "����: " << genre << endl;
        cout << "����� �����: " << shelfNumber << endl;
        cout << "����� ����� �����: " << (canBorrow ? "��" : "���") << endl;
    }
};

// �����-��������� - ����� ���������� ����
class ReadingRoomBook : public Book {
private:
    int roomNumber;
    string readerCardRequired;

public:
    ReadingRoomBook(string t, string a, string g, int rn, string rc)
        : Book(t, a, g), roomNumber(rn), readerCardRequired(rc) {}

    // ���������� ����������� ������� (���������� �.3)
    void fullDisplay() const override {
        cout << "=== ����� ���������� ���� ===" << endl;
        cout << "��������: " << title << endl;
        cout << "�����: " << author << endl;
        cout << "����: " << genre << endl;
        cout << "����� ����: " << roomNumber << endl;
        cout << "��������� ������������ �����: " << readerCardRequired << endl;
    }
};

// �������� ����� - ���������� (�� ���. ������ �1)
class Library {
private:
    string name;
    string address;
    vector<unique_ptr<Book>> books;  // ���������������� ������ (���������� �.6)

public:
    Library(string n, string a) : name(n), address(a) {}

    // ����� ��� ���������� ����� ����� (����������� ��� �.6)
    void addBook(unique_ptr<Book> book) {
        books.push_back(move(book));
    }

    // ����� ������ ���� ������ (���������� �.6)
    void displayAll() const {
        cout << "\n=== ���������� � ���������� ===" << endl;
        cout << "��������: " << name << endl;
        cout << "�����: " << address << endl;
        cout << "\n=== ����� � ���������� ===" << endl;

        for (const auto& book : books) {
            book->fullDisplay();
            cout << endl;
        }
    }
};

int main() {
    cout << "=== ������������ ������ 4 ===" << endl;
    cout << "=== ������ � ������������ �������� � ������������� ===" << endl;

    // 1. �������� ������� �������� ������ (���������� �.4)
    vector<unique_ptr<Book>> bookCollection;

    // ��������� ������� ������ �������-�����������
    bookCollection.push_back(make_unique<MainHallBook>("1984", "��. ������", "����������", 5, true));
    bookCollection.push_back(make_unique<ReadingRoomBook>("����� � ���", "�. �������", "�����", 3, "��"));
    bookCollection.push_back(make_unique<MainHallBook>("����� ������", "��. �������", "�������", 7, false));

    // 2. ����� ������ (���������� �.5)
    cout << "\n����� ������ �� �������:" << endl;
    for (const auto& book : bookCollection) {
        book->fullDisplay();
        cout << endl;
    }

    // 3. ������ � �������� ������� (���������� �.7)
    cout << "\n������ � ������� Library:" << endl;
    Library centralLibrary("����������� ����������", "��. ������, 10");

    // ��������� ����� ������ �����
    centralLibrary.addBook(make_unique<MainHallBook>("������������ � ���������", "�. �����������", "�����", 2, true));
    centralLibrary.addBook(make_unique<ReadingRoomBook>("������������", "������ ������", "����������", 1, "��"));
    centralLibrary.addBook(make_unique<MainHallBook>("�������", "�. ������", "�����", 4, false));

    // ������� ��� ������
    centralLibrary.displayAll();

    cout << "\n=== ���������� ��������� ===" << endl;
    return 0;
}