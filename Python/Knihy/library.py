from book import Book

class Library:
    def __init__(self, path_to_file):
        self.path = path_to_file
        self.books = self._load_books()

    def _load_books(self):
        with open(self.path, "r", encoding="utf-8") as file:
            return sorted([Book(line.strip()) for line in file], key=lambda x: x.author)

    def add_book(self, book):
        if not any(existing_book.eq(book) for existing_book in self.books):
            self.books.append(book)
            print("\nKniha přidána s ID:", book.id)
        else:
            print("\nKniha nemá unikátní ID")

    def get_unique_id(self):
        return max(int(book.id) for book in self.books) + 1

    def show_available_books(self):
        for book in self.books:
            if book.available == "Available":
                print(book)

    def find_book_and_borrow_it(self, name):
        found_books = [book for book in self.books if name.lower() in book.name.lower() and book.available == "Available"]
        if not found_books:
            print("\nNenalezena žádná dostupná kniha s tímto jménem.")
        elif len(found_books) > 1:
            print("\nNalezena více knih, prosím upřesněte hledání:")
            for book in found_books:
                print(book)
        else:
            print("\nNalezena tato kniha:")
            print(found_books[0])
            answer = input("Chcete knihu vypůjčit (A/N): ")
            if answer.lower() == "a":
                found_books[0].available = "Unavailable"
                print("Kniha půjčena")

    def __repr__(self):
        return "\n".join(str(book) for book in self.books)