#include "temperament.h"

#include <iostream>
#include <limits>
#include <vector>

int main() {
    const auto questions = default_questions();
    std::vector<int> answers;
    answers.reserve(questions.size());

    std::cout << "Temperament mini-test (rate 1-5)\n";
    for (const auto& q : questions) {
        int score = 0;
        while (true) {
            std::cout << "- " << q.text << " ";
            if (std::cin >> score && score >= 1 && score <= 5) {
                break;
            }
            std::cout << "Please enter a number between 1 and 5.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        answers.push_back(score);
    }

    const Result r = evaluate(questions, answers);
    std::cout << "\n" << explain(r) << "\n";
    return 0;
}
