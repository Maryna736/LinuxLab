#pragma once

#include <string>
#include <vector>

// Core temperament categories.
enum class Temperament {
    Sanguine = 0,
    Choleric = 1,
    Phlegmatic = 2,
    Melancholic = 3
};

// Minimal question descriptor: associates a question with a temperament axis.
struct Question {
    std::string text;
    Temperament category;
};

// Evaluation outcome: per-category scores and the dominant temperament.
struct Result {
    std::vector<int> scores; // order matches Temperament enum values
    Temperament dominant;
};

// Default survey with a small, illustrative set of prompts.
std::vector<Question> default_questions();

// Compute aggregated scores; answers must match questions by index.
Result evaluate(const std::vector<Question>& questions, const std::vector<int>& answers);

// Helpers for presentation.
std::string to_string(Temperament t);
std::string explain(const Result& r);
