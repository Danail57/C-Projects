//QUIZ PROJECT

#include <iostream>
using namespace std;

const int NUM_QUESTIONS = 20;
const int NUM_OPTIONS = 4;

struct Question {
	string question_text;
	string options[NUM_OPTIONS];
	char correct_option_index;
};

void display_question(const Question& questions)
{
    cout << "Question: " << questions.question_text << endl;
    for (int i = 0; i < NUM_OPTIONS; i++)
    {
        cout << questions.options[i] << endl;
    }
    cout << endl;
}

char get_user_choice()
{
    cout << "Enter your choice (A,B,C,D) : ";
    char choice;
    cin >> choice;
    choice = toupper(choice);
    return choice;
}

bool validate_choice(char choice)
{
    return (choice == 'A' || choice == 'B' || choice == 'C' || choice == 'D');
}

void process_answer(const Question& questions, char user_choice, int& score)
{
    if (!validate_choice(user_choice))
    {
        cout << "Invalid choice! Got 0. " << endl;
        return;
    }

    if (user_choice == questions.correct_option_index) 
    {
        cout << "\tCorrect!" << endl;
        score += 10;
    }
    else
    {
        cout << "\tIncorrect! The correct answer is: "
            << questions.correct_option_index << endl; 
        score -= 5;
    }
}


void display_result(int& score)
{
    cout << "      QUIZ COMPLETED!" << endl;
    cout << "You got " << score << " out of " << NUM_QUESTIONS * 10 << endl;
}


int main()
{
    Question questions[NUM_QUESTIONS] =
    {
        {
            "Which of these is a valid way to create a dictionary?",
            {"A. dict(a=1, b=2)", "B. {'a': 1, 'b': 2}", "C. dict([('a',1), ('b',2)])", "D. All of the above"},
            'D'
        },
        {
            "What will be the output of print(type([1, 2, 3]))?",
            {"A. list", "B. array", "C. <class 'list'>", "D. type: list"},
            'C'
        },
        {
            "What is the difference between list.append() and list.extend()?",
            {"A. No difference", "B. append() adds one element, extend() adds multiple elements", "C. append() adds to the start, extend() to the end", "D. append() works with lists only"},
            'B'
        },
        {
            "What is a decorator in Python?",
            {"A. A function that adds CSS styling", "B. A design pattern for classes", "C. A function that takes another function and extends its behavior", "D. A way to comment code"},
            'C'
        },
        {
            "What does this code output?\nx = [1, 2, 3]\ny = x\ny.append(4)\nprint(x)",
            {"A. [1, 2, 3]", "B. [1, 2, 3, 4]", "C. [4]", "D. Error"},
            'B'
        },
        {
            "What is the purpose of the __init__ method in a class?",
            {"A. To initialize class variables", "B. To create a new instance of the class", "C. To define the constructor of the class", "D. To import required modules"},
            'C'
        },
        {
            "What is a generator in Python?",
            {"A. A function that generates random numbers", "B. A function that yields values one at a time", "C. A class that creates new instances", "D. A tool for creating new functions"},
            'B'
        },
        {
            "Which statement about Python's GIL is correct?",
            {"A. It allows multiple threads simultaneously", "B. It prevents multiple threads simultaneously", "C. It is used for garbage collection", "D. It manages database connections"},
            'B'
        },
        {
            "What is the correct way to handle exceptions?",
            {"A. except:", "B. except Exception:", "C. except ZeroDivisionError:", "D. Both B and C are correct"},
            'D'
        },
        {
            "What is the output of this list comprehension?\n[x**2 for x in range(5) if x % 2 == 0]",
            {"A. [0, 2, 4]", "B. [0, 4, 16]", "C. [0, 1, 4, 9, 16]", "D. [0, 4]"},
            'B'
        },
        {
            "What is a variable in Python?",
            {"A. A reserved keyword", "B. A container for storing data", "C. A function", "D. A data type"},
            'B'
        },
        {
            "Which of the following is NOT a built-in data type in Python?",
            {"A. int", "B. float", "C. string", "D. char"},
            'D'
        },
        {
            "What does the // operator do in Python?",
            {"A. Division", "B. Modulo", "C. Floor division", "D. Power"},
            'C'
        },
        {
            "Which keyword is used for conditional execution?",
            {"A. loop", "B. if", "C. switch", "D. when"},
            'B'
        },
        {
            "What will this code print?\nfor i in range(3): print(i)",
            {"A. 1 2 3", "B. 0 1 2", "C. 0 1 2 3", "D. Error"},
            'B'
        },
        {
            "Are Python strings mutable?",
            {"A. Yes", "B. No", "C. Only lowercase", "D. Only uppercase"},
            'B'
        },
        {
            "What is a key property of tuples?",
            {"A. Mutable", "B. Ordered", "C. Immutable", "D. Numeric only"},
            'C'
        },
        {
            "How do you access value 'age' in dictionary d?",
            {"A. d.age", "B. d('age')", "C. d['age']", "D. d.get"},
            'C'
        },
        {
            "What does self refer to in a Python class?",
            {"A. The class", "B. Static variable", "C. Current object", "D. Parent class"},
            'C'
        },
        {
            "Which block is always executed in exception handling?",
            {"A. try", "B. except", "C. finally", "D. raise"},
            'C'
        }
    };

    int score = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++)
    {
        display_question(questions[i]);
        char user_choice = get_user_choice();
        process_answer(questions[i], user_choice, score);
        cout << endl << endl;
    }

    display_result(score);
}
