#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int File_Path_Nothing = 1;
const int ID_Nothing = 2;

void printRecipeNames(string recipe_file_path, unsigned int select_ID=0){
  // レシピファイルが見つからなかった時のエラー処理
  ifstream recipe_file(recipe_file_path);
  if(recipe_file.fail()){
    cout << "レシピファイルが見つかりません" << endl;
    exit(EXIT_FAILURE);
  }

  // レシピファイルから一行ずつ読み出力する
  string recipe_name;
  unsigned int count = 1;
  while(getline(recipe_file, recipe_name)){
    if(select_ID == 0){
      cout << count << ": " << recipe_name << endl;
    } else {
        if(select_ID == count){
          cout << count << ": " << recipe_name << endl;
        }
      }
    count++;
  }
}

int main(int argc, char* argv[])
{
  if(argc == File_Path_Nothing){
    cout << "レシピファイルを指定してください";
    exit(EXIT_FAILURE);
  } else if(argc == ID_Nothing){
    string recipe_file_path = argv[1];
    printRecipeNames(recipe_file_path);
  } else{
    string recipe_file_path = argv[1];
    unsigned int select_ID = atoi(argv[2]);
    printRecipeNames(recipe_file_path, select_ID);
  }

  exit(EXIT_SUCCESS);
}
