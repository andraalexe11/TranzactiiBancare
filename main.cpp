#include <iostream>
#include "teste.h"
#include "ui.h"
using namespace std;
int main() {
   //testTranzactie();
   Repository repository;
   Service service(repository);
   UI ui(service);
   ui.printMenu();
   return 0;
}
