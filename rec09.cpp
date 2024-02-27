// Zoe Dauphinee, rec 09, inheritance tutorial

        // Task 1 - drawing UML diagram for following code
#include <iostream>
using namespace std;

/*
class PrintedMaterial {
public:
private:
};

class Magazine : public PrintedMaterial {
public:
private:
};

class Book : public PrintedMaterial {
public:
private:
};

class TextBook : public Book {
public:
private:
};

class Novel : public Book {
public:
private:
};

// tester/modeler code
int main() {
    TextBook text;
    Novel novel;
    Magazine mag;
}
*/


        // Task 2 - add unsigned numberOfPages
/*
class PrintedMaterial {
public:
private:
    unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
private:
    unsigned numberOfPages;
};

class Book : public PrintedMaterial {
public:
private:
    unsigned numberOfPages;
};

class TextBook : public Book {
public:
private:
    unsigned numberOfPages;
};

class Novel : public Book {
public:
private:
    unsigned numberOfPages;
};

// tester/modeler code
int main() {
    TextBook text;
    Novel novel;
    Magazine mag;
}
*/


        // Task 3 - Task 2 done correctly
/*
class PrintedMaterial {
public:
private:
    unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
private:
};

class Book : public PrintedMaterial {
public:
private:
};

class TextBook : public Book {
public:
private:
};

class Novel : public Book {
public:
private:
};

// tester/modeler code
int main() {
    TextBook text;
    Novel novel;
    Magazine mag;
}
*/


        // Task 4 - initializing... where does constructor go?
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numberOfPages) : numberOfPages(numberOfPages) {}
private:
    unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
private:
};

class Book : public PrintedMaterial {
public:
private:
};

class TextBook : public Book {
public:
private:
};

class Novel : public Book {
public:
private:
};

// tester/modeler code
int main() {
    TextBook text;
    Novel novel;
    Magazine mag;
}
        
        // putting the constructor just in the base class is incorrect
        // all three of these declarations error
        // "the default constructor of "TextBook" cannot be referenced -- it is a deleted function"
*/


// Task 5 - children classes call base class constructor
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numberOfPages) : numberOfPages(numberOfPages) {}
private:
    unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numberOfPages) : PrintedMaterial(numberOfPages) {}
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numberOfPages) : PrintedMaterial(numberOfPages) {}
private:
};

class TextBook : public Book {
public:
    // doesn't work!
    // TextBook(unsigned numberOfPages) : PrintedMaterial(numberOfPages) {}
private:
};

class Novel : public Book {
public:
    // doesn't work!
    // Novel(unsigned numberOfPages) : PrintedMaterial(numberOfPages) {}
private:
};

// tester/modeler code
int main() {
    TextBook text(5430);
    Novel novel(213);
    Magazine mag(6);
}
*/


        // Task 6 - where does displayNumPages() method go?
/*
class PrintedMaterial {
public:
    void displayNumPages() const { cout << numberOfPages; }
private:
    unsigned numberOfPages;
};

class Magazine : public PrintedMaterial {
public:
private:
};

class Book : public PrintedMaterial {
public:
private:
};

class TextBook : public Book {
public:
private:
};

class Novel : public Book {
public:
private:
};

// tester/modeler code
int main() {
    TextBook text;
    Novel novel;
    Magazine mag;

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";
}
*/


        // Task 7 - displayNumPages also shows numOfIndexPages for textbooks
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    void displayNumPages() const { cout << numOfPages; }
private:
    unsigned numOfPages;
};

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs )
        : Book(numPages), numOfIndexPages(numIndxPgs) {}
    void displayNumPages() const {
	    cout << numOfIndexPages << endl;
	    cout << numOfPages;
        // this is wrong because numOfPages is inaccessible
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
private:
};

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";
}
*/


        // Task 8 - fixing Task 7
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    void displayNumPages() const { cout << numOfPages << endl; }
private:
    unsigned numOfPages;
};

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs )
        : Book(numPages), numOfIndexPages(numIndxPgs) {}
    void displayNumPages() const {
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
private:
};

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";
}
*/


        // Task 9 - testing copying
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    void displayNumPages() const { cout << numOfPages << endl; }
private:
    unsigned numOfPages;
};

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs ) 
        : Book(numPages), numOfIndexPages(numIndxPgs) {}
    void displayNumPages() const {
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
private:
};

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

    cout << "\nA PrintedMaterial material object!\n";
    PrintedMaterial pm(2345);
    pm.displayNumPages();

    cout << "\nA PrintedMaterial variable containing a TextBook value\n";
    pm = text; // like putting a Textbook into a PrintedMaterial
    pm.displayNumPages();
// when copied into PrintedMaterial object, the TextBook printed as a PrintedMaterial instead of a TextBook
}
*/


        // Task 10 - using pointers to fix copying problem
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    void displayNumPages() const { cout << numOfPages << endl; }
private:
    unsigned numOfPages;
};

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs ) 
        : Book(numPages), numOfIndexPages(numIndxPgs) {}
    void displayNumPages() const {
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
private:
};

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

    cout << "\nA PrintedMaterial material object!\n";
    PrintedMaterial pm(2345);
    pm.displayNumPages();

    cout << "\nA PrintedMaterial variable containing a TextBook value\n";
    pm = text; // like putting a Textbook into a PrintedMaterial
    pm.displayNumPages();

    cout << "\nA pointer to a PrintedMaterial containing a TextBook address\n";
    PrintedMaterial* pmPtr;
    pmPtr = &text;
    // instead of putting an actual PrintedMaterial object into the vector, we put the address of
    // a PrintedMaterial object (text) into a vector of pointers-to-PrintedMaterial
    // (that is, pointers to the Base class)
    // we'll be "managing" our objects by using pointers to PrintedMaterial values.
    pmPtr->displayNumPages();
}
*/


        // Task 11 - using virtual to get Index pages to print
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    virtual void displayNumPages() const { cout << numOfPages << endl; }
private:
    unsigned numOfPages;
};

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs ) 
        : Book(numPages), numOfIndexPages(numIndxPgs) {}
    void displayNumPages() const {
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
private:
};

        // Task 12 - standalone function that utilizes virtual method
void displayNumberOfPages(const PrintedMaterial& literature) {
    literature.displayNumPages();
        // i tried doing literature->displayNumPages();
        // this is wrong:
        // "error: no matching function for call to 'displayNumberOfPages' displayNumberOfPages(__)"
        // note: candidate function not viable: no known conversion from 'Magazine' to 'const PrintedMaterial *' for 1st argument; take the address of the argument with & void displayNumberOfPages(const PrintedMaterial* literature) {
}

// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

    cout << "\nA PrintedMaterial material object!\n";
    PrintedMaterial pm(2345);
    pm.displayNumPages();

    cout << "\nA PrintedMaterial variable containing a TextBook value\n";
    pm = text; // like putting a Textbook into a PrintedMaterial
    pm.displayNumPages();

    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
    cout << "Now with the virtual mechanism involved\n";
    // should work now that the virtual mechanism is being invoked
    PrintedMaterial* pmPtr;
    pmPtr = &text; 
    pmPtr->displayNumPages();

    // print some stuff by calling a generic function
    cout << "\nUse a generic functinon for printing\n";
    displayNumberOfPages(mag);
    displayNumberOfPages(novel);
    displayNumberOfPages(text);
}
*/


        // Task 13 - create derivatives of PrintedMaterial without allowing PrintedMaterial objects to be made (pure virtual methods)
// making a method pure makes the class it's in abstract - an object of that type cannot be created
// a concrete class is a class with no pure virtual methods - an object can be created
// a concrete class derived from an abstract class must override the pure virtual method
// the reason for a pure virtual/abstract class is to ensure all children have that method
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    //    LOOK AT THE = 0
    virtual void displayNumPages() const = 0;
private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs)
	    : Book(numPages), numOfIndexPages(numIndxPgs) {}
    void displayNumPages() const {
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
};


void displayNumberOfPages(const PrintedMaterial& anyPM) {
    anyPM.displayNumPages();
}


// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

    cout << "\nA PrintedMaterial material object!\n";
    PrintedMaterial pm(2345);
    pm.displayNumPages();

    pm = text; // like putting a Textbook into a PrintedMaterial
    pm.displayNumPages();

    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
    cout << "Now with the virtual mechanism involved\n";
    // should work now that the virtual mechanism is being invoked
    PrintedMaterial* pmPtr;
    pmPtr = &text; 
    pmPtr->displayNumPages();

    // print some stuff by calling a generic function
    cout << "\nUse a generic functino for printing\n";
    displayNumberOfPages(mag);
    displayNumberOfPages(novel);
    displayNumberOfPages(text);
}
// won't compile - says "object of abstract class type "Novel" is not allowed:"
// (Novel, Magazine, PrintedMateral)
*/


        // Task 14
// Task 13 didn't compile because we were trying to instantiate abstract classes
// PrintedMaterial is abstract and we want to keep it that way, but why don't Novel and Magazine work?
//          because they use PrintedMaterial's displayNumPages() method -- they need to have their own definition
/*
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    virtual void displayNumPages() const = 0;
private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}

    // virtual - NOTE even without writing "virtual"
    // again, this overriden method IS virtual
    // viruality cannot be removed once installed
    // Also note that the = 0 has is not there
    void displayNumPages() const {
        cout << "Hi, I'm a Magazine object stored\n"
            << "(but I can't know that I am being\n"
            << "stored (by pointer) in a vector of\n"
            << "PrintedMaterial pointers!\n";
        PrintedMaterial::displayNumPages();
        cout << "(and I'm very glossy!\n";
    }
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs)
	    : Book(numPages), numOfIndexPages(numIndxPgs) {}

    void displayNumPages() const {
        cout << "\nThis is a textbook.\n";
        cout << "It is a very boring textbook.\n";
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages) : Book(numPages) {}
    void displayNumPages() const {
        cout << "\nThis is the story of a very\n"
            << " interesting programmer's quest\n"
            << "  to understand inheritance.\n"
            << "   The journey is just beginning\n"
            << "    and already the journeyman\n"
            << "      hacker, no - not a hacker! -\n"
            << "         a programmer who reads, and\n"
            << "             studies and understands code\n"
            << "                 Hackers steal and don't even\n"
            << "                      try to understand what they stole\n"
            << "                           before using it.\n"
            << "\n       ...But I digress.\n"
            << "\nThis novel is quite long, there\n"
            << "being this number of pages:\n"
            << "=====================================\n"
            << "                 ";
        PrintedMaterial::displayNumPages();
        cout << "=====================================\n"
            << "Whew!\n"
            << " but there is an exciting\n"
            << "  programming adventure on every\n"
            << "   single one of them!\n"
            << "    And now, let's let the quest continue..."
            << endl << endl << endl;
    }

private:
};


// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

    cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
    cout << "Now with the virtual mechanism involved\n";
    PrintedMaterial* pmPtr;
    pmPtr = &text; // like putting t into a vector but
    // we are actually putting the address of t
    // into a vector pointers of pointers to
    // PrintedMaterials. We'll "say" we are putting
    // t into the vector
    // (that is, pointers to the Base class)
    pmPtr->displayNumPages();
}
*/


        // Task 15 - storing different PrintedMaterial objects in a vector
class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages) : numOfPages(numPages) {}
    virtual void displayNumPages() const = 0;
private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}

    // virtual NOTE even without writing "virtual"
    // again, this overriden method IS virtual
    // viruality cannot be removed once installed
    // Also note that the = 0 has is not there
    void displayNumPages() const {
        cout << "Hi, I'm a Magazine object stored\n"
            << "(but I can't know that I am being\n"
            << "stored (by pointer) in a vector of\n"
            << "PrintedMaterial pointers!\n";
        PrintedMaterial::displayNumPages();
        cout << "(and I'm very glossy!\n";
    }
private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs)
	    : Book(numPages), numOfIndexPages(numIndxPgs) {}

    void displayNumPages() const {
        cout << "\nThis is a textbook.\n";
        cout << "It is a very boring textbook.\n";
        cout << "Pages: ";
        PrintedMaterial::displayNumPages();
        cout << "Index pages: ";
        cout << numOfIndexPages << endl; 
    }
private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
	Novel(unsigned numPages) : Book(numPages) {}
	void displayNumPages() const
	{
		cout << "\nThis is the story of a very\n"
			 << " interesting programmer's quest\n"
			 << "  understand inheritance.\n"
			 << "   The journey is just beginning\n"
			 << "    and already the journeyman\n"
			 << "      hacker, no - not a hacker! -\n"
			 << "         a programmer who reads, and\n"
			 << "             studies and understands code\n"
			 << "                 Hackers steal and don't even\n"
			 << "                      try to understand what they stole\n"
			 << "                           before using it.\n"
			 << "\n       ...But I digress.\n"
			 << "\nThis novel is quite long, there\n"
			 << "being this number of pages:\n"
			 << "=====================================\n"
			 << "                 ";
		PrintedMaterial::displayNumPages();
		cout << "=====================================\n"
		     << "Whew!\n"
		     << " but there is an exciting\n"
		     << "  programming adventure on every\n"
		     << "   single one of them!\n"
		     << "    And now, let's let the quest continue..."
		     << endl << endl << endl;
	}
private:
};


// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    // as direct method calls
    cout << "\nEach will now be asked directly,\n"
	 << "using the dot member operator to\n"
	 << "display its number of pages:\n";
    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

    // Storing generic objects in a vector 
    cout << "\n\nNow we'll use a container. Yea!!!\n\n";
    vector< PrintedMaterial* > allThemPrinties;
    allThemPrinties.push_back(&text);
    allThemPrinties.push_back(&novel);
    allThemPrinties.push_back(&mag);
    for(size_t ndx=0; ndx < allThemPrinties.size(); ++ ndx) {
	allThemPrinties[ndx]->displayNumPages();
	cout << endl;
    }
    cout << "===========\n";
    for (const PrintedMaterial* pmPtr : allThemPrinties) {
	pmPtr->displayNumPages();
	cout << endl;
    }
}