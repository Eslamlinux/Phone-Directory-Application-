    #include "menu.h"
    #include "header/colors.h"
    #include <iostream>
    #include <limits>
    // #include "header/setup.h"
    char Start_Menu(char User_Chose){

        std::cout << "\n--------------------------------------------\n";
        std::cout << Colors.bold_yellow_bg <<Colors.bold_red << "\t📞 Phone Directory Menu 📞" <<Colors.reset;
         std::cout << "\n--------------------------------------------\n";
         std::cout << "1: "<< Colors.blue<< "🔗 add new contact         "<< Colors.bold_green<< "press[1]\n"<<Colors.reset;
         std::cout << "2: "<< Colors.blue<<"🧐 To see all contacts     "<< Colors.bold_green<< "press[2]\n"<<Colors.reset;
         std::cout << "3: "<< Colors.blue<<"📇 Total contact           "<< Colors.bold_green<< "press[3]\n"<<Colors.reset;
         std::cout << "4: "<< Colors.blue<<"🗑️  Delete contacts         "<< Colors.bold_green<< "press[D]\n"<<Colors.reset;
         std::cout << "5: "<< Colors.blue<<"📤  Export & Import Data   "<< Colors.bold_green<< "press[E]\n"<<Colors.reset;
         std::cout << "6: "<< Colors.blue<<"🧹 ignore the changes      "<< Colors.bold_green<< "press[I]\n"<<Colors.reset;
         std::cout << "7: "<< Colors.blue<<"📊 To see Total changes    "<< Colors.bold_green<< "press[T]\n"<<Colors.reset;
         std::cout << "8: "<< Colors.blue<<"💾 Save last changes       "<< Colors.bold_green<< "press[S]\n"<<Colors.reset;
         std::cout << "9: "<< Colors.blue<<"🔍 To search contact       "<< Colors.bold_green<< "press[F]\n"<<Colors.reset;
         std::cout << "0: "<< Colors.blue<<"⏻  To exit                 "<< Colors.bold_green<< "press[Q]"<<Colors.reset <<std::endl;
         std::cout << Colors.reset;

         std::cout << "--------------------------------------------\n";
         std::cout << "Your choice>>: ";
         std::cin >> User_Chose;
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
         return User_Chose;
        }