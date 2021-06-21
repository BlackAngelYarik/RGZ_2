#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
void MainLogic(ifstream& INumFile, ifstream& ICharFile, string FirstWord, string SecondWord);
void RowSort(vector<vector<char>>& CharArr, string FirstWord, string SecondWord);
void ColSort(vector<vector<char>>& CharArr, string FirstWord, string SecondWord);
void ShowTable(vector<vector<char>>& CharArr);


////////   ÐÐ°Ð¿Ð¸ÑÐ°Ð½Ð¾ Ð Ð°Ð·Ð¾Ð¼   ////////
int main()
{
    ifstream INumFile("File_Of_Numbers.txt");

    if (!INumFile)
        cout << "File opening error: \"File_Of_Numbers.txt\"\n"
        "Check its integrity!";
    else
    {
        ifstream ICharFile("Binary_Table_File.txt");
        if (!ICharFile)
            cout << "File opening error: \"Binary_Table_File.txt\"\n"
            "Check its integrity!";
        else
        {
            string FirstWord, SecondWord;

            cout << "Please enter 2 words in Latin:\n"
                "-"; getline(cin, FirstWord);
            cout << "-"; getline(cin, SecondWord);

            MainLogic(INumFile, ICharFile, FirstWord, SecondWord);

            INumFile.close();
            ICharFile.close();
        }
    }
    system("pause");
    return 0;
}
////////   ÐÐ°Ð¿Ð¸ÑÐ°Ð½Ð¾ Ð Ð°Ð·Ð¾Ð¼   ////////



////////   ÐÐ°Ð¿Ð¸ÑÐ°Ð½Ð¾ Ð‘Ð¾Ð³Ð´Ð°Ð½Ð¾Ð¼   ////////
void MainLogic(ifstream& INumFile, ifstream& ICharFile, string FirstWord, string SecondWord)
{

    vector<vector<char>> CharArr(SecondWord.size() + 1, vector<char>(FirstWord.size() + 1, '*'));

    for (size_t it = 0; it < FirstWord.size(); it++)
    {
        CharArr[0][it + 1] = FirstWord[it];
    }

    for (size_t it = 0; it < SecondWord.size(); it++)
    {
        CharArr[it + 1][0] = SecondWord[it];
    }


    vector<char> tmpCharArr{};
    for (size_t it = 0; it < FirstWord.size() * SecondWord.size(); it++)
    {
        int  readNum;               //ÑÑ‡Ð¸Ñ‚Ð°Ð½Ð¾Ðµ Ñ‡Ð¸ÑÐ»Ð¾ Ð¸Ð· Ñ„Ð°Ð¹Ð»Ð°
        int  readBinNum;
        int  tmpNum;                //Ð¿ÐµÑ€ÐµÐ¼ÐµÐ½Ð½Ð°Ñ Ñ ÐºÐ¾Ñ‚Ð¾Ñ€Ð¾Ð¹ Ð±ÑƒÐ´ÐµÑ‚ Ñ€Ð°Ð±Ð¾Ñ‚Ð°Ñ‚ÑŒ Ð°Ð»Ð³Ð¾Ñ€Ð¸Ñ‚Ð¼
        int  tmpBinNum;             //Ð¿ÐµÑ€ÐµÐ¼ÐµÐ½Ð½Ð°Ñ Ð² ÐºÐ¾Ñ‚Ð¾Ñ€Ð¾Ð¹ Ð±ÑƒÐ´ÐµÑ‚ Ñ…Ñ€Ð°Ð½Ð¸Ñ‚ÑŒÑÑ Ð´Ð²Ð¾Ð¸Ñ‡Ð½Ð¾Ðµ Ð¿Ñ€ÐµÐ´ÑÑ‚Ð°Ð²Ð»ÐµÐ½Ð¸Ðµ ÑÑ‡Ð¸Ñ‚Ð°Ð½Ð¾Ð³Ð¾ Ñ‡Ð¸ÑÐ»Ð°
        int  BitCount = 0;          //Ð¿ÐµÑ€ÐµÐ¼ÐµÐ½Ð½Ð°Ñ Ð´Ð»Ñ Ð¿Ð¾Ð´ÑÑ‡ÐµÑ‚Ð° Ð±Ð¸Ñ‚Ð¾Ð² Ð² Ð´Ð²Ð¾Ð¸Ñ‡Ð½Ð¾Ð¼ Ñ‡Ð¸ÑÐ»Ðµ
        int  check = 0;             //Ð¿Ð¾Ð±Ð¾Ñ‡Ð½Ð°Ñ Ð¿ÐµÑ€ÐµÐ¼ÐµÐ½Ð½Ð°Ñ

        char readLetter;            //ÑÑ‡Ð¸Ñ‚Ð°Ð½Ñ‹Ð¹ Ð¸Ð· Ñ„Ð°Ð¹Ð»Ð° ÑÐ¸Ð¼Ð²Ð¾Ð» Ð±ÑƒÐºÐ²Ñ‹

        string CharBinNum{};        //Ð¼Ð°ÑÑÐ¸Ð² ÑÐ¸Ð¼Ð²Ð¾Ð»Ð¾Ð² Ð´Ð²Ð¾Ð¸Ñ‡Ð½Ð¾Ð³Ð¾ Ð¿Ñ€ÐµÐ´ÑÑ‚Ð°Ð²Ð»ÐµÐ½Ð¸Ðµ Ñ‡Ð¸ÑÐ»Ð°


        INumFile >> readNum;
        tmpNum = readNum;

        for (int i = 0; tmpNum > 0; i++)
        {
            tmpNum /= 2;
            BitCount++;
        }

        tmpNum = readNum;
        for (int i = 0; i < BitCount; i++)
        {
            if ((check = tmpNum % 2) == 0)
                CharBinNum += '0';
            else
                CharBinNum += '1';

            tmpNum /= 2;
        }

        string ReverseCharBinNum(CharBinNum); //Ð¿ÐµÑ€ÐµÐ²ÐµÑ€Ð½ÑƒÑ‚Ñ‹Ð¹ Ð¼Ð°ÑÑÐ¸Ð² (Ð²ÐµÑ€Ð½Ð°Ñ Ñ„Ð¾Ñ€Ð¼Ð°)
        for (int i = 0; i < BitCount; i++)
        {
            ReverseCharBinNum[i] = CharBinNum[BitCount - i - 1];
        }

        std::istringstream is(ReverseCharBinNum);
        is >> tmpBinNum;

        ICharFile >> readLetter >> readBinNum;
        while (readBinNum != tmpBinNum)
            ICharFile >> readLetter >> readBinNum;

        tmpCharArr.push_back(readLetter);
        ICharFile.seekg(0, std::ios::beg);
    }

    for (size_t i = 1, iter = 0; i < CharArr.size(); i++)
    {
        for (size_t j = 1; j < CharArr[i].size(); j++)
        {
            CharArr[i][j] = tmpCharArr[iter++];
        }
    }

    ShowTable(CharArr);

    RowSort(CharArr, FirstWord, SecondWord);

    ColSort(CharArr, FirstWord, SecondWord);

    cout << "\n\n\n\n";
    ShowTable(CharArr);
}
////////   ÐÐ°Ð¿Ð¸ÑÐ°Ð½Ð¾ Ð‘Ð¾Ð³Ð´Ð°Ð½Ð¾Ð¼   ////////




////////   ÐÐ°Ð¿Ð¸ÑÐ°Ð½Ð¾ Ð¯Ñ€Ð¾ÑÐ»Ð°Ð²Ð¾Ð¼   ////////
void ShowTable(vector<vector<char>>& CharArr)
{
    for (size_t i = 0; i < CharArr.size(); i++)
    {
        for (size_t j = 0; j < CharArr[i].size(); j++)
        {
            if (CharArr[i][j] == '*')
                cout << "   ";
            else
                cout << CharArr[i][j] << "  ";
        }
        cout << endl;
    }
}

void RowSort(vector<vector<char>>& CharArr, string FirstWord, string SecondWord)
{
    for (size_t i = 0; i < CharArr.size() - 1; i++)
    {
        for (size_t j = 1; j < CharArr[i].size() - i - 1; j++)
        {
            vector<char> tmpCharArr(FirstWord.size() + 1);
            if (CharArr[0][j] > CharArr[0][j + 1])
            {
                for (size_t it = 0; it <= SecondWord.size(); it++)
                    tmpCharArr[it] = CharArr[it][j];

                for (size_t it = 0; it <= SecondWord.size(); it++)
                    CharArr[it][j] = CharArr[it][j + 1];

                for (size_t it = 0; it <= SecondWord.size(); it++)
                    CharArr[it][j + 1] = tmpCharArr[it];
            }
        }
    }
}



void ColSort(vector<vector<char>>& CharArr, string FirstWord, string SecondWord)
{
    for (size_t i = 1; i < CharArr.size(); i++)
    {
        for (size_t j = 1; j < CharArr[i].size() - i; j++)
        {
            vector<char> tmpCharArr(SecondWord.size() + 1);
            if (CharArr[j][0] > CharArr[j + 1][0])
            {
                for (size_t it = 0; it <= FirstWord.size(); it++)
                    tmpCharArr[it] = CharArr[j][it];

                for (size_t it = 0; it <= FirstWord.size(); it++)
                    CharArr[j][it] = CharArr[j + 1][it];

                for (size_t it = 0; it <= FirstWord.size(); it++)
                    CharArr[j + 1][it] = tmpCharArr[it];
            }
        }
    }
}
////////   ÐÐ°Ð¿Ð¸ÑÐ°Ð½Ð¾ Ð¯Ñ€Ð¾ÑÐ»Ð°Ð²Ð¾Ð¼   ////////
