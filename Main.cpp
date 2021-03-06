#include<fstream>
#include<iostream>
#include "BinaryTree.h"
using namespace std;
int main(int argc, char *argv[]){
    BinaryTree list;
    bool found;
    string userInput="";
    ItemType item;
    int input;//input
    int number=0;//nums to add
    std::fstream fs;
    fs.open(argv[1], std::fstream::in);
    if (fs.is_open()){
        fs >> input;
        while (!fs.eof()){
            item.initialize(input);
            list.insert(item);
            fs >> input;
        }
    }
    else{
        std::cout << "Failed to open the input file" << std::endl;
        return 0;
    }
    cout<<"insert (i), delete (d), retrieve (r), length(l), in-order (n), pre-order (p), post-order (o), getSameLebelNonsiblings (c),quit (q)"<<endl;
    while(userInput.compare("q")!=0){
        cout<<"\nEnter a command: ";
        cin>>userInput;
        ItemType temp;
        //insert value
        if(userInput.compare("i")==0){
            cout<<"Item to insert: ";
            cin>>number;
            temp.initialize(number);
            list.insert(temp);
	    cout<<"\nIn-Order: ";
            list.inOrder();
            cout<<endl;
        }
        else if(userInput.compare("d")==0){
            cout<<"Item to delete: ";
            cin>>number;
            temp.initialize(number);
            list.retrieve(temp,found);
            if(found==true){
                list.deleteItem(temp);
            }
            else{
                cout<<"Item not in tree.";
            }
            cout<<"\nIn-Order: ";
            list.inOrder();
            cout<<endl;
        }
        else if(userInput.compare("r")==0){
	  cout<<"Item to be retrieved: ";
	  cin>>number;
      cout<<endl;
	  temp.initialize(number);
	  list.retrieve(temp,found); //need to fix
      if(!found){
          cout<<"Item not in tree."<<endl;
      }
      else{
          cout<<"Item found in tree."<<endl;
      }
        }
	else if(userInput.compare("l")==0){
	  cout<<"\nList Length: "<<list.getLength();
        }
        else if(userInput.compare("n")==0){
	  cout<<"In-order: ";
	  list.inOrder();
        }
        else if(userInput.compare("p")==0){
	  cout<<"Pre-order: ";
	  list.preOrder();
        }
        else if(userInput.compare("o")==0){
	  cout<<"Post-order: ";
	  list.postOrder();
        }
        else if(userInput.compare("c")==0){
	  cout<<"Item to find same level nonsiblings: ";
	  cin>>number;
	  temp.initialize(number);
	  list.getSameLevelNonsiblings(temp);
        }
        else if(userInput.compare("q")==0){
            cout<<"Quitting program...";
        }
        //invalid command
        else{
            cout<<"Command not recognized. Try again";
        }
        cout<<endl;
    }
}

