#include "slr.h"
#include <vector>
#include <numeric>
#include <iostream>

slr::slr() : slope(0.0), intercept(0.0), isFitted(false) {}

void slr::fit(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.empty() || x.size() != y.size()) {
        std::cerr << "Error: Input vectors must be non-empty and of equal size." << std::endl;
        return;
    }

    size_t n = x.size();
    double sumX = 0.0, sumY = 0.0;
    double sumXY = 0.0, sumX2 = 0.0;

    for (size_t i = 0; i < n; ++i) {
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    double denominator = (n * sumX2) - (sumX * sumX);
    if (denominator == 0.0) {
        std::cerr << "Error: Division by zero encountered in slope calculation." << std::endl;
        return;
    }

    // Calculate slope (beta_1) and intercept (beta_0)
    slope = ((n * sumXY) - (sumX * sumY)) / denominator;
    intercept = (sumY - (slope * sumX)) / static_cast<double>(n);
    isFitted = true;
}

double slr::predict(double x) const {
    if (!isFitted) {
        std::cerr << "Warning: Model has not been fitted yet." << std::endl;
        return 0.0;
    }
    return slope * x + intercept;
}

double slr::getSlope() const {
    return slope;
}

double slr::getIntercept() const {
    return intercept;
}