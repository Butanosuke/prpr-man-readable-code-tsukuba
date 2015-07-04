#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void printRecipeNames(string recipe_file_path){
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
    cout << count << ": " << recipe_name << endl;
    count++;
  }
}

int main(int argc, char* argv[])
{
  if(argc == 1){
    cout << "レシピファイルを指定してください";
    exit(EXIT_FAILURE);
  }

  // レシピファイルをコンソールに表示
  string recipe_file_path = argv[1];
  printRecipeNames(recipe_file_path);

  exit(EXIT_SUCCESS);
}
