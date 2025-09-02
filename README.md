### Zadanie: Zarządzanie Kolekcją Książek

#### Opis:
Stwórz program, który zarządza kolekcją książek w bibliotece. Każda książka powinna mieć tytuł, autora i numer ISBN. Kolekcja książek powinna być przechowywana dynamicznie, a więc należy użyć operatorów `new` i `delete` do zarządzania pamięcią.

#### Wymagania:
1. **Klasa `Book`**:
    - Atrybuty: `title`, `author`, `isbn`, 'index'.
    - Konstruktor do inicjalizacji atrybutów.
    - Destruktor `~Book()`, który wyświetli komunikat o zniszczeniu obiektu (dla celów demonstracyjnych), brzmiący: Destroying book: <title>
    - Gettery: `getTitle()`, `getAuthor()`, `getIsbn()`, `getIndex()` do uzyskiwania wartości atrybutów.

2. **Klasa `Library`**:
    - Atrybut: wskaźnik do tablicy wskaźników na obiekty `Book`.
    - Atrybut: liczba książek w bibliotece.
    - Metody:
        - `addBook(Book* book)`: dodaje książkę do kolekcji.
            - Tworzy nową dynamiczną tablicę wskaźników na książki, która jest o jeden element większa niż poprzednia.
            - Kopiuje wszystkie istniejące wskaźniki do nowej tablicy.
            - Dodaje nowy wskaźnik na końcu tablicy.
            - Zwalnia pamięć zajmowaną przez starą tablicę.
            - Aktualizuje wskaźnik do tablicy i liczbę książek.
            - Przypisuje atrybutowi `index` index ksiązki w tablicy. 
        - `removeBook(int index)`: usuwa książkę z kolekcji i zwalnia pamięć.
            - Sprawdza, czy podany indeks jest prawidłowy, w przypadku nieprawidłowego wyświetla komunikat: "Invalid index".
            - Usuwa książkę o podanym indeksie, zwalniając pamięć.
            - Przesuwa wskaźniki w tablicy, aby wypełnić lukę.
            - Zmniejsza liczbę książek.
        - Gettery: `getBooks()`, `getCount()` do uzyskiwania wartości atrybutów.
        - Destruktor `~Library()`: zwalnia całą pamięć zajmowaną przez tablicę książek.
            - Iteruje przez tablicę wskaźników i usuwa każdą książkę, zwalniając pamięć.
            - Zwalnia pamięć zajmowaną przez tablicę wskaźników.
            - Wyświetla komunikat o zniszczeniu obiektu `Library`, brzmiący: "Library destroyed".

3. **Diagram klas**:
    - Klasa `Book` z atrybutami i metodami.
    - Klasa `Library` z atrybutami i metodami.

### Diagram klas:

```
+------------+                   +------------+
|   Book     |                   |  Library   |
+------------+                   +------------+
| - title    |                   | - books[]  |
| - author   |                   | - count    |
| - isbn     |
| - index    |                   +------------+
+------------+                   | +addBook() |
| +Book()    |                   | +removeBook()|
| +~Book()   |                   | +getBooks() |
| +getTitle()|                   | +getCount() |
| +getAuthor()|                   | +~Library()|
| +getIsbn() |                   +------------+
| +getIndex()|
+------------+                   
```

### Przykład użycia:

```cpp
#include <iostream>
#include <string>

int main() {
    Library library;
    library.addBook(new Book("1984", "George Orwell", "1234567890"));
    library.addBook(new Book("Brave New World", "Aldous Huxley", "0987654321"));
    library.removeBook(0);

    for (int i = 0; i < library.getCount(); ++i) {
        Book* book = library.getBooks()[i];
        std::cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", ISBN: " << book->getIsbn() << ", Index: " << book->getIndex() << std::endl;
    }
    return 0;
}
```

W powyższym przykładzie dodane zostały gettery do klas `Book` i `Library`, a także zaktualizowany opis zadania, aby uwzględniał te zmiany.

### Uruchomienie testów:

```bash
make test_book
make test_library
make test_memory

```
