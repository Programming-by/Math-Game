#include <iostream>
#include <stdlib.h>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}
enum enQuestionLevel
{
    Easy = 1,
    Med = 2,
    Hard = 3,
    MixLevel = 4
};
enum enOperationType
{
    Add = 1,
    Subtract = 2,
    Multiply = 3,
    Division = 4,
    MixType = 5
};
enum enAnswer
{
    RightAnswer = 1,
    WrongAnswer = 2,
};
struct stQuestionInfo
{
    short QuestionNumber;
    short Number1;
    short Number2;
    enOperationType OperationType;
    string OperationTypeCharacter;
    enAnswer Answer;
};

struct stGameResults
{

    short QuestionNumber = 0;
    enQuestionLevel QuestionLevel;
    string QuestionLevelName = "";
    enOperationType OperationType;
    string OperationTypeName = "";
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;

};

enQuestionLevel
MixQuestionLevel()
{
    return (enQuestionLevel)RandomNumber(1, 4);
}
enOperationType MixOperationType()
{
    return (enOperationType)RandomNumber(1, 5);
}
enQuestionLevel ReadQuestionLevel()
{
    short QuestionLevel = 1;
    do
    {
        cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?";
        cin >> QuestionLevel;
    } while (QuestionLevel < 1 || QuestionLevel > 10);
    return (enQuestionLevel)QuestionLevel;
}
enOperationType ReadOperationType()
{
    short OperationType = 1;
    do
    {
        cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?";
        cin >> OperationType;
    } while (OperationType < 1 || OperationType > 5);
    return (enOperationType)OperationType;
}

// string QuestionLevelName(enQuestionLevel QuestionLevel)
// {

//     string arrQuestionLevelName = {"Easy", "Med", "Hard", "Mix"};

//     return arrQuestionLevelName[QuestionLevel - 1];
// }

// string OperationTypeName(enOperationType OperationType)
// {

//     string arrOperationLevelName = {"Add", "Sub", "Mul", "Div", "Mix"};

//     return arrOperationLevelName[OperationType - 1];
// }

short ReadHowManyQuestions()
{
    short Questions = 0;
    do
    {
        cout << "How Many Questions do you want to answer ?";
        cin >> Questions;
    } while (Questions < 1 || Questions > 10);
    return Questions;
}
short GetRandomNumber(enQuestionLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy:
        /* code */
        return RandomNumber(1, 10);
        break;
    case enQuestionLevel::Med:
        /* code */
    cout <<"QuestionLevel";
        return RandomNumber(10, 50);
        break;
    case enQuestionLevel::Hard:
        /* code */
        return RandomNumber(50, 100);
        break;
    case enQuestionLevel::MixLevel:
        return RandomNumber(1, 100);
        break;
    default:
        break;
    }
}
// char RandomOperationType()
// {
//     return  RandomNumber(1, 5);
// }
enOperationType GetOperationType(enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:

        return (enOperationType)'+';
        break;
    case enOperationType::Subtract:
        return (enOperationType)'-';
        break;
    case enOperationType::Multiply:
        return (enOperationType)'*';
        break;
    case enOperationType::Division:
        return (enOperationType)'/';
        break;
        // case enOperationType::MixType:
        //     return  RandomOperationType();
        // break;
    default:
        break;
    }
}
stQuestionInfo PlayGame(short ReadHowManyQuestions)
{
        
    stQuestionInfo QuestionInfo;

    enQuestionLevel QuestionLevel = ReadQuestionLevel();
    enOperationType OperationTypr = ReadOperationType();



    short RightAnswerTimes = 0, WrongAnswerTimes = 0;
    for (short QuestionNumber = 1; QuestionNumber <= ReadHowManyQuestions; QuestionNumber++)
    {
        QuestionInfo.QuestionNumber = QuestionNumber;
        QuestionInfo.Number1 = GetRandomNumber(QuestionLevel);
        // QuestionInfo.Number2 = GetRandomNumber(ReadQuestionLevel());
        // QuestionInfo.OperationType = GetOperationType(ReadOperationType());
        // if (QuestionInfo.Answer == enAnswer::RightAnswer)
        // {
        //     RightAnswerTimes++;
        // }
        // else if (QuestionInfo.Answer == enAnswer::WrongAnswer)
        // {
        //     WrongAnswerTimes++;
        // }
    }
}
// void SetScreenColor()
// {
//     switch ()
//     {
//     case:
//         system("color 2F");
//     case:
//         system("color 4F");
//     default:
//         system("color 6F");
//     }
// }
string Tabs(short NumberOfTabs)
{
    string t = "";
    for (int i = 1; i < NumberOfTabs; i++)
    {
        t = t + "\t";
        cout << t;
    }
    return t;
}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}
void startGame()
{
    char PlayAgain = 'Y';
    do
    {
        ResetScreen();
        stQuestionInfo GameInfo = PlayGame(ReadHowManyQuestions());
        //     ShowFinalGameResults(GameResults);
        cout << endl
             << "Do you want to play again? Y/N? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'y' || PlayAgain == 'Y');
}
int main()
{
    srand((unsigned)time(NULL));
    startGame();
    return 0;
}