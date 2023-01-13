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
    short QuestionNumbers;
    short QuestionNumber;
    short Number1;
    short Number2;
    enOperationType OperationType;
    string OperationTypeCharacter;
    enAnswer Answer;
};

struct stGameResults
{

    short NumberOfQuestions = 0;
    enQuestionLevel QuestionLevel;
    string QuestionLevelType = "";
    enOperationType OperationType;
    string OperationTypeCharacter = "";
    short NumberOfRightAnswers = 0;
    short NumberOfWrongAnswers = 0;
};

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

short RandomQuestionLevel()
{
    return RandomNumber(1, 4);
}

short RandomOperationType()
{
    return RandomNumber(1, 4);
}

string QuestionLevelType(enQuestionLevel QuestionLevel)
{

    string arrQuestionLevelName[3] = {"Easy", "Med", "Hard"};

    return arrQuestionLevelName[QuestionLevel - 1];
}

string OperationTypeCharacter(enOperationType OperationType)
{

    string arrOperationType[4] = {"+", "-", "*", "/"};
    return arrOperationType[OperationType - 1];
}

enQuestionLevel GetQuestionLevel(enQuestionLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
    case enQuestionLevel::Easy: // 1 - 10
        return enQuestionLevel::Easy;
        break;
    case enQuestionLevel::Med: // 10 - 20
        return enQuestionLevel::Med;
        break;
    case enQuestionLevel::Hard: // 20 - 100
        return enQuestionLevel::Hard;
        break;
    case enQuestionLevel::MixLevel:
        return enQuestionLevel::MixLevel;
        break;
    default:
        break;
    }
}

enOperationType GetOperationType(enOperationType OperationType)
{
    switch (OperationType)
    {
    case enOperationType::Add:
        return enOperationType::Add;
        break;
    case enOperationType::Subtract:
        return enOperationType::Subtract;
        break;
    case enOperationType::Multiply:
        return enOperationType::Multiply;
        break;
    case enOperationType::Division:
        return enOperationType::Division;
        break;
    case enOperationType::MixType:
        return (enOperationType)RandomOperationType();
        break;
    default:
        break;
    }
}

// short Sum(stQuestionInfo QuestionInfo) {

// return  QuestionInfo.Number1 + QuestionInfo.Number2;
// }

// short Subtract(stQuestionInfo QuestionInfo) {

// return  QuestionInfo.Number1 - QuestionInfo.Number2;
// }

// short Multiply(stQuestionInfo QuestionInfo) {

// return QuestionInfo.Number1 * QuestionInfo.Number2;
// }

// short Division(stQuestionInfo QuestionInfo) {

// return  QuestionInfo.Number1 / QuestionInfo.Number2;
// }

// compare user answer with sum,subtract ...functions

string AnswerName(enAnswer Answer)
{
    string arrAnswerName[2] = {"Right Answer :)", "Wrong Answer :("};

    return arrAnswerName[Answer - 1];
}

enAnswer Answer(stQuestionInfo QuestionInfo)
{

    short Sum = QuestionInfo.Number1 + QuestionInfo.Number2;
    short Sub = QuestionInfo.Number1 - QuestionInfo.Number2;
    short Mul = QuestionInfo.Number1 * QuestionInfo.Number2;
    short Div = QuestionInfo.Number1 / QuestionInfo.Number2;
    switch (QuestionInfo.OperationType)
    {

    case enOperationType::Add:

        return  enAnswer::RightAnswer;
        break;
    case enOperationType::Subtract:
        return  enAnswer::RightAnswer;
        break;
    case enOperationType::Multiply:
        return  enAnswer::RightAnswer;
        break;
    case enOperationType::Division:
        return  enAnswer::RightAnswer;
        break;
    }
}

void UserAnswer(stQuestionInfo QuestionInfo)
{

    short MyAnswer = 0;

    do
    {

        cin >> MyAnswer;

    } while (MyAnswer < 0 || MyAnswer > 200);

    if (Answer(QuestionInfo) == MyAnswer)
    {
        cout << "Right Answer :)" << endl;
    }
    else
    {

        cout << "Wrong Answer :(" << endl;
        cout << "The right answer is " << Answer(QuestionInfo) << endl;
    }




}

void GameOverScreen()
{
    cout << "_________________";
 
    cout << "Final Result is ";
    //    if (true)  {
    //     cout << "Pass :)"
    // }
    // else
    // {
    //     cout << "Fail :("
    // }
    cout << "_________________";
}

void PrintQuestionResults(stQuestionInfo QuestionInfo)
{

    cout << "Question [" << QuestionInfo.QuestionNumber << "/" << QuestionInfo.QuestionNumbers << "]" << endl
         << endl;
    cout << QuestionInfo.Number1 << endl;
    cout << QuestionInfo.Number2;
    cout << " " << QuestionInfo.OperationTypeCharacter << endl;
    cout << "_____" << endl;
    cout << endl;
    cout << endl;
    UserAnswer(QuestionInfo);
    GameOverScreen();
}

//  stGameResults FillGameResults (short NumberOfQuestions,short QuestionLevel,short OperationType,short RightAnswer,short WrongAnswer) {

// stGameResults GameResults;
// GameResults.NumberOfQuestions = NumberOfQuestions ;
// GameResults.QuestionLevel = QuestionLevel;
// GameResults.OperationType =  OperationType;
// // GameResults.NumberOfRightAnswers =  RightAnswerTimes;
// // GameResults.NumberOfWrongAnswers = WrongAnswerTimes;

//  }

stQuestionInfo PlayGame(short ReadHowManyQuestions)
{

    stQuestionInfo QuestionInfo;

    enQuestionLevel QuestionLevel = ReadQuestionLevel();
    enOperationType OperationType = ReadOperationType();

    short RightAnswerTimes = 0, WrongAnswerTimes = 0;
    for (short QuestionNumber = 1; QuestionNumber <= ReadHowManyQuestions; QuestionNumber++)
    {
        QuestionInfo.QuestionNumbers = ReadHowManyQuestions;
        QuestionInfo.QuestionNumber = QuestionNumber;
        QuestionInfo.Number1 = GetRandomNumber(QuestionLevel);
        QuestionInfo.Number2 = GetRandomNumber(QuestionLevel);
        QuestionInfo.OperationType = GetOperationType(OperationType);
        QuestionInfo.OperationTypeCharacter = OperationTypeCharacter(QuestionInfo.OperationType);
        QuestionInfo.Answer = Answer(QuestionInfo);

        // if (QuestionInfo.Answer == enAnswer::RightAnswer)
        // {
        //     RightAnswerTimes++;
        // }
        // else if (QuestionInfo.Answer == enAnswer::WrongAnswer)
        // {
        //     WrongAnswerTimes++;
        // }
        PrintQuestionResults(QuestionInfo);
    }
    // return FillGameResults(ReadHowManyQuestions,QuestionLevel ,QuestionInfo.OperationType , RightAnswerTimes, WrongAnswerTimes);
}
void SetScreenColor(stQuestionInfo QuestionInfo)
{
    switch (QuestionInfo.Answer)
    {
    case enAnswer::RightAnswer :
        system("color 2F");
    case enAnswer::WrongAnswer :
        system("color 4F");
    default:
        system("color 6F");
    }
}
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