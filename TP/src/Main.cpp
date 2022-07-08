#include "BinaryTree.hpp"

int main(int argc, char const *argv[]) {
    BinaryTree tree = BinaryTree();

    Email email1 = Email(1, "SAAAAAALVE RAPAZIADA!!");
    Email email2 = Email(2, "EAEEE");
    Email email3 = Email(3, "TRANQUILO");
    Email email4 = Email(4, "SAAAAAALVE RAPAZIADA!!");
    Email email5 = Email(5, "SAAAAAALVE RAPAZIADA!!");
    Email email6 = Email(6, "SAAAAAALVE RAPAZIADA!!");
    Email email7 = Email(7, "SAAAAAALVE RAPAZIADA!!");
    Email email8 = Email(8, "SAAAAAALVE RAPAZIADA!!");
    Email email9 = Email(9, "SAAAAAALVE RAPAZIADA!!");
    Email email10 = Email(10, "SAAAAAALVE RAPAZIADA!!");


    tree.insert(email7);
    tree.insert(email4);
    tree.insert(email5);
    tree.insert(email1);
    tree.insert(email8);
    tree.insert(email10);
    tree.insert(email9);
    tree.insert(email6);
    tree.insert(email2);
    tree.insert(email3);

    std::cout << "--------- Test Insert ----------" <<std::endl;
    tree.printInOrder();

    std::cout << std::endl;
    std::cout << "--------- Test Search ----------" <<std::endl;

    tree.search(1).print();
    tree.search(2).print();
    tree.search(3).print();
    tree.search(4).print();
    tree.search(5).print();
    tree.search(6).print();
    tree.search(7).print();
    tree.search(8).print();
    tree.search(9).print();
    tree.search(10).print();

    std::cout << std::endl;
    std::cout << "--------- Test Remove ----------" << std::endl;
    std::cout << "--------- 1 Remove ----------" << std::endl;
    tree.remove(1);
    tree.printInOrder();

    std::cout << "--------- 2 Remove ----------" << std::endl;
    tree.remove(2);
    tree.printInOrder();

    std::cout << "--------- 3 Remove ----------" << std::endl;
    tree.remove(3);
    tree.printInOrder();

    std::cout << "--------- 4 Remove ----------" << std::endl;
    tree.remove(4);
    tree.printInOrder();

    std::cout << "--------- 5 Remove ----------" << std::endl;
    tree.remove(5);
    tree.printInOrder();

    std::cout << "--------- 6 Remove ----------" << std::endl;
    tree.remove(6);
    tree.printInOrder();

    std::cout << "--------- 7 Remove ----------" << std::endl;
    tree.remove(7);
    tree.printInOrder();

    std::cout << "--------- 8 Remove ----------" << std::endl;
    tree.remove(8);
    tree.printInOrder();

    std::cout << "--------- 9 Remove ----------" << std::endl;
    tree.remove(9);
    tree.printInOrder();

    std::cout << "--------- 10 Remove ----------" << std::endl;
    tree.remove(10);
    tree.printInOrder();






    return 0;
}
