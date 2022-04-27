#include<iostream>
using namespace std;

void wrongAnswer() {
    int response;
    response = rand() % 4 + 1;
    switch (response) {
    case 1:
        cout << "No. Please try again." << endl;
        break;
    case 2:
        cout << "Wrong.Try once more." << endl;
        break;
    case 3:
        cout << "Don't give up!" << endl;
        break;
    case 4:
        cout << "No. Keep trying." << endl;
        break;
    }
}
void correctAnswer()
{
    int response;
    response = rand() % 4 + 1;
    switch (response)
    {
    case 1:
        cout << "Very good!" << endl;
        break;
    case 2:
        cout << "Excellent!" << endl;
        break;
    case 3:
        cout << "Nice work!" << endl;
        break;
    case 4:
        cout << "Keep up the good work!" << endl;
        break;
    }
}

unsigned int dvisionGenerator() {
    int num1, num2;
    srand(static_cast<int>(time(0)));
    num1 = rand() % 19 + 1;
    num2 = rand() % 9 + 1;
    while (num1 % num2 != 0) {
        num1 = rand() % 9 + 1;
    }
    cout << "How much is " << num1 << " divided by " << num2 << "?" << endl;
    return num1 / num2;
}

unsigned int subractionGenerator() {
    int num1, num2;
    srand(static_cast<int>(time(0)));
    num1 = rand() % 9 + 1;
    num2 = rand() % 9 + 1;
    while (num1 < num2) {
        num1 = rand() % 9 + 1;
    }
    cout << "How much is " << num1 << " mius " << num2 << " ?" << endl;
    return num1 - num2;
}
int additionGenerator() {
    int num1, num2;
    srand(static_cast<int>(time(0)));
    num1 = rand() % 9 + 1;
    num2 = rand() % 9 + 1;
    cout << "How much is " << num1 << " plus " << num2 << " ?" << endl;
    return num1 + num2;
}
int multiplicationGenerator1() {
    int num1, num2;
    srand(static_cast<int>(time(0)));
    num1 = rand() % 9 + 1;
    num2 = rand() % 9 + 1;
    cout << "How much is " << num1 << " times " << num2 << " ?" << endl;
    return num1 * num2;
}

void multiplicationAssistLevel1() {
    int answer, product;
    int countC = 0, countW = 0;
    int totalPoints = 0;

    while (totalPoints < 10) 
    {
        product = multiplicationGenerator1();
        cin >> answer;
        while (product != answer) 
        {
            countW++;
            wrongAnswer();
            if (countW + countC > 9)
            {
                break;
            }
            else
            {
                cin >> answer;
            }
        }
        if (answer == product)
        {
            countC++;
            correctAnswer();
        }
        totalPoints = countW + countC;
    }

    cout << "Correct answers " << countC << ", Wrong answers " << countW << endl;
    if (countC >= 8) {
        cout << "\n**^^**^^**^^**^^**^^**^^**^^**^^**" << endl;
        cout << "Congratulations, you are doing great :) \nLet's move forward\n " << endl;
    }
    else if (countW >= 2) {
        cout << "Please ask your teacher for extra help." << endl;
    }
}

void additionAssist() {
    int answer, total;
    int countC = 0, countW = 0;
    int totalPoints = 0;

    while (totalPoints < 10) {
        total = additionGenerator();
        cin >> answer;

        while (total != answer) {
            countW++;
            wrongAnswer();
            if (countW + countC > 9) {
                break;
            }
            else
            {
                cin >> answer;
            }
        }
        if (answer == total) {
            countC++;
            correctAnswer();
        }
        totalPoints = countW + countC;
    }
    cout << "Correct answers " << countC << ", Wrong answers " << countW << endl;
}


void subractionAssist() {
    unsigned int answer, total;
    int countC = 0, countW = 0;
    int totalPoints = 0;

    while (totalPoints < 10) {
        total = subractionGenerator();
        cin >> answer;

        while (total != answer) {
            countW++;
            wrongAnswer();
            if (countW + countC > 9)
            {
                break;
            }
            else
            {
                cin >> answer;
            }
        }
        if (answer == total)
        {
            countC++;
            correctAnswer();
        }
        totalPoints = countW + countC;
    }
    cout << "Correct answers " << countC << ", Wrong answers " << countW << endl;
}

void divisionAssist() {
    unsigned int answer, total;
    int countC = 0, countW = 0;
    int totalPoints = 0;

    while (totalPoints < 10) {
        total = dvisionGenerator();
        cin >> answer;

        while (total != answer) 
        {
            countW++;
            wrongAnswer();
            if (countW + countC > 9) 
            {
                break;
            }
            else
            {
                cin >> answer;
            }
        }
        if (answer == total) {
            countC++;
            correctAnswer();
        }
        totalPoints = countW + countC;
    }
    cout << "Correct answers " << countC << ", Wrong answers " << countW << endl;
}
int main() {

    int choice;
    char x = 'y';
    while (x == 'y') {
        cout << "Please enter a choice: \n'1' for addition  \n'2' for subraction \n'3' for multiplication \n'4' for division \n'5' for a random choice  " << endl;
        cin >> choice;
        if (choice == 5) {
            choice = rand() % 4 + 1;
        }
        switch (choice)
        {
        case 1:
            cout << "Addition quiz:" << endl;
            additionAssist();
            break;
        case 2:
            cout << "Subtraction quiz:" << endl;
            subractionAssist();
            break;
        case 3:
            cout << "Multiplication quiz: " << endl;
            multiplicationAssistLevel1();
            break;
        case 4:
            cout << "Division quiz" << endl;
            divisionAssist();
            break;
        }
        cout << "Enter 'y' for another quiz or 'x' to quit" << endl;
        cin >> x;
    }
    return 0;
}