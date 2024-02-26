class Book:
    def __init__(self, book):
        self.id, self.name, self.author, self.available = book.split(";")

    def set_id(self, new_id):
        self.id = new_id

    def eq(self, other):
        return self.id == other.id

    def __repr__(self):
        return f"{self.id};{self.name};{self.author};{self.available}"
