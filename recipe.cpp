#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string getRecipeName(string recipe_file_path){
  ifstream recipe_file(recipe_file_path);
  if(recipe_file.fail()){
    cout << "レシピファイルが見つかりません" << endl;
    exit(EXIT_FAILURE);
  }
  
  string recipe_name;
  recipe_file >> recipe_name;

  return recipe_name;
}

int main()
{
  string recipe_name = getRecipeName("data/recipe-data.txt");

  cout << recipe_name << endl;
  
  exit(EXIT_SUCCESS);
}
