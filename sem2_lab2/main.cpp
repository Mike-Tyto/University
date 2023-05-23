#include <iostream>

#include "sequence.h"
#include "array_sequence.h"
#include "list_sequence.h"

void menu() {
    int flag = 1, choice, index;
    float value;
    Sequence<float>* seq = nullptr;

    while (flag) {
        std::cout << "\n<-------------------------------------->\n";
        std::cout << "Select an option:\n";
        std::cout << "1. Create a new array sequence\n";
        std::cout << "2. Create a new linked list sequence\n";
        std::cout << "3. Print the sequence\n";
        std::cout << "4. Get the first element\n";
        std::cout << "5. Get the last element\n";
        std::cout << "6. Get an element by index\n";
        std::cout << "7. Get the length of the sequence\n";
        std::cout << "8. Append an element\n";
        std::cout << "9. Prepend an element\n";
        std::cout << "10. Insert an element at an index\n";
        std::cout << "0. Finish program\n";
        std::cout << "<-------------------------------------->\n";
        std::cin >> choice;

        switch (choice)
        {
            case 1:
                // Create a new array sequence
                if (seq != nullptr)
                {
                    delete seq;
                    seq = nullptr;
                }
                seq = new ArraySequence<float>();
                break;

            case 2:
                // Create a new linked list sequence
                if (seq != nullptr)
                {
                    delete seq;
                    seq = nullptr;
                }
                seq = new ListSequence<float>();
                break;

            case 3:
                // Print the sequence
                if (seq == nullptr)
                {
                    std::cout << "Sequence is empty.\n";
                    break;
                }
                std::cout << "<~~~~~~~~~~~~Your Sequence~~~~~~~~~~~~~>\n";
                    std::cout << seq;
                std::cout << "\n<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>\n";
                std::cout << std::endl;
                break;

            case 4:
                // Get the first element
                if (seq == nullptr)
                {
                    std::cout << "Sequence is empty.\n";
                    break;
                }
                std::cout << "First element: " << seq->GetFirst() << std::endl;
                break;

            case 5:
                // Get the last element
                if (seq == nullptr)
                {
                    std::cout << "Sequence is empty.\n";
                    break;
                }
                std::cout << "Last element: " << seq->GetLast() << std::endl;
                break;

            case 6:
                // Get an element by index
                if (seq == nullptr) {
                    std::cout << "Sequence is empty.\n";
                    break;
                }
                std::cout << "Enter index: ";
                std::cin >> index;
                if (index < 0 || index >= seq->GetLength()) {
                    std::cout << "Index out of range.\n";
                    break;
                }
                std::cout << "Element at index " << index << ": " << seq->Get(index) << std::endl;
                break;

            case 7:
                // Get the length of the sequence
                if (seq == nullptr) {
                    std::cout << "Sequence is empty.\n";
                    break;
                }
                std::cout << "Sequence length: " << seq->GetLength() << std::endl;
                break;

            case 8:
                // Append an element
                std::cout << "Enter value to append: ";
                std::cin >> value;
                seq->Append(value);
                break;

            case 9:
                // Prepend an element
                std::cout << "Enter the element to prepend: ";
                std::cin >> value;
                seq->Prepend(value);
                break;

            case 10:
                // Insert an element at an index
                int index;
                std::cout << "Enter the index where you want to insert the element: ";
                std::cin >> index;
                if (index < 0 || index > seq->GetLength()) {
                    std::cout << "Invalid index. Please enter a valid index between 0 and " << seq->GetLength() << "." << std::endl;
                    break;
                }
                float value;
                std::cout << "Enter the value of the element: ";
                std::cin >> value;
                seq->InsertAt(value, index);
                break;
            case 0:
                // Finish program
                flag = 0;
                delete seq;
                seq = nullptr;
                break;
            default:
                break;
        }

    }
}

int main()
{
   menu();
}
