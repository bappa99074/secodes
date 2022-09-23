#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>

using namespace std;

class Library{
    public:
        char bookName[200], authorName[100], publisherName[100];
        int bookID, bookQuantity;
        float bookPrice;
        Library(){
            bookID = 0;
            bookQuantity = 0;
            bookPrice = 0.0;
            strcpy(bookName, "No Book Name");
            strcpy(authorName, "No Book Name");
            strcpy(authorName, "No Publisher Name");
        }


        void showMenu();
        void student();
        void librarian();
        void thankYouMessage();
        void retryMessage();

        //student and librarian functions
        void viewBooks(int);
        void searchBooks(int);
        void addBook(int);
        void issueBook(int);
        void getBookData();

};

void Library::thankYouMessage(){
    cout << "\n\n\t\tThank you for using Library Management System!\n";
    getch();
    exit(0);
}

void Library::retryMessage(){
    cout << "\t\tPlease enter a valid option :( \n";
    getch();
    system("cls");
}

void Library::getBookData(){
    fflush(stdin);
    cout << "\n\t\tEnter book details \n";

    cout << "\n\t\tEnter Book title: ";
    cin.getline(bookName, 200);
    cout << "\t\tEnter Author's name: ";
    cin.getline(authorName, 100);
    cout << "\t\tEnter Publisher's name: ";
    cin.getline(publisherName, 100);
    cout << "\t\tEnter Book ID: ";
    cin >> bookID;
    cout << "\t\tEnter Book price: ";
    cin >> bookPrice;
    cout << "\t\tEnter Book quantity: ";
    cin >> bookQuantity;

}

void Library::viewBooks(int user){
    cout << "\n\t\t-----------------------------------";
    cout << "\n\t\t            VIEW BOOKS\n";
    cout << "\t\t-----------------------------------\n\n\n";

    //if user == 1 then student and user == 2 then librarian
    getch();
    system("cls");
    if(user == 1)
        student();
    else
        librarian();
}

void Library::searchBooks(int user){
    cout << "\n\t\t-----------------------------------";
    cout << "\n\t\t            SEARCH BOOKS\n";
    cout << "\t\t-----------------------------------\n\n\n";


    //if user == 1 then student and user == 2 then librarian
    getch();
    system("cls");
    if(user == 1)
        student();
    else
        librarian();
}

void Library::addBook(int user){
    cout << "\n\t\t-----------------------------------";
    cout << "\n\t\t           ADD NEW BOOK\n";
    cout << "\t\t-----------------------------------\n\n\n";

    getBookData();
    ofstream outf("BookStore.txt", ios::app);
    outf.write((char*)this, sizeof(*this));
    outf.close();

    cout << "\n\t\tBooks details entered! Thank you!";

    //if user == 1 then student and user == 2 then librarian
    getch();
    system("cls");
    if(user == 1)
        student();
    else
        librarian();
}

void Library::issueBook(int user){
    cout << "\n\t\t-----------------------------------";
    cout << "\n\t\t            ISSUE BOOK\n";
    cout << "\t\t-----------------------------------\n\n\n";


    //if user == 1 then student and user == 2 then librarian
    getch();
    system("cls");
    if(user == 1)
        student();
    else
        librarian();
}

void Library::student(){
    cout << "\n\t\t-----------------------------------";
    cout << "\n\t\t          WELCOME STUDENT\n";
    cout << "\t\t-----------------------------------\n\n\n";

    cout << "\t\tPlease choose an option \n";
    cout << "\t\t1. View Booklist \n";
    cout << "\t\t2. Search for a book \n";
    cout << "\t\t3. Issue book \n";
    cout << "\t\t4. Go to main menu \n";
    cout << "\t\t5. Close Application\n";
    cout << "\n\t\tEnter your choice:  ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        viewBooks(1);
        break;

    case 2:
        system("cls");
        searchBooks(1);
        break;

    case 3:
        system("cls");
        issueBook(1);
        break;

    case 4:
        system("cls");
        showMenu();
        break;

    case 5:
        thankYouMessage();
        break;

    default:
        retryMessage();
        showMenu();
    }

}

void Library::librarian(){
    cout << "\n\t\t-----------------------------------";
    cout << "\n\t\t         WELCOME LIBRARIAN\n";
    cout << "\t\t-----------------------------------\n\n\n";

    cout << "\t\tPlease choose an option \n";
    cout << "\t\t1. View Booklist \n";
    cout << "\t\t2. Search for a book \n";
    cout << "\t\t3. Add book \n";
    cout << "\t\t4. Issue book \n";
    cout << "\t\t5. Go to main menu \n";
    cout << "\t\t6. Close Application\n";
    cout << "\n\t\tEnter your choice:  ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        viewBooks(2);
        break;

    case 2:
        system("cls");
        searchBooks(2);
        break;

    case 3:
        system("cls");
        addBook(2);
        break;

    case 4:
        system("cls");
        issueBook(2);
        break;

    case 5:
        system("cls");
        showMenu();
        break;

    case 6:
        thankYouMessage();
        break;

    default:
        retryMessage();
        showMenu();
    }


}

void Library::showMenu(){
    cout << "\n\t\t-----------------------------------";
    cout << "\n\t\t     LIBRARY MANAGEMENT SYSTEM\n";
    cout << "\t\t-----------------------------------\n\n\n";

    cout << "\t\tPlease choose any option to login: \n";
    cout << "\t\t1. Student \n";
    cout << "\t\t2. Librarian \n";
    cout << "\t\t3. Close Application \n";
    cout << "\n\t\tEnter your choice:  ";
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        student();
        break;

    case 2:
        system("cls");
        librarian();
        break;

    case 3:
        thankYouMessage();
        break;

    default:
        retryMessage();
        showMenu();
    }

}

int main(){
    Library obj;
    obj.showMenu();
    getch();
    cout << endl;
    return 0;
}