#include "temperament.h"

#include <algorithm>
#include <array>
#include <sstream>

namespace {
// Clamp helper to keep answers within an expected range.
int clamp_score(int value, int low, int high) {
    return std::min(std::max(value, low), high);
}
}

std::vector<Question> default_questions() {
    return {
        {"Do you easily meet new people? (1-5)", Temperament::Sanguine},
        {"Do you tend to make decisions quickly? (1-5)", Temperament::Choleric},
        {"Are you comfortable maintaining steady routines? (1-5)", Temperament::Phlegmatic},
        {"Do you often focus on small details? (1-5)", Temperament::Melancholic},
        {"How energetic are you with new projects? (1-5)", Temperament::Choleric},
        {"Is it easy for you to switch tasks? (1-5)", Temperament::Sanguine},
        {"How consistent are you day to day? (1-5)", Temperament::Phlegmatic},
        {"Do you often analyze past experiences? (1-5)", Temperament::Melancholic}
    };
}

Result evaluate(const std::vector<Question>& questions, const std::vector<int>& answers) {
    constexpr int kTypes = 4;
    std::array<int, kTypes> accum{};

    const std::size_t count = std::min(questions.size(), answers.size());
    for (std::size_t i = 0; i < count; ++i) {
        const int bounded = clamp_score(answers[i], 1, 5);
        const auto idx = static_cast<int>(questions[i].category);
        accum[idx] += bounded;
    }

    auto max_it = std::max_element(accum.begin(), accum.end());
    const int dominant_idx = static_cast<int>(std::distance(accum.begin(), max_it));

    Result r;
    r.scores.assign(accum.begin(), accum.end());
    r.dominant = static_cast<Temperament>(dominant_idx);
    return r;
}

std::string to_string(Temperament t) {
    switch (t) {
        case Temperament::Sanguine:
            return "Sanguine";
        case Temperament::Choleric:
            return "Choleric";
        case Temperament::Phlegmatic:
            return "Phlegmatic";
        case Temperament::Melancholic:
            return "Melancholic";
        default:
            return "Unknown";
    }
}

std::string explain(const Result& r) {
    std::ostringstream oss;
    oss << "Dominant temperament: " << to_string(r.dominant) << "\n";
    oss << "Scores (Sanguine/Choleric/Phlegmatic/Melancholic): ";
    for (std::size_t i = 0; i < r.scores.size(); ++i) {
        oss << r.scores[i];
        if (i + 1 < r.scores.size()) {
            oss << "/";
        }
    }
    return oss.str();
}
