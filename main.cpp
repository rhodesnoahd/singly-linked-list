// include the .cpp file for template classes instead of header file
#include "SinglyLinkedList.cpp"

int main()
{
    // construct list of int
    SinglyLinkedList<int> numbers;

    // append values
    numbers.addEnd(0);
    numbers.addEnd(1);
    numbers.addEnd(2);
    std::cout << numbers.getSize() << " items in list: ";
    numbers.print();
    std::cout << "reverse printed: ";
    numbers.reversePrint();

    // prepend values
    numbers.addFront(-1);
    numbers.addFront(-2);
    std::cout << "prepended -1, -2: ";
    numbers.print();

    // remove last item
    numbers.removeEnd();
    std::cout << "removed last item: ";
    numbers.print();

    // remove first item
    numbers.removeFront();
    std::cout << "removed first item: ";
    numbers.print();

    // remove 0
    numbers.removeNode(0);
    std::cout << "removed 0: ";
    numbers.print();

    // add duplicate items
    for (int i=0; i<3; i++)
    {
        numbers.addFront(-99);
        numbers.addEnd(99);
    }
    std::cout << "added duplicate values: ";
    numbers.print();

    // remove duplicate items
    numbers.removeDuplicates();
    std::cout << "removed duplicate values: ";
    numbers.print();

    // reverse list
    numbers.reverse();
    std::cout << "reversed order: ";
    numbers.print();

    // testing reversePrint()
    std::cout << "reverse printed: ";
    numbers.reversePrint();

    // invoke copy constructor
    SinglyLinkedList<int> numbersCopy(numbers);
    if (numbersCopy.getHead() != numbers.getHead())
    {
        std::cout << "invoked copy constructor\n";
        std::cout << "created deep copy: ";
        numbersCopy.print();
    }
    SinglyLinkedList<int> secondCopy = numbers;
    if (secondCopy.getHead() != numbers.getHead())
    {
        std::cout << "invoked copy constructor\n";
        std::cout << "created deep copy: ";
        secondCopy.print();
    }

    // invoke assignment operator
    SinglyLinkedList<int> a;
    a = numbers;
    if (a.getHead() == numbers.getHead())
    {
        std::cout << "invoked assignment operator\n";
        std::cout << "performed shallow copy: ";
        secondCopy.print();
    }

    // construct list of strings
    SinglyLinkedList<std::string> techies;
    
    // append items
    techies.addEnd("Ben Straub");
    techies.addEnd("Scott Chacon");
    techies.addEnd("Max Tegmark");
    techies.print();

    return EXIT_SUCCESS;
}